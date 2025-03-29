/*
ShaderGlass preset bezel/Mega_Bezel_Base / MBZ__5__POTATO-SUPER-XBR__GDV-NTSC imported from MegaBezel:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/bezel/Mega_Bezel
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class BezelMega_BezelPresetsBase_CRT_PresetsMBZ__5__POTATOSUPERXBR__GDVNTSCPresetDef : public PresetDef
{
public:
	BezelMega_BezelPresetsBase_CRT_PresetsMBZ__5__POTATOSUPERXBR__GDVNTSCPresetDef() : PresetDef{}
	{
		Name = "MBZ__5__POTATO-SUPER-XBR__GDV-NTSC";
		Category = "bezel/Mega_Bezel_Base";
	}

	virtual void Build() {
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestExtrasHsmDrezNoneShaderDef()
.Param("alias", "DerezedPass")
.Param("filter_linear", "false")
.Param("scale_type", "source")
.Param("scale_x", "1")
.Param("scale_y", "1")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseCacheInfoPotatoParamsShaderDef()
.Param("alias", "InfoCachePass")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestExtrasHsmFetchDrezOutputShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "source")
.Param("scale_x", "1")
.Param("scale_y", "1")
.Param("srgb_framebuffer", "true"));
         	ShaderDefs.push_back(BezelMega_BezelShadersDeditherDeditherGammaPrep1BeforeShaderDef()
.Param("alias", "LinearGamma"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianSgenptMixSgenptMixPass1ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianSgenptMixSgenptMixPass2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianSgenptMixSgenptMixPass3ShaderDef()
.Param("alias", "CB_Output")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianSgenptMixSgenptMixPass4ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianSgenptMixSgenptMixPass5ShaderDef()
.Param("filter_linear", "false"));
         	ShaderDefs.push_back(BezelMega_BezelShadersDeditherDeditherGammaPrep2AfterShaderDef());
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestExtrasHsmGSharp_resamplerShaderDef());
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestExtrasHsmSharpsmootherShaderDef()
.Param("alias", "DeditherPass"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseStockShaderDef()
.Param("alias", "XbrSource"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianCrtSuperXbrSuperXbrPass0ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianCrtSuperXbrSuperXbrPass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "2.000000")
.Param("scale_y", "2.000000")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianCrtSuperXbrSuperXbrPass2ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianCrtSuperXbrCustomBicubicXShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "false")
.Param("mipmap_input", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000")
.Param("srgb_framebuffer", "true")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersHyllianCrtSuperXbrCustomBicubicYShaderDef()
.Param("filter_linear", "false")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "1")
.Param("scale_y", "0.5")
.Param("wrap_mode", "clamp_to_edge"));
         	ShaderDefs.push_back(BezelMega_BezelShadersDogwayHsmGradeShaderDef()
.Param("alias", "ColorCorrectPass")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseStockShaderDef()
.Param("alias", "PrePass0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestNtscHsmNtscPass1ShaderDef()
.Param("alias", "NPass1")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("frame_count_mod", "2")
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "4.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestNtscHsmNtscPass2ShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type", "source")
.Param("scale_x", "0.5")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestNtscHsmNtscPass3ShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "source")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseStockShaderDef()
.Param("alias", "PrePass")
.Param("filter_linear", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "source")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmAvgLumShaderDef()
.Param("alias", "AvgLumPass")
.Param("filter_linear", "true")
.Param("mipmap_input", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmInterlaceAndLinearizeShaderDef()
.Param("alias", "LinearizePass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmCrtGuestAdvancedNtscPass1ShaderDef()
.Param("alias", "Pass1")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmGaussian_horizontalShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "source")
.Param("scale_x", "640.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmGaussian_verticalShaderDef()
.Param("alias", "GlowPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "640.0")
.Param("scale_y", "480.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmBloom_horizontalShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "640.0")
.Param("scale_y", "480.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmBloom_verticalShaderDef()
.Param("alias", "BloomPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "640.0")
.Param("scale_y", "480.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmCrtGuestAdvancedNtscPass2PotatoShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type", "viewport")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmDeconvergenceShaderDef()
.Param("alias", "CRTPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale_type", "viewport")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBasePostCrtPrepPotatoShaderDef()
.Param("alias", "PostCRTPass")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "viewport"));
            TextureDefs.push_back(BezelMega_BezelShadersGuestLutTrinitronLutTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT1"));
            TextureDefs.push_back(BezelMega_BezelShadersGuestLutInvTrinitronLutTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT2"));
            TextureDefs.push_back(BezelMega_BezelShadersGuestLutNecLutTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT3"));
            TextureDefs.push_back(BezelMega_BezelShadersGuestLutNtscLutTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT4"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "false")
.Param("name", "ScreenPlacementImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesBaked_Frame_Carbonfiber_BackgroundTextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "BackgroundImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesBaked_Frame_Carbonfiber_Background_VertTextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "BackgroundVertImage"));
            OverrideParam("GAMMA_INPUT", (float)2.000000);
            OverrideParam("HSM_ASPECT_RATIO_MODE", (float)1.000000);
            OverrideParam("HSM_CORE_RES_SAMPLING_MULT_OPPOSITE_DIR", (float)100.000000);
            OverrideParam("HSM_CORE_RES_SAMPLING_MULT_SCANLINE_DIR", (float)600.000000);
            OverrideParam("HSM_DOWNSAMPLE_BLUR_OPPOSITE_DIR", (float)0.000000);
            OverrideParam("HSM_DOWNSAMPLE_BLUR_SCANLINE_DIR", (float)0.000000);
            OverrideParam("SGPT_BLEND_OPTION", (float)1.000000);
            OverrideParam("SHARPEN", (float)1.000000);
            OverrideParam("SHARPSMOOTHER_ON", (float)1.000000);
            OverrideParam("SUPERXBR_ON", (float)1.000000);
            OverrideParam("gamma_out", (float)1.950000);
            OverrideParam("h_sharp", (float)15.000000);
            OverrideParam("lumad", (float)0.500000);
            OverrideParam("masksize", (float)0.000000);
            OverrideParam("max_w", (float)0.050000);
            OverrideParam("min_w", (float)0.000000);
            OverrideParam("mtric", (float)0.300000);
            OverrideParam("s_sharp", (float)1.500000);
            OverrideParam("smoot", (float)0.400000);
	}
};
}
