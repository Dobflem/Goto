#include "output.h"

#include <string>
#include <iostream>

Output::Output(){    
}

void Output::outputTextToScreen(string text) {
    cout << text << endl;
}

void Output::outputErrorToScreen(string text) {
    cout << text << endl;
}
