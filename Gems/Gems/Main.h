#pragma once

constexpr unsigned BONUS_CHANCE = 5;    /**Chance to spawn bonus for every gem destroyed at once*/
constexpr unsigned BONUS_COUNT = 2; /**Amount of bonuses available */
constexpr unsigned FRAME_RATE = 3;  /**How many frames change in a second*/
constexpr unsigned BONUS_SPAWN_RADIUS = 3;  /*How far can bonus spawn from original*/

/**
*Special enum for every entity type
*
*Mainly used to load and keep textures for every type of tile
*/
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