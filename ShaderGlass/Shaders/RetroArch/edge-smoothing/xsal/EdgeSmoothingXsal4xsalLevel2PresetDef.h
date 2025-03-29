/*
ShaderGlass preset edge-smoothing/xsal / 4xsal-level2 imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/edge-smoothing/xsal/4xsal-level2.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class EdgeSmoothingXsal4xsalLevel2PresetDef : public PresetDef
{
public:
	EdgeSmoothingXsal4xsalLevel2PresetDef() : PresetDef{}
	{
		Name = "4xsal-level2";
		Category = "edge-smoothing/xsal";
	}

	virtual void Build() {
         	ShaderDefs.push_back(EdgeSmoothingXsalShaders2xsalLevel2ShaderDef()
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
