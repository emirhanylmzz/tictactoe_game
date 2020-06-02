#include "proje3.h"
#include <iostream>
using namespace std;

int main(){
	char choose;
	char board[4][4]={
	{'-','-','-','-'},
	{'-','-','-','-'},
	{'-','-','-','-'},
	{'-','-','-','-'},
	};
    char a,b,c,d;
    cout << "takim 1 : X veya O :"; 
	cin >> choose;
	if(choose=='X'||choose=='x'){
		a='X';
		b='x';
		c='O';
		d='o';
		cout<<"TAKIM 1 X TAKIMI\nTAKIM 2 O TAKIMI\n";
	}
	else if(choose=='O'||choose=='o'){
	a='O';
	b='o';
	c='X';
	d='x';
	cout << "TAKIM 1 O TAKIMI\n TAKIM 2 X TAKIMI\n";
	}
	Takim t1(a, b);
	Takim t2(c, d);

    TicTacToe tiktak(board,t1, t2);
	int sira = 0;
	int sira2 = 0;
	int sira3 = 0;
	int secim1, secim2;
    while (!tiktak.isGameOver() && tiktak.winner().getter(1) == '-')
    {
		cout << tiktak;
		if (sira % 2 == 0){
			if(sira2 % 2 == 0){
				cout << "TAKİM 1'in 1.oyuncusu hangı satir olduğunu secsin" << endl;
				cin >> secim1;
				cout << "TAKİM 1'in 1.oyuncusu hangı sütun olduğunu secsin" << endl;
				cin >> secim2;
				if(tiktak.control(secim1, secim2))
					tiktak.putChar(secim1, secim2, a);
				else
					cout << "HAMLE HAKKINIZ GECTİ!" << endl;	
			}
			if(sira2 % 2 == 1){
				cout << "TAKİM 1'in 2.oyuncusu hangı satir olduğunu secsin" << endl;
				cin >> secim1;
				cout << "TAKİM 1'in 2.oyuncusu hangı sütun olduğunu secsin" << endl;
				cin >> secim2;
				if(tiktak.control(secim1, secim2))
					tiktak.putChar(secim1, secim2, b);
				else
					cout << "HAMLE HAKKINIZ GECTİ!" << endl;
			}
			sira2++;
		}
		else if(sira % 2 == 1)
		{
			if(sira3 % 2 == 0){
				cout << "TAKİM 2'in 1.oyuncusu hangı satir olduğunu secsin" << endl;
				cin >> secim1;
				cout << "TAKİM 2'in 1.oyuncusu hangı sütun olduğunu secsin" << endl;
				cin >> secim2;
				if(tiktak.control(secim1, secim2))
					tiktak.putChar(secim1, secim2, c);
				else
					cout << "HAMLE HAKKINIZ GECTİ!" << endl;
			}
			if(sira3 % 2 == 1){
				cout << "TAKİM 2'in 2.oyuncusu hangı satir olduğunu secsin" << endl;
				cin >> secim1;
				cout << "TAKİM 2'in 2.oyuncusu hangı sütun olduğunu secsin" << endl;
				cin >> secim2;
				if(tiktak.control(secim1, secim2))
					tiktak.putChar(secim1, secim2, d);
				else
					cout << "HAMLE HAKKINIZ GECTİ!" << endl;
			}
			sira3++;
		}
		sira++;
    }
	cout << "WİNNER İS TEAM:" << tiktak.winner().getter(1);
	//tiktak.istatistik();
    return 0;
}
