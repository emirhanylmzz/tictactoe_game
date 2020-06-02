#include <iostream>
#include "taki.h"
using namespace std;
class TicTacToe{
    friend ostream & operator<<(ostream & o, const TicTacToe & t);
    public:
        TicTacToe();
        TicTacToe(char board[][4], const Takim& team1, const Takim& team2);
        TicTacToe(const TicTacToe & other);
        ~TicTacToe();
        void putChar(int str, int stn, char c);
        bool control(int str, int stn);
        char *getter_board();
        Takim getter_team(char c);
        void setter(char board[][4], const Takim& team1, const Takim& team2);
        const TicTacToe & operator =(const TicTacToe& t1);
        friend bool operator ==(const TicTacToe& t1, const TicTacToe& t2);
        friend bool operator !=(const TicTacToe& t1, const TicTacToe& t2);
        bool isGameOver();
        Takim winner();
        int istatistik();
    private:
        char board[4][4];
        Takim team1; //X takımı
        Takim team2; //O takımı
        int istatistiks[4] = {0, 0, 0, 0};
};
