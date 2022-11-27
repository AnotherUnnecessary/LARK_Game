#include "entity_manager.h"

char scrollText1[512] = {
    "\r\nTUTORIAL OF UNIX COMMANDS\r\nUse 'ls' to see all the 'files' in the game\r\nUse 'cd' to go to other levels EXAMPLE: 'cd lvl1.level'\r\nUse 'cat' to find the stats of a file EXAMPLE: 'cat 1.key'\r\nUse 'echo' to output your thoughts into the terminal\r\nUse 'man' to see all the commands you can use and their descriptions.\r\nThats the basics. Experiment!\r\nGood luck!"
};

char scrollText2[512] = {
    "\r\nYou find a note. It has scribbles of a penguin drawing as well as some writing.\r\nIt reads: 'Ive lost count of the days. Ive stepped on so many traps I cant move anymore.\r\nI dont feel my legs. I cant even see my legs... wait where are my legs?'\r\nThe rest is illegible.\r\nNow that you think about it: You cant see your legs either."
};
char scrollText3[32] = {
    "\r\n'cd lvl1993.secret'"
};
char scrollText4[256] = {
    "You find a piece of paper... it feels like paper\r\n'I keep seeing bits and bites of penguins...'\r\nThere's no more writing.\r\nYou look at the back of the 'paper' and you read 'cd lvl4.secret'"
};

char scrollText5[512] = {
    "You feel a stream of 0s and 1s coming into your brain.\r\nThe penguin speaks to you.\r\n'I am tux. As you can tell, you're trapped inside of a Linux computer.'\r\nYou feel welcome yet overwhelmed by their presence\r\n'You will need this key to get out of the simulation.'\r\n'Whenever you feel lost, keep going. Doors will open themselves to you.'\r\n'Theres a reason you don't see windows around here.'\r\nIt looks at you, waiting for you to pick up the key and get going."
};

char glyphText1[128]="\r\nTraps ahead. ./use.sh of lantern '*' recommended for better visibility.";
char glyphText2[512]="\r\nThree massive doors lay in front of you, each to their own room. Something tells you that the code to the exit hides behind them.\r\nWhy? You dont know why.";
char glyphText4[256]="\r\nYou find a vent on this corner. Thats odd...\r\nYou open the vent and see a note.\r\n'cd lvl69.secret'\r\n...\r\noh lord'";
char glyphText0[256]="\r\nThe writing on the wall reads 'Tux'\r\n...\r\nThats a little underwhelming.\r\nIt seems important though... Maybe the other doors have more answers\r\nI think there's nothing else to do here though... Maybe checking other levels out will help.";
char glyphText9[128]="\r\nThis time the wall reads 'Torvalds'\r\nOne more door and all will be revealed";
char glyphText8[256]="\r\nYou see a bunch of 0s and 1s but for some reason you can read it\r\nIt says '1991'\r\n'become su by combining your 3 passcodes and exit out'\r\nYou finally know what to do.";
char glyphText10[512]="\r\nHey! Developer speaking here.\r\nOriginally this game started as a doom inspired game\r\nIt had the same first person view and we wanted to use it as a maze\r\nBut we had to change course when we realized it wasnt very fun\r\nWe went with top view because the debugger of the doom view looked like what youre playing right now :)\r\nThats all though so developer out! Thank you for playing our game <3";
char susText[24] = {"You are a sussy baka"};

Transform *ROOT;
//level1
    //triggers
Transform *trigger1lvl1;
Transform *trigger2lvl1;
Transform *trigger3lvl1;
Transform *trigger5lvl1;
Transform *trigger6lvl1;
    //keys and doors
Transform *key1lvl1;
Transform *key2lvl1;
Transform *key4lvl1;
Transform *key5lvl1;
Transform *key0lvl1;
Transform *key8lvl1;
Transform *door1lvl1;
Transform *door2lvl1;
Transform *door4lvl1;
Transform *door5lvl1;
Transform *door52lvl1;
        //final doors
Transform *door0lvl1;
Transform *door9lvl1;
Transform *door8lvl1;
    //scrolls and glyphs
Transform *scroll1lvl1;
Transform *scroll2lvl1;
Transform *scroll3lvl1;
Transform *scroll4lvl1;
Transform *scroll5lvl1;
Transform *glyph1;
Transform *glyph2;
Transform *glyph3;
Transform *glyph4;
Transform *glyph0;
Transform *glyph9;
Transform *glyph8;
    //lanters, chests and traps
