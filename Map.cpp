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

    std::vector<Connection *> getConnections(){

    }