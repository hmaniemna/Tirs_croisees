#ifndef GAME_PVSM_H
#define GAME_PVSM_H
#include "Machine.h"
#include "Chessboard.h"
#include "Game.h"
#include <iostream>
using namespace std;
class Game_PvsM : public Game
{
    public:
     Machine M;//creating a Machine that take the chessboard that going to play on
    public:
     void Result();//it display the result of the game in the end
     void Game_Progress_M(Chessboard&);//it's rsponsible of the progress of the game between player and Machine
};

#endif // GAME_PVSM_H
