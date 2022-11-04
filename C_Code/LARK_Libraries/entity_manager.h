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

extern char scrollText1[512];

extern Transform *ROOT;
extern Transform *trigger1lvl1WakeUp;
extern Transform *door1lvl1;
extern Transform *key1lvl1;

extern Transform *entity2;
extern Transform *entity3;
extern Transform *scroll1;
extern Transform *lantern;
extern Transform *chest;

//logs all entities
void LOG_ENTITIES();

//sets up basic entities
void ENTITY_SETUP();

#endif