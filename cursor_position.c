#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
/*
�E����x y
�E�Yx y �]�w�ܤj���ȨҦp>5000, �άO�ܤp���� �Ҧp -100 �|�o�ͤ��򪬪p?   �|�^�� x=0 y=0���y�� 
�Ex y �ȤӤj�Ӥp�ASetConsoleCursorPosition �|�^�Ǥ�����?   loc.x = 0 ; loc.y = 0; 

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
