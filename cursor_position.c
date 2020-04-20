#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
/*
‧改變x y
‧若x y 設定很大的值例如>5000, 或是很小的值 例如 -100 會發生什麼狀況?   會回到 x=0 y=0的座標 
‧x y 值太大太小，SetConsoleCursorPosition 會回傳什麼資料?   loc.x = 0 ; loc.y = 0; 

*/


HANDLE hand;

void setCursorVisable(int v){
	
	    CONSOLE_CURSOR_INFO cursor_info = {100,v};
		SetConsoleCursorInfo(hand, &cursor_info);		 
}
void gotoxy(int x,int y){
	COORD loc;
	loc.X = x;
	loc.Y = y;
	SetConsoleCursorPosition(hand, loc);
}
void printxy(char *str,int x,int y){
	gotoxy(x,y);
	printf("%s",str);
}


int main(){
	
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);
	//gotoxy(10,10);
	printxy("X",1000,100);
	system("pause");
	return 0;
}
