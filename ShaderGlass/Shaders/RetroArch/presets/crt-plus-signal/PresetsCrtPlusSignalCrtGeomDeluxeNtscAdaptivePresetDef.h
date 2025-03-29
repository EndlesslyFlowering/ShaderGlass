/*
ShaderGlass preset presets/crt-plus-signal / crt-geom-deluxe-ntsc-adaptive imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/presets/crt-plus-signal/crt-geom-deluxe-ntsc-adaptive.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsCrtPlusSignalCrtGeomDeluxeNtscAdaptivePresetDef : public PresetDef
{
public:
	PresetsCrtPlusSignalCrtGeomDeluxeNtscAdaptivePresetDef() : PresetDef{}
	{
		Name = "crt-geom-deluxe-ntsc-adaptive";
		Category = "presets/crt-plus-signal";
	}

	virtual void Build() {
         	ShaderDefs.push_back(NtscShadersNtscAdaptiveNtscPass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale_type", "source")
.Param("scale_x", "4.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(NtscShadersNtscAdaptiveNtscPass2ShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "source")
.Param("scale_x", "0.5")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxePhosphor_applyShaderDef()
.Param("alias", "internal1"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxePhosphor_updateShaderDef()
.Param("alias", "phosphor"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxeGaussxShaderDef()
.Param("alias", "internal2")
.Param("filter_linear", "true"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxeGaussyShaderDef()
.Param("alias", "blur_texture")
.Param("filter_linear", "true"));
         	ShaderDefs.push_back(CrtShadersGeomDeluxeCrtGeomDeluxeShaderDef()
.Param("filter_linear", "true")
.Param("mipmap_input", "true"));
            TextureDefs.push_back(CrtShadersGeomDeluxeMasksAperture_2_4_rgbTextureDef()
.Param("name", "aperture"));
            TextureDefs.push_back(CrtShadersGeomDeluxeMasksSlot_2_5x4_bgrTextureDef()
.Param("name", "slot"));
            TextureDefs.push_back(CrtShadersGeomDeluxeMasksDelta_2_4x1_rgbTextureDef()
.Param("name", "delta"));
            OverrideParam("cornersmooth", (float)170.000000);
            OverrideParam("curvature", (float)0.000000);
            OverrideParam("cust_artifacting", (float)2.300000);
            OverrideParam("cust_fringing", (float)1.000000);
            OverrideParam("geom_lum", (float)0.250000);
            OverrideParam("halation", (float)0.050000);
            OverrideParam("ntsc_fields", (float)1.000000);
            OverrideParam("ntsc_phase", (float)2.000000);
            OverrideParam("quality", (float)-1.000000);
            OverrideParam("scanline_weight", (float)0.400000);
	}
};
}
