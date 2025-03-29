/*
ShaderGlass preset edge-smoothing/xbr / xbr-lv2-sharp imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/edge-smoothing/xbr/xbr-lv2-sharp.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class EdgeSmoothingXbrXbrLv2SharpPresetDef : public PresetDef
{
public:
	EdgeSmoothingXbrXbrLv2SharpPresetDef() : PresetDef{}
	{
		Name = "xbr-lv2-sharp";
		Category = "edge-smoothing/xbr";
	}

	virtual void Build() {
         	ShaderDefs.push_back(EdgeSmoothingXbrShadersSupportLinearizeShaderDef()
.Param("alias", "XbrSource")
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(EdgeSmoothingXbrShadersXbrLv2MultipassXbrLv2Pass0ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(EdgeSmoothingXbrShadersXbrLv2MultipassXbrLv2Pass1ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "4.000000")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(EdgeSmoothingXbrShadersSupportBSplineXShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source"));
         	ShaderDefs.push_back(EdgeSmoothingXbrShadersSupportBSplineYShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "viewport"));
         	ShaderDefs.push_back(EdgeSmoothingXbrShadersSupportDelinearizeShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.000000")
.Param("scale_type", "source"));
            OverrideParam("KA", (float)0.350000);
            OverrideParam("SMALL_DETAILS", (float)1.000000);
            OverrideParam("WP4", (float)0.800000);
	}
};
}
