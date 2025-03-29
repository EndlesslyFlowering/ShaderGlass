/*
ShaderGlass preset vhs / vhs_mpalko imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/vhs/vhs_mpalko.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class VhsVhs_mpalkoPresetDef : public PresetDef
{
public:
	VhsVhs_mpalkoPresetDef() : PresetDef{}
	{
		Name = "vhs_mpalko";
		Category = "vhs";
	}

	virtual void Build() {
         	ShaderDefs.push_back(VhsShadersVhs_mpalkoVhs_mpalko_pass0ShaderDef()
.Param("alias", "Pass1")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale", "4.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(VhsShadersVhs_mpalkoVhs_mpalko_pass1ShaderDef()
.Param("filter_linear", "true"));
         	ShaderDefs.push_back(VhsShadersRewindShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "viewport"));
            TextureDefs.push_back(VhsResourcesRewTextureDef()
.Param("name", "rew"));
            TextureDefs.push_back(VhsResourcesPlayTextureDef()
.Param("name", "play"));
	}
};
}
