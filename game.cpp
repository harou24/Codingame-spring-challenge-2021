#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Cell
{
    public:
        int index;
        int richness;
        int neigh0;
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        bool is_tree;
        bool is_shadow;
        bool is_hit_by_sun;

        Cell(){}
        Cell(int i, int rich, int n0, int n1, int n2, int n3, int n4, int n5)
        {
            this->index = i;
            this->richness = rich;
            this->neigh0 = n0;
            this->neigh1 = n1;
            this->neigh2 = n2;
            this->neigh3 = n3;
            this->neigh4 = n4;
            this->neigh5 = n5;
        }
};

class Tree
{
    public:
        int cellIndex;
        int size;
        bool isMine;
        bool isDormant;

        Tree(){}
        Tree(int i, int size, bool is_m, bool is_d)
        {
            this->cellIndex = i;
            this->size =size;
            this->isMine = is_m;
            this->isDormant = is_d;
        }
};

class Action
{
    public:
        string command;

    Action(){}
    Action(string cmd):command(cmd){}
};

class Game
{
    int sun;
    int day;
    int sun_dir;
    int nutrients;
    int nb_trees;
    int nb_trees_0;
    int nb_trees_1;
    int nb_trees_2;
    int nb_trees_3;

};

int main()
{
    int numberOfCells; // 37
    cin >> numberOfCells; cin.ignore();
    for (int i = 0; i < numberOfCells; i++) {
        int index; // 0 is the center cell, the next cells spiral outwards
        int richness; // 0 if the cell is unusable, 1-3 for usable cells
        int neigh0; // the index of the neighbouring cell for each direction
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
    }

    // game loop
    while (1) {
        int day; // the game lasts 24 days: 0-23
        cin >> day; cin.ignore();
        int nutrients; // the base score you gain from the next COMPLETE action
        cin >> nutrients; cin.ignore();
        int sun; // your sun points
        int score; // your current score
        cin >> sun >> score; cin.ignore();
        int oppSun; // opponent's sun points
        int oppScore; // opponent's score
        bool oppIsWaiting; // whether your opponent is asleep until the next day
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        int numberOfTrees; // the current amount of trees
        cin >> numberOfTrees; cin.ignore();
        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
        }
        int numberOfPossibleActions; // all legal actions
        cin >> numberOfPossibleActions; cin.ignore();
        for (int i = 0; i < numberOfPossibleActions; i++) {
            string possibleAction;
            getline(cin, possibleAction); // try printing something from here to start with
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        cout << "WAIT" << endl;
    }
}
