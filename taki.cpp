#include "taki.h"
Takim::Takim(){}
Takim::Takim(char player1, char player2){
    this->player1 = player1;
    this->player2 = player2;
}

Takim::Takim(const Takim& t1){
    player1 = t1.player1;
    player2 = t1.player2;
}

char Takim::getter(int i){
    if(i == 1)
        return player1;
    if(i == 2)
        return player2;
    else
        return player1;
}
void Takim::setter(char p1, char p2){
    player1 = p1;
    player2 = p2;
}
const Takim & Takim::operator =(const Takim& t1){
    player1 = t1.player1;
    player2 = t1.player2;
    return *this;
}

bool operator ==(const Takim& t1, const Takim& t2){
    return t1.player1 == t2.player1 && t1.player2 == t2.player2;
}
bool operator !=(const Takim& t1, const Takim& t2){
    return !(t1.player1 == t2.player1 || t1.player2 == t2.player2);
}