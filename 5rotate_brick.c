#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


HANDLE hand;
int cur_x = 0, cur_y = 0;

#define HEIGHT 14
#define WIDTH 18 
int surface[HEIGHT][WIDTH]={0}; 

#define block_h 4
#define block_w 4
int Block0[block_h][block_w] = {
   {0,0,0,0},
   {0,1,1,0},
   {0,1,1,0},
   {0,0,0,0}
};
int BlockJ[block_h][block_w] = {
   {0,0,1,0},
   {0,0,1,0},
   {0,1,1,0},
   {0,0,0,0}
};

int block_cur[block_h][block_w]={0};

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

void copy_block(int block_s[][block_w],int block_d[][block_w]){
	int w,h;
	for(w=0;w<block_w;w++){
		for(h=0;h<block_h;h++){
			block_d[h][w] = block_s[h][w]; 
		}
		
	}
}
void rotate_block(){
	int temp[block_h][block_w] = {0};
	copy_block(block_cur,temp);
	int w,h;
	for(w=0;w<block_w;w++){
		for(h=0;h<block_h;h++){
			block_cur[h][w] = temp[block_w-1-w][h]; 
		}
		
	} 
}
 
void print_block(int block[][block_w], int x, int y){
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
int isCollision(int x, int y){
	if (x<0||x+block_w > WIDTH){
		return 1;
	}
	else if(y<0 || y+block_h > HEIGHT){
		return 1;
	}
	
	return 0;
}

void key_control(){
	int ch;
	while(1){
		if (kbhit()!=0){
		ch = getch();
		switch (ch){
		case 72: //up
		        		
				erase_block(block_cur,cur_x,cur_y);
				rotate_block();		
				print_block(block_cur,cur_x,cur_y);
			
				      
				break;
		case 80: //down
		         if (isCollision(cur_x,cur_y+1)==0){
				 
				erase_block(block_cur,cur_x,cur_y);
				cur_y++; 
				print_block(block_cur,cur_x,cur_y);
			} 
				break;
		case 75: //left
		         if (isCollision(cur_x-1,cur_y)==0){
				 
				erase_block(block_cur,cur_x,cur_y);
				cur_x--; 
				print_block(block_cur,cur_x,cur_y);
		}
				
				break;
		case 77: //right
		         if (isCollision(cur_x+1,cur_y)==0){
				 
				erase_block(block_cur,cur_x,cur_y);
				cur_x++; 
				print_block(block_cur,cur_x,cur_y);
		}
				
				break;
		case 32: //space
				//printf("%d\n",ch);
				break;
		case 113: //Q
				//printf("%d\n",ch);
				return;
				break;	
		default:
		        //printf("%d else\n",ch);		
				break;												
		}
	
      }
      
   }
 }
int main(){
	
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(0);
	//block_cur = Block0;
	copy_block(BlockJ,block_cur);
	
    print_surface();
	print_block(Block0, cur_x,cur_y);
	key_control();

	system("pause");
	return 0;
}
