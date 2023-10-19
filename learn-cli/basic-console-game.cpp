// basic-console-game.cpp
// Created by: Icko Iben
// Referenced from: https://www.youtube.com/watch?v=cWc0hgYwZyc
// All code is run on windows, maybe not compatible on mac

#include <iostream>
using namespace std;

#include "olcConsoleGameEngine.h"




/*
int main(int argc, char *argv[]) {
    // Initial Variable Declaration
    // Essentially treats the console as a 2-D array of pixels
    wchar_t *screen = new wchar_t[80*30];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ*//*smth else, was cut
                                                              off*//*);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // Add a `while true` loop to represent a game loop
    while(1) {
        screen [10 * 80 + 15] = L'P';

        // Update the screen
        WriteConsoleOutputCharacter(hConsole, screen, nScreen, *//*cut off*//*);
    }

    return 0;
}
*/
