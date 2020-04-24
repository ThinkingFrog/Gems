#pragma once

enum color_code {
    clGreen,
    clBlue,
    clRed,
    clYellow,
    clCyan,
    clMagenta,
    clBlack,
    clCount,
    clUnknown
};

void InitTexturesSet(void);
color_code ColorType(sf::Color color);
sf::Texture *GetTextureByColor(sf::Color color);