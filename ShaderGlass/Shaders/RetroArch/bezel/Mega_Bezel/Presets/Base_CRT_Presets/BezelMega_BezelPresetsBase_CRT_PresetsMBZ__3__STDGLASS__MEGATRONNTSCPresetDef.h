/*
ShaderGlass preset bezel/Mega_Bezel_Base / MBZ__3__STD-GLASS__MEGATRON-NTSC imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/23046258f7fd02242cc6dd4c08c997a8ddb84935/bezel/Mega_Bezel/Presets/Base_CRT_Presets/MBZ__3__STD-GLASS__MEGATRON-NTSC.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class BezelMega_BezelPresetsBase_CRT_PresetsMBZ__3__STDGLASS__MEGATRONNTSCPresetDef : public PresetDef
{
public:
	BezelMega_BezelPresetsBase_CRT_PresetsMBZ__3__STDGLASS__MEGATRONNTSCPresetDef() : PresetDef{}
	{
		Name = "MBZ__3__STD-GLASS__MEGATRON-NTSC";
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
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseCacheInfoGlassParamsShaderDef()
.Param("alias", "InfoCachePass")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseTextStdGlassShaderDef()
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
         	ShaderDefs.push_back(BezelMega_BezelShadersFxaaFxaaShaderDef()
.Param("alias", "DeditherPass")
.Param("float_framebuffer", "true"));
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
         	ShaderDefs.push_back(BezelMega_BezelShadersMegatronCrtSonyMegatronShaderDef()
.Param("alias", "CRTPass")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "false")
.Param("scale_type", "viewport")
.Param("wrap_mode", "clamp_to_border"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBasePostCrtPrepGlassShaderDef()
.Param("alias", "PostCRTPass")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "viewport"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseLinearizeCrtHdrShaderDef()
.Param("alias", "BR_MirrorLowResPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "absolute")
.Param("scale_x", "800")
.Param("scale_y", "600"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseBlurOutsideScreenHorizShaderDef()
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseBlurOutsideScreenVertShaderDef()
.Param("alias", "BR_MirrorBlurredPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true"));
         	ShaderDefs.push_back(BlursShadersRoyaleBlur9x9ShaderDef()
.Param("alias", "BR_MirrorReflectionDiffusedPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "absolute")
.Param("scale_x", "128")
.Param("scale_y", "128"));
         	ShaderDefs.push_back(BlursShadersRoyaleBlur9x9ShaderDef()
.Param("alias", "BR_MirrorFullscreenGlowPass")
.Param("filter_linear", "true")
.Param("float_framebuffer", "true")
.Param("mipmap_input", "true")
.Param("scale_type", "absolute")
.Param("scale_x", "12")
.Param("scale_y", "12"));
         	ShaderDefs.push_back(BezelMega_BezelShadersBaseReflectionGlassHdrShaderDef()
.Param("alias", "ReflectionPass")
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
            TextureDefs.push_back(BezelMega_BezelShadersTexturesTopLayerImageGradient_3840x2160TextureDef()
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
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
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
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
.Param("linear", "true")
.Param("mipmap", "1")
.Param("name", "NightLightingImage"));
            TextureDefs.push_back(BezelMega_BezelShadersTexturesPlaceholder_Transparent_16x16TextureDef()
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
            OverrideParam("HSM_BG_BRIGHTNESS", (float)0.000000);
            OverrideParam("HSM_BG_OPACITY", (float)1.000000);
            OverrideParam("HSM_BZL_HEIGHT", (float)3000.000000);
            OverrideParam("HSM_BZL_INNER_CORNER_RADIUS_SCALE", (float)100.000000);
            OverrideParam("HSM_BZL_INNER_EDGE_SHADOW", (float)0.000000);
            OverrideParam("HSM_BZL_INNER_EDGE_SHARPNESS", (float)30.000000);
            OverrideParam("HSM_BZL_INNER_EDGE_THICKNESS", (float)350.000000);
            OverrideParam("HSM_BZL_WIDTH", (float)3000.000000);
            OverrideParam("HSM_CRT_CURVATURE_SCALE", (float)0.000000);
            OverrideParam("HSM_FRM_OPACITY", (float)100.000000);
            OverrideParam("HSM_GLASS_BORDER_ON", (float)1.000000);
            OverrideParam("HSM_GLOBAL_GRAPHICS_BRIGHTNESS", (float)100.000000);
            OverrideParam("HSM_INT_SCALE_MODE", (float)1.000000);
            OverrideParam("HSM_REFLECT_BEZEL_INNER_EDGE_AMOUNT", (float)60.000000);
            OverrideParam("HSM_REFLECT_BEZEL_INNER_EDGE_FULLSCREEN_GLOW", (float)40.000000);
            OverrideParam("HSM_REFLECT_BLUR_MAX", (float)60.000000);
            OverrideParam("HSM_REFLECT_BLUR_MIN", (float)30.000000);
            OverrideParam("HSM_REFLECT_CORNER_FADE", (float)0.000000);
            OverrideParam("HSM_REFLECT_FADE_AMOUNT", (float)20.000000);
            OverrideParam("HSM_REFLECT_FULLSCREEN_GLOW", (float)30.000000);
            OverrideParam("HSM_REFLECT_FULLSCREEN_GLOW_GAMMA", (float)1.500000);
            OverrideParam("HSM_REFLECT_GLOBAL_AMOUNT", (float)7.000000);
            OverrideParam("HSM_REFLECT_GLOBAL_GAMMA_ADJUST", (float)0.900000);
            OverrideParam("HSM_REFLECT_LATERAL_OUTER_FADE_POSITION", (float)500.000000);
            OverrideParam("HSM_REFLECT_NOISE_AMOUNT", (float)100.000000);
            OverrideParam("HSM_REFLECT_NOISE_SAMPLES", (float)4.000000);
            OverrideParam("HSM_REFLECT_NOISE_SAMPLE_DISTANCE", (float)15.000000);
            OverrideParam("HSM_REFLECT_RADIAL_FADE_HEIGHT", (float)300.000000);
            OverrideParam("HSM_REFLECT_RADIAL_FADE_WIDTH", (float)500.000000);
            OverrideParam("HSM_SCREEN_VIGNETTE_IN_REFLECTION", (float)0.000000);
            OverrideParam("HSM_SCREEN_VIGNETTE_POWER", (float)4.000000);
            OverrideParam("HSM_SCREEN_VIGNETTE_STRENGTH", (float)20.000000);
            OverrideParam("HSM_TUBE_BLACK_EDGE_SHARPNESS", (float)90.000000);
            OverrideParam("HSM_TUBE_BLACK_EDGE_THICKNESS", (float)-7.000000);
            OverrideParam("feedback_pass", (float)0.000000);
            OverrideParam("g_vignette", (float)0.000000);
            OverrideParam("gamma_out", (float)1.950000);
            OverrideParam("h_sharp", (float)15.000000);
            OverrideParam("hcrt_hdr", (float)0.000000);
            OverrideParam("s_sharp", (float)1.500000);
	}
};
}
