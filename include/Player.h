#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Chessboard.h"
class Player
{
  public:
    string name;// player's name
    int Splayer; // player's score
  public:
    Player();
    void Update_score(int);// update the score of the player
    void help( Chessboard);// method help the player when he is stuck after a specific  period of time
    int click(Chessboard&);// the player chooses a new box
    bool verifpos(int&,int&, Chessboard&); //check if the new chosen positions are valid
};
#endif // PLAYER_H
