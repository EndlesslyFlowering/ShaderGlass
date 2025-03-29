/*
ShaderGlass preset edge-smoothing/xbrz / 6xbrz-linear imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/edge-smoothing/xbrz/6xbrz-linear.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class EdgeSmoothingXbrz6xbrzLinearPresetDef : public PresetDef
{
public:
	EdgeSmoothingXbrz6xbrzLinearPresetDef() : PresetDef{}
	{
		Name = "6xbrz-linear";
		Category = "edge-smoothing/xbrz";
	}

	virtual void Build() {
         	ShaderDefs.push_back(EdgeSmoothingXbrzShaders6xbrzShaderDef()
.Param("filter_linear", "false")
.Param("scale", "6.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(StockStockShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "viewport"));
	}
};
}
