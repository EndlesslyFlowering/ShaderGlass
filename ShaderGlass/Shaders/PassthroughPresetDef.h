/*
ShaderGlass: shader effect overlay
Copyright (C) 2021-2025 mausimus (mausimus.net)
https://github.com/mausimus/ShaderGlass
GNU General Public License v3.0
*/

#pragma once

class PassthroughPresetDef : public PresetDef
{
public:
    PassthroughPresetDef() : PresetDef {}
    {
        Name     = "none";
        Category = "general";
        ShaderDefs.push_back(PassthroughShaderDef());
    }
};
