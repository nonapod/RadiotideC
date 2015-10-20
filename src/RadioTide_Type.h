#ifndef RADIOTIDE_RADIOTIDE_TYPE_H
#define RADIOTIDE_RADIOTIDE_TYPE_H


#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DISPLAY_TREE "T"
#define DISPLAY_FLAT "."
#define DISPLAY_SMALL_TREE "t"
#define DISPLAY_RUINS "x"
#define DISPLAY_BADLANDS "?" //"\u2620"
#define DISPLAY_RADIATED "*" //"\u2622"
#define DISPLAY_WATER "~"
#define DISPLAY_MOUNTAIN "^"
#define DISPLAY_CITY "H" //"\u2599"
#define DISPLAY_SETTLEMENT "h" //"\u2302"
#define DISPLAY_REDOUBT "Q" //"\u265c"
#define DISPLAY_MERCURY "+" //"\u263F"

#define TILE_NAME_SIZE 25
#define TILE_TERM_DISPLAY_SIZE 25

#define TILE_DIRECTIONS 9

#define CHARACTERISTIC_MIN_CHANCE 0
#define CHARACTERISTIC_MAX_CHANCE 100

#define ELEVATION_DEFAULT_CHANCE 35
#define WILDERNESS_DEFAULT_CHANCE 45
#define FOLIAGE_DEFAULT_CHANCE 30
#define URBAN_DEFAULT_CHANCE 15
#define WATER_DEFAULT_CHANCE 40

typedef struct RadioTide_Proximity_Struct RadioTide_Proximity;

typedef struct RadioTide_Map_Struct RadioTide_Map;

typedef struct RadioTide_Tile_Struct RadioTide_Tile;

typedef struct CharacteristicChance_Struct CharacteristicChance;


typedef enum Color {
    NONE,
    BROWN,
    YELLOW,
    GREEN,
    PURPLE,
    LIGHTPURPLE,
    RED,
    BLUE,
    LIGHTBLUE,
    BLACK,
    LIGHTGREEN,
    CYAN,
    LIGHTCYAN,
    WHITE,
    LIGHTGRAY,
    LIGHTRED,
    GRAY,
    ColorEnumEnd
} Color;

typedef enum Characteristic {
    ELEVATION,
    WILDERNESS,
    FOLIAGE,
    URBAN,
    WATER,
    CharacteristicEnumEnd
} Characteristic;

struct RadioTide_Tile_Struct {

    char name[TILE_NAME_SIZE];
    char term_display[TILE_TERM_DISPLAY_SIZE];
    int movement;
    int cover;
    int loot_chance;
    int view_bonus;
    bool blocked;
    Color color;
    Characteristic characteristic;

} RadioTide_Tile_Struct;


struct CharacteristicChance_Struct {

    int chance;
    Characteristic characteristic;

} CharacteristicChance_Struct;


struct RadioTide_Map_Struct {

    int x;
    int y;
    int *characteristic_chance;
    RadioTide_Tile **tiles;

} RadioTide_Map_Struct;


struct RadioTide_Proximity_Struct {

    char up[TILE_NAME_SIZE];
    char down[TILE_NAME_SIZE];
    char left[TILE_NAME_SIZE];
    char right[TILE_NAME_SIZE];
    char center[TILE_NAME_SIZE];
    char up_left[TILE_NAME_SIZE];
    char down_left[TILE_NAME_SIZE];
    char up_right[TILE_NAME_SIZE];
    char down_right[TILE_NAME_SIZE];

} RadioTide_Proximity_Struct_Default = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};


#endif
