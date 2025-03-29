/*
ShaderGlass preset presets/tvout / tvout+nes-color-decoder imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/presets/tvout/tvout+nes-color-decoder.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsTvoutTvoutNesColorDecoderPresetDef : public PresetDef
{
public:
	PresetsTvoutTvoutNesColorDecoderPresetDef() : PresetDef{}
	{
		Name = "tvout+nes-color-decoder";
		Category = "presets/tvout";
	}

	virtual void Build() {
         	ShaderDefs.push_back(Nes_raw_paletteShadersNesColorDecoderShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(CrtShadersTvoutTweaksShaderDef()
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000"));
         	ShaderDefs.push_back(MiscShadersImageAdjustmentShaderDef());
            OverrideParam("B", (float)1.000000);
            OverrideParam("G", (float)1.000000);
            OverrideParam("R", (float)1.000000);
            OverrideParam("TVOUT_COMPOSITE_CONNECTION", (float)0.000000);
            OverrideParam("TVOUT_RESOLUTION", (float)320.000000);
            OverrideParam("TVOUT_TV_COLOR_LEVELS", (float)0.000000);
            OverrideParam("bright_boost", (float)0.000000);
            OverrideParam("contrast", (float)1.000000);
            OverrideParam("luminance", (float)1.000000);
            OverrideParam("monitor_gamma", (float)2.200000);
            OverrideParam("overscan_percent_x", (float)0.000000);
            OverrideParam("overscan_percent_y", (float)0.000000);
            OverrideParam("saturation", (float)1.000000);
            OverrideParam("target_gamma", (float)2.200000);
	}
};
}
