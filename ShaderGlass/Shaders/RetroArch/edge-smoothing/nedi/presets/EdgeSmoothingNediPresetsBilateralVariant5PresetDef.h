/*
ShaderGlass preset edge-smoothing/nedi/presets / bilateral-variant5 imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/edge-smoothing/nedi/presets/bilateral-variant5.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class EdgeSmoothingNediPresetsBilateralVariant5PresetDef : public PresetDef
{
public:
	EdgeSmoothingNediPresetsBilateralVariant5PresetDef() : PresetDef{}
	{
		Name = "bilateral-variant5";
		Category = "edge-smoothing/nedi/presets";
	}

	virtual void Build() {
         	ShaderDefs.push_back(DenoisersShadersFastBilateralShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingNediShadersNediPass0ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "2.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingNediShadersNediPass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "2.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingNediShadersNediPass2ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(EdgeSmoothingNediShadersNediJincShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(MiscShadersNaturalVisionShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(VhsShadersVhsShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(SharpenShadersAdaptiveSharpenShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(SharpenShadersAdaptiveSharpenShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(ReshadeShadersVibrancePassSh1nra358ShaderDef()
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "false")
.Param("wrap_mode", "clamp_to_border"));
            OverrideParam("CURVE_HEIGHT", (float)0.800000);
            OverrideParam("GIN", (float)2.200000);
            OverrideParam("GOUT", (float)2.200000);
            OverrideParam("I", (float)1.100000);
            OverrideParam("JINC2_AR_STRENGTH", (float)0.800000);
            OverrideParam("JINC2_SINC", (float)0.920000);
            OverrideParam("JINC2_WINDOW_SINC", (float)0.420000);
            OverrideParam("Q", (float)1.100000);
            OverrideParam("SIGMA_R", (float)0.400000);
            OverrideParam("Y", (float)1.100000);
            OverrideParam("smear", (float)0.500000);
            OverrideParam("wiggle", (float)0.000000);
	}
};
}
