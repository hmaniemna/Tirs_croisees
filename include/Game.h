#ifndef GAME_H
#define GAME_H
#include "Player.h"
class Game
{
    public:
     Player P1;
     int Tour; //define the number of tour
    public:
     Game();// Constructor
     char ChoosePlayer(); //choose if you want to play versus Machine or another Player
     virtual void Result ()=0; // compare the two scores in the end of the game and display the winner
     void Game_progress(Chessboard); //where the game takes place
     bool GameOver(Chessboard);//a method that verify the end of the game


};
#endif // GAME_H
