#include "Difficulty.h"
#include "Game.h"
#include "Chessboard.h"
#include <iostream>
using namespace std;

int main()
{
    cout<<endl<< "                                              **** Welcome to "<< "TIRS CROISEES ****" <<endl;
    char replay='n';
    do
    {
        Game *G;
        Chessboard ch;
        G->Game_progress(ch);
        cout<<"Do you want to play again?"<<endl;
        cin >> replay;
    }
    while (replay=='y'||replay=='Y');
    return 0;
}
