#ifndef GOTOTIME_H_
#define GOTOTIME_H_

#include "Command.h"
#include "Parser.h"
#include "Timezone.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class GoToTime {
private:
	Parser parser;
    Timezone *currentTimezone;
    void createTimezones();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
    void printMap();
    void goTimezone(Command command);
    void processPutCommand(Command command);
    void processTakeCommand(Command command);
    void createItems();
    void displayItems();

public:
    GoToTime();
	void play();
	string go(string direction);
};

#endif /*GoToTime_H_*/
