#include "entity_manager.h"

char scrollText1[512] = {
    "\r\nThis is a scroll. They contain useful information to learn how to play the game.\r\nYou already know that if you walk over something, you can use './pickup.sh' to pick it up\r\nYou can also use './drop.sh' to drop it\r\nThere is also './use.sh' to use (but you already know that)"
};

char susText[24] = {"You are a sussy baka"};

Transform *ROOT;
Transform *trigger1lvl1WakeUp;
Transform *key1lvl1;
Transform *door1lvl1;
Transform *entity2;
Transform *entity3;
Transform *scroll1;
Transform *lantern;
Transform *chest;

Transform *susScroll;

void LOG_ENTITIES(){
    for(int i = 0; i < numEntities; i++){
        fprintf(myLog, "CREATED ENTITY : [%s] with [%d] Instance ID\n", ENTITIES[i].name, ENTITIES[i].instanceID);
    }
}

void ENTITY_SETUP(){
    //Player!
    PLAYER->position.x = mapX/2;
    PLAYER->position.y = mapY/2;
    PLAYER->OnUpdate = (&OnPlayerUpdate);
    PLAYER->rotation = PI/2;
    PLAYER->tag = PLAYER_TAG;
    PLAYER->sprite = '$';
    PLAYER->OnUse = &ModifyHealth;
    sprintf(PLAYER->name, "PLAYER");

    //TRUE LEVEL 1 TEST

    //Trigger for the player waking up
    trigger1lvl1WakeUp = ADD_ENTITY();
    trigger1lvl1WakeUp->isFile = false;
    trigger1lvl1WakeUp->sprite = ' ';
    trigger1lvl1WakeUp->level = 1;
    trigger1lvl1WakeUp->position.x = 30;
    trigger1lvl1WakeUp->position.y = 16;
    trigger1lvl1WakeUp->isVisible = false;
    trigger1lvl1WakeUp->tag = DEFAULT;
    trigger1lvl1WakeUp->OnUpdate = &TriggerUpdate;
    sprintf(trigger1lvl1WakeUp->name, "You're finally awake. Its a cozy corner to wake up in.");

    //key 1 for door 1 in level 1
    key1lvl1 = ADD_ENTITY();
    key1lvl1->isFile = true;
    key1lvl1->isJob = true;
    key1lvl1->isVisible = true;
    key1lvl1->sprite = 'K';
    key1lvl1->position.x = 18;
    key1lvl1->position.y = 17;
    key1lvl1->tag = PICKUP;
    key1lvl1->level = 1;
    key1lvl1->OnUse = &UseKey;
    key1lvl1->useParam = key1lvl1;
    sprintf(key1lvl1->name, "1.key");

    door1lvl1 = ADD_ENTITY();
    door1lvl1->isFile = false;
    door1lvl1->isJob = true;
    door1lvl1->sprite = '%';
    door1lvl1->level = 1;
    door1lvl1->position.x = 29;
    door1lvl1->position.y = 19;
    door1lvl1->isVisible = true;
    door1lvl1->tag = DOOR;
    sprintf(door1lvl1->name, "1.door");

    //scrolls


    //LEVEL 2

    entity2 = ADD_ENTITY();
    entity2->isFile = true;
    entity2->isJob = true;
    entity2->isVisible = true;
    entity2->level = 2;
    entity2->position.x = 10;
    entity2->position.y = 10;
    entity2->sprite = 'K';
    entity2->tag = PICKUP;
    entity2->OnUse = &UseKey;
    entity2->useParam = entity2;
    sprintf(entity2->name, "2.key");

    entity3 = ADD_ENTITY();
    entity3->isFile = false;
    entity3->isJob = true;
    entity3->sprite = '%';
    entity3->level = 2;
    entity3->position.x = 10;
    entity3->position.y = 26;
    entity3->isVisible = true;
    entity3->tag = DOOR;
    sprintf(entity3->name, "2.door");

    scroll1 = ADD_ENTITY();
    scroll1->isFile = true;
    scroll1->isJob = false;
    scroll1->isVisible = true;
    scroll1->level = 2;
    scroll1->position.x = 10;
    scroll1->position.y = 12;
    scroll1->sprite = '@';
    scroll1->tag = PICKUP;
    scroll1->OnUse = &WriteToTerminalOutput;
    scroll1->useParam = &scrollText1;
    sprintf(scroll1->name, "basics.scroll");

    lantern = ADD_ENTITY();
    lantern->isFile = true;
    lantern->isJob = false;
    lantern->isVisible = true;
    lantern->level = 2;
    lantern->position.x = 10;
    lantern->position.y = 8;
    lantern->sprite = '*';
    lantern->tag = PICKUP;
    lantern->OnUse = &UseLantern;
    sprintf(lantern->name, "lantern.light");

    chest = ADD_ENTITY();
    chest->isFile = true;
    chest->isJob = false;
    chest->isVisible = true;
    chest->level = 2;
    chest->position.x = 34;
    chest->position.y = 16;
    chest->sprite = 'X';
    chest->tag = DEFAULT;
    chest->OnInteract = &OpenChest;
    sprintf(chest->name, "chest.container");

    //SECRET LEVELS 
    //SECRET STUFF

    //Among us level
    susScroll = ADD_ENTITY();
    susScroll->isFile = false;
    susScroll->isJob = false;
    susScroll->isVisible= true;
    susScroll->level = 69;
    susScroll->sprite = '@';
    susScroll->tag = PICKUP;
    susScroll->OnUse = &WriteToTerminalOutput;
    susScroll->useParam = &susText;
    sprintf(susScroll->name, "sussy_scroll.scroll");
    susScroll->position.x = 35;
    susScroll->position.y = 20;

    LOG_ENTITIES();
}

