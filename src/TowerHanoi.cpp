#include "TowerHanoi.h"

TowerHanoi::TowerHanoi(int numberOfDiscs)
{
    this->numberOfDiscs = numberOfDiscs;
    vector<string> discs;
    unsigned int discCharacters = 1;

    for (int disc = 0; disc < numberOfDiscs; ++disc)
    {
        stringstream sstream;

        unsigned int padding = (MAX_DISC_CRT - discCharacters)/2;

        for (unsigned int chrt = 0; chrt < padding; ++chrt)
        {
            sstream << " ";
        }

        sstream << " ";

        for (unsigned int chrt = 0; chrt < discCharacters; ++chrt)
        {
            sstream << "X";
        }

        for (unsigned int chrt = 0; chrt < padding; ++chrt)
        {
            sstream << " ";
        }

        discCharacters += 2;
        discs.push_back(sstream.str());
    }

    while (!discs.empty())
    {
        this->leftRod.push(discs.back());
        discs.pop_back();
    }
}

TowerHanoi::~TowerHanoi()
{
    //dtor
}

void TowerHanoi::move(int from, int to)
{

}

bool TowerHanoi::checkWin()
{
    return true;
}

ostream& operator<<(ostream& os, TowerHanoi& tower)
{
    return os << tower.leftRod.toString()
              << tower.centerRod.toString()
              << tower.rightRod.toString()
              << "---------------------------------" << endl
              << "      1          2          3    " << endl;
}
