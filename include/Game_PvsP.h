#ifndef GAME_PVSP_H
#define GAME_PVSP_H
#include "Player.h"
#include"Chessboard.h"
#include "Game.h"
class Game_PvsP : public Game{
    public:
     Player P2; //creating a second player
    public:
     void Result();//it display the result of the game in the end
     void Game_Progress_P(Chessboard Ch);//it's responsabel of the progress of the game between player and another player

};

#endif // GAME_PVSP_H
