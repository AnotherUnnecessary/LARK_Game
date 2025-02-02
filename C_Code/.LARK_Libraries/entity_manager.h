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
extern char scrollText2[512];
extern char scrollText3[32];
extern char scrollText4[256];
extern char scrollText5[512];
extern char glyphText1[128];
extern char glyphText2[512];
extern char glyphText3[512];
extern char glyphText4[256];
extern char glyphText5[256];
extern char glyphText0[256];
extern char glyphText9[128];
extern char glyphText8[256];
//secret level things
extern char glyphText10[512];
extern char susText[24];

extern Transform *ROOT;
//level1
     //triggers
extern Transform *trigger1lvl1;
extern Transform *trigger2lvl1;
extern Transform *trigger3lvl1;
extern Transform *trigger5lvl1;
extern Transform *trigger6lvl1;
    //keys and doors
extern Transform *key1lvl1;
extern Transform *key2lvl1;
extern Transform *key4lvl1;
extern Transform *key5lvl1;
extern Transform *key8lvl1;
extern Transform *key0lvl1;
extern Transform *door1lvl1;
extern Transform *door2lvl1;
extern Transform *door4lvl1;
extern Transform *door5lvl1;
extern Transform *door52lvl1;
        //final doors
extern Transform *door0lvl1;
extern Transform *door9lvl1;
extern Transform *door8lvl1;
    //scrolls and glyphs
extern Transform *scroll1lvl1;
extern Transform *scroll2lvl1;
extern Transform *scroll3lvl1;
extern Transform *scroll4lvl1;
extern Transform *scroll5lvl1;
extern Transform *glyph1;
extern Transform *glyph2;
extern Transform *glyph3;
extern Transform *glyph4;
extern Transform *glyph0;
extern Transform *glyph9;
extern Transform *glyph8;
    //lanters, chests and traps
extern Transform *lantern1;
extern Transform *lantern2;
extern Transform *chest;
extern Transform *chest2;
extern Transform *chest3;
extern Transform *chest4;
extern Transform *trap1;
extern Transform *trap2;
extern Transform *trap3;
extern Transform *trap4;
extern Transform *trap5;
extern Transform *trap6;
extern Transform *trap7;
extern Transform *trap8;
extern Transform *trap9;
extern Transform *trap10;
extern Transform *trap11;
extern Transform *trap12;
//Level2
extern Transform *entity2;
extern Transform *entity3;
//secret levels
extern Transform *susScroll;
extern Transform *glyph10;


//logs all entities
void LOG_ENTITIES();

//sets up basic entities
void ENTITY_SETUP();

#endif