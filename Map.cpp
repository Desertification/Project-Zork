//
// Created by alex on 12/16/15.
//

#include "Map.h"

    std::vector<Room *> getRooms(){
        std::vector<Room *> rooms;

        //0 outside on the street
        rooms.push_back(new Room("You see a house in the distance..\nMaybe you'll find shelter in there from the dark and the rain\n"));
        //1 walk on TODO implement death
        rooms.push_back(new Room("you chose to keep walking in the dark forest in the rain.\nYou have tripped over a fallen branch, hit your head and died.\n"));
        //2 the house
        rooms.push_back(new Room("The front door seems to be locked\nMaybe there is a back door open.\n"));
        //3 the door outside
        rooms.push_back(new Room("You see the door that leads towards the kitchen\n"));
        //4 the kitchen
        rooms.push_back(new Room("Finally shelter. And maybe, with a little luck you'll find some food in the cabins.\n"
                                         "While searching the cabins, you suddenly hear a deep voice coming from the dark saying : \n"
                                         "\"Who is it there, trying to steal from me?\"\n\n"
                                         "You answer the deep voice : \n"
                                         "\"I'm sorry, I didn't know someone was home. I...\"\n"
                                         "The voice interrupts you with his deep voice and in an angry tone :\n"
                                         "\"You shall mourn the day you walked inside! Now you're mine for eternity.\"\n"
                                         "The voice now was laughing, just laughing with you, and you never felt so scared. You wanted to get out of there, and ran towards the door.\n"
                                         "As you approached the door, the door slams, and locks. It looks like you're trapped inside.\n"

        ));
        //5 living room
        rooms.push_back(new Room("You appear to be in the living room. \n"
                                         "All the furniture is covered in white sheets. There is a door towards what you assume is the hallway\n"));
        //6 hallway
        rooms.push_back(new Room("The front door is still locked and there doesn't appear to be a key lying around.\n"
                                         "Perhaps there is something on the first floor. I could use the stairs\n"));
        //7 hallway
        rooms.push_back(new Room("There are 4 doors and a food elevator.\n"
                                         "The first 3 doors are locked\n"));
        //8 bedroom
        rooms.push_back(new Room("It seems to be a childrens bedroom.\n"
                                         "There is a faint light coming out of the closet.\n"));
        //9 closet //TODO make this with inventory
        rooms.push_back(new Room("you find a can of peas and a knife\n"));

        //10 food elevator
        rooms.push_back(new Room("The small elevator is just big enough for you to fit.\n"
                                         "The light is bussing. There is a button.\n"));

        //11 basement
        rooms.push_back(new Room("It stopped in a mouldy basement. It's dark and you can't see very well.\n"));

        //12 basement dark
        rooms.push_back(new Room("Your hands meet a cold copper doorknob. It appears to be locked\n"));

        //13 light switch
        rooms.push_back(new Room("You find a light switch.\n"));

        //14 basement lit
        rooms.push_back(new Room("You turn the light on and look around the room.\n"
                                         "You see a loose brick sticking out of the wall.\n"));
        //15 tunnel opening
        rooms.push_back(new Room("The brick slights in and the wall opens\n"
                                         "A dark tunnel appears\n"));
        //16
        rooms.push_back(new Room("Torches turn on and a beautifull library appears.\n"
                                         "There is a big book on a table and another book hanging out of a bookcase\n"));
        //17
        rooms.push_back(new Room("You open the book and start reading the first page.\n"
                                         "The book is the book of revelations.\n"
                                         "It speaks of the and of days and a witness of the end times.\n"
                                         "A witness that is destined to either save the world or destroy it.\n"
                                         "In the book there is a not saying that you are are the witness and the end of days begins today.\n"
                                         "The note also says that the fate of the world rests upon your shoulders. No pressure.\n"));
        //18
        rooms.push_back(new Room("There is just one book standing in the bookcase. You wonder how it keeps standing\n"
                                         "As you try to pull it out, the bookcase starts sliding to the right, revealing another tunnel.\n"
                                         "You wonder who took the time to implement such easy and difficult to implement contraptions instead of you know, using keys.\n"));
        //19
        rooms.push_back(new Room("numbering error\n"));
        //20
        rooms.push_back(new Room("On the side of the tunnel is a picture of you.\n"
                                         "In one hand your a holding an angel. In the other you are holding a demon.\n"
                                         "The fate of the world is really in your hands.\n"
                                         "Also, the nose is painted a bit too big.\n"));
        //21 //TODO add a flashlight object in the coffin
        rooms.push_back(new Room("You arrive in a thomb.\n"
                                         "There is a beautifull marble coffin in the middle.\n"
                                         "In the marble there is some engraved text :\n"
                                         "\"Here lise the witness\"\n"
                                         "There is a tunnel on the other side of the coffin\n"));

        //22 TODO add in a fight against dracula
        rooms.push_back(new Room("The tunnel ends in a cold and dark room\n"
                                         "In the corner of the room there is a hole in the ground.\n"));

        //23
        rooms.push_back(new Room("A person is standing in the middle of the room.\n"));

        //24 TODO implement death
        rooms.push_back(new Room("The person was a black eyed being. A creature of evil.\n"
                                         "Because you came closer in a friendly manner, the creature was able to take a swing at you.\n"
                                         "You feel his abnormal long nails slice your neck. You DIED."));

        //25
        rooms.push_back(new Room("numbering error\n"));

        //26
        rooms.push_back(new Room("As you enter the room, a angel comes to you.\n"));

        //27 TODO start combat
        rooms.push_back(new Room("Only a sinning human refuses to do what i want.\n"));

        //28
        rooms.push_back(new Room("A witness! It is so nice to meet you!\n"
                                         "My name is orion.\n"
                                         "What are you doing here?\n"));

        //29
        rooms.push_back(new Room("Maybe we can join join forces.\n"
                                         "I'm looking to purify the world of all sin. What do you think?\n"));

        //30
        rooms.push_back(new Room("Ok, if that is what you think\n"
                                         "As the angel flies away, the grounds breaks open to form a cliff. \n"
                                         "A rope hanging on the side falls down, and now hangs down the cliff.\n"));

        //31 TODO add the monster conquest
        rooms.push_back(new Room("As you are rapelling down the rope, you come in a new room.\n"
                                         "Here you encounter Conquest. He's the first horseman of the apocalypse.\n"
                                         "They are here to set a divine apocalypse upon the world.\n"
                                         "\n"
                                         "There is a window in the room. You don't understand how there can be, because you are so deep underground, but you just go with it \n"));

        //32 TODO add zombies
        rooms.push_back(new Room("Behind the window is a room filled with zombies.\n"
                                         "You can either face them all and fight your way trough or you can sneak to the other side.\n"));

        //33 TODO add zombies
        rooms.push_back(new Room("You sneak across the room, and just before you reach the other side, you trip over your shoe laces.\n"
                                         "The zombies notice, and attack you. You need to defeat them to get to the door on the other side of the room.\n"));

        //34 TODO add monster wendigo
        rooms.push_back(new Room("A wendigo appears. This evil creature wants to possess you to ensure the apocalypse happens.\n"
                                         "Behind the Wendigo is a climable wall.\n"));

        //35 TODO add War
        rooms.push_back(new Room("On top is the second horseman of the apocalypse. His name is War.\n"
                                         "He wants for all people to start killing each other.\n"
                                         "\nBehind the horseman is a crack in the wall.\n"));

        //36 TODO add Ortheos
        rooms.push_back(new Room("Behind the crack is a street-like place. It is filled with bones.\n"
                                         "A dog starst running towards you. This however is no normal dog. This is Ortheos! A two headed dog.\n"
                                         "\n Once Ortheos is dead, you will be able to walk down the street\n"));

        //37 TODO add cyclops
        rooms.push_back(new Room("As you continue down the street, the bones continue. Some bones have roman armor, some medieval. The latest of combat gear you see are nazi uniforms.\n"
                                         "You encounter a cyclops. He's huge, but only has one eye. He attacks you with the intint to eat you.\n"
                                         "\n"
                                         "There is a hole in the street that you can jump into.\n"));

        //38 TODO add Famine
        rooms.push_back(new Room("This room is filled with rotten fruit. The third horseman of the apocalypse appears in front of you.\n"
                                         "\n"
                                         "Behind the horseman, between the mountains of rotten food, there is a tiny door.\n"));

        //39
        rooms.push_back(new Room("As you have clammed yourself trought the little door, you see the grim reaper. He speaks to you :\n"
                                         "\"Congratulations on getting this far. As a present, i give you the chance to save a life.\n"
                                         "Behind me are two cages, each with a living being, you can save one of them.\"\n"
                                         "\n"
                                         "You see two cages, one with a baby, and one with a puppy.\n"));

        //40
        rooms.push_back(new Room("As you go and open the cage with a baby in it, you hear the puppy make a high pitched sound, and then just fall dead.\n"
                                         "The baby smiles as you pick it up, then it slowly fades back to the real world. \n"
                                         "The only thing left in your hands, is a name tag. It says Adolf Hitler.\n"
                                         "A hole in the wall appears.\n"));

        //41 TODO add dog
        rooms.push_back(new Room("As you go and open the cage with a pupy in it, you hear the baby cry, and then just fall dead.\n"
                                         "As you look back at the puppy, there is no puppy anymore, there is a big evil dog that attacks you.\n"
                                         "\n A hole in the wall appears."));

        //42 TODO add hydra
        rooms.push_back(new Room("The next room smells weird. There is a rare skinn lying around and a weird staircase going up.\n"));

        //43 TODO add death
        rooms.push_back(new Room("As you climb up the staircase, you notice there is a room before the staircase continues.\n"
                                         "The last of the 4 horsemen of the apocalypse, Death itself stands before you. \n"
                                         "He wants to take your life and the life of evryone that doesn't believe in God.\n"));

        //44 todo add ghosts
        rooms.push_back(new Room("The stairs end, and a door appears. As you open the door, an overwhelming amound of screaming is heard.\n"
                                         "You see a giant field filled with 140 000 ghosts that the horsemen killed, but weren't allowed to continue to judgment.\n"
                                         "One ghost sees you, and approaches.\n"
                                         "\n"
                                         "When you killed him, you see another door seemingly just standing in the field."));

        //45
        rooms.push_back(new Room("As you enter trough the door, you reach a stone room.\n"
                                         "In the middle there is a flower pot with only dirt in it. It stands one a stone pillar \n"
                                         "There is a rhyme on the pillar, and a pot of water next to the pillar.\n"));

        //46
        rooms.push_back(new Room("I was angry with my friend. I told my wrath, my wrath did end.\n"
                                         "I was angry with my foe. I told him not, my wrath did grow.\n"
                                         "\n"
                                         "And I watered it in fears, night and day with my TEARS.\n"
                                         "And i sunned it with smiles, soft, deceitfull smiles.\n"
                                         "\n"
                                         "And it grew both day and night, untill it bore an apple bright.\n"
                                         "And my foe behold it shine. And he knew that it was mine.\n"
                                         "\n"
                                         "And into my graden stole, where the neight had veiled the pole.\n"
                                         "In the morning glad I see, My foe atstreched beneath the tree\n"));

        //47
        rooms.push_back(new Room("The plant grows and bares an apple. A staircase in the ground opens up\n"));

        //48 todo add imp
        rooms.push_back(new Room("The earth starts to rumble and the structural integrety of the staircase begins to degrade.\n"
                                         "Seemingly appearing out of nowhere, a small creature starts pointing and laughing. It's an imp. It caused the earthquake just as a prank \n"
                                         "There is a rhyme on the pillar, and a pot of water next to the pillar.\n"
                                         "\n"
                                         "At the buttom of the staircase there is a doorway."));

        //49
        rooms.push_back(new Room("When you go trough the doorway, a fairy starts talking to you :\n"
                                         "\"Hello traveller, who are you?\"\n"));

        //50
        rooms.push_back(new Room("\" You're the witness? Its an absolute honor to meet you!\n"
                                         "What are you doing here, if i may ask?\"\n"));

        //51
        rooms.push_back(new Room("\"Can you do me a favor?\"\n"));

        //52
        rooms.push_back(new Room("\"Can you give this to my best, best friend please? \n"
                                         "You'll know who he is once you meet him.\"\n"));

        //53
        rooms.push_back(new Room("There is a big door with the text :\n"
                                         "\"Let the 7 trumper judgements begin !\"\n"));

        //54 todo add dragon
        rooms.push_back(new Room("The first trumpet is the one of Hail, fire and blood.\n"
                                         "To beat this trumpet, you must defeat the dragon inside this room.\n"
                                         "\n"
                                         "The next trumpet is trough the next door\n"));

        //55 todo add typhon
        rooms.push_back(new Room("The second trumpet is the one of a vulcano.\n"
                                         "The monster that you must defeat is Typhon (A fire-breathing titan).\n"
                                         "\n"
                                         "The next trumpet is trough the next door\n"));

        //56 todo add new jersey devil
        rooms.push_back(new Room("The third trumpet is the one of Meteorites.\n"
                                         "To beat this trumpet, you must dodge it fast airstrikes.\n"
                                         "\n"
                                         "The next trumpet is trough the next door\n"));

        //57 todo add dragon
        rooms.push_back(new Room("The fourth trumpet is the one of Darkness that falls.\n"
                                         "To beat this trumpet, you must defeat a ghost.\n"
                                         "\n"
                                         "The next trumpet is trough the next door\n"));

        //58 todo add satan as enemy
        rooms.push_back(new Room("The fifth trumpet is the one of a buttemless pit.\n"
                                         "God gives the keys of the buttomless pit to satan.\n"
                                         "Satan wants to open the abyss to let the demons come.\n"
                                         "The next trumpet is trough the next door\n"));

        //59 todo add Chimera, Demon and ogre
        rooms.push_back(new Room("Four angels are leading an army of 200 horsemen to kill all the unbelievers that are still remaining\n"
                                         "\n"
                                         "The final gate is in front of you. It's made of gold\n"));

        //60
        rooms.push_back(new Room("As you want to open the gate, you suddenly find yourself binded by magic. \n"
                                         "There are multiple angels, all speaking the very same things at the same time.\n"
                                         "They all ask at the same time :\n"
                                         "\"Did you meet the good fairy?\"\n"));

        //61
        rooms.push_back(new Room("\"Did she give you something?\"\n"));

        //62
        rooms.push_back(new Room("\"Give it to us!\"\n"));
        //63
        rooms.push_back(new Room("\"Give it to us!\"\n"));
        //64
        rooms.push_back(new Room("\"Give it to us!\"\n"));

        //65
        rooms.push_back(new Room("You get rescued by the good fairy.\n"
                                         "Out of gratitude she gives you a glass bowl with a flame inside.\n"));
        //66
        rooms.push_back(new Room("Congratulations" "\n"
                                         "You have reached the kingdom of christ and saved the world.\n"
                                         "Jezus comes to you, and asks :\n"
                                         "\"Can i please have the glass bowl with the burning flame.\"\n"));

        //67
        rooms.push_back(new Room("A bright light appears. \n"
                                         "Suddenly you notice the bright light is light of your home hallway.\n"
                                         "You look at the time and notice only one minute has passed since you entered that home. You wonder how that is possible.\n"
                                         "YOU HAVE WON!\n"));

        //68 todo implement death
        rooms.push_back(new Room("\"You dare lie to an angel?\"\n"
                                         "YOU DIED\n"));

        //69
        rooms.push_back(new Room("\"Are you lying?\"\n"));

        //70 todo implement death
        rooms.push_back(new Room("After giving it to them, they still kill because they know about the dead hooker in your basement.\n"
                                         "YOU DIED\n"));

        //71 todo implement death
        rooms.push_back(new Room("Jezus says you are selfish, and the flame in the bowl suddenly encompasses the whole room. You are burnt alive.\n"
                                         "YOU DIED\n"));

        //72 todo implement death
        rooms.push_back(new Room("\"You dare lie to an angel?\"\n"
                                         "YOU DIED\n"));

        //73
        rooms.push_back(new Room("\"Are you lying?\"\n"));

        //74
        rooms.push_back(new Room("\"Did she give you something?\"\n"));

        //75
        rooms.push_back(new Room("\"Are you lying?\"\n"));

        //76 todo implement death
        rooms.push_back(new Room("\"You dare lie to an angel?\"\n"
                                         "YOU DIED\n"));

        return rooms;
    }

    std::vector<Connection *> getConnections(std::vector<Room *> rooms){
        std::vector<Connection *> connections;
        //0 TODO implement death
        connections.push_back(new Connection(rooms[1], "You died", "death", rooms[0], "The forest path home",
                                             "home"));
        //1
        connections.push_back(new Connection(rooms[2], "The path towards the forest you came from", "forest", rooms[0], "The path towards the house",
                                             "house"));
        //2
        connections.push_back(new Connection(rooms[2], "There seems to be a little pathway around the house", "search", rooms[3], "The little pathway towards the front door",
                                             "back"));
        //3
        connections.push_back(new Connection(rooms[3], "Enter the kitchen", "kitchen", rooms[4], "unaviable",
                                             "back"));
        //4
        connections.push_back(new Connection(rooms[4], "There is a door in the corner", "door", rooms[5], "Go back to the kitchen",
                                             "kitchen"));
        //5
        connections.push_back(new Connection(rooms[5], "Go to the hallway", "hallway", rooms[6], "go back to the living room",
                                             "back"));
        //6
        connections.push_back(new Connection(rooms[6], "Go up the stairs", "upstairs", rooms[7], "go back downstairs",
                                             "downstairs"));
        //7
        connections.push_back(new Connection(rooms[7], "Try the doors", "doors", rooms[8], "go back to the stairs",
                                             "stairs"));
        //8
        connections.push_back(new Connection(rooms[6], "Try the doors", "doors", rooms[8], "go back to the stairs",
                                             "stairs"));
        //9
        connections.push_back(new Connection(rooms[7], "Try to cramp yourself in the food elevator", "elevator", rooms[10], "go back to the stairs",
                                             "stairs"));
        //10
        connections.push_back(new Connection(rooms[10], "Press the button to go down", "basement", rooms[11], "Press the button again",
                                             "button"));
        //11
        connections.push_back(new Connection(rooms[11], "Look for a door", "door", rooms[12], "Press the button again",
                                             "button"));
        //12
        connections.push_back(new Connection(rooms[11], "Look for a light switch", "switch", rooms[13], "Press the button again",
                                             "button"));
        //13
        connections.push_back(new Connection(rooms[12], "Look for a light switch", "switch", rooms[13], "Press the button again",
                                             "button"));
        //14
        connections.push_back(new Connection(rooms[13], "Flick the switch", "switch", rooms[14], "Press the button again",
                                             "button"));
        //15 TODO maybe make a monster appear that you have to fight
        connections.push_back(new Connection(rooms[14], "pull the brick", "pull", rooms[14], "Press the button again",
                                             "button"));
        //16
        connections.push_back(new Connection(rooms[14], "push the brick", "push", rooms[15], "Press the button again",
                                             "button"));
        //17
        connections.push_back(new Connection(rooms[15], "go into the tunnel", "tunnel", rooms[16], "Go back",
                                             "back"));
        //18
        connections.push_back(new Connection(rooms[16], "go to the book on the table", "table", rooms[17], "Go back",
                                             "back"));
        //19
        connections.push_back(new Connection(rooms[17], "go to the book in the bookcase", "bookcase", rooms[18], "Go back to the book on the table",
                                             "table"));
        //20
        connections.push_back(new Connection(rooms[16], "go to the book in the bookcase", "bookcase", rooms[18], "Go back",
                                             "back"));
        //21
        connections.push_back(new Connection(rooms[18], "go into the tunnel", "tunnel", rooms[20], "Go back",
                                             "back"));
        //22
        connections.push_back(new Connection(rooms[20], "go further into the tunnel", "further", rooms[21], "Go back",
                                             "back"));
        //23
        connections.push_back(new Connection(rooms[21], "go into the tunnel", "tunnel", rooms[22], "Go back",
                                             "back"));
        //24
        connections.push_back(new Connection(rooms[22], "go into the hole", "tunnel", rooms[23], "Go back",
                                             "back"));

        //25
        connections.push_back(new Connection(rooms[22], "go talk to the person", "tunnel", rooms[24], "Go back",
                                             "back"));

        //26 todo disable this from happening when the monster isn't dead
        connections.push_back(new Connection(rooms[22], "go further", "further", rooms[26], "Go back",
                                             "back"));
        //27
        connections.push_back(new Connection(rooms[26], "go the hostile approach", "hostile", rooms[27], "Go back",
                                             "back"));

        //28
        connections.push_back(new Connection(rooms[26], "Tell him that you are the witness", "friendly", rooms[28], "Go back",
                                             "back"));

        //29
        connections.push_back(new Connection(rooms[28], "Tell him you're here to save the world", "friendly", rooms[29], "Go back",
                                             "back"));

        //30
        connections.push_back(new Connection(rooms[29], "Decline his offer", "decline", rooms[30], "Go back",
                                             "back"));

        //31
        connections.push_back(new Connection(rooms[30], "go down the rope", "rope", rooms[31], "Go up the rope",
                                             "rope"));
        //32
        connections.push_back(new Connection(rooms[31], "go trough the window", "window", rooms[32], "Go back",
                                             "back"));
        //33
        connections.push_back(new Connection(rooms[32], "go sneak", "sneak", rooms[33], "Go back",
                                             "back"));
        //34 todo only enable this when all monsters are dead
        connections.push_back(new Connection(rooms[32], "just continue to the door", "door", rooms[34], "Go back",
                                             "back"));
        //35
        connections.push_back(new Connection(rooms[33], "just continue to the door", "door", rooms[34], "Go back",
                                             "back"));
        //36
        connections.push_back(new Connection(rooms[34], "Climb the wall", "climb", rooms[35], "Go back",
                                             "back"));
        //37
        connections.push_back(new Connection(rooms[35], "Go trough the crack", "crack", rooms[36], "Go back",
                                             "back"));
        //38
        connections.push_back(new Connection(rooms[36], "continue walking the street", "street", rooms[37], "Go back",
                                             "back"));
        //39
        connections.push_back(new Connection(rooms[37], "jump into the hole", "hole", rooms[38], "Go back",
                                             "back"));
        //40
        connections.push_back(new Connection(rooms[38], "Go trough the tiny door", "door", rooms[39], "Go back",
                                             "back"));
        //41
        connections.push_back(new Connection(rooms[39], "Rescue the Baby", "baby", rooms[40], "Go back",
                                             "back"));
        //42
        connections.push_back(new Connection(rooms[39], "Rescue the puppy", "puppy", rooms[41], "Go back",
                                             "back"));
        //43
        connections.push_back(new Connection(rooms[40], "Go trough the hole", "hole", rooms[42], "Go back",
                                             "back"));
        //44
        connections.push_back(new Connection(rooms[41], "Go trough the hole", "hole", rooms[42], "Go back",
                                             "back"));
        //45
        connections.push_back(new Connection(rooms[42], "Go up the stairs", "stairs", rooms[43], "Go back",
                                             "back"));
        //46
        connections.push_back(new Connection(rooms[43], "Continue", "further", rooms[44], "Go back",
                                             "back"));
        //47
        connections.push_back(new Connection(rooms[44], "Go to the door", "door", rooms[45], "Go back",
                                             "back"));
        //48
        connections.push_back(new Connection(rooms[45], "Go and read the poem", "read", rooms[46], "Go back",
                                             "back"));
        //49
        connections.push_back(new Connection(rooms[46], "Cry on the plant", "cry", rooms[47], "Go back",
                                             "back"));
        //50
        connections.push_back(new Connection(rooms[47], "Go down the stairs", "stairs", rooms[48], "Go back up the stairs",
                                             "stairs"));
        //51
        connections.push_back(new Connection(rooms[48], "Go to the door", "door", rooms[49], "Go back",
                                             "back"));
        //52
        connections.push_back(new Connection(rooms[49], "Explain that you are the witness", "explain", rooms[50], "Go back",
                                             "back"));
        //53
        connections.push_back(new Connection(rooms[50], "Tell it that you are here to battle evil", "tell", rooms[51], "Go back",
                                             "back"));
        //54
        connections.push_back(new Connection(rooms[51], "Accept do it a favor", "accept", rooms[52], "Go back",
                                             "back"));
        //55
        connections.push_back(new Connection(rooms[52], "Agree to give it to him", "agree", rooms[53], "Go back",
                                             "back"));
        //56
        connections.push_back(new Connection(rooms[53], "Go to the door", "door", rooms[54], "Go back",
                                             "back"));
        //57
        connections.push_back(new Connection(rooms[54], "Go to the door", "door", rooms[55], "Go back",
                                             "back"));
        //58
        connections.push_back(new Connection(rooms[55], "Go to the door", "door", rooms[56], "Go back",
                                             "back"));
        //59
        connections.push_back(new Connection(rooms[56], "Go to the door", "door", rooms[57], "Go back",
                                             "back"));
        //60
        connections.push_back(new Connection(rooms[57], "Go to the door", "door", rooms[58], "Go back",
                                             "back"));
        //61
        connections.push_back(new Connection(rooms[58], "Go to the door", "door", rooms[59], "Go back",
                                             "back"));
        //62
        connections.push_back(new Connection(rooms[59], "Go to the golden gate", "gate", rooms[60], "Go back",
                                             "back"));
        //63
        connections.push_back(new Connection(rooms[60], "Answer positive", "yes", rooms[61], "Go back",
                                             "back"));
        //64
        connections.push_back(new Connection(rooms[61], "Answer positive", "yes", rooms[62], "Go back",
                                             "back"));
        //65
        connections.push_back(new Connection(rooms[62], "Answer negative", "no", rooms[63], "Go back",
                                             "back"));
        //66
        connections.push_back(new Connection(rooms[63], "Answer negative", "no", rooms[64], "Go back",
                                             "back"));
        //67
        connections.push_back(new Connection(rooms[64], "Answer negative", "no", rooms[65], "Go back",
                                             "back"));
        //68
        connections.push_back(new Connection(rooms[65], "Go to the final gate", "gate", rooms[66], "Go back",
                                             "back"));
        //69
        connections.push_back(new Connection(rooms[66], "Give it to him", "give", rooms[67], "Go back",
                                             "back"));
        //70
        connections.push_back(new Connection(rooms[66], "Don't give it to him", "keep", rooms[68], "Go back",
                                             "back"));
        //71
        connections.push_back(new Connection(rooms[62], "Answer positive", "yes", rooms[70], "Go back",
                                             "back"));
        //72
        connections.push_back(new Connection(rooms[63], "Answer positive", "yes", rooms[70], "Go back",
                                             "back"));
        //73
        connections.push_back(new Connection(rooms[64], "Answer positive", "yes", rooms[70], "Go back",
                                             "back"));
        return connections;
    }

    void addConnectionsToRooms(std::vector<Room *> rooms, std::vector<Connection *> connections){

        //the street
        rooms[0]->addConnection(connections[0]);
        rooms[0]->addConnection(connections[1]);
        //the house
        rooms[2]->addConnection(connections[1]);
        rooms[2]->addConnection(connections[2]);
        //the search
        rooms[3]->addConnection(connections[2]);
        rooms[3]->addConnection(connections[3]);
        // the kitchen
        rooms[4]->addConnection(connections[4]);
        // the living room
        rooms[5]->addConnection(connections[4]);
        rooms[5]->addConnection(connections[5]);
        // the hallway
        rooms[6]->addConnection(connections[5]);
        rooms[6]->addConnection(connections[6]);
        // the upstairs
        rooms[7]->addConnection(connections[6]);
        rooms[7]->addConnection(connections[7]);
        rooms[7]->addConnection(connections[9]);
        // the childrens bedroom
        rooms[8]->addConnection(connections[7]);
        // the food elevator
        rooms[10]->addConnection(connections[9]);
        rooms[10]->addConnection(connections[10]);
        // the basement
        rooms[11]->addConnection(connections[10]);
        rooms[11]->addConnection(connections[11]);
        rooms[11]->addConnection(connections[12]);
        // the basement dark
        rooms[12]->addConnection(connections[13]);
        // the basement lighted
        rooms[13]->addConnection(connections[14]);
        rooms[14]->addConnection(connections[15]);
        rooms[14]->addConnection(connections[16]);
        // a dark tunnel
        rooms[15]->addConnection(connections[16]);
        rooms[15]->addConnection(connections[17]);

        rooms[16]->addConnection(connections[17]);
        rooms[16]->addConnection(connections[18]);
        rooms[16]->addConnection(connections[20]);

        rooms[17]->addConnection(connections[18]);
        rooms[17]->addConnection(connections[19]);

        rooms[18]->addConnection(connections[19]);
        rooms[18]->addConnection(connections[20]);
        rooms[18]->addConnection(connections[21]);

        rooms[20]->addConnection(connections[21]);
        rooms[20]->addConnection(connections[22]);

        rooms[21]->addConnection(connections[22]);
        rooms[21]->addConnection(connections[23]);

        rooms[22]->addConnection(connections[23]);
        rooms[22]->addConnection(connections[25]);
        rooms[22]->addConnection(connections[26]);

        rooms[24]->addConnection(connections[25]);

        rooms[26]->addConnection(connections[26]);
        rooms[26]->addConnection(connections[27]);
        rooms[26]->addConnection(connections[28]);

        rooms[28]->addConnection(connections[29]);
        rooms[29]->addConnection(connections[30]);

        rooms[30]->addConnection(connections[31]);

        rooms[31]->addConnection(connections[31]);
        rooms[31]->addConnection(connections[32]);

        rooms[32]->addConnection(connections[32]);
        rooms[32]->addConnection(connections[33]);
        rooms[32]->addConnection(connections[34]);

        rooms[33]->addConnection(connections[35]);

        rooms[34]->addConnection(connections[36]);

        rooms[35]->addConnection(connections[36]);
        rooms[35]->addConnection(connections[37]);

        rooms[36]->addConnection(connections[37]);
        rooms[36]->addConnection(connections[38]);

        rooms[37]->addConnection(connections[38]);
        rooms[37]->addConnection(connections[39]);

        rooms[38]->addConnection(connections[39]);
        rooms[38]->addConnection(connections[40]);

        rooms[39]->addConnection(connections[40]);
        rooms[39]->addConnection(connections[41]);
        rooms[39]->addConnection(connections[42]);

        rooms[40]->addConnection(connections[43]);

        rooms[41]->addConnection(connections[44]);

        rooms[42]->addConnection(connections[44]);
        rooms[42]->addConnection(connections[45]);

        rooms[43]->addConnection(connections[45]);
        rooms[43]->addConnection(connections[46]);

        rooms[44]->addConnection(connections[46]);
        rooms[44]->addConnection(connections[47]);

        rooms[45]->addConnection(connections[47]);
        rooms[45]->addConnection(connections[47]);

        rooms[46]->addConnection(connections[48]);
        rooms[46]->addConnection(connections[49]);

        rooms[47]->addConnection(connections[49]);
        rooms[47]->addConnection(connections[50]);

        rooms[48]->addConnection(connections[50]);
        rooms[48]->addConnection(connections[51]);

        rooms[49]->addConnection(connections[51]);
        rooms[49]->addConnection(connections[52]);

        rooms[50]->addConnection(connections[53]);

        rooms[51]->addConnection(connections[54]);

        rooms[52]->addConnection(connections[55]);

        rooms[53]->addConnection(connections[56]);

        rooms[54]->addConnection(connections[56]);
        rooms[54]->addConnection(connections[57]);

        rooms[55]->addConnection(connections[57]);
        rooms[55]->addConnection(connections[58]);

        rooms[56]->addConnection(connections[58]);
        rooms[56]->addConnection(connections[59]);

        rooms[57]->addConnection(connections[59]);
        rooms[57]->addConnection(connections[60]);

        rooms[58]->addConnection(connections[60]);
        rooms[58]->addConnection(connections[61]);

        rooms[59]->addConnection(connections[61]);
        rooms[59]->addConnection(connections[62]);

        rooms[60]->addConnection(connections[62]);
        rooms[60]->addConnection(connections[63]);

        rooms[61]->addConnection(connections[64]);

        rooms[62]->addConnection(connections[65]);
        rooms[62]->addConnection(connections[71]);

        rooms[63]->addConnection(connections[66]);
        rooms[63]->addConnection(connections[72]);

        rooms[64]->addConnection(connections[67]);
        rooms[64]->addConnection(connections[73]);

        rooms[65]->addConnection(connections[68]);

        rooms[66]->addConnection(connections[69]);
        rooms[66]->addConnection(connections[70]);
    }
