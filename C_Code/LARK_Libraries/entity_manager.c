#include "entity_manager.h"

char scrollText1[512] = {
    "\r\n'I dont know how I got here.\r\nEverything is overwhelmingly dark or blindinly bright.\r\nIm scared but there must be a way out.'\r\nThe rest of the writing is illegible."
};

char scrollText2[512] = {
    "\r\n'Its been days.\r\nThis L holds so much more value than any other L Ive ever seen\r\nI can see places just thinking about my sorroundings.\r\nls is the way'\r\nThere seems to be a drawing at the bottom.\r\nIt looks like a weird penguin."
};

char susText[24] = {"You are a sussy baka"};

Transform *ROOT;
//level1
Transform *trigger1lvl1WakeUp;
Transform *trigger2lvl1LRoom;
Transform *trigger3lvl1RightRoom;
Transform *key1lvl1;
Transform *key2lvl1;
Transform *door1lvl1;
Transform *door2lvl1;
Transform *door5lvl1;
Transform *scroll1lvl1;
Transform *scroll2lvl1;


Transform *entity2;
Transform *entity3;
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
        //L room lol
    trigger2lvl1LRoom = ADD_ENTITY();
    trigger2lvl1LRoom->isFile = false;
    trigger2lvl1LRoom->sprite = ' ';
    trigger2lvl1LRoom->level = 1;
    trigger2lvl1LRoom->position.x = 29;
    trigger2lvl1LRoom->position.y = 20;
    trigger2lvl1LRoom->isVisible = false;
    trigger2lvl1LRoom->tag = DEFAULT;
    trigger2lvl1LRoom->OnUpdate = &TriggerUpdate;
    sprintf(trigger2lvl1LRoom->name, "There is a big L in this room. I wonder what that could stand for?");
        //hallway!
    trigger3lvl1RightRoom = ADD_ENTITY();
    trigger3lvl1RightRoom->isFile = false;
    trigger3lvl1RightRoom->sprite = ' ';
    trigger3lvl1RightRoom->level = 1;
    trigger3lvl1RightRoom->position.x = 34;
    trigger3lvl1RightRoom->position.y = 21;
    trigger3lvl1RightRoom->isVisible = false;
    trigger3lvl1RightRoom->tag = DEFAULT;
    trigger3lvl1RightRoom->OnUpdate = &TriggerUpdate;
    sprintf(trigger3lvl1RightRoom->name, "This hallway feels infinitely long! ...until it isn't");

    //DOORS AND KEYS
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
        //first door the player shall open
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

        //key 2 to the level south
    key2lvl1 = ADD_ENTITY();
    key2lvl1->isFile = true;
    key2lvl1->isJob = true;
    key2lvl1->isVisible = true;
    key2lvl1->sprite = 'K';
    key2lvl1->position.x = 46;
    key2lvl1->position.y = 29;
    key2lvl1->tag = PICKUP;
    key2lvl1->level = 1;
    key2lvl1->OnUse = &UseKey;
    key2lvl1->useParam = key1lvl1;
    sprintf(key2lvl1->name, "2.key");

        //door 2 south level 1
    door2lvl1 = ADD_ENTITY();
    door2lvl1->isFile = false;
    door2lvl1->isJob = true;
    door2lvl1->sprite = '%';
    door2lvl1->level = 1;
    door2lvl1->position.x = 22;
    door2lvl1->position.y = 9;
    door2lvl1->isVisible = true;
    door2lvl1->tag = DOOR;
    sprintf(door2lvl1->name, "2.door");

        //Door to secret room at the end of hallway
    door5lvl1 = ADD_ENTITY();
    door5lvl1->isFile = false;
    door5lvl1->isJob = true;
    door5lvl1->sprite = '%';
    door5lvl1->level = 1;
    door5lvl1->position.x = 55;
    door5lvl1->position.y = 21;
    door5lvl1->isVisible = true;
    door5lvl1->tag = DOOR;
    sprintf(door5lvl1->name, "5.door");
    
    //scrolls section for level 1

        //awakening scroll
    scroll1lvl1 = ADD_ENTITY();
    scroll1lvl1->isFile = false;
    scroll1lvl1->isJob = false;
    scroll1lvl1->isVisible = true;
    scroll1lvl1->level = 1;
    scroll1lvl1->position.x = 32;
    scroll1lvl1->position.y = 18;
    scroll1lvl1->sprite = '@';
    scroll1lvl1->tag = PICKUP;
    scroll1lvl1->OnUse = &WriteToTerminalOutput;
    scroll1lvl1->useParam = &scrollText1;
    sprintf(scroll1lvl1->name, "awakening.scroll");

        //linux scroll
    scroll2lvl1 = ADD_ENTITY();
    scroll2lvl1->isFile = false;
    scroll2lvl1->isJob = false;
    scroll2lvl1->isVisible = true;
    scroll2lvl1->level = 1;
    scroll2lvl1->position.x = 25;
    scroll2lvl1->position.y = 25;
    scroll2lvl1->sprite = '@';
    scroll2lvl1->tag = PICKUP;
    scroll2lvl1->OnUse = &WriteToTerminalOutput;
    scroll2lvl1->useParam = &scrollText2;
    sprintf(scroll2lvl1->name, "linux.scroll");

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
    sprintf(entity2->name, "99.key");

    entity3 = ADD_ENTITY();
    entity3->isFile = false;
    entity3->isJob = true;
    entity3->sprite = '%';
    entity3->level = 2;
    entity3->position.x = 10;
    entity3->position.y = 26;
    entity3->isVisible = true;
    entity3->tag = DOOR;
    sprintf(entity3->name, "99.door");

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

