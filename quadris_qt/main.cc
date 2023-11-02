#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "quadris.h"

using namespace std;


int main(int argc, char *argv[]){
    string sequenceFile = "sequence.txt";
    int startLevel = 0;
    int seed = 1;
    for (int i = 1; i < argc; ++i){
        if (argv[i] == string("-seed")){
            if (i + 1 < argc){
                ++i;
                istringstream iss{argv[i]};
                int potentialSeed;
                if (iss >> potentialSeed){
                    if (potentialSeed < 0){
                        potentialSeed *= -1;
                    }
                    seed = potentialSeed;
                }
            }
        }
        else if (argv[i] == string("-scriptfile")){
            if (i + 1 < argc){
                ++i;
                sequenceFile = argv[i];
            }
        }
        else if (argv[i] == string("-startlevel")){
            if (i + 1 < argc){
                ++i;
                istringstream iss{argv[i]};
                int potentialLevel;
                if (iss >> potentialLevel){
                    if (potentialLevel > 0 && potentialLevel < 5){
                        startLevel = potentialLevel;
                    }
                }
            }
        }
    }
    srand(seed);
    Quadris theGame{cin, cout, sequenceFile, startLevel};
    theGame.playGame();
}
