#include "TowerHanoi.h"

const unsigned int MAX_DISC_CRT = 11;
const string EMPTY_DISC = string("           ");

TowerHanoi::TowerHanoi(int numberOfDiscs)
{
    this->numberOfDiscs = numberOfDiscs;
    vector<string> discs;
    vector<int> sizes;
    unsigned int discSize = 1;

    // Initializing the three rods
    rod[1] = LStack<string>();
    rod[2] = LStack<string>();
    rod[3] = LStack<string>();

    for (int disc = 0; disc < numberOfDiscs; ++disc)
    {
        stringstream sstream;

        unsigned int padding = (MAX_DISC_CRT - discSize)/2;

        for (unsigned int chrt = 0; chrt < padding; ++chrt)
        {
            sstream << " ";
        }

        sstream << " ";

        for (unsigned int chrt = 0; chrt < discSize; ++chrt)
        {
            sstream << "X";
        }

        for (unsigned int chrt = 0; chrt < padding; ++chrt)
        {
            sstream << " ";
        }

        discs.push_back(sstream.str());
        sizes.push_back(discSize);
        discSize += 2;
    }

    while (!discs.empty())
    {
        this->rod[1].push(discs.back());
        this->rod[1].setNodeSize(sizes.back());

        discs.pop_back();
        sizes.pop_back();
    }
}

TowerHanoi::~TowerHanoi()
{
    //dtor
}

void TowerHanoi::move(int from, int to)
{

    if (from == to)
    {
        cout << "Invalid movement: from/to rods cannot be equals." << endl;
    }
    else if (this->rod[from].isEmpty())
    {
        cout << "There are no disks in the rod " << from << endl;
    }
    else if (this->rod[to].isEmpty())
    {
        int sizeDisc = this->rod[from].getNodeSize();
        string disc = this->rod[from].pop();

        this->rod[to].push(disc);
        this->rod[to].setNodeSize(sizeDisc);
    }
    else
    {
        int fromSizeDisc = this->rod[from].getNodeSize();
        int toSizeDisc = this->rod[to].getNodeSize();

        if (fromSizeDisc > toSizeDisc)
        {
            cout << "Invalid movement: No disk may be placed on top of a smaller disk" << endl;
        }
        else
        {
            string disc = this->rod[from].pop();
            this->rod[to].push(disc);
            this->rod[to].setNodeSize(fromSizeDisc);
        }
    }
}

bool TowerHanoi::checkWin()
{
    return this->rod[3].getStackSize() == this->numberOfDiscs;
}

ostream& operator<<(ostream& os, TowerHanoi& tower)
{
    string disc = "";

    for (int level = tower.numberOfDiscs; level > 0 ; --level)
    {
        for (int n = 1; n <= 3; ++n)
        {
            disc = tower.rod[n].getNodeAt(level);
            os << (disc.empty() ? EMPTY_DISC : disc);
        }

        os << endl;
    }

    return os << "-------------------------------------" << endl
              << "      1           2           3      " << endl;
}
