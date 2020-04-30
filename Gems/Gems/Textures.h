#pragma once

enum color_code {
    clGreen,
    clBlue,
    clRed,
    clYellow,
    clCyan,
    clMagenta,
    clBlack,
    clBomb,
    clPainter,
    clCount
};

void InitTexturesSet(void);
sf::Texture* GetTextureByColor(sf::Color color);
sf::Texture* GetTextureByCode(color_code code);
bool TexturesSetIsDamaged(void);