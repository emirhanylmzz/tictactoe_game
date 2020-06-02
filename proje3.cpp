#include "proje3.h"
#include <string.h>
using namespace std;

//default const
TicTacToe::TicTacToe(){}

TicTacToe::TicTacToe(char board[][4], const Takim& team1, const Takim& team2){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            this->board[i][j] = board[i][j];
        }
    }
    this->team1 = team1;
    this->team2 = team2;
}
TicTacToe::TicTacToe(const TicTacToe & other){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
                board[i][j] = other.board[i][j];
        }
    }
    team1 = other.team1;
    team2 = other.team2;
}
//deconstructer
TicTacToe::~TicTacToe(){}
char *TicTacToe::getter_board(){
    return &board[0][0];
}
Takim TicTacToe::getter_team(char c){
    if(c == 'X' || c == 'x')
        return team1;
    else if(c == 'O'|| c == 'o')
        return team2;
    cout << "Takim 1 döndü:" << endl;
    return team1;
}

void TicTacToe::setter(char board[][4], const Takim& team1, const Takim& team2){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            this->board[i][j] = board[i][j];
        }
    }
    this->team1 = team1;
    this->team2 = team2;
}
const TicTacToe & TicTacToe::operator =(const TicTacToe & other){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
                board[i][j] = other.board[i][j];
        }
    }
    team1 = other.team1;
    team2 = other.team2;
    return *this;
}

bool operator ==(const TicTacToe& t1, const TicTacToe& t2){
    if(t1.team1 != t2.team1)
        return false;
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (t1.board[i][j] != t2.board[i][j])
                return false;
        }
    }
    return true;
}

bool operator !=(const TicTacToe& t1, const TicTacToe& t2){
    if (t1 == t2)
        return false;
    else
        return true;
}
void TicTacToe::putChar(int str, int stn, char c){
    board[str][stn] = c;
}
bool TicTacToe::control(int str, int stn){
    if(board[str][stn] == '-')
        return true;
    else
        return false;
}
bool TicTacToe::isGameOver(){
    int count = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            char t = board[i][j];
            if(t == 'O' || t == 'o' || t == 'X' || t == 'x')
                count++;
        }
    }
    if (count == 16){
        return true;
    }
    else
        return false;
}
Takim TicTacToe::winner(){
    char cond1[4] ={'X','x','x','X'};
    char cond2[4] ={'x','X','X','x'};
    char cond3[4] ={'X','X','x','x'};
    char cond4[4] ={'x','x','X','X'};
    char cond5[4] ={'O','o','o','O'};
    char cond6[4] ={'o','O','O','o'};
    char cond7[4] ={'O','O','o','o'};
    char cond8[4] ={'o','o','O','O'};

    for (int i = 0; i < 4; ++i){
        if (board[i][0] == 'X'){
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond1[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond3[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
        }
        if (board[i][0] == 'x'){
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond2[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond4[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
        }
        if (board[i][0] == 'O'){
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond5[j]){
                    if (j == 3){
                        return team2;
                    }
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond7[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
        }
        if (board[i][0] == 'o'){
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond6[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[i][j] == cond8[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i){
        if (board[0][i] == 'X'){
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond1[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond3[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
        }
        if (board[0][i] == 'x'){
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond2[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond4[j]){
                    if (j == 3)
                        return team1;
                }
                else{
                    break;
                }
            }
        }
        if (board[0][i] == 'O'){
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond5[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond7[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
        }
        if (board[0][i] == 'o'){
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond6[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
            for (int j = 0; j < 4; j++){
                if(board[j][i] == cond8[j]){
                    if (j == 3)
                        return team2;
                }
                else{
                    break;
                }
            }
        }
    }
    if (board[0][0]=='X'&&board[1][1]=='x'&&board[2][2]=='X'&&board[3][3]=='x')
    return team1; 
    if (board[0][0]=='x'&&board[1][1]=='X'&&board[2][2]=='X'&&board[3][3]=='x')
    return team1;
    if (board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='x'&&board[3][3]=='x')
    return team1;
    if (board[0][0]=='x'&&board[1][1]=='x'&&board[2][2]=='X'&&board[3][3]=='X')
    return team1;
    if (board[0][0]=='O'&&board[1][1]=='o'&&board[2][2]=='o'&&board[3][3]=='O')
    return team2;
    if (board[0][0]=='o'&&board[1][1]=='O'&&board[2][2]=='O'&&board[3][3]=='o')
    return team2;
    if (board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='o'&&board[3][3]=='o')
    return team2;
    if (board[0][0]=='o'&&board[1][1]=='o'&&board[2][2]=='O'&&board[3][3]=='O')
    return team2;
    if (board[0][3]=='X'&&board[1][2]=='x'&&board[2][1]=='X'&&board[3][0]=='x')
    return team1; 
    if (board[0][3]=='x'&&board[1][2]=='X'&&board[2][1]=='X'&&board[3][0]=='x')
    return team1;
    if (board[0][3]=='X'&&board[1][2]=='X'&&board[2][1]=='x'&&board[3][0]=='x')
    return team1;
    if (board[0][3]=='x'&&board[1][2]=='x'&&board[2][1]=='X'&&board[3][0]=='X')
    return team1;
    if (board[0][3]=='O'&&board[1][2]=='o'&&board[2][1]=='o'&&board[3][0]=='O')
    return team2;
    if (board[0][3]=='o'&&board[1][2]=='O'&&board[2][1]=='O'&&board[3][0]=='o')
    return team2;
    if (board[0][3]=='O'&&board[1][2]=='O'&&board[2][1]=='o'&&board[3][0]=='o')
    return team2;
    if (board[0][3]=='o'&&board[1][2]=='o'&&board[2][1]=='O'&&board[3][0]=='O')
    return team2;
        
    //XxxX, xXXx, XXxx, xxXX -> Xx Takimi kazananir.
    //OooO, oOOo, OOoo, ooOO -> Oo Takimi kazanir.
	Takim t = Takim('-', '-');
    return t;
}
ostream& operator <<(ostream & o, const TicTacToe & t){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            o << "\t" << "["<< t.board[i][j] << "]";
        }
        o << endl << endl;
    }
    return o;
}
int TicTacToe::istatistik(){
    //int satirX = 0, satirO = 0, kosegenX = 0, kosegenO = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; i < 4; ++j)
        {
            if (board[i][j] == 'X' || board[i][j] == 'x')
            {
                istatistiks[0] += 1;
            }
            if (board[i][j] == 'O' || board[i][j] == 'o')
            {
                istatistiks[1] += 1;
            }
        }
    }
    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        j = i;
        if (board[i][j] == 'X' || board[i][j] == 'x')
            istatistiks[2] += 1;
        if (board[i][j] == 'O' || board[i][j] == 'o')
            istatistiks[3] += 1;
    }
    int a = 3; 
    for (int i = 0; i < 4; i++)
    {
        if (board[i][a] == 'X' || board[i][a] == 'x')
            istatistiks[2] += 1;
        if (board[i][a] == 'O' || board[i][a] == 'o')
            istatistiks[3] += 1;
        a--;
    }
    cout << istatistiks[0] << endl;
    cout << istatistiks[1] << endl;
    cout << istatistiks[2] << endl;
    cout << istatistiks[3] << endl;
    return 0;
}