Transform *lantern1;
Transform *lantern2;
Transform *chest;
Transform *chest2;
Transform *chest3;
Transform *chest4;
Transform *trap1;
Transform *trap2;
Transform *trap3;
Transform *trap4;
Transform *trap5;
Transform *trap6;
Transform *trap7;
Transform *trap8;
Transform *trap9;
Transform *trap10;
Transform *trap11;
Transform *trap12;
//Level2
Transform *entity2;
Transform *entity3;
//secret levels
Transform *susScroll;
Transform *glyph10;

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
    trigger1lvl1->isJob= false;
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
    trigger2lvl1->isJob= false;
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
    trigger3lvl1->isJob= false;
    trigger3lvl1->sprite = ' ';
    trigger3lvl1->level = 1;
    trigger3lvl1->position.x = 34;
    trigger3lvl1->position.y = 21;
    trigger3lvl1->isVisible = false;
    trigger3lvl1->tag = DEFAULT;
    trigger3lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger3lvl1->name, "\r\nThis hallway feels infinitely long! ...until it isnt.\r\nYou see a room with a locked door.\r\nIt looks like a bunch of circuits.");

        //Chest room! to the right of the trap room
    trigger5lvl1 = ADD_ENTITY();
    trigger5lvl1->isFile = false;
    trigger5lvl1->isJob= false;
    trigger5lvl1->sprite = ' ';
    trigger5lvl1->level = 1;
    trigger5lvl1->position.x = 48;
    trigger5lvl1->position.y = 26;
    trigger5lvl1->isVisible = false;
    trigger5lvl1->tag = DEFAULT;
    trigger5lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger5lvl1->name, "You spot a chest across the room. Inspecting chests heals your health.\r\nCould be useful...");

    trigger6lvl1 = ADD_ENTITY();
    trigger6lvl1->isFile = false;
    trigger6lvl1->isJob= false;
    trigger6lvl1->sprite = ' ';
    trigger6lvl1->level = 1;
    trigger6lvl1->position.x = 37;
    trigger6lvl1->position.y = 5;
    trigger6lvl1->isVisible = false;
    trigger6lvl1->tag = DEFAULT;
    trigger6lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger6lvl1->name, "You enter a massive room. It feels like an empty church.\r\nIf you could scream, echo and reverb would wash over you.");

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

        //key 4, inside the room to the left of the 3 doors room
    key4lvl1 = ADD_ENTITY();
    key4lvl1->isFile = true;
    key4lvl1->isJob = true;
    key4lvl1->isVisible = true;
    key4lvl1->sprite = 'K';
    key4lvl1->position.x = 29;
    key4lvl1->position.y = 12;
    key4lvl1->tag = PICKUP;
    key4lvl1->level = 1;
    key4lvl1->OnUse = &UseKey;
    key4lvl1->useParam = key4lvl1;
    sprintf(key4lvl1->name, "4.key");

        //door 4 to go up to then go to start going to tux level
    door4lvl1 = ADD_ENTITY();
    door4lvl1->isFile = false;
    door4lvl1->isJob = true;
    door4lvl1->sprite = '%';
    door4lvl1->level = 1;
    door4lvl1->position.x = 14;
    door4lvl1->position.y = 9;
    door4lvl1->isVisible = true;
    door4lvl1->tag = DOOR;
    sprintf(door4lvl1->name, "4.door");

        //Door to secret room at the end of hallway

    key5lvl1 = ADD_ENTITY();
    key5lvl1->isFile = true;
    key5lvl1->isJob = true;
    key5lvl1->isVisible = true;
    key5lvl1->sprite = 'K';
    key5lvl1->position.x = 5;
    key5lvl1->position.y = 5;
    key5lvl1->tag = PICKUP;
    key5lvl1->level = 1;
    key5lvl1->OnUse = &UseKey;
    key5lvl1->useParam =key5lvl1;
    sprintf(key5lvl1->name, "5.key");

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

    //another door 5 so the player can open it with key 5 again
    //cuz If the player finds an easter egg too soon into the game it cang et confusing
    door52lvl1 = ADD_ENTITY();
    door52lvl1->isFile = false;
    door52lvl1->isJob = true;
    door52lvl1->sprite = '%';
    door52lvl1->level = 1;
    door52lvl1->position.x = 54;
    door52lvl1->position.y = 19;
    door52lvl1->isVisible = true;
    door52lvl1->tag = DOOR;
    sprintf(door52lvl1->name, "5.door");

        //FINAL DOORS
        //door 1 "Tux"
    key0lvl1 = ADD_ENTITY();
    key0lvl1->isFile = true;
    key0lvl1->isJob = true;
    key0lvl1->isVisible = true;
    key0lvl1->sprite = 'K';
    key0lvl1->position.x = 34;
    key0lvl1->position.y = 11;
    key0lvl1->tag = PICKUP;
    key0lvl1->level = 4;
    key0lvl1->OnUse = &UseKey;
    key0lvl1->useParam = key0lvl1;
    sprintf(key0lvl1->name, "0.key");

    door0lvl1 = ADD_ENTITY();
    door0lvl1->isFile = false;
    door0lvl1->isJob = true;
    door0lvl1->sprite = '%';
    door0lvl1->level = 1;
    door0lvl1->position.x = 49;
    door0lvl1->position.y = 12;
    door0lvl1->isVisible = true;
    door0lvl1->tag = DOOR;
    sprintf(door0lvl1->name, "0.door");

        //door 2 "Torvalds"
    door9lvl1 = ADD_ENTITY();
    door9lvl1->isFile = false;
    door9lvl1->isJob = true;
    door9lvl1->sprite = '%';
    door9lvl1->level = 1;
    door9lvl1->position.x = 49;
    door9lvl1->position.y = 8;
    door9lvl1->isVisible = true;
    door9lvl1->tag = DOOR;
    sprintf(door9lvl1->name, "9.door");
        //door 3 "1991"

    key8lvl1 = ADD_ENTITY();
    key8lvl1->isFile = true;
    key8lvl1->isJob = true;
    key8lvl1->isVisible = true;
    key8lvl1->sprite = 'K';
    key8lvl1->position.x = 7;
    key8lvl1->position.y = 29;
    key8lvl1->tag = PICKUP;
    key8lvl1->level = 1;
    key8lvl1->OnUse = &UseKey;
    key8lvl1->useParam = key8lvl1;
    sprintf(key8lvl1->name, "8.key");

    
    door8lvl1 = ADD_ENTITY();
    door8lvl1->isFile = false;
    door8lvl1->isJob = true;
    door8lvl1->sprite = '%';
    door8lvl1->level = 1;
    door8lvl1->position.x = 49;
    door8lvl1->position.y = 4;
    door8lvl1->isVisible = true;
    door8lvl1->tag = DOOR;
    sprintf(door8lvl1->name, "8.door");
    
    
    //scrolls and glyphs section for level 1
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

        //scroll for player to find sus room
    scroll3lvl1 = ADD_ENTITY();
    scroll3lvl1->isFile = false;
    scroll3lvl1->isJob = false;
    scroll3lvl1->isVisible = true;
    scroll3lvl1->level = 1;
    scroll3lvl1->position.x = 56;
    scroll3lvl1->position.y = 22;
    scroll3lvl1->sprite = '@';
    scroll3lvl1->tag = PICKUP;
    scroll3lvl1->OnUse = &WriteToTerminalOutput;
    scroll3lvl1->useParam = &scrollText3;
    sprintf(scroll3lvl1->name, "secretlevel.scroll");

        //scroll corner left go to tux
    scroll4lvl1 = ADD_ENTITY();
    scroll4lvl1->isFile = false;
    scroll4lvl1->isJob = false;
    scroll4lvl1->isVisible = true;
    scroll4lvl1->level = 1;
    scroll4lvl1->position.x = 1;
    scroll4lvl1->position.y = 20;
    scroll4lvl1->sprite = '@';
    scroll4lvl1->tag = PICKUP;
    scroll4lvl1->OnUse = &WriteToTerminalOutput;
    scroll4lvl1->useParam = &scrollText4;
    sprintf(scroll4lvl1->name, "FirstEncounter.scroll");

    //talking to tux
    scroll5lvl1 = ADD_ENTITY();
    scroll5lvl1->isFile = false;
    scroll5lvl1->isJob = false;
    scroll5lvl1->isVisible = true;
    scroll5lvl1->level = 4;
    scroll5lvl1->position.x = 29;
    scroll5lvl1->position.y = 11;
    scroll5lvl1->sprite = '@';
    scroll5lvl1->tag = PICKUP;
    scroll5lvl1->OnUse = &WriteToTerminalOutput;
    scroll5lvl1->useParam = &scrollText5;
    sprintf(scroll5lvl1->name, "penguin.scroll");
        //glyphs
        //glyph for funny trap room warning the player
    glyph1 = ADD_ENTITY();
    glyph1->isFile = false;
    glyph1->isJob = false;
    glyph1->isVisible = true;
    glyph1->level = 1;
    glyph1->position.x = 45;
    glyph1->position.y = 27;
    glyph1->sprite = 'X';
    glyph1->tag = DEFAULT;
    glyph1->OnInteract= &AddToTerminalOutput;
    glyph1->useParam = &glyphText1;
    sprintf(glyph1->name, "glyph1.glyph");

        //room with 3 doors, explains the player a little story wise
    glyph2 = ADD_ENTITY();
    glyph2->isFile = false;
    glyph2->isJob = false;
    glyph2->isVisible = true;
    glyph2->level = 1;
    glyph2->position.x = 44;
    glyph2->position.y = 8;
    glyph2->sprite = 'X';
    glyph2->tag = DEFAULT;
    glyph2->OnInteract= &AddToTerminalOutput;
    glyph2->useParam = &glyphText2;
    sprintf(glyph2->name, "glyph2.glyph");

        //glyph warning in hallway all the way to the left
    glyph3 = ADD_ENTITY();
    glyph3->isFile = false;
    glyph3->isJob = false;
    glyph3->isVisible = true;
    glyph3->level = 1;
    glyph3->position.x = 13;
    glyph3->position.y = 10;
    glyph3->sprite = 'X';
    glyph3->tag = DEFAULT;
    glyph3->OnInteract= &AddToTerminalOutput;
    glyph3->useParam = &glyphText1;
    sprintf(glyph3->name, "glyph3.glyph");

    glyph4 = ADD_ENTITY();
    glyph4->isFile = false;
    glyph4->isJob = false;
    glyph4->isVisible = true;
    glyph4->level = 1;
    glyph4->position.x = 47;
    glyph4->position.y = 18;
    glyph4->sprite = 'X';
    glyph4->tag = DEFAULT;
    glyph4->OnInteract= &AddToTerminalOutput;
    glyph4->useParam = &glyphText4;
    sprintf(glyph4->name, "glyph4.glyph");

    //Final glyphs
    glyph0 = ADD_ENTITY();
    glyph0->isFile = false;
    glyph0->isJob = false;
    glyph0->isVisible = true;
    glyph0->level = 1;
    glyph0->position.x = 58;
    glyph0->position.y = 12;
    glyph0->sprite = 'X';
    glyph0->tag = DEFAULT;
    glyph0->OnInteract= &AddToTerminalOutput;
    glyph0->useParam = &glyphText0;
    sprintf(glyph0->name, "glyph0.glyph");

    glyph9 = ADD_ENTITY();
    glyph9->isFile = false;
    glyph9->isJob = false;
    glyph9->isVisible = true;
    glyph9->level = 1;
    glyph9->position.x = 55;
    glyph9->position.y = 9;
    glyph9->sprite = 'X';
    glyph9->tag = DEFAULT;
    glyph9->OnInteract= &AddToTerminalOutput;
    glyph9->useParam = &glyphText9;
    sprintf(glyph9->name, "glyph9.glyph");

    glyph8 = ADD_ENTITY();
    glyph8->isFile = false;
    glyph8->isJob = false;
    glyph8->isVisible = true;
    glyph8->level = 1;
    glyph8->position.x = 57;
    glyph8->position.y = 4;
    glyph8->sprite = 'X';
    glyph8->tag = DEFAULT;
    glyph8->OnInteract= &AddToTerminalOutput;
    glyph8->useParam = &glyphText8;
    sprintf(glyph8->name, "glyph8.glyph");

    glyph10 = ADD_ENTITY();
    glyph10->isFile = false;
    glyph10->isJob = false;
    glyph10->isVisible = true;
    glyph10->level = 1993;
    glyph10->position.x = 42;
    glyph10->position.y = 25;
    glyph10->sprite = 'X';
    glyph10->tag = DEFAULT;
    glyph10->OnInteract= &AddToTerminalOutput;
    glyph10->useParam = &glyphText10;
    sprintf(glyph10->name, "glyph10.glyph");

    //Chests, lanterns and traps
        //Chest1
    chest = ADD_ENTITY();
    chest->isFile = true;
    chest->isJob = false;
    chest->isVisible = true;
    chest->level = 1;
    chest->position.x = 58;
    chest->position.y = 26;
    chest->sprite = 'X';
    chest->tag = DEFAULT;
    chest->OnInteract = &OpenChest;
    sprintf(chest->name, "chest.container");

        //chest2 in room of key 3
    chest2 = ADD_ENTITY();
    chest2->isFile = true;
    chest2->isJob = false;
    chest2->isVisible = true;
    chest2->level = 1;
    chest2->position.x = 33;
    chest2->position.y = 10;
    chest2->sprite = 'X';
    chest2->tag = DEFAULT;
    chest2->OnInteract = &OpenChest;
    sprintf(chest2->name, "chest2.container");

    chest3 = ADD_ENTITY();
    chest3->isFile = true;
    chest3->isJob = false;
    chest3->isVisible = true;
    chest3->level = 1;
    chest3->position.x = 9;
    chest3->position.y = 7;
    chest3->sprite = 'X';
    chest3->tag = DEFAULT;
    chest3->OnInteract = &OpenChest;
    sprintf(chest3->name, "chest3.container");

    chest4 = ADD_ENTITY();
    chest4->isFile = true;
    chest4->isJob = false;
    chest4->isVisible = true;
    chest4->level = 1;
    chest4->position.x = 36;
    chest4->position.y = 16;
    chest4->sprite = 'X';
    chest4->tag = DEFAULT;
    chest4->OnInteract = &OpenChest;
    sprintf(chest4->name, "chest4.container");

        //Lantern1
    lantern1 = ADD_ENTITY();
    lantern1->isFile = true;
    lantern1->isJob = false;
    lantern1->isVisible = true;
    lantern1->level = 1;
    lantern1->position.x = 46;
    lantern1->position.y = 29;
    lantern1->sprite = '*';
    lantern1->tag = PICKUP;
    lantern1->OnUse = &UseLantern;
    sprintf(lantern1->name, "lantern1.light");

    //Lantern2
    lantern2 = ADD_ENTITY();
    lantern2->isFile = true;
    lantern2->isJob = false;
    lantern2->isVisible = true;
    lantern2->level = 1;
    lantern2->position.x = 30;
    lantern2->position.y = 3;
    lantern2->sprite = '*';
    lantern2->tag = PICKUP;
    lantern2->OnUse = &UseLantern;
    sprintf(lantern2->name, "lantern2.light");
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

    //Traps in hallway to the left

    trap8 = ADD_ENTITY();
    trap8->isFile = false;
    trap8->isJob = false;
    trap8->isVisible = false;
    trap8->level = 1;
    trap8->position.x = 7;
    trap8->position.y = 12;
    trap8->sprite = 'T';
    trap8->tag = TRAP;
    trap8->OnUpdate = &TriggerTrapOnce;
    sprintf(trap8->name, "trap8.trap");

    trap9 = ADD_ENTITY();
    trap9->isFile = false;
    trap9->isJob = false;
    trap9->isVisible = false;
    trap9->level = 1;
    trap9->position.x = 14;
    trap9->position.y = 12;
    trap9->sprite = 'T';
    trap9->tag = TRAP;
    trap9->OnUpdate = &TriggerTrapOnce;
    sprintf(trap9->name, "trap9.trap");

    trap10 = ADD_ENTITY();
    trap10->isFile = false;
    trap10->isJob = false;
    trap10->isVisible = false;
    trap10->level = 1;
    trap10->position.x = 38;
    trap10->position.y = 29;
    trap10->sprite = 'T';
    trap10->tag = TRAP;
    trap10->OnUpdate = &TriggerTrapOnce;
    sprintf(trap10->name, "trap10.trap");

    trap11 = ADD_ENTITY();
    trap11->isFile = false;
    trap11->isJob = false;
    trap11->isVisible = false;
    trap11->level = 1;
    trap11->position.x =4;
    trap11->position.y = 11;
    trap11->sprite = 'T';
    trap11->tag = TRAP;
    trap11->OnUpdate = &TriggerTrapOnce;
    sprintf(trap11->name, "trap11.trap");

    trap12 = ADD_ENTITY();
    trap12->isFile = false;
    trap12->isJob = false;
    trap12->isVisible = false;
    trap12->level = 1;
    trap12->position.x = 6;
    trap12->position.y = 13;
    trap12->sprite = 'T';
    trap12->tag = TRAP;
    trap12->OnUpdate = &TriggerTrapOnce;
    sprintf(trap12->name, "trap12.trap");

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

