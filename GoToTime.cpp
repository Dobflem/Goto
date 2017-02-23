// StdIncludes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
// QIncludes
#include <QApplication>
#include <QString>

#include "GoToTime.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow *m = new MainWindow();

    //createTimezones();

    m->show();
    return app.exec();
}

/*void GoToTime::createTimezones()  {
    Timezone *tzTimePortal, *tz20s, *tz30s, *tz40s, *tz50s, *tz60s, *tz70s, *tz80s, *tz90s, *tz00s, *tzPresentDay;

    tzTimePortal = new Timezone("Time-Portal", "portal.jpg");
    tz20s = new Timezone("Twenties", "twenties.jpg");
    tz30s = new Timezone("Thirties", "thirties.jpg");
    tz40s = new Timezone("Fourties", "fourties.jpg");
    tz50s = new Timezone("Fifties", "fifties.jpg");
    tz60s = new Timezone("Sixties", "sixties.png");
    tz70s = new Timezone("Seventies", "seventies.jpg");
    tz80s = new Timezone("Eighties", "eighties.jpg");
    tz90s = new Timezone("Nineties", "nineties.jpg");
    tz00s = new Timezone("Noughties", "noughties.jpg");
    tzPresentDay = new Timezone("Present Day", "today.jpg");

    // (N, E, S, W)
    tzTimePortal->setExits(tz60s, tz20s, tz80s, tz00s);
    tz20s->setExits(tz30s, NULL, tz40s, tzTimePortal);
    tz30s->setExits(tz50s, NULL, tz20s, NULL);
    tz40s->setExits(tz20s, NULL, NULL, NULL);
    tz50s->setExits(NULL, NULL, tz30s, NULL);
    tz60s->setExits(tz70s, NULL, tzTimePortal, NULL);
    tz70s->setExits(NULL, NULL, tz60s, tz90s);
    tz80s->setExits(tzTimePortal, NULL, NULL, NULL);
    tz90s->setExits(NULL, tz70s, NULL, NULL);
    tz00s->setExits(NULL, tzTimePortal, tzPresentDay, NULL);
    tzPresentDay->setExits(tz00s, NULL, NULL, NULL);

   // currentTimezone = tzTimePortal;
}*/

/**
 *  Main play routine.  Loops until end of play.
 */
/*void GoToTime::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
    writer.outputTextToScreen("\n\nGame Over");
}

// To be deleted once GUI is implemented
void GoToTime::printWelcome() {
    writer.outputTextToScreen("Start:\n(Type 'info' for help)\n\n" + currentTimezone->longDescription());
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the GoToTime game, true is returned, otherwise false is
 * returned.
 */

/*bool GoToTime::processCommand(Command command) {
	if (command.isUnknown()) {
        writer.outputErrorToScreen("Invalid input");
		return false;
	}

	string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0) {
        printHelp();
    } else if (commandWord.compare("map") == 0) {
        printMap();
    } else if (commandWord.compare("go") == 0) {
        goTimezone(command);
    } else if (commandWord.compare("take") == 0) {
        processTakeCommand(command);
    } else if (commandWord.compare("put") == 0) {
        processPutCommand(command);
    } else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord()) {
            writer.outputTextToScreen("overdefined input");
        } else {
            return true; //signal to quit
        }
    }
	return false;
}*/


/** COMMANDS **/


/*void GoToTime::printHelp() {
    writer.outputTextToScreen("Valid inputs are:\n" + parser.showCommands());
}

void GoToTime::printMap() {
    writer.outputTextToScreen("[90s] --- [70s]    [50s] ");
    writer.outputTextToScreen("            |        |   ");
    writer.outputTextToScreen("            |        |   ");
    writer.outputTextToScreen("          [60s]    [30s] ");
    writer.outputTextToScreen("            |        |   ");
    writer.outputTextToScreen("            |        |   ");
    writer.outputTextToScreen("[00s] --- [TP] --- [20s] ");
    writer.outputTextToScreen(" |          |        |   ");
    writer.outputTextToScreen(" |          |        |   ");
    writer.outputTextToScreen("[PD]      [80s]    [40s] ");
}

void GoToTime::processTakeCommand(Command command) {
    //TODO

    //Zork Code
    /*if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
    } else {
        if (command.hasSecondWord()) {
            cout << "you're trying to take " + command.getSecondWord() << endl;
            int location = currentTimezone->isItemInTimezone(command.getSecondWord());
            if (location  < 0 ) {
                cout << "item is not in timezone" << endl;
            } else {
                cout << "item is in timezone" << endl;
                cout << "index number " << + location << endl;
                cout << endl;
                cout << currentTimezone->longDescription() << endl;
            }
        }
    }
}

void GoToTime::processPutCommand(Command command) {
    //TODO

    //Zork code
    /*if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
    } else
        if (command.hasSecondWord()) {
        cout << "you're adding " + command.getSecondWord() << endl;
        itemsInTimezone.push_Back;
    }

}

void GoToTime::goTimezone(Command command) {
    if (!command.hasSecondWord()) {
        writer.outputErrorToScreen("Incomplete input");
		return;
	}

	string direction = command.getSecondWord();

    // Try to leave current timezone.
    Timezone* nextTimezone = currentTimezone->nextTimezone(direction);

    if (nextTimezone == NULL)
         writer.outputErrorToScreen("Underdefined input");
	else {
        currentTimezone = nextTimezone;
        writer.outputTextToScreen("Successfully changed timezones.\n" + currentTimezone->longDescription());
	}
}

string GoToTime::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next Timezone
    Timezone* nextTimezone = currentTimezone->nextTimezone(direction);
    if (nextTimezone == NULL)
		return("direction null");
	else
	{
        currentTimezone = nextTimezone;
        return currentTimezone->longDescription();
	}
}*/
