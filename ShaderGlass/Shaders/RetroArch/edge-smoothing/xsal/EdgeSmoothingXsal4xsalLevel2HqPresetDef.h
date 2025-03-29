/*
ShaderGlass preset edge-smoothing/xsal / 4xsal-level2-hq imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/edge-smoothing/xsal/4xsal-level2-hq.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class EdgeSmoothingXsal4xsalLevel2HqPresetDef : public PresetDef
{
public:
	EdgeSmoothingXsal4xsalLevel2HqPresetDef() : PresetDef{}
	{
		Name = "4xsal-level2-hq";
		Category = "edge-smoothing/xsal";
	}

	virtual void Build() {
         	ShaderDefs.push_back(EdgeSmoothingXsalShaders2xsalLevel2HqShaderDef()
.Param("filter_linear", "false")
.Param("scale", "4.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(EdgeSmoothingXsalShaders2xsalLevel2Pass2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(StockStockShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "viewport"));
	}
};
}
