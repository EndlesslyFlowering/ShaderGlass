/*
ShaderGlass preset bezel/Mega_Bezel_Base / MBZ__0__SMOOTH-ADV-SCREEN-ONLY__MEGATRON-NTSC imported from MegaBezel:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/bezel/Mega_Bezel
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class BezelMega_BezelPresetsBase_CRT_PresetsMBZ__0__SMOOTHADVSCREENONLY__MEGATRONNTSCPresetDef : public PresetDef
{
public:
	BezelMega_BezelPresetsBase_CRT_PresetsMBZ__0__SMOOTHADVSCREENONLY__MEGATRONNTSCPresetDef() : PresetDef{}
	{
		Name = "MBZ__0__SMOOTH-ADV-SCREEN-ONLY__MEGATRON-NTSC";
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
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseCacheInfoNoReflectParamsShaderDef()
.Param("alias", "InfoCachePass")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseTextAdvNoReflectShaderDef()
.Param("alias", "TextPass")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
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
         	ShaderDefs.push_back(BezelMega_BezelShadersPs1ditherHsmPS1UnditherBoxBlurShaderDef());
         	ShaderDefs.push_back(BezelMega_BezelShadersFxaaFxaaShaderDef()
.Param("float_framebuffer", "true"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestExtrasHsmGSharp_resamplerShaderDef());
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestExtrasHsmSharpsmootherShaderDef()
.Param("alias", "DeditherPass"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseStockShaderDef()
.Param("alias", "refpass"));
         	ShaderDefs.push_back(BezelMega_BezelShadersScalefxHsmScalefxPass0ShaderDef()
.Param("alias", "scalefx_pass0")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersScalefxHsmScalefxPass1ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersScalefxHsmScalefxPass2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersScalefxHsmScalefxPass3ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersScalefxHsmScalefxPass4ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "3")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseIntroShaderDef()
.Param("alias", "IntroPass")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseStockShaderDef()
.Param("alias", "PreCRTPass"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmAfterglow0ShaderDef()
.Param("alias", "AfterglowPass")
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmPreShadersAfterglowShaderDef()
.Param("filter_linear", "true")
.Param("mipmap_input", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
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
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmCustomFastSharpenNtscShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "source")
.Param("scale_x", "1.0")
.Param("scale_y", "1.0"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseStockShaderDef()
.Param("alias", "PrePass")
.Param("float_framebuffer", "true"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmAvgLumShaderDef()
.Param("alias", "AvgLumPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersGuestHsmInterlaceShaderDef()
.Param("alias", "LinearizePass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersMegatronCrtSonyMegatronSourcePassShaderDef()
.Param("alias", "SourceSDR")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersMegatronCrtSonyMegatronHdrPassShaderDef()
.Param("alias", "SourceHDR")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale", "1.0")
.Param("scale_type", "source")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersMegatronCrtSonyMegatronNoReflectShaderDef()
.Param("alias", "CRTPass")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type", "viewport")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBasePostCrtPrepNoReflectShaderDef()
.Param("alias", "PostCRTPass")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "viewport"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseOutputHdrShaderDef()
.Param("alias", "OutputPass"));
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
            TextureDefs.push_back(BezelMega_BezelShadersTexturesIntroImage_MegaBezelLogoTextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "IntroImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "false")
.Param("name", "ScreenPlacementImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesTube_Diffuse_2390x1792TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "TubeDiffuseImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesColored_Gel_RainbowTextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "TubeColoredGelImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesTube_Shadow_1600x1200TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "TubeShadowImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesTubeGlassOverlayImageCropped_1440x1080TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "TubeStaticReflectionImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesBackgroundImage_Carbon_3840x2160TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "BackgroundImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "BackgroundVertImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_White_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "ReflectionMaskImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesFrameTexture_2800x2120TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "FrameTextureImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "CabinetGlassImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "DeviceImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "DeviceVertImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "DeviceLEDImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "DecalImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesNightLightingClose_1920x1080TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "NightLightingImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesNightLightingFar_1920x1080TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "NightLighting2Image"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "LEDImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "TopLayerImage"));
            OverrideParam("GAMMA_INPUT", (float)2.000000);
            OverrideParam("HSM_CORE_RES_SAMPLING_MULT_OPPOSITE_DIR", (float)100.000000);
            OverrideParam("HSM_CORE_RES_SAMPLING_MULT_SCANLINE_DIR", (float)600.000000);
            OverrideParam("HSM_CRT_CURVATURE_SCALE", (float)0.000000);
            OverrideParam("HSM_DOWNSAMPLE_BLUR_OPPOSITE_DIR", (float)30.000000);
            OverrideParam("HSM_DOWNSAMPLE_BLUR_SCANLINE_DIR", (float)0.000000);
            OverrideParam("HSM_GLOBAL_GRAPHICS_BRIGHTNESS", (float)100.000000);
            OverrideParam("HSM_INT_SCALE_MODE", (float)1.000000);
            OverrideParam("HSM_REFLECT_GLOBAL_AMOUNT", (float)7.000000);
            OverrideParam("HSM_SCALEFX_ON", (float)1.000000);
            OverrideParam("SGPT_BLEND_OPTION", (float)1.000000);
            OverrideParam("feedback_pass", (float)0.000000);
            OverrideParam("gamma_out", (float)1.950000);
            OverrideParam("h_sharp", (float)15.000000);
            OverrideParam("hcrt_hdr", (float)0.000000);
            OverrideParam("mask_bloom", (float)0.300000);
            OverrideParam("masksize", (float)0.000000);
            OverrideParam("s_sharp", (float)1.500000);
            OverrideParam("shadowMask", (float)1.000000);
	}
};
}
