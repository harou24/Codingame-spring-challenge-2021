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

        Cell()
        {
            this->index = 0;
            this->richness = 0;
        }

        Cell(int index, int richness):index(index), richness(richness)
        {
            
        }
};

class Tree
{
    public:
        int index;
        int size;
        bool is_mine;
        bool is_dormant;

        Tree()
        {
            this->index = 0;
            this->size = 0;
            this->is_mine = false;
            this->is_dormant = false;
        }

        Tree(int index, int size, bool is_mine, bool is_dormant):index(index), size(size), is_mine(is_mine), is_dormant(is_dormant){}

        
};

class Move
{
    public:
        string action;

        Move(){}
        Move(string action):action(action){}
};

#define NB_CELL 37

class Game
{
    public:
        Cell *cells;
        Tree *trees;
        Move *moves;

        Game(Cell cells[NB_CELL], Tree trees[], Move moves[]):cells(cells), trees(trees), moves(moves){}


};

int main()
{
    int numberOfCells; // 37
    cin >> numberOfCells; cin.ignore();
    Cell cells[NB_CELL];

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
        cells[i] = Cell(index, richness);
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
        Tree trees[numberOfTrees];
        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
            trees[i] = Tree(cellIndex, size, isMine, isDormant);
        }
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves; cin.ignore();
        Move moves[numberOfPossibleMoves];
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string possibleMove;
            getline(cin, possibleMove);
            cerr << "Action -> " << possibleMove << endl;
            moves[i] = Move(possibleMove);
        }
        Game g = Game(cells, trees, moves);
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        if (numberOfPossibleMoves > 1)
            cout << g.moves[1].action << endl;
        else
            cout << "WAIT" << endl;

    }
}
