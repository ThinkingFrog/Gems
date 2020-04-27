#pragma once

enum color_code {
    clGreen,
    clBlue,
    clRed,
    clYellow,
    clCyan,
    clMagenta,
    clCount,
    clBlack
};

void InitTexturesSet(void);
sf::Texture* GetTextureByColor(sf::Color color);