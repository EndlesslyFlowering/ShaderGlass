/*
ShaderGlass shader crt/shaders/crt-royale/src-fast\crt-royale-bloom-horizontal-reconstitute imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/crt/shaders/crt-royale/src-fast/crt-royale-bloom-horizontal-reconstitute.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

/////////////////////////////  GPL LICENSE NOTICE  /////////////////////////////
//  crt-royale: A full-featured CRT shader, with cheese.
//  Copyright (C) 2014 TroggleMonkey <trogglemonkey@gmx.com>
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along with
//  this program; if not, write to the Free Software Foundation, Inc., 59 Temple
//  Place, Suite 330, Boston, MA 02111-1307 USA
/////////////////////////////  SETTINGS MANAGEMENT  ////////////////////////////
/////////////////////////////  GPL LICENSE NOTICE  /////////////////////////////
//  crt-royale: A full-featured CRT shader, with cheese.
//  Copyright (C) 2014 TroggleMonkey <trogglemonkey@gmx.com>
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along with
//  this program; if not, write to the Free Software Foundation, Inc., 59 Temple
//  Place, Suite 330, Boston, MA 02111-1307 USA
/////////////////////////////  SETTINGS MANAGEMENT  ////////////////////////////
//	float mask_sample_mode_desired;
//    #ifdef DRIVERS_ALLOW_DERIVATIVES
//        #define DRIVERS_ALLOW_FINE_DERIVATIVES
//    #endif
//#define DRIVERS_ALLOW_DYNAMIC_BRANCHES
//#define ACCOMODATE_POSSIBLE_DYNAMIC_LOOPS
//#define DRIVERS_ALLOW_TEX2DLOD
//#define DRIVERS_ALLOW_TEX2DBIAS
//#define INTEGRATED_GRAPHICS_COMPATIBILITY_MODE
//#define RUNTIME_ANTIALIAS_SUBPIXEL_OFFSETS
//#define PHOSPHOR_BLOOM_TRIADS_LARGER_THAN_6_PIXELS
//#define PHOSPHOR_BLOOM_TRIADS_LARGER_THAN_9_PIXELS
//#define PHOSPHOR_BLOOM_TRIADS_LARGER_THAN_12_PIXELS
//  GAMMA:
//  LEVELS MANAGEMENT:
//  HALATION/DIFFUSION/BLOOM:
//  ANTIALIASING:
//  PHOSPHOR MASK:
//  GEOMETRY:
//  BORDERS:
//  PASS SCALES AND RELATED CONSTANTS:
//  PHOSPHOR MASK TEXTURE CONSTANTS:
//vec2 mask_texture_large_size = vec2(512.0, 512.0);
//#define PHOSPHOR_MASK_GRILLE14
//float mask_grille14_avg_color = 50.6666666/255.0;
////////////////////////  COMMON MATHEMATICAL CONSTANTS  ///////////////////////
//  Override some parameters for gamma-management.h and tex2Dantialias.h:
//#pragma parameter mask_sample_mode_desired "Mask - Sample Mode" 0.0 0.0 2.0 1.0   //  Consider blocking mode 2.
//#define mask_sample_mode_desired global.mask_sample_mode_desired
//#define interlace_bff global.interlace_bff
//  Provide accessors for vector constants that pack scalar uniforms:
//  Get an aspect ratio vector.  Enforce geom_max_aspect_ratio, and prevent
//  the absolute scale from affecting the uv-mapping for curvature:
//  Provide accessors settings which still need "cooking:
//float get_mask_sample_mode()
//{
//    return mask_sample_mode_desired;
//}
///////////////////////////////  VERTEX INCLUDES  //////////////////////////////
/////////////////////////////  GPL LICENSE NOTICE  /////////////////////////////
//  crt-royale: A full-featured CRT shader, with cheese.
//  Copyright (C) 2014 TroggleMonkey <trogglemonkey@gmx.com>
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along with
//  this program; if not, write to the Free Software Foundation, Inc., 59 Temple
//  Place, Suite 330, Boston, MA 02111-1307 USA
//////////////////////////////////  INCLUDES  //////////////////////////////////
/////////////////////////////////  MIT LICENSE  ////////////////////////////////
//  Copyright (C) 2014 TroggleMonkey
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
///////////////////////////  GAUSSIAN ERROR FUNCTION  //////////////////////////
//  Requires:   x is the standard parameter to erf().
//  Returns:    Return an Abramowitz/Stegun approximation of erf(), where:
//                  erf(x) = 2/sqrt(pi) * integral(e**(-x**2))
//              This approximation has a max absolute error of 2.5*10**-5
//              with solid numerical robustness and efficiency.  See:
//                  https://en.wikipedia.org/wiki/Error_function#Approximation_with_elementary_functions
//  Float3 version:
//  Float2 version:
//  Float version:
//  Requires:   x is the standard parameter to erf().
//  Returns:    Approximate erf() with the hyperbolic tangent.  The error is
//              visually noticeable, but it's blazing fast and perceptually
//              close...at least on ATI hardware.  See:
//                  http://www.maplesoft.com/applications/view.aspx?SID=5525&view=html
//  Warning:    Only use this if your hardware drivers correctly implement
//              tanh(): My nVidia 8800GTS returns garbage output.
//  Float3 version:
//  Float2 version:
//  Float version:
//  Requires:   x is the standard parameter to erf().
//  Returns:    Some approximation of erf(x), depending on user settings.
//  Float3 version:
//  Float2 version:
//  Float version:
///////////////////////////  COMPLETE GAMMA FUNCTION  //////////////////////////
//  Requires:   1.) s is the standard parameter to the gamma function, and
//                  it should lie in the [0, 36] range.
//              2.) s_inv = 1.0/s.  This implementation function requires
//                  the caller to precompute this value, giving users the
//                  opportunity to reuse it.
//  Returns:    Return approximate gamma function (real-numbered factorial)
//              output using the Lanczos approximation with two coefficients
//              calculated using Paul Godfrey's method here:
//                  http://my.fit.edu/~gabdo/gamma.txt
//              An optimal g value for s in [0, 36] is ~1.12906830989, with
//              a maximum relative error of 0.000463 for 2**16 equally
//              evals.  We could use three coeffs (0.0000346 error) without
//              hurting latency, but this allows more parallelism with
//              outside instructions.
//  gamma(s + 1) = base**sph * lanczos_sum; divide by s for gamma(s).
//  This has less error for small s's than (s -= 1.0) at the beginning.
//  Float3 version:
//  Float2 version:
//  Float version:
//  Requires:   s is the standard parameter to the gamma function, and it
//              should lie in the [0, 36] range.
//  Returns:    Return approximate gamma function output with a maximum
//              relative error of 0.000463.  See gamma_impl for details.
//  Float3 version:
//  Float2 version:
//  Float version:
////////////////  INCOMPLETE GAMMA FUNCTIONS (RESTRICTED INPUT)  ///////////////
//  Lower incomplete gamma function for small s and z (implementation):
//  Requires:   1.) s < ~0.5
//              2.) z <= ~0.775075
//              3.) s_inv = 1.0/s (precomputed for outside reuse)
//  Returns:    A series representation for the lower incomplete gamma
//              function for small s and small z (4 terms).
//  The actual "rolled up" summation looks like:
//      last_sign = 1.0; last_pow = 1.0; last_factorial = 1.0;
//      sum = last_sign * last_pow / ((s + k) * last_factorial)
//      for(int i = 0; i < 4; ++i)
//      {
//          last_sign *= -1.0; last_pow *= z; last_factorial *= i;
//          sum += last_sign * last_pow / ((s + k) * last_factorial);
//      }
//  Unrolled, constant-unfolded and arranged for madds and parallelism:
//  Summation iterations 1, 2, and 3:
//vec4 denom4 = 24.0*s + vec4(96.0);
//sum += z_sq * z_sq / denom4;
//  Scale and return:
//  Float3 version:
//  Float2 version:
//  Float version:
//  Upper incomplete gamma function for small s and large z (implementation):
//  Requires:   1.) s < ~0.5
//              2.) z > ~0.775075
//  Returns:    Gauss's continued fraction representation for the upper
//              incomplete gamma function (4 terms).
//  The "rolled up" continued fraction looks like this.  The denominator
//  is truncated, and it's calculated "from the bottom up:
//      denom = vec4('inf');
//      vec4 one = vec4(1.0);
//      for(int i = 4; i > 0; --i)
//      {
//          denom = ((i * 2.0) - one) + z - s + (i * (s - i))/denom;
//      }
//  Unrolled and constant-unfolded for madds and parallelism:
//  Float3 version:
//  Float2 version:
//  Float version:
//  Normalized lower incomplete gamma function for small s (implementation):
//  Requires:   1.) s < ~0.5
//              2.) s_inv = 1/s (precomputed for outside reuse)
//              3.) gamma_s_inv = 1/gamma(s) (precomputed for outside reuse)
//  Returns:    Approximate the normalized lower incomplete gamma function
//              for s < 0.5.  Since we only care about s < 0.5, we only need
//              to evaluate two branches (not four) based on z.  Each branch
//              uses four terms, with a max relative error of ~0.00182.  The
//              branch threshold and specifics were adapted for fewer terms
//              from Gil/Segura/Temme's paper here:
//                  http://oai.cwi.nl/oai/asset/20433/20433B.pdf
//  Evaluate both branches: Real branches test slower even when available.
//  Combine the results from both branches:
//  Float3 version:
//  Float2 version:
//  Float version:
//  Normalized lower incomplete gamma function for small s:
//  Requires:   s < ~0.5
//  Returns:    Approximate the normalized lower incomplete gamma function
//              for s < 0.5.  See normalized_ligamma_impl() for details.
//  Float3 version:
//  Float2 version:
//  Float version:
/////////////////////////////  SCANLINE FUNCTIONS  /////////////////////////////
//  Use a power function:
//  Use a spherical function:
//  Sample 1/3 pixel away in each direction as well:
//  Average three pure Gaussian samples:
//  Avoid repeated divides:
//  Sample 1/3 pixel closer to and farther from the scanline too.
//  Average three generalized Gaussian samples:
// 2 - Apply mask only.
//  Use max to avoid bizarre artifacts from negative colors:
//  Inputs: color0-3 are colors in linear RGB.
// wtf fixme
//			float beam_horiz_linear_rgb_weight1 = 1.0;
//  Use under_half to fix a rounding bug right around exact texel locations.
//  Get Quilez, Lanczos2, or Gaussian resize weights for 2/4 nearby texels:
//  Quilez:
//  Gaussian:
//  Lanczos2:
//  Linear:
//  Ensure the weight sum == 1.0:
//  Get the interpolated horizontal scanline color:
//  TODO: Add function requirements.
//  Rely on a helper to make convergence easier.
// Monolythic
//  Use under_half to fix a rounding bug right around exact texel locations.
//  Snap to the center of the previous scanline in the current field:
//  Save the sample's distance from the scanline, in units of scanlines:
//  Detect interlacing based on the number of lines in the source.
//  NTSC: 525 lines, 262.5/field; 486 active (2 half-lines), 243/field
//  NTSC Emulators: Typically 224 or 240 lines
//  PAL: 625 lines, 312.5/field; 576 active (typical), 288/field
//  PAL Emulators: ?
//  ATSC: 720p, 1080i, 1080p
//  Where do we place our cutoffs?  Assumptions:
//  1.) We only need to care about active lines.
//  2.) Anything > 288 and <= 576 lines is probably interlaced.
//  3.) Anything > 576 lines is probably not interlaced...
//  4.) ...except 1080 lines, which is a crapshoot (user decision).
//  5.) Just in case the main program uses calculated video sizes,
//      we should nudge the float thresholds a bit.
// copied from bloom-functions.h
//  Requires:   1.) triad_size is the final phosphor triad size in pixels
//              2.) thresh is the max desired pixel difference in the
//                  blurred triad (e.g. 1.0/256.0).
//  Returns:    Return the minimum sigma that will fully blur a phosphor
//              triad on the screen to an even color, within thresh.
//              This closed-form function was found by curve-fitting data.
//  Estimate: max error = ~0.086036, mean sq. error = ~0.0013387:
//  Estimate: max error = ~0.16486, mean sq. error = ~0.0041041:
//return 0.5985*triad_size - triad_size*sqrt(thresh)
//  We can use the Gaussian integral to calculate the asymptotic weight for
//  the center pixel.  Since the unnormalized center pixel weight is 1.0,
//  the normalized weight is the same as the weight sum inverse.  Given a
//  large enough blur (9+), the asymptotic weight sum is close and faster:
//      center_weight = 0.5 *
//          (erf(0.5/(sigma*sqrt(2.0))) - erf(-0.5/(sigma*sqrt(2.0))))
//      erf(-x) == -erf(x), so we get 0.5 * (2.0 * erf(blah blah)):
//  However, we can get even faster results with curve-fitting.  These are
//  also closer than the asymptotic results, because they were constructed
//  from 64 blurs sizes from [3, 131) and 255 equally-spaced sigmas from
//  (0, blurN_std_dev), so the results for smaller sigmas are biased toward
//  smaller blurs.  The max error is 0.0031793913.
//  Relative FPS: 134.3 with erf, 135.8 with curve-fitting.
//float temp = 0.5/sqrt(2.0);
//return erf(temp/sigma);
//  Stated tile properties must be correct:
//  If mask_specify_num_triads is 1.0/true and estimated_viewport_size.x is
//  wrong, the user preference will be misinterpreted:
//  Make sure we're not upsizing:
//  Enforce min_tile_size and max_tile_size in both dimensions:
//  We need integer tile sizes in both directions for tiled sampling to
//  work correctly.  Use floor (to make sure we don't round up), but be
//  careful to avoid a rounding bug where floor decreases whole numbers:
//  We're horizontally blurring the bloom input (vertically blurred
//  brightpass).  Get the uv distance between output pixels / input texels
//  in the horizontal direction (this pass must NOT resize):
//  Calculate a runtime bloom_sigma in case it's needed:
//    undim_mask_contrast_factors = 2.0 * (255.0/46.0) * 1.0;
//////////////////////////////  FRAGMENT INCLUDES  //////////////////////////////
//  Sample the masked scanlines.  Alpha contains the auto-dim factor:
//  Calculate the mask dimpass, add it to the blurred brightpass, and
//  undim (from scanline auto-dim) and amplify (from mask dim) the result:
//  Encode and output the bloomed image:

*/

