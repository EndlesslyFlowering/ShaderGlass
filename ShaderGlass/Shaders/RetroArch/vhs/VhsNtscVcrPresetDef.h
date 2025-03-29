/*
ShaderGlass preset vhs / ntsc-vcr imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/vhs/ntsc-vcr.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class VhsNtscVcrPresetDef : public PresetDef
{
public:
	VhsNtscVcrPresetDef() : PresetDef{}
	{
		Name = "ntsc-vcr";
		Category = "vhs";
	}

	virtual void Build() {
         	ShaderDefs.push_back(NtscShadersMaisterNtscPass1Composite3phaseShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("frame_count_mod", "2")
.Param("scale_type", "source")
.Param("scale_x", "4.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(NtscShadersMaisterNtscPass23phaseShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "source")
.Param("scale_x", "0.5")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(NtscShadersMaisterNtscStockShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type_x", "source")
.Param("scale_type_y", "viewport"));
         	ShaderDefs.push_back(VhsShadersStaticShaderDef()
.Param("scale_type", "source"));
         	ShaderDefs.push_back(MiscShadersImageAdjustmentShaderDef()
.Param("scale_type", "source"));
            TextureDefs.push_back(VhsResourcesPlayTextureDef()
.Param("name", "play"));
            OverrideParam("GRAIN_STR", (float)6.000000);
            OverrideParam("bright_boost", (float)0.100000);
            OverrideParam("luminance", (float)1.100000);
            OverrideParam("saturation", (float)0.700000);
            OverrideParam("target_gamma", (float)3.500000);
	}
};
}
