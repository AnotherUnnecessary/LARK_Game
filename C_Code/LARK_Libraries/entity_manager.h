#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Player.h"
#include "entity_functions.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    PICKUP,
    DOOR,
    TRAP
};
//level 1
    //scrolls and glyphs
extern char scrollText1[512];
extern char scrollText2[48];
extern char glyphText1[64];
//secret level things
extern char susText[24];

extern Transform *ROOT;
//level1
     //triggers
extern Transform *trigger1lvl1;
extern Transform *trigger2lvl1;
extern Transform *trigger3lvl1;
extern Transform *trigger4lvl1;
extern Transform *trigger5lvl1;
    //keys and doors
extern Transform *key1lvl1;
extern Transform *key2lvl1;
extern Transform *door1lvl1;
extern Transform *door2lvl1;
extern Transform *door5lvl1;
        //final doors
extern Transform *door0lvl1;
extern Transform *door9lvl1;
extern Transform *door8lvl1;
    //scrolls and glyphs
extern Transform *scroll1lvl1;
extern Transform *scroll2lvl1;
extern Transform *scroll3lvl1;
extern Transform *glyph1;
    //lanters, chests and traps
extern Transform *lantern1;
extern Transform *chest;
extern Transform *trap1;
extern Transform *trap2;
extern Transform *trap3;
extern Transform *trap4;
extern Transform *trap5;
extern Transform *trap6;
extern Transform *trap7;
//Level2
extern Transform *entity2;
extern Transform *entity3;
//secret levels
extern Transform *susScroll;

//logs all entities
void LOG_ENTITIES();

//sets up basic entities
void ENTITY_SETUP();

#endif