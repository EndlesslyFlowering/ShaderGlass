/*
ShaderGlass preset presets / crt-royale-xm29plus imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/presets/crt-royale-xm29plus.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsCrtRoyaleXm29plusPresetDef : public PresetDef
{
public:
	PresetsCrtRoyaleXm29plusPresetDef() : PresetDef{}
	{
		Name = "crt-royale-xm29plus";
		Category = "presets";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ReshadeShadersLUTLUTShaderDef());
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleFirstPassLinearizeCrtGammaBobFieldsShaderDef()
.Param("alias", "ORIG_LINEARIZED")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleScanlinesVerticalInterlacingShaderDef()
.Param("alias", "VERTICAL_SCANLINES")
.Param("filter_linear", "true")
.Param("scale_type_x", "source")
.Param("scale_type_y", "viewport")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBloomApproxShaderDef()
.Param("alias", "BLOOM_APPROX")
.Param("filter_linear", "true")
.Param("scale_type", "absolute")
.Param("scale_x", "320")
.Param("scale_y", "240")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(BlursShadersRoyaleBlur5fastVerticalShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(BlursShadersRoyaleBlur5fastHorizontalShaderDef()
.Param("alias", "HALATION_BLUR")
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleMaskResizeVerticalShaderDef()
.Param("filter_linear", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "viewport")
.Param("scale_x", "64")
.Param("scale_y", "0.0625"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleMaskResizeHorizontalShaderDef()
.Param("alias", "MASK_RESIZE")
.Param("filter_linear", "false")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "0.0625")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleScanlinesHorizontalApplyMaskShaderDef()
.Param("alias", "MASKED_SCANLINES")
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "viewport")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBrightpassShaderDef()
.Param("alias", "BRIGHTPASS")
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "viewport")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBloomVerticalShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleBloomHorizontalReconstituteShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(CrtShadersCrtRoyaleSrcCrtRoyaleGeometryAaLastPassShaderDef()
.Param("filter_linear", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "viewport"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearApertureGrille15Wide8And5d5SpacingResizeTo64TextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "mask_grille_texture_small")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearApertureGrille15Wide8And5d5SpacingTextureDef()
.Param("linear", "true")
.Param("mipmap", "true")
.Param("name", "mask_grille_texture_large")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearSlotMaskTall15Wide9And4d5Horizontal9d14VerticalSpacingResizeTo64TextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "mask_slot_texture_small")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearSlotMaskTall15Wide9And4d5Horizontal9d14VerticalSpacingTextureDef()
.Param("linear", "true")
.Param("mipmap", "true")
.Param("name", "mask_slot_texture_large")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearShadowMaskEDPResizeTo64TextureDef()
.Param("linear", "true")
.Param("mipmap", "false")
.Param("name", "mask_shadow_texture_small")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(CrtShadersCrtRoyaleTileableLinearShadowMaskEDPTextureDef()
.Param("linear", "true")
.Param("mipmap", "true")
.Param("name", "mask_shadow_texture_large")
.Param("wrap_mode", "repeat"));
            TextureDefs.push_back(ReshadeShadersLUTNEC_XM29plus_captureTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT"));
            OverrideParam("LUT_Size", (float)32.000000);
            OverrideParam("aa_cubic_c", (float)0.500000);
            OverrideParam("aa_gauss_sigma", (float)0.500000);
            OverrideParam("aa_subpixel_r_offset_x_runtime", (float)-0.333333);
            OverrideParam("aa_subpixel_r_offset_y_runtime", (float)0.000000);
            OverrideParam("beam_horiz_filter", (float)0.000000);
            OverrideParam("beam_horiz_linear_rgb_weight", (float)1.000000);
            OverrideParam("beam_horiz_sigma", (float)0.555000);
            OverrideParam("beam_max_shape", (float)2.000000);
            OverrideParam("beam_max_sigma", (float)0.250000);
            OverrideParam("beam_min_shape", (float)2.000000);
            OverrideParam("beam_min_sigma", (float)0.075000);
            OverrideParam("beam_shape_power", (float)0.250000);
            OverrideParam("beam_spot_power", (float)0.330000);
            OverrideParam("bloom_excess", (float)0.335000);
            OverrideParam("bloom_underestimate_levels", (float)1.200000);
            OverrideParam("border_compress", (float)2.500000);
            OverrideParam("border_darkness", (float)0.000000);
            OverrideParam("border_size", (float)0.005000);
            OverrideParam("convergence_offset_x_b", (float)0.000000);
            OverrideParam("convergence_offset_x_g", (float)0.000000);
            OverrideParam("convergence_offset_x_r", (float)0.000000);
            OverrideParam("convergence_offset_y_b", (float)-0.200000);
            OverrideParam("convergence_offset_y_g", (float)0.000000);
            OverrideParam("convergence_offset_y_r", (float)0.200000);
            OverrideParam("crt_gamma", (float)2.400000);
            OverrideParam("diffusion_weight", (float)0.075000);
            OverrideParam("geom_aspect_ratio_x", (float)432.000000);
            OverrideParam("geom_aspect_ratio_y", (float)329.000000);
            OverrideParam("geom_mode_runtime", (float)0.000000);
            OverrideParam("geom_overscan_x", (float)1.000000);
            OverrideParam("geom_overscan_y", (float)1.000000);
            OverrideParam("geom_radius", (float)3.000000);
            OverrideParam("geom_tilt_angle_x", (float)0.000000);
            OverrideParam("geom_tilt_angle_y", (float)0.000000);
            OverrideParam("geom_view_dist", (float)2.000000);
            OverrideParam("halation_weight", (float)0.000000);
            OverrideParam("interlace_1080i", (float)0.000000);
            OverrideParam("interlace_bff", (float)0.000000);
            OverrideParam("lcd_gamma", (float)2.400000);
            OverrideParam("levels_contrast", (float)0.750000);
            OverrideParam("mask_sample_mode_desired", (float)1.000000);
            OverrideParam("mask_specify_num_triads", (float)0.000000);
            OverrideParam("mask_triad_size_desired", (float)3.000000);
            OverrideParam("mask_type", (float)1.000000);
	}
};
}
