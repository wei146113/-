#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


HANDLE hand;
#define HEIGHT 18
#define WIDTH 14
int surface[HEIGHT][WIDTH]={0}; 
#define block_h 4
#define block_w 4
int Block0[block_h][block_w] = {
   {0,0,0,0},
   {0,1,1,0},
   {0,1,1,0},
   {0,0,0,0}
};
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
 
void print_block(int block[][block_w],int x,int y){
	int w,h;
	for(w=0;w<block_w;w++){
		for(h=0;h<block_h;h++){
			if (block[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void erase_block(int block[][block_w],int x,int y){
	int w,h;
	for(w=0;w<block_w;w++){
		for(h=0;h<block_h;h++){
			if (block[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void for_sleep(int max){
	int i =0;
	for (i=0;i<max;i++){
		
	}
}

void key_control(){
	int ch;
	while(1){
		ch = getch();
		switch (ch){
		case 72: //up
				printf("%d\n",ch);
				break;
		case 80: //down
				printf("%d\n",ch);
				break;
		case 75: //left
				printf("%d\n",ch);
				break;
		case 77: //right
				printf("%d\n",ch);
				break;
		case 32: //space
				printf("%d\n",ch);
				break;
		case 113: //Q
				printf("%d\n",ch);
				return;
				break;	
		default:
		        printf("%d else \n",ch);		
																
		}
		printf("��L����\n");
	}
}
int main(){
	
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);
	//gotoxy(10,10);
	//printxy("X",10,10);	
	//print_surface();
	//print_block(Block0,0,0);
	//for_sleep(INT_MAX);
	//Sleep(2000);
	//erase_block(Block0,0,0);
	//print_block(Block0,20,20);
	key_control();
	system("pause");
	return 0;
}
