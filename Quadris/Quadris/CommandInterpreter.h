#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <iostream>
#include <map>
#include <vector>

//Handles input and exception safety for that input

//This basically to get input, then game takes that input
//and turns it into a call to Board

class CommandInterpreter {
public:

	//A list of commands
	//Each command is paivector<string>r composed of a commandCode and a list of the commandCode's arguments
	std::vector < std::pair < std::string, std::vector<std::string> > > nextInput();
	std::vector < std::pair < std::string, std::vector<std::string> > > nextInput(std::istream& in, char);
	CommandInterpreter(std::istream &);

private:
	std::istream& in; 

	//The command dictionary maps a user command as a key and 
	//the programCommand (or an array of program commands) as a value
	//The program command consists of the command itself and an array 
	//of arguments for the program command if it needs it. 
	//TODO: Use typedef for this long type name to make code more readable
	std::map<std::string, std::vector < std::pair < std::string, std::vector<std::string> > > > commandDictionary;
	std::vector<std::string> multiplierCompatibleCommands; 
	
	void initializeMap(); 
	
	//TODO: encapsulate all the info for parseMultiplier, special commands and program commands
	//in one data structure
	std::vector < std::pair < std::string, std::vector<std::string> > > findProgramCommands(std::string);
	std::vector < std::pair < std::string, std::vector<std::string> > > sequenceCommand(std::string);
	std::string parseMultiplier(std::string input, std::string& multiplier);
	
	bool isCommandMultiplierCompatible(std::string);
	bool partialMatch(std::string partial, std::string full);
	
};

#endif

