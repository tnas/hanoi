#ifndef TOWERHANOI_H
#define TOWERHANOI_H

#include "../LStack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class TowerHanoi
{
    const unsigned int MAX_DISC_CRT = 11;
    LStack<string> rod[4];

    public:
        TowerHanoi(int numberOfDiscs);
        ~TowerHanoi();
        void move(int from, int to);
        bool checkWin();
        friend ostream& operator<<(ostream& os, TowerHanoi& tower);

    protected:

    private:
        int numberOfDiscs;
};



#endif // TOWERHANOI_H
