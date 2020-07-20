//
//  getch.cpp
//  GiT
//
//  Created by Jay Advani on 17/07/20.
//  Copyright © 2020 Jay Advani. All rights reserved.
//


#include <bits/stdc++.h>
using namespace std;

#include <termios.h>
#include <unistd.h>
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
