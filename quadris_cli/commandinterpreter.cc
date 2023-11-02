#include <string>
#include <sstream>

#include "commandinterpreter.h"

using namespace std;


CommandInterpreter::CommandInterpreter(): theCommand{""}, theFile{""}, theMultiplier{0}{}


CommandInterpreter::~CommandInterpreter(){}


string CommandInterpreter::getCommand() const{
    return theCommand;
}


string CommandInterpreter::getFile() const{
    return theFile;
}


int CommandInterpreter::getMultiplier() const{
    return theMultiplier;
}


bool CommandInterpreter::updateCommand(string newCommand){
    string potentialCommand;
    int potentialMultiplier;
    istringstream iss{newCommand};
    if (iss >> potentialMultiplier){
        if (potentialMultiplier < 0) potentialMultiplier *= -1;
        theMultiplier = potentialMultiplier;
        istringstream issCommand{newCommand};
    }
    else{
        theMultiplier = 1;
    }
    iss.clear();
    iss >> potentialCommand;
    theFile = "";
    if (potentialCommand.length() < 1){
        theCommand = "";
        return false;
    }
    if (potentialCommand.c_str()[0] == 'I'){
        theCommand = "I";
    }
    else if (potentialCommand.c_str()[0] == 'J'){
        theCommand = "J";
    }
    else if (potentialCommand.c_str()[0] == 'L'){
        theCommand = "L";
    }
    else if (potentialCommand.c_str()[0] == 'S'){
        theCommand = "S";
    }
    else if (potentialCommand.c_str()[0] == 'Z'){
        theCommand = "Z";
    }
    else if (potentialCommand.c_str()[0] == 'O'){
        theCommand = "O";
    }
    else if (potentialCommand.c_str()[0] == 'T'){
        theCommand = "T";
    }
    else if (potentialCommand.c_str()[0] == 'h'){
        theCommand = "Hint";
    }
    else if (potentialCommand.c_str()[0] == 's'){
        theCommand = "Sequence";
        iss >> theFile;
    }
    else if (potentialCommand.c_str()[0] == 'n'){
        theCommand = "NoRandom";
        iss >> theFile;
    }
    else if (potentialCommand.length() < 2){
        theCommand = newCommand;
    }
    else if (potentialCommand.substr(0, 2) == "ri\0"){
        theCommand = "Right";
    }
    else if (potentialCommand.substr(0, 2) == "ra\0"){
        theCommand = "Random";
    }
    else if (potentialCommand.substr(0, 2) == "re\0"){
        theCommand = "Restart";
    }
    else if (potentialCommand.substr(0, 2) == "do\0"){
        theCommand = "Down";
    }
    else if (potentialCommand.substr(0, 2) == "dr\0"){
        theCommand = "Drop";
    }
    else if (potentialCommand.substr(0, 2) == "cl\0"){
        theCommand = "ClockWise";
    }
    else if (potentialCommand.substr(0, 2) == "co\0"){
        theCommand = "CounterClockWise";
    }
    else if (potentialCommand.length() < 3){
        theCommand = newCommand;
    }
    else if (potentialCommand.substr(0, 3) == "lef\0"){
        theCommand = "Left";
    }
    else if (potentialCommand.length() < 6){
        theCommand = newCommand;
    }
    else if (potentialCommand.substr(0, 6) == "levelu\0"){
        theCommand = "LevelUp";
    }
    else if (potentialCommand.substr(0, 6) == "leveld\0"){
        theCommand = "LevelDown";
    }
    else{
        theCommand = newCommand;
    }
    return true;
}