#pragma once

namespace RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs
{
static const BYTE sVertexByteCode[] =
{
68,88,66,67,76,216,
48,66,204,0,112,252,
8,97,87,49,36,154,
68,100,1,0,0,0,
200,18,0,0,5,0,
0,0,52,0,0,0,
12,11,0,0,88,11,
0,0,64,12,0,0,
44,18,0,0,82,68,
69,70,208,10,0,0,
2,0,0,0,136,0,
0,0,2,0,0,0,
60,0,0,0,0,5,
254,255,0,129,0,0,
168,10,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
124,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,128,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,1,0,
0,0,1,0,0,0,
0,0,0,0,85,66,
79,0,80,117,115,104,
0,171,171,171,124,0,
0,0,32,0,0,0,
184,0,0,0,192,0,
0,0,0,0,0,0,
0,0,0,0,128,0,
0,0,5,0,0,0,
72,9,0,0,80,0,
0,0,0,0,0,0,
0,0,0,0,184,5,
0,0,0,0,0,0,
64,0,0,0,2,0,
0,0,204,5,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,240,5,0,0,
64,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
44,6,0,0,68,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,61,6,
0,0,72,0,0,0,
4,0,0,0,2,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,84,6,0,0,
76,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
118,6,0,0,80,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,138,6,
0,0,84,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,160,6,0,0,
88,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
182,6,0,0,92,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,205,6,
0,0,96,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,227,6,0,0,
100,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
249,6,0,0,104,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,17,7,
0,0,108,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,42,7,0,0,
112,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
66,7,0,0,116,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,102,7,
0,0,120,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,132,7,0,0,
124,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
162,7,0,0,128,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,192,7,
0,0,132,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,222,7,0,0,
136,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
252,7,0,0,140,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,26,8,
0,0,144,0,0,0,
4,0,0,0,2,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,43,8,0,0,
148,0,0,0,4,0,
0,0,2,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
74,8,0,0,152,0,
0,0,4,0,0,0,
2,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,105,8,
0,0,156,0,0,0,
4,0,0,0,2,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,136,8,0,0,
160,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
174,8,0,0,164,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,212,8,
0,0,168,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,230,8,0,0,
172,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
252,8,0,0,176,0,
0,0,4,0,0,0,
0,0,0,0,8,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,17,9,
0,0,180,0,0,0,
4,0,0,0,0,0,
0,0,8,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,40,9,0,0,
184,0,0,0,4,0,
0,0,0,0,0,0,
8,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
103,108,111,98,97,108,
95,77,86,80,0,102,
108,111,97,116,52,120,
52,0,2,0,3,0,
4,0,4,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,195,5,
0,0,103,108,111,98,
97,108,95,99,114,116,
95,103,97,109,109,97,
0,102,108,111,97,116,
0,171,0,0,3,0,
1,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,1,6,
0,0,103,108,111,98,
97,108,95,108,99,100,
95,103,97,109,109,97,
0,103,108,111,98,97,
108,95,108,101,118,101,
108,115,95,99,111,110,
116,114,97,115,116,0,
103,108,111,98,97,108,
95,98,108,111,111,109,
95,117,110,100,101,114,
101,115,116,105,109,97,
116,101,95,108,101,118,
101,108,115,0,103,108,
111,98,97,108,95,98,
108,111,111,109,95,101,
120,99,101,115,115,0,
103,108,111,98,97,108,
95,98,101,97,109,95,
109,105,110,95,115,105,
103,109,97,0,103,108,
111,98,97,108,95,98,
101,97,109,95,109,97,
120,95,115,105,103,109,
97,0,103,108,111,98,
97,108,95,98,101,97,
109,95,115,112,111,116,
95,112,111,119,101,114,
0,103,108,111,98,97,
108,95,98,101,97,109,
95,109,105,110,95,115,
104,97,112,101,0,103,
108,111,98,97,108,95,
98,101,97,109,95,109,
97,120,95,115,104,97,
112,101,0,103,108,111,
98,97,108,95,98,101,
97,109,95,115,104,97,
112,101,95,112,111,119,
101,114,0,103,108,111,
98,97,108,95,98,101,
97,109,95,104,111,114,
105,122,95,102,105,108,
116,101,114,0,103,108,
111,98,97,108,95,98,
101,97,109,95,104,111,
114,105,122,95,115,105,
103,109,97,0,103,108,
111,98,97,108,95,98,
101,97,109,95,104,111,
114,105,122,95,108,105,
110,101,97,114,95,114,
103,98,95,119,101,105,
103,104,116,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
120,95,114,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
120,95,103,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
120,95,98,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
121,95,114,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
121,95,103,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
121,95,98,0,103,108,
111,98,97,108,95,109,
97,115,107,95,116,121,
112,101,0,103,108,111,
98,97,108,95,109,97,
115,107,95,110,117,109,
95,116,114,105,97,100,
115,95,100,101,115,105,
114,101,100,0,103,108,
111,98,97,108,95,109,
97,115,107,95,116,114,
105,97,100,95,115,105,
122,101,95,100,101,115,
105,114,101,100,0,103,
108,111,98,97,108,95,
109,97,115,107,95,115,
112,101,99,105,102,121,
95,110,117,109,95,116,
114,105,97,100,115,0,
103,108,111,98,97,108,
95,97,97,95,115,117,
98,112,105,120,101,108,
95,114,95,111,102,102,
115,101,116,95,120,95,
114,117,110,116,105,109,
101,0,103,108,111,98,
97,108,95,97,97,95,
115,117,98,112,105,120,
101,108,95,114,95,111,
102,102,115,101,116,95,
121,95,114,117,110,116,
105,109,101,0,103,108,
111,98,97,108,95,97,
97,95,99,117,98,105,
99,95,99,0,103,108,
111,98,97,108,95,97,
97,95,103,97,117,115,
115,95,115,105,103,109,
97,0,103,108,111,98,
97,108,95,105,110,116,
101,114,108,97,99,101,
95,98,102,102,0,103,
108,111,98,97,108,95,
105,110,116,101,114,108,
97,99,101,95,49,48,
56,48,105,0,103,108,
111,98,97,108,95,105,
110,116,101,114,108,97,
99,101,95,100,101,116,
101,99,116,95,116,111,
103,103,108,101,0,171,
16,10,0,0,0,0,
0,0,16,0,0,0,
2,0,0,0,44,10,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,80,10,
0,0,16,0,0,0,
16,0,0,0,0,0,
0,0,44,10,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,100,10,0,0,
32,0,0,0,16,0,
0,0,2,0,0,0,
44,10,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
118,10,0,0,48,0,
0,0,16,0,0,0,
0,0,0,0,44,10,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,146,10,
0,0,64,0,0,0,
16,0,0,0,0,0,
0,0,44,10,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,112,97,114,97,
109,115,95,83,111,117,
114,99,101,83,105,122,
101,0,102,108,111,97,
116,52,0,171,171,171,
1,0,3,0,1,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,34,10,0,0,
112,97,114,97,109,115,
95,79,114,105,103,105,
110,97,108,83,105,122,
101,0,112,97,114,97,
109,115,95,79,117,116,
112,117,116,83,105,122,
101,0,112,97,114,97,
109,115,95,77,65,83,
75,69,68,95,83,67,
65,78,76,73,78,69,
83,83,105,122,101,0,
112,97,114,97,109,115,
95,66,82,73,71,72,
84,80,65,83,83,83,
105,122,101,0,77,105,
99,114,111,115,111,102,
116,32,40,82,41,32,
72,76,83,76,32,83,
104,97,100,101,114,32,
67,111,109,112,105,108,
101,114,32,49,48,46,
49,0,73,83,71,78,
68,0,0,0,2,0,
0,0,8,0,0,0,
56,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,15,15,0,0,
56,0,0,0,1,0,
0,0,0,0,0,0,
3,0,0,0,1,0,
0,0,3,3,0,0,
84,69,88,67,79,79,
82,68,0,171,171,171,
79,83,71,78,224,0,
0,0,8,0,0,0,
8,0,0,0,200,0,
0,0,0,0,0,0,
0,0,0,0,3,0,
0,0,0,0,0,0,
3,12,0,0,200,0,
0,0,1,0,0,0,
0,0,0,0,3,0,
0,0,0,0,0,0,
12,3,0,0,200,0,
0,0,2,0,0,0,
0,0,0,0,3,0,
0,0,1,0,0,0,
1,14,0,0,200,0,
0,0,5,0,0,0,
0,0,0,0,3,0,
0,0,1,0,0,0,
2,13,0,0,200,0,
0,0,6,0,0,0,
0,0,0,0,3,0,
0,0,1,0,0,0,
4,11,0,0,200,0,
0,0,3,0,0,0,
0,0,0,0,3,0,
0,0,2,0,0,0,
15,0,0,0,200,0,
0,0,4,0,0,0,
0,0,0,0,3,0,
0,0,3,0,0,0,
15,0,0,0,209,0,
0,0,0,0,0,0,
1,0,0,0,3,0,
0,0,4,0,0,0,
15,0,0,0,84,69,
88,67,79,79,82,68,
0,83,86,95,80,111,
115,105,116,105,111,110,
0,171,171,171,83,72,
69,88,228,5,0,0,
80,0,1,0,121,1,
0,0,106,8,0,1,
89,0,0,4,70,142,
32,0,0,0,0,0,
10,0,0,0,89,0,
0,4,70,142,32,0,
1,0,0,0,3,0,
0,0,95,0,0,3,
242,16,16,0,0,0,
0,0,95,0,0,3,
50,16,16,0,1,0,
0,0,101,0,0,3,
50,32,16,0,0,0,
0,0,101,0,0,3,
194,32,16,0,0,0,
0,0,101,0,0,3,
18,32,16,0,1,0,
0,0,101,0,0,3,
34,32,16,0,1,0,
0,0,101,0,0,3,
66,32,16,0,1,0,
0,0,101,0,0,3,
242,32,16,0,2,0,
0,0,101,0,0,3,
242,32,16,0,3,0,
0,0,103,0,0,4,
242,32,16,0,4,0,
0,0,1,0,0,0,
104,0,0,2,3,0,
0,0,14,0,0,11,
66,32,16,0,0,0,
0,0,2,64,0,0,
0,0,128,63,0,0,
128,63,0,0,128,63,
0,0,128,63,10,128,
32,0,1,0,0,0,
0,0,0,0,54,0,
0,5,50,32,16,0,
0,0,0,0,70,16,
16,0,1,0,0,0,
54,0,0,5,130,32,
16,0,0,0,0,0,
1,64,0,0,0,0,
0,0,14,0,0,9,
18,0,16,0,0,0,
0,0,10,128,32,0,
1,0,0,0,2,0,
0,0,26,128,32,0,
0,0,0,0,9,0,
0,0,0,0,0,9,
18,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,42,128,
32,128,65,0,0,0,
0,0,0,0,9,0,
0,0,50,0,0,11,
18,0,16,0,0,0,
0,0,58,128,32,0,
0,0,0,0,9,0,
0,0,10,0,16,0,
0,0,0,0,42,128,
32,0,0,0,0,0,
9,0,0,0,56,0,
0,7,18,0,16,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
0,65,51,0,0,7,
18,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,1,64,
0,0,0,0,128,66,
52,0,0,7,18,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,1,64,0,0,
0,0,128,65,56,0,
0,11,98,0,16,0,
0,0,0,0,2,64,
0,0,0,0,0,0,
57,142,99,61,57,142,
99,61,0,0,0,0,
6,129,32,0,1,0,
0,0,2,0,0,0,
51,0,0,7,50,0,
16,0,0,0,0,0,
150,5,16,0,0,0,
0,0,6,0,16,0,
0,0,0,0,51,0,
0,7,18,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,0,0,0,7,
18,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,1,64,
0,0,0,0,128,55,
65,0,0,5,18,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,50,0,0,9,
34,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,1,64,
0,0,40,126,156,61,
1,64,0,0,104,174,
83,189,50,0,0,10,
18,0,16,0,0,0,
0,0,10,0,16,128,
65,0,0,0,0,0,
0,0,1,64,0,0,
224,17,23,60,26,0,
16,0,0,0,0,0,
0,0,0,7,34,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,1,64,0,0,
143,63,176,189,14,0,
0,10,98,0,16,0,
0,0,0,0,2,64,
0,0,0,0,0,0,
185,90,178,62,149,117,
204,62,0,0,0,0,
86,4,16,0,0,0,
0,0,56,0,0,7,
34,0,16,0,0,0,
0,0,26,0,16,0,
0,0,0,0,1,64,
0,0,59,170,184,63,
25,0,0,5,34,0,
16,0,0,0,0,0,
26,0,16,0,0,0,
0,0,56,0,0,7,
34,0,16,0,0,0,
0,0,26,0,16,0,
0,0,0,0,1,64,
0,0,59,170,184,63,
25,0,0,5,34,0,
16,0,0,0,0,0,
26,0,16,0,0,0,
0,0,51,0,0,7,
34,32,16,0,1,0,
0,0,42,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
49,0,0,11,98,0,
16,0,0,0,0,0,
6,128,32,0,0,0,
0,0,9,0,0,0,
2,64,0,0,0,0,
0,0,0,0,0,63,
0,0,192,63,0,0,
0,0,55,0,0,9,
66,0,16,0,0,0,
0,0,42,0,16,0,
0,0,0,0,1,64,
0,0,44,100,177,64,
1,64,0,0,62,6,
199,64,55,0,0,9,
34,0,16,0,0,0,
0,0,26,0,16,0,
0,0,0,0,1,64,
0,0,87,246,153,64,
42,0,16,0,0,0,
0,0,15,0,0,8,
66,32,16,0,1,0,
0,0,166,138,32,0,
0,0,0,0,4,0,
0,0,86,5,16,0,
0,0,0,0,54,0,
0,5,18,32,16,0,
1,0,0,0,10,0,
16,0,0,0,0,0,
56,0,0,7,18,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,14,0,
0,7,18,0,16,0,
0,0,0,0,1,64,
0,0,0,0,0,63,
10,0,16,0,0,0,
0,0,56,0,0,10,
242,0,16,0,1,0,
0,0,6,0,16,0,
0,0,0,0,2,64,
0,0,59,170,184,191,
59,170,184,192,131,191,
79,193,59,170,184,193,
56,0,0,10,242,0,
16,0,0,0,0,0,
6,0,16,0,0,0,
0,0,2,64,0,0,
254,68,16,194,131,191,
79,194,85,98,141,194,
59,170,184,194,25,0,
0,5,242,0,16,0,
0,0,0,0,70,14,
16,0,0,0,0,0,
25,0,0,5,242,0,
16,0,1,0,0,0,
70,14,16,0,1,0,
0,0,0,0,0,7,
50,0,16,0,2,0,
0,0,214,5,16,0,
1,0,0,0,134,0,
16,0,1,0,0,0,
14,0,0,7,50,32,
16,0,3,0,0,0,
214,5,16,0,1,0,
0,0,70,0,16,0,
2,0,0,0,0,0,
0,7,194,0,16,0,
2,0,0,0,86,13,
16,0,0,0,0,0,
6,8,16,0,0,0,
0,0,14,0,0,7,
194,32,16,0,3,0,
0,0,86,13,16,0,
0,0,0,0,166,14,
16,0,2,0,0,0,
54,0,0,5,242,32,
16,0,2,0,0,0,
70,14,16,0,2,0,
0,0,56,0,0,8,
242,0,16,0,0,0,
0,0,86,21,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
1,0,0,0,50,0,
0,10,242,0,16,0,
0,0,0,0,6,16,
16,0,0,0,0,0,
70,142,32,0,0,0,
0,0,0,0,0,0,
70,14,16,0,0,0,
0,0,50,0,0,10,
242,0,16,0,0,0,
0,0,166,26,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
2,0,0,0,70,14,
16,0,0,0,0,0,
50,0,0,10,242,32,
16,0,4,0,0,0,
246,31,16,0,0,0,
0,0,70,142,32,0,
0,0,0,0,3,0,
0,0,70,14,16,0,
0,0,0,0,62,0,
0,1,83,84,65,84,
148,0,0,0,44,0,
0,0,3,0,0,0,
0,0,0,0,10,0,
0,0,37,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,4,0,0,0,
2,0,0,0,1,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0
};


static const BYTE sFragmentByteCode[] =
{
68,88,66,67,172,57,
146,103,31,116,62,108,
28,170,209,16,37,170,
205,200,1,0,0,0,
184,17,0,0,5,0,
0,0,52,0,0,0,
144,10,0,0,84,11,
0,0,136,11,0,0,
28,17,0,0,82,68,
69,70,84,10,0,0,
1,0,0,0,132,1,
0,0,7,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
43,10,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
28,1,0,0,3,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
1,0,0,0,1,0,
0,0,44,1,0,0,
3,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,3,0,
0,0,1,0,0,0,
1,0,0,0,64,1,
0,0,3,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
4,0,0,0,1,0,
0,0,1,0,0,0,
90,1,0,0,2,0,
0,0,5,0,0,0,
4,0,0,0,255,255,
255,255,2,0,0,0,
1,0,0,0,13,0,
0,0,97,1,0,0,
2,0,0,0,5,0,
0,0,4,0,0,0,
255,255,255,255,3,0,
0,0,1,0,0,0,
13,0,0,0,108,1,
0,0,2,0,0,0,
5,0,0,0,4,0,
0,0,255,255,255,255,
4,0,0,0,1,0,
0,0,13,0,0,0,
125,1,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,95,83,111,117,
114,99,101,95,115,97,
109,112,108,101,114,0,
95,66,82,73,71,72,
84,80,65,83,83,95,
115,97,109,112,108,101,
114,0,95,77,65,83,
75,69,68,95,83,67,
65,78,76,73,78,69,
83,95,115,97,109,112,
108,101,114,0,83,111,
117,114,99,101,0,66,
82,73,71,72,84,80,
65,83,83,0,77,65,
83,75,69,68,95,83,
67,65,78,76,73,78,
69,83,0,85,66,79,
0,171,171,171,125,1,
0,0,32,0,0,0,
156,1,0,0,192,0,
0,0,0,0,0,0,
0,0,0,0,156,6,
0,0,0,0,0,0,
64,0,0,0,0,0,
0,0,176,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,212,6,0,0,
64,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
16,7,0,0,68,0,
0,0,4,0,0,0,
2,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,33,7,
0,0,72,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,56,7,0,0,
76,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
90,7,0,0,80,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,110,7,
0,0,84,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,132,7,0,0,
88,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
154,7,0,0,92,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,177,7,
0,0,96,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,199,7,0,0,
100,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
221,7,0,0,104,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,245,7,
0,0,108,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,14,8,0,0,
112,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
38,8,0,0,116,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,74,8,
0,0,120,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,104,8,0,0,
124,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
134,8,0,0,128,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,164,8,
0,0,132,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,194,8,0,0,
136,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
224,8,0,0,140,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,254,8,
0,0,144,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,15,9,0,0,
148,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
46,9,0,0,152,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,77,9,
0,0,156,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,108,9,0,0,
160,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
146,9,0,0,164,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,184,9,
0,0,168,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,202,9,0,0,
172,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
224,9,0,0,176,0,
0,0,4,0,0,0,
0,0,0,0,236,6,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,245,9,
0,0,180,0,0,0,
4,0,0,0,0,0,
0,0,236,6,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,12,10,0,0,
184,0,0,0,4,0,
0,0,0,0,0,0,
236,6,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
103,108,111,98,97,108,
95,77,86,80,0,102,
108,111,97,116,52,120,
52,0,2,0,3,0,
4,0,4,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,167,6,
0,0,103,108,111,98,
97,108,95,99,114,116,
95,103,97,109,109,97,
0,102,108,111,97,116,
0,171,0,0,3,0,
1,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,229,6,
0,0,103,108,111,98,
97,108,95,108,99,100,
95,103,97,109,109,97,
0,103,108,111,98,97,
108,95,108,101,118,101,
108,115,95,99,111,110,
116,114,97,115,116,0,
103,108,111,98,97,108,
95,98,108,111,111,109,
95,117,110,100,101,114,
101,115,116,105,109,97,
116,101,95,108,101,118,
101,108,115,0,103,108,
111,98,97,108,95,98,
108,111,111,109,95,101,
120,99,101,115,115,0,
103,108,111,98,97,108,
95,98,101,97,109,95,
109,105,110,95,115,105,
103,109,97,0,103,108,
111,98,97,108,95,98,
101,97,109,95,109,97,
120,95,115,105,103,109,
97,0,103,108,111,98,
97,108,95,98,101,97,
109,95,115,112,111,116,
95,112,111,119,101,114,
0,103,108,111,98,97,
108,95,98,101,97,109,
95,109,105,110,95,115,
104,97,112,101,0,103,
108,111,98,97,108,95,
98,101,97,109,95,109,
97,120,95,115,104,97,
112,101,0,103,108,111,
98,97,108,95,98,101,
97,109,95,115,104,97,
112,101,95,112,111,119,
101,114,0,103,108,111,
98,97,108,95,98,101,
97,109,95,104,111,114,
105,122,95,102,105,108,
116,101,114,0,103,108,
111,98,97,108,95,98,
101,97,109,95,104,111,
114,105,122,95,115,105,
103,109,97,0,103,108,
111,98,97,108,95,98,
101,97,109,95,104,111,
114,105,122,95,108,105,
110,101,97,114,95,114,
103,98,95,119,101,105,
103,104,116,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
120,95,114,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
120,95,103,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
120,95,98,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
121,95,114,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
121,95,103,0,103,108,
111,98,97,108,95,99,
111,110,118,101,114,103,
101,110,99,101,95,111,
102,102,115,101,116,95,
121,95,98,0,103,108,
111,98,97,108,95,109,
97,115,107,95,116,121,
112,101,0,103,108,111,
98,97,108,95,109,97,
115,107,95,110,117,109,
95,116,114,105,97,100,
115,95,100,101,115,105,
114,101,100,0,103,108,
111,98,97,108,95,109,
97,115,107,95,116,114,
105,97,100,95,115,105,
122,101,95,100,101,115,
105,114,101,100,0,103,
108,111,98,97,108,95,
109,97,115,107,95,115,
112,101,99,105,102,121,
95,110,117,109,95,116,
114,105,97,100,115,0,
103,108,111,98,97,108,
95,97,97,95,115,117,
98,112,105,120,101,108,
95,114,95,111,102,102,
115,101,116,95,120,95,
114,117,110,116,105,109,
101,0,103,108,111,98,
97,108,95,97,97,95,
115,117,98,112,105,120,
101,108,95,114,95,111,
102,102,115,101,116,95,
121,95,114,117,110,116,
105,109,101,0,103,108,
111,98,97,108,95,97,
97,95,99,117,98,105,
99,95,99,0,103,108,
111,98,97,108,95,97,
97,95,103,97,117,115,
115,95,115,105,103,109,
97,0,103,108,111,98,
97,108,95,105,110,116,
101,114,108,97,99,101,
95,98,102,102,0,103,
108,111,98,97,108,95,
105,110,116,101,114,108,
97,99,101,95,49,48,
56,48,105,0,103,108,
111,98,97,108,95,105,
110,116,101,114,108,97,
99,101,95,100,101,116,
101,99,116,95,116,111,
103,103,108,101,0,77,
105,99,114,111,115,111,
102,116,32,40,82,41,
32,72,76,83,76,32,
83,104,97,100,101,114,
32,67,111,109,112,105,
108,101,114,32,49,48,
46,49,0,171,73,83,
71,78,188,0,0,0,
7,0,0,0,8,0,
0,0,176,0,0,0,
0,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,3,3,
0,0,176,0,0,0,
1,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,12,12,
0,0,176,0,0,0,
2,0,0,0,0,0,
0,0,3,0,0,0,
1,0,0,0,1,0,
0,0,176,0,0,0,
5,0,0,0,0,0,
0,0,3,0,0,0,
1,0,0,0,2,2,
0,0,176,0,0,0,
6,0,0,0,0,0,
0,0,3,0,0,0,
1,0,0,0,4,4,
0,0,176,0,0,0,
3,0,0,0,0,0,
0,0,3,0,0,0,
2,0,0,0,15,15,
0,0,176,0,0,0,
4,0,0,0,0,0,
0,0,3,0,0,0,
3,0,0,0,15,15,
0,0,84,69,88,67,
79,79,82,68,0,171,
171,171,79,83,71,78,
44,0,0,0,1,0,
0,0,8,0,0,0,
32,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,15,0,0,0,
83,86,95,84,97,114,
103,101,116,0,171,171,
83,72,69,88,140,5,
0,0,80,0,0,0,
99,1,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,0,0,
0,0,5,0,0,0,
90,0,0,3,0,96,
16,0,2,0,0,0,
90,0,0,3,0,96,
16,0,3,0,0,0,
90,0,0,3,0,96,
16,0,4,0,0,0,
88,24,0,4,0,112,
16,0,2,0,0,0,
85,85,0,0,88,24,
0,4,0,112,16,0,
3,0,0,0,85,85,
0,0,88,24,0,4,
0,112,16,0,4,0,
0,0,85,85,0,0,
98,16,0,3,50,16,
16,0,0,0,0,0,
98,16,0,3,194,16,
16,0,0,0,0,0,
98,16,0,3,34,16,
16,0,1,0,0,0,
98,16,0,3,66,16,
16,0,1,0,0,0,
98,16,0,3,242,16,
16,0,2,0,0,0,
98,16,0,3,242,16,
16,0,3,0,0,0,
101,0,0,3,242,32,
16,0,0,0,0,0,
104,0,0,2,4,0,
0,0,0,0,0,10,
242,0,16,0,0,0,
0,0,182,17,16,0,
3,0,0,0,2,64,
0,0,0,0,224,64,
0,0,160,64,0,0,
64,64,0,0,128,63,
50,0,0,10,242,0,
16,0,1,0,0,0,
230,30,16,128,65,0,
0,0,0,0,0,0,
6,5,16,0,0,0,
0,0,70,20,16,0,
0,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,2,0,0,0,
230,10,16,0,1,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
114,0,16,0,1,0,
0,0,70,0,16,0,
1,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,56,0,0,7,
114,0,16,0,2,0,
0,0,70,2,16,0,
2,0,0,0,166,26,
16,0,2,0,0,0,
50,0,0,9,114,0,
16,0,1,0,0,0,
70,2,16,0,1,0,
0,0,246,31,16,0,
2,0,0,0,70,2,
16,0,2,0,0,0,
50,0,0,10,242,0,
16,0,2,0,0,0,
230,30,16,128,65,0,
0,0,0,0,0,0,
166,15,16,0,0,0,
0,0,70,20,16,0,
0,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,3,0,0,0,
70,0,16,0,2,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
114,0,16,0,2,0,
0,0,230,10,16,0,
2,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,50,0,0,9,
114,0,16,0,1,0,
0,0,70,2,16,0,
3,0,0,0,86,21,
16,0,2,0,0,0,
70,2,16,0,1,0,
0,0,50,0,0,9,
114,0,16,0,1,0,
0,0,70,2,16,0,
2,0,0,0,6,16,
16,0,2,0,0,0,
70,2,16,0,1,0,
0,0,69,0,0,139,
194,0,0,128,67,85,
21,0,114,0,16,0,
2,0,0,0,70,16,
16,0,0,0,0,0,
70,126,16,0,2,0,
0,0,0,96,16,0,
2,0,0,0,0,0,
0,7,114,0,16,0,
1,0,0,0,70,2,
16,0,1,0,0,0,
70,2,16,0,2,0,
0,0,50,0,0,9,
242,0,16,0,2,0,
0,0,230,30,16,0,
0,0,0,0,246,10,
16,0,0,0,0,0,
70,20,16,0,0,0,
0,0,50,0,0,9,
242,0,16,0,0,0,
0,0,230,30,16,0,
0,0,0,0,86,0,
16,0,0,0,0,0,
70,20,16,0,0,0,
0,0,69,0,0,139,
194,0,0,128,67,85,
21,0,114,0,16,0,
3,0,0,0,70,0,
16,0,2,0,0,0,
70,126,16,0,2,0,
0,0,0,96,16,0,
2,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,2,0,0,0,
230,10,16,0,2,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
50,0,0,9,114,0,
16,0,1,0,0,0,
70,2,16,0,3,0,
0,0,6,16,16,0,
2,0,0,0,70,2,
16,0,1,0,0,0,
50,0,0,9,114,0,
16,0,1,0,0,0,
70,2,16,0,2,0,
0,0,86,21,16,0,
2,0,0,0,70,2,
16,0,1,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
114,0,16,0,2,0,
0,0,70,0,16,0,
0,0,0,0,70,126,
16,0,2,0,0,0,
0,96,16,0,2,0,
0,0,69,0,0,139,
194,0,0,128,67,85,
21,0,114,0,16,0,
0,0,0,0,230,10,
16,0,0,0,0,0,
70,126,16,0,2,0,
0,0,0,96,16,0,
2,0,0,0,50,0,
0,9,114,0,16,0,
1,0,0,0,70,2,
16,0,2,0,0,0,
166,26,16,0,2,0,
0,0,70,2,16,0,
1,0,0,0,50,0,
0,9,114,0,16,0,
0,0,0,0,70,2,
16,0,0,0,0,0,
246,31,16,0,2,0,
0,0,70,2,16,0,
1,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,1,0,0,0,
70,16,16,0,0,0,
0,0,70,126,16,0,
4,0,0,0,0,96,
16,0,4,0,0,0,
69,0,0,139,194,0,
0,128,67,85,21,0,
114,0,16,0,2,0,
0,0,70,16,16,0,
0,0,0,0,70,126,
16,0,3,0,0,0,
0,96,16,0,3,0,
0,0,0,0,0,8,
114,0,16,0,1,0,
0,0,70,2,16,0,
1,0,0,0,70,2,
16,128,65,0,0,0,
2,0,0,0,50,0,
0,9,114,0,16,0,
0,0,0,0,70,2,
16,0,0,0,0,0,
86,21,16,0,1,0,
0,0,70,2,16,0,
1,0,0,0,56,0,
0,7,114,0,16,0,
0,0,0,0,70,2,
16,0,0,0,0,0,
166,26,16,0,1,0,
0,0,47,0,0,5,
114,0,16,0,0,0,
0,0,70,2,16,0,
0,0,0,0,14,0,
0,11,130,0,16,0,
0,0,0,0,2,64,
0,0,0,0,128,63,
0,0,128,63,0,0,
128,63,0,0,128,63,
26,128,32,0,0,0,
0,0,4,0,0,0,
56,0,0,7,114,0,
16,0,0,0,0,0,
70,2,16,0,0,0,
0,0,246,15,16,0,
0,0,0,0,25,0,
0,5,114,32,16,0,
0,0,0,0,70,2,
16,0,0,0,0,0,
54,0,0,5,130,32,
16,0,0,0,0,0,
1,64,0,0,0,0,
128,63,62,0,0,1,
83,84,65,84,148,0,
0,0,34,0,0,0,
4,0,0,0,0,0,
0,0,7,0,0,0,
21,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,11,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0
};


static const uint32_t sVertexHash[] = 
{
0x68bd2bc,0x44ea9cf6,0x663e4180,0x51b7faa1,0xfb60da91,0x9dda7965,
0x7dc55069,0x85bd4fdf
};


static const uint32_t sFragmentHash[] =
{
0x1c8aaff7,0xed7f3d53,0x28f41534,0xa75eb311,0x92e5e1cc,0x55de4325,
0x545d8974,0xe3f38750
};

}

