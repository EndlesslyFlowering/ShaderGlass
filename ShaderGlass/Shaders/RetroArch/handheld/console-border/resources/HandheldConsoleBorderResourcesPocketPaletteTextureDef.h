/*
ShaderGlass texture handheld/console-border/resources / pocket-palette imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/handheld/console-border/resources/pocket-palette.png
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace HandheldConsoleBorderResourcesPocketPaletteTextureDefs
{
const BYTE sData[] =
{137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,128,0,0,0,64,1,3,0,0,0,232,24,237,60,0,0,0,6,80,76,84
,69,166,172,132,18,25,34,236,12,135,37,0,0,0,23,73,68,65,84,120,1,99,128,129,255,80,64,164,192,168,192,168,192,168,192,168,0,0,11,76
,254,16,194,179,25,208,0,0,0,0,73,69,78,68,174,66,96,130};
}

class HandheldConsoleBorderResourcesPocketPaletteTextureDef : public TextureDef
{
public:
	HandheldConsoleBorderResourcesPocketPaletteTextureDef() : TextureDef{}
	{
		Name = "pocket-palette.png";
		Data = HandheldConsoleBorderResourcesPocketPaletteTextureDefs::sData;
		DataLength = sizeof(HandheldConsoleBorderResourcesPocketPaletteTextureDefs::sData);
	}
};
