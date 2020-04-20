#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


HANDLE hand;

enum block_type{
	O,
	J
};

int block_type_num = 2;

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
			  printxy(" ",x,y);
		    }
		    else{
		    	printxy("O",x,y);
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
void make_new_block(){
	enum block_type type= (int)(rand()%block_type_num);
	switch (type){
		case O:
			copy_block(Block0,block_cur);
			break;
		case J:
			copy_block(BlockJ,block_cur);
			break;
		default:
		break;		
	}
	cur_x = (WIDTH-block_w)/2;
	cur_y = 0;
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

void land_block(){
	int w,h;
	for(w=0;w<block_w;w++){
		for(h=0;h<block_h;h++){
			if (block_cur[h][w]==1){
				surface[cur_y+h][cur_x+w]=1;
			}
		}
	}	
	
} 
int get_block_x_fill(int row){
	int is_fill = 0;
	int col;
	for (col=0;col<block_w;col++){
		if(block_cur[row][col]==1){
			is_fill = 1;
		}
	}
	return is_fill;
}

int get_block_y_fill(int col){
	int is_fill = 0;
	int row;
	for (row=0;row<block_h;row++){
		if(block_cur[row][col]==1){
			is_fill = 1;
		}
	}
	return is_fill;

}
    

int get_block_left_right_margin(int *left_margin, int *right_margin){
	int is_fill;
	int i;
	for (i=0;i<block_w/2;i++){
		is_fill = get_block_x_fill(i); 
		if(is_fill == 0){
			*left_margin += 1;
		}
	}
	for (i=block_w-1;i>=block_h/2;i--){
		is_fill = get_block_x_fill(i);
		if (is_fill ==0){
			*right_margin += 1;
		}
	}
	
}
int get_block_top_bottom_margin(int *top_margin, int *bottom_margin){
	int is_fill;
	int i;
	for (i=0;i<block_h/2;i++){
		is_fill = get_block_y_fill(i); 
		if(is_fill == 0){
			*top_margin += 1;
		}
	}
	for (i=block_h-1;i>=block_h/2;i--){
		is_fill = get_block_y_fill(i);
		if (is_fill == 0){
			*bottom_margin += 1;
		}
	}
	
}
void print_block(int block[][block_w], int x, int y){
	int w,h;
	for(w=0;w<block_w;w++){
		for(h=0;h<block_h;h++){
			if (block[h][w]==1){
				printxy("O", x+w , y+h); 
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
	int left_margin = 0,right_margin = 0,top_margin = 0,bottom_margin = 0;
	get_block_left_right_margin(&left_margin,&right_margin);
	get_block_top_bottom_margin(&top_margin,&bottom_margin);
	if (x<0-left_margin||x+block_w > WIDTH+right_margin){
	return 1;
	}
	else if(y<0-top_margin || y+block_h > HEIGHT+bottom_margin){
		return 1;
	}
	int w,h;
	for (w=0;w<block_w;w++){
		for (h=0;h<block_h;h++){
			if (block_cur[h][w]==1){
			  if(surface[y+h][x+w]==1){
			  	return 1;
			  } 
			}
		}
	}	
	return 0;
}

int tm =800; //定時器間隔
UINT_PTR timerId;

static void set_timer(int t){
	KillTimer(NULL, timerId);
	timerId = SetTimer(NULL,0,t,NULL);
	
}

static void close_timer(){
	KillTimer(NULL, timerId);
	
}
  

void move_block_down(){
 if (isCollision(cur_x,cur_y+1)==0){
				 
				erase_block(block_cur,cur_x,cur_y);
				cur_y++; 
				print_block(block_cur,cur_x,cur_y);
		}
	else {
		land_block();
		make_new_block();
		if (isCollision(cur_x,cur_y)==1){
			close_timer();
			
		} 

		print_block(block_cur,cur_x,cur_y);

	}	
}

 
void key_control(){
	int ch;
	MSG msg;   
	while(1){
		
		if (PeekMessage(&msg,NULL,WM_TIMER,WM_TIMER,PM_REMOVE)!=0){
			move_block_down();
			
		}
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
	
	srand(time(NULL));
	//block_cur = Block0;
	//copy_block(BlockJ,block_cur);
	
    print_surface();
    	make_new_block();

	print_block(Block0, cur_x,cur_y);
	set_timer(tm);
	key_control();

	system("pause");
	return 0;
}
