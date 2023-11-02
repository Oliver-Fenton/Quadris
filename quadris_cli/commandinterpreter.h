#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>


class CommandInterpreter{
    std::string theCommand;
    std::string theFile;
    int theMultiplier;
public:
    CommandInterpreter();
    ~CommandInterpreter();
    std::string getCommand() const;
    std::string getFile() const;
    int getMultiplier() const;
    bool updateCommand(std::string newCommand);
};


#endif
