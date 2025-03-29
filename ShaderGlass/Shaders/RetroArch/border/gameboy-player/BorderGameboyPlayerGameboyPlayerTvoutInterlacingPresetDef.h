/*
ShaderGlass preset border/gameboy-player / gameboy-player-tvout+interlacing imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/border/gameboy-player/gameboy-player-tvout+interlacing.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class BorderGameboyPlayerGameboyPlayerTvoutInterlacingPresetDef : public PresetDef
{
public:
	BorderGameboyPlayerGameboyPlayerTvoutInterlacingPresetDef() : PresetDef{}
	{
		Name = "gameboy-player-tvout+interlacing";
		Category = "border/gameboy-player";
	}

	virtual void Build() {
         	ShaderDefs.push_back(BorderShadersImgborderGbpShaderDef()
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "608")
.Param("scale_y", "448"));
         	ShaderDefs.push_back(CrtShadersTvoutTweaksShaderDef()
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000"));
         	ShaderDefs.push_back(MiscShadersImageAdjustmentShaderDef());
         	ShaderDefs.push_back(MiscShadersInterlacingShaderDef());
         	ShaderDefs.push_back(AutoBoxBoxCenterShaderDef()
.Param("filter_linear", "false"));
            TextureDefs.push_back(BorderGameboyPlayerGameboyPlayerTextureDef()
.Param("name", "BORDER"));
            OverrideParam("TVOUT_COMPOSITE_CONNECTION", (float)0.000000);
            OverrideParam("TVOUT_RESOLUTION", (float)512.000000);
            OverrideParam("TVOUT_TV_COLOR_LEVELS", (float)1.000000);
            OverrideParam("box_scale", (float)2.000000);
            OverrideParam("enable_480i", (float)1.000000);
            OverrideParam("in_res_x", (float)240.000000);
            OverrideParam("in_res_y", (float)160.000000);
            OverrideParam("location", (float)0.500000);
            OverrideParam("top_field_first", (float)1.000000);
	}
};
}
