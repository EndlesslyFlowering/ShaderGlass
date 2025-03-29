/*
ShaderGlass preset misc / geom imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/misc/geom.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class MiscGeomPresetDef : public PresetDef
{
public:
	MiscGeomPresetDef() : PresetDef{}
	{
		Name = "geom";
		Category = "misc";
	}

	virtual void Build() {
         	ShaderDefs.push_back(StockStockShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "viewport"));
         	ShaderDefs.push_back(MiscShadersGeomShaderDef()
.Param("filter_linear", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "viewport")
.Param("wrap_mode", "clamp_to_border"));
	}
};
}
