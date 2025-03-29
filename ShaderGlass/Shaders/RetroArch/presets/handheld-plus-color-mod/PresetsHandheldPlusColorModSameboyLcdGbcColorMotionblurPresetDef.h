/*
ShaderGlass preset presets/handheld-plus-color-mod / sameboy-lcd-gbc-color-motionblur imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/presets/handheld-plus-color-mod/sameboy-lcd-gbc-color-motionblur.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsHandheldPlusColorModSameboyLcdGbcColorMotionblurPresetDef : public PresetDef
{
public:
	PresetsHandheldPlusColorModSameboyLcdGbcColorMotionblurPresetDef() : PresetDef{}
	{
		Name = "sameboy-lcd-gbc-color-motionblur";
		Category = "presets/handheld-plus-color-mod";
	}

	virtual void Build() {
         	ShaderDefs.push_back(MotionblurShadersResponseTimeShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(HandheldShadersColorLutGBCLUTShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(HandheldShadersSameboyLcdShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "viewport"));
         	ShaderDefs.push_back(HandheldShadersColorGbcColorShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
            TextureDefs.push_back(HandheldShadersColorLutGbcGrey1TextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT1"));
            TextureDefs.push_back(HandheldShadersColorLutGbcGrey2TextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT2"));
            OverrideParam("LUT_selector_param", (float)2.000000);
            OverrideParam("response_time", (float)0.111000);
	}
};
}
