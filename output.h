#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <iostream>
using namespace std;

class Output {
public:
    Output();
    void outputTextToScreen(string text);
    void outputErrorToScreen(string text);
};

#endif // OUTPUT_H