namespace RetroArch
{
class CrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDef : public ShaderDef
{
public:
	CrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDef() : ShaderDef{}
	{
		Name = "crt-royale-bloom-horizontal-reconstitute";
		VertexByteCode = RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs::sVertexByteCode);
		VertexHash = RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchCrtShadersCrtRoyaleSrcFastCrtRoyaleBloomHorizontalReconstituteShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("crt_gamma", 0, 64, 4, 1.000000f, 5.000000f, 2.400000f, 0.025000f, "Simulated CRT Gamma"));
		Params.push_back(ShaderParam("lcd_gamma", 0, 68, 4, 1.000000f, 5.000000f, 2.400000f, 0.025000f, "Your Display Gamma"));
		Params.push_back(ShaderParam("levels_contrast", 0, 72, 4, 0.000000f, 4.000000f, 0.671875f, 0.015625f, "Contrast"));
		Params.push_back(ShaderParam("bloom_underestimate_levels", 0, 76, 4, 0.000000f, 5.000000f, 1.000000f, 0.010000f, "Bloom - Underestimate Levels"));
		Params.push_back(ShaderParam("bloom_excess", 0, 80, 4, 0.000000f, 1.000000f, 0.000000f, 0.005000f, "Bloom - Excess"));
		Params.push_back(ShaderParam("beam_min_sigma", 0, 84, 4, 0.005000f, 1.000000f, 0.055000f, 0.005000f, "Beam - Min Sigma"));
		Params.push_back(ShaderParam("beam_max_sigma", 0, 88, 4, 0.005000f, 1.000000f, 0.200000f, 0.005000f, "Beam - Max Sigma"));
		Params.push_back(ShaderParam("beam_spot_power", 0, 92, 4, 0.010000f, 16.000000f, 0.380000f, 0.010000f, "Beam - Spot Power"));
		Params.push_back(ShaderParam("beam_min_shape", 0, 96, 4, 2.000000f, 32.000000f, 2.000000f, 0.100000f, "Beam - Min Shape"));
		Params.push_back(ShaderParam("beam_max_shape", 0, 100, 4, 2.000000f, 32.000000f, 2.000000f, 0.100000f, "Beam - Max Shape"));
		Params.push_back(ShaderParam("beam_shape_power", 0, 104, 4, 0.010000f, 16.000000f, 0.250000f, 0.010000f, "Beam - Shape Power"));
		Params.push_back(ShaderParam("beam_horiz_filter", 0, 108, 4, 0.000000f, 3.000000f, 0.000000f, 1.000000f, "Beam - Horiz Filter"));
		Params.push_back(ShaderParam("beam_horiz_sigma", 0, 112, 4, 0.000000f, 0.670000f, 0.350000f, 0.005000f, "Beam - Horiz Sigma"));
		Params.push_back(ShaderParam("beam_horiz_linear_rgb_weight", 0, 116, 4, 0.000000f, 1.000000f, 1.000000f, 0.010000f, "Beam - Horiz Linear RGB Weight"));
		Params.push_back(ShaderParam("convergence_offset_x_r", 0, 120, 4, -4.000000f, 4.000000f, 0.000000f, 0.050000f, "Convergence - Offset X Red"));
		Params.push_back(ShaderParam("convergence_offset_x_g", 0, 124, 4, -4.000000f, 4.000000f, 0.000000f, 0.050000f, "Convergence - Offset X Green"));
		Params.push_back(ShaderParam("convergence_offset_x_b", 0, 128, 4, -4.000000f, 4.000000f, 0.000000f, 0.050000f, "Convergence - Offset X Blue"));
		Params.push_back(ShaderParam("convergence_offset_y_r", 0, 132, 4, -2.000000f, 2.000000f, 0.050000f, 0.050000f, "Convergence - Offset Y Red"));
		Params.push_back(ShaderParam("convergence_offset_y_g", 0, 136, 4, -2.000000f, 2.000000f, -0.050000f, 0.050000f, "Convergence - Offset Y Green"));
		Params.push_back(ShaderParam("convergence_offset_y_b", 0, 140, 4, -2.000000f, 2.000000f, 0.050000f, 0.050000f, "Convergence - Offset Y Blue"));
		Params.push_back(ShaderParam("mask_type", 0, 144, 4, 0.000000f, 2.000000f, 0.000000f, 1.000000f, "Mask - Type"));
		Params.push_back(ShaderParam("mask_num_triads_desired", 0, 148, 4, 342.000000f, 1920.000000f, 480.000000f, 1.000000f, "Mask - Number of Triads Desired"));
		Params.push_back(ShaderParam("mask_triad_size_desired", 0, 152, 4, 1.000000f, 18.000000f, 3.000000f, 0.125000f, "Mask - Triad Size Desired"));
		Params.push_back(ShaderParam("mask_specify_num_triads", 0, 156, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Mask - Specify Number of Triads"));
		Params.push_back(ShaderParam("aa_subpixel_r_offset_x_runtime", 0, 160, 4, -0.333333f, 0.333333f, -0.333333f, 0.333333f, "AA - Subpixel R Offset X"));
		Params.push_back(ShaderParam("aa_subpixel_r_offset_y_runtime", 0, 164, 4, -0.333333f, 0.333333f, 0.000000f, 0.333333f, "AA - Subpixel R Offset Y"));
		Params.push_back(ShaderParam("aa_cubic_c", 0, 168, 4, 0.000000f, 4.000000f, 0.500000f, 0.015625f, "AA - Cubic Sharpness"));
		Params.push_back(ShaderParam("aa_gauss_sigma", 0, 172, 4, 0.062500f, 1.000000f, 0.500000f, 0.015625f, "AA - Gaussian Sigma"));
		Params.push_back(ShaderParam("interlace_bff", 0, 176, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Interlacing - Bottom Field First"));
		Params.push_back(ShaderParam("interlace_1080i", 0, 180, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Interlace - Detect 1080i"));
		Params.push_back(ShaderParam("interlace_detect_toggle", 0, 184, 4, 0.000000f, 1.000000f, 0.000000f, 1.000000f, "Interlacing - Toggle"));
		Params.push_back(ShaderParam("SourceSize", -1, 0, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", -1, 16, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("MASKED_SCANLINESSize", -1, 48, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("BRIGHTPASSSize", -1, 64, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Samplers.push_back(ShaderSampler("Source", 2));
		Samplers.push_back(ShaderSampler("MASKED_SCANLINES", 4));
		Samplers.push_back(ShaderSampler("BRIGHTPASS", 3));
/*
VertexSource = %*VERTEX_SOURCE*%;
*/
/*
FragmentSource = %*FRAGMENT_SOURCE*%;
*/
	}
};
}
