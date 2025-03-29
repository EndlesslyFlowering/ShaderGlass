/*
ShaderGlass preset crt / crt-yo6-KV-M1420B-sharp imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/crt/crt-yo6-KV-M1420B-sharp.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class CrtCrtYo6KVM1420BSharpPresetDef : public PresetDef
{
public:
	CrtCrtYo6KVM1420BSharpPresetDef() : PresetDef{}
	{
		Name = "crt-yo6-KV-M1420B-sharp";
		Category = "crt";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersCrtYo6CrtYo6NativeResolutionShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "absolute")
.Param("scale_x", "439")
.Param("scale_y", "233")
.Param("wrap_mode", "clamp_to_edge"));
         	ShaderDefs.push_back(CrtShadersCrtYo6CrtYo6WarpShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "absolute")
.Param("scale_x", "1684")
.Param("scale_y", "1329")
.Param("wrap_mode", "clamp_to_edge"));
         	ShaderDefs.push_back(InterpolationShadersJinc2ShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "viewport"));
            TextureDefs.push_back(CrtShadersCrtYo6KVM1420BTextureDef()
.Param("linear", "false")
.Param("name", "TEX_CRT"));
            OverrideParam("JINC2_AR_STRENGTH", (float)0.500000);
            OverrideParam("JINC2_SINC", (float)0.820000);
            OverrideParam("JINC2_WINDOW_SINC", (float)0.440000);
	}
};
}
