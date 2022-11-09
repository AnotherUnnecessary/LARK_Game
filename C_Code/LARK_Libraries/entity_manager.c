#include "entity_manager.h"

char scrollText1[512] = {
    "\r\n'I dont know how I got here.\r\nEverything is overwhelmingly dark or blindinly bright.\r\nIm scared but there must be a way out.'\r\nThe rest of the writing is illegible."
};

char scrollText2[512] = {
    "\r\nIt looks like scribbles of a penguin drawing"
};
char glyphText1[48]="\tMan, this room is funny.";
char susText[24] = {"You are a sussy baka"};

Transform *ROOT;
//level1
    //triggers
Transform *trigger1lvl1;
Transform *trigger2lvl1;
Transform *trigger3lvl1;
Transform *trigger4lvl1;
Transform *trigger5lvl1;
    //keys and doors
Transform *key1lvl1;
Transform *key2lvl1;
Transform *door1lvl1;
Transform *door2lvl1;
Transform *door5lvl1;
    //scrolls and glyphs
Transform *scroll1lvl1;
Transform *scroll2lvl1;
    //lanters, chests and traps
Transform *lantern;
Transform *chest;
Transform *trap1;
Transform *trap2;
Transform *trap3;
Transform *trap4;
Transform *trap5;
Transform *trap6;
Transform *trap7;
//Level2
Transform *entity2;
Transform *entity3;
//secret levels
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
    trigger1lvl1 = ADD_ENTITY();
    trigger1lvl1->isFile = false;
    trigger1lvl1->sprite = ' ';
    trigger1lvl1->level = 1;
    trigger1lvl1->position.x = 30;
    trigger1lvl1->position.y = 16;
    trigger1lvl1->isVisible = false;
    trigger1lvl1->tag = DEFAULT;
    trigger1lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger1lvl1->name, "You're finally awake. Its a cozy corner to wake up in.");
        //L room lol
    trigger2lvl1 = ADD_ENTITY();
    trigger2lvl1->isFile = false;
    trigger2lvl1->sprite = ' ';
    trigger2lvl1->level = 1;
    trigger2lvl1->position.x = 29;
    trigger2lvl1->position.y = 20;
    trigger2lvl1->isVisible = false;
    trigger2lvl1->tag = DEFAULT;
    trigger2lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger2lvl1->name, "There is a big L in this room. I wonder what that could stand for?");
        //hallway!
    trigger3lvl1 = ADD_ENTITY();
    trigger3lvl1->isFile = false;
    trigger3lvl1->sprite = ' ';
    trigger3lvl1->level = 1;
    trigger3lvl1->position.x = 34;
    trigger3lvl1->position.y = 21;
    trigger3lvl1->isVisible = false;
    trigger3lvl1->tag = DEFAULT;
    trigger3lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger3lvl1->name, "\r\nThis hallway feels infinitely long! ...until it isnt.\r\nYou see a room with a locked door.\r\nIt looks like a bunch of circuits.");

        //You sense traps in this room (to the right of the L room after going in the hallway)
    trigger4lvl1= ADD_ENTITY();
    trigger4lvl1->isFile = false;
    trigger4lvl1->sprite = ' ';
    trigger4lvl1->level = 1;
    trigger4lvl1->position.x = 44;
    trigger4lvl1->position.y = 26;
    trigger4lvl1->isVisible = false;
    trigger4lvl1->tag = DEFAULT;
    trigger4lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger4lvl1->name, "There's something off about this room. Try using your lantern.");

        //Chest room! to the right of the trap room
    trigger5lvl1 = ADD_ENTITY();
    trigger5lvl1->isFile = false;
    trigger5lvl1->sprite = ' ';
    trigger5lvl1->level = 1;
    trigger5lvl1->position.x = 48;
    trigger5lvl1->position.y = 26;
    trigger5lvl1->isVisible = false;
    trigger5lvl1->tag = DEFAULT;
    trigger5lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger5lvl1->name, "You spot a chest across the room. Inspecting chests heals your health.\r\nCould be useful...");

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

        //key 2 to the south section
    key2lvl1 = ADD_ENTITY();
    key2lvl1->isFile = true;
    key2lvl1->isJob = true;
    key2lvl1->isVisible = true;
    key2lvl1->sprite = 'K';
    key2lvl1->position.x = 34;
    key2lvl1->position.y = 28;
    key2lvl1->tag = PICKUP;
    key2lvl1->level = 1;
    key2lvl1->OnUse = &UseKey;
    key2lvl1->useParam = key2lvl1;
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

    //Chests, lanterns and traps
        //Chest1
    chest = ADD_ENTITY();
    chest->isFile = true;
    chest->isJob = false;
    chest->isVisible = true;
    chest->level = 1;
    chest->position.x = 58;
    chest->position.y = 26;
    chest->sprite = 'C';
    chest->tag = DEFAULT;
    chest->OnInteract = &OpenChest;
    sprintf(chest->name, "chest.container");
        //Lantern1
    lantern = ADD_ENTITY();
    lantern->isFile = true;
    lantern->isJob = false;
    lantern->isVisible = true;
    lantern->level = 1;
    lantern->position.x = 46;
    lantern->position.y = 29;
    lantern->sprite = '*';
    lantern->tag = PICKUP;
    lantern->OnUse = &UseLantern;
    sprintf(lantern->name, "lantern.light");
        //Traps for trap room with key 2
    trap1 = ADD_ENTITY();
    trap1->isFile = false;
    trap1->isJob = false;
    trap1->isVisible= false;
    trap1->level = 1;
    trap1->position.x = 35;
    trap1->position.y = 28;
    trap1->sprite = 'T';
    trap1->tag = TRAP;
    trap1->OnUpdate = &TriggerTrap;
    sprintf(trap1->name, "trap1.trap");

    trap2 = ADD_ENTITY();
    trap2->isFile = false;
    trap2->isJob = false;
    trap2->isVisible= false;
    trap2->level = 1;
    trap2->position.x = 34;
    trap2->position.y = 27;
    trap2->sprite = 'T';
    trap2->tag = TRAP;
    trap2->OnUpdate = &TriggerTrap;
    sprintf(trap2->name, "trap2.trap");

    trap3 = ADD_ENTITY();
    trap3->isFile = false;
    trap3->isJob = false;
    trap3->isVisible= false;
    trap3->level = 1;
    trap3->position.x = 40;
    trap3->position.y = 25;
    trap3->sprite = 'T';
    trap3->tag = TRAP;
    trap3->OnUpdate = &TriggerTrap;
    sprintf(trap3->name, "trap3.trap");

    trap4 = ADD_ENTITY();
    trap4->isFile = false;
    trap4->isJob = false;
    trap4->isVisible= false;
    trap4->level = 1;
    trap4->position.x = 41;
    trap4->position.y = 26;
    trap4->sprite = 'T';
    trap4->tag = TRAP;
    trap4->OnUpdate = &TriggerTrap;
    sprintf(trap4->name, "trap4.trap");

    trap5 = ADD_ENTITY();
    trap5->isFile = false;
    trap5->isJob = false;
    trap5->isVisible= false;
    trap5->level = 1;
    trap5->position.x = 40;
    trap5->position.y = 24;
    trap5->sprite = 'T';
    trap5->tag = TRAP;
    trap5->OnUpdate = &TriggerTrap;
    sprintf(trap5->name, "trap5.trap");

    trap6 = ADD_ENTITY();
    trap6->isFile = false;
    trap6->isJob = false;
    trap6->isVisible= false;
    trap6->level = 1;
    trap6->position.x = 37;
    trap6->position.y = 26;
    trap6->sprite = 'T';
    trap6->tag = TRAP;
    trap6->OnUpdate = &TriggerTrap;
    sprintf(trap6->name, "trap6.trap");

    trap7 = ADD_ENTITY();
    trap7->isFile = false;
    trap7->isJob = false;
    trap7->isVisible = false;
    trap7->level = 1;
    trap7->position.x = 38;
    trap7->position.y = 29;
    trap7->sprite = 'T';
    trap7->tag = TRAP;
    trap7->OnUpdate = &TriggerTrap;
    sprintf(trap7->name, "trap7.trap");

    /*glyph1 = ADD_ENTITY();
    glyph1->isFile = false;
    glyph1->isJob = false;
    glyph1->isVisible = false;
    glyph1->level = 1;
    glyph1->position.x = 34;
    glyph1->position.y = 24;
    glyph1->tag = DEFAULT;
    glyph1->OnInteract= &AddToTerminalOutput;
    glyph1->useParam = &glyphText1;
    sprintf(glyph1->name, "glyph1.glyph")*/

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

