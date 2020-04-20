#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*





*/

HANDLE hand;
#define HEIGHT 18
#define WIDTH 14
int surface[HEIGHT][WIDTH]={0}; 

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

void print_surface(){
	int x,y;
	for (x=0; x<WIDTH;x++){
		for(y=0; y<HEIGHT;y++){
			int row = y;
			int col = x;
			if (surface[row][col]==0){
			  printxy("0",x,y);
		    }
		    else{
		    	printxy("1",x,y);
			}
		}
	}
}

int main(){
	
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);
	gotoxy(60,10);
	//printxy("X",10,10);
	
	print_surface();
	system("pause");
	return 0;
}
