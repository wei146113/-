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


#define block1_h 8
#define block1_w 8 

#define block2_h 8
#define block2_w 8 

#define block3_h 8
#define block3_w 8 

#define block4_h 8
#define block4_w 8

#define block5_h 8
#define block5_w 8 

#define block6_h 8
#define block6_w 8 

#define block7_h 8
#define block7_w 8 

#define block8_h 8
#define block8_w 8 

#define block9_h 8
#define block9_w 8 

#define block10_h 8
#define block10_w 8 

#define block11_h 8
#define block11_w 8 

#define block12_h 8
#define block12_w 8 

#define block13_h 8
#define block13_w 8  
int Block1[block1_h][block1_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,1,1,1,0,1,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,1,0,0,0,1,0},
   {0,0,0,0,0,0,0,0}
};
int Block2[block2_h][block2_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,1,0,0,1,0},
   {0,0,0,0,0,0,0,0}
};
int Block3[block3_h][block3_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,0,1,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,0,0,0,0,0}
};
int Block4[block4_h][block4_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,1,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,1,0,0,0,0}
};
int Block5[block5_h][block5_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0}
};
int Block6[block6_h][block6_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,1,1,0,0,0,0}
};
int Block7[block7_h][block7_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,1,1,1,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,1,1,0,1,0,0},
   {0,0,0,0,0,1,0,0}
};
int Block8[block8_h][block8_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0}
};
int Block9[block9_h][block9_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,1,0,0,1,0},
   {0,0,0,0,0,0,0,0}
};
int Block10[block10_h][block10_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,0,1,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,0,0,0,0,0,0}
};
int Block11[block11_h][block11_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,0,0,0,0},
   {0,0,1,1,0,0,0,0}
};
int Block12[block12_h][block12_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,1,1,1,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,1,1,0,1,0,0},
   {0,0,0,0,0,1,0,0}
};
int Block13[block13_h][block13_w] = {
   {0,0,1,0,0,0,0,0},
   {0,0,1,0,0,0,0,0},
   {0,0,0,1,1,0,0,0},
   {0,0,1,1,0,1,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,1,0,1,0,0},
   {0,0,1,0,0,0,1,0},
   {0,0,0,0,0,0,0,0}
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
void print_block1(int block1[][block1_w],int x,int y){
	int w,h;
	for(w=0;w<block1_w;w++){
		for(h=0;h<block1_h;h++){
			if (block1[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block2(int block2[][block2_w],int x,int y){
	int w,h;
	for(w=0;w<block2_w;w++){
		for(h=0;h<block2_h;h++){
			if (block2[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block3(int block3[][block3_w],int x,int y){
	int w,h;
	for(w=0;w<block3_w;w++){
		for(h=0;h<block3_h;h++){
			if (block3[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block4(int block4[][block4_w],int x,int y){
	int w,h;
	for(w=0;w<block4_w;w++){
		for(h=0;h<block4_h;h++){
			if (block4[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block5(int block5[][block5_w],int x,int y){
	int w,h;
	for(w=0;w<block5_w;w++){
		for(h=0;h<block5_h;h++){
			if (block5[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block6(int block6[][block6_w],int x,int y){
	int w,h;
	for(w=0;w<block6_w;w++){
		for(h=0;h<block6_h;h++){
			if (block6[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block7(int block7[][block7_w],int x,int y){
	int w,h;
	for(w=0;w<block7_w;w++){
		for(h=0;h<block7_h;h++){
			if (block7[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block8(int block8[][block8_w],int x,int y){
	int w,h;
	for(w=0;w<block8_w;w++){
		for(h=0;h<block8_h;h++){
			if (block8[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block9(int block9[][block9_w],int x,int y){
	int w,h;
	for(w=0;w<block9_w;w++){
		for(h=0;h<block9_h;h++){
			if (block9[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block10(int block10[][block10_w],int x,int y){
	int w,h;
	for(w=0;w<block10_w;w++){
		for(h=0;h<block10_h;h++){
			if (block10[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block11(int block11[][block11_w],int x,int y){
	int w,h;
	for(w=0;w<block11_w;w++){
		for(h=0;h<block11_h;h++){
			if (block11[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block12(int block12[][block12_w],int x,int y){
	int w,h;
	for(w=0;w<block12_w;w++){
		for(h=0;h<block12_h;h++){
			if (block12[h][w]==1){
				printxy("O",x+w,y+h); 
			}
		}
	}	
}
void print_block13(int block13[][block13_w],int x,int y){
	int w,h;
	for(w=0;w<block13_w;w++){
		for(h=0;h<block13_h;h++){
			if (block13[h][w]==1){
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
void erase_block1(int block1[][block1_w],int x,int y){
	int w,h;
	for(w=0;w<block1_w;w++){
		for(h=0;h<block1_h;h++){
			if (block1[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block2(int block2[][block2_w],int x,int y){
	int w,h;
	for(w=0;w<block2_w;w++){
		for(h=0;h<block2_h;h++){
			if (block2[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block3(int block3[][block3_w],int x,int y){
	int w,h;
	for(w=0;w<block3_w;w++){
		for(h=0;h<block3_h;h++){
			if (block3[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block4(int block4[][block4_w],int x,int y){
	int w,h;
	for(w=0;w<block4_w;w++){
		for(h=0;h<block4_h;h++){
			if (block4[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block5(int block5[][block5_w],int x,int y){
	int w,h;
	for(w=0;w<block5_w;w++){
		for(h=0;h<block5_h;h++){
			if (block5[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block6(int block6[][block6_w],int x,int y){
	int w,h;
	for(w=0;w<block6_w;w++){
		for(h=0;h<block6_h;h++){
			if (block6[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block7(int block7[][block7_w],int x,int y){
	int w,h;
	for(w=0;w<block7_w;w++){
		for(h=0;h<block7_h;h++){
			if (block7[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block8(int block8[][block8_w],int x,int y){
	int w,h;
	for(w=0;w<block8_w;w++){
		for(h=0;h<block8_h;h++){
			if (block8[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block9(int block9[][block9_w],int x,int y){
	int w,h;
	for(w=0;w<block9_w;w++){
		for(h=0;h<block9_h;h++){
			if (block9[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block10(int block10[][block10_w],int x,int y){
	int w,h;
	for(w=0;w<block10_w;w++){
		for(h=0;h<block10_h;h++){
			if (block10[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block11(int block11[][block11_w],int x,int y){
	int w,h;
	for(w=0;w<block11_w;w++){
		for(h=0;h<block11_h;h++){
			if (block11[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block12(int block12[][block12_w],int x,int y){
	int w,h;
	for(w=0;w<block12_w;w++){
		for(h=0;h<block12_h;h++){
			if (block12[h][w]==1){
				printxy(" ",x+w,y+h); 
			}
		}
	}	
}
void erase_block13(int block13[][block13_w],int x,int y){
	int w,h;
	for(w=0;w<block13_w;w++){
		for(h=0;h<block13_h;h++){
			if (block13[h][w]==1){
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
int main(){
	
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);
	//gotoxy(10,10);
	//printxy("X",10,10);	
	//print_surface();
	int n=0;
	for (n=0;n<20;n++)
	{
		
	print_block1(Block1,30,10);
	Sleep(200);
    erase_block1(Block1,30,10);
    print_block2(Block2,30,10);
    Sleep(200);
    erase_block2(Block2,30,10);
    print_block3(Block3,30,10);
    Sleep(200);
    erase_block3(Block3,30,10);
    print_block4(Block4,30,10);
    Sleep(200);
    erase_block4(Block4,30,10);
    print_block5(Block5,30,10);
    Sleep(200);
    erase_block5(Block5,30,10);
    print_block6(Block6,30,10);
    Sleep(200);
    erase_block6(Block6,30,10);
    print_block7(Block7,30,10);
    Sleep(200);
    erase_block7(Block7,30,10);
    print_block8(Block8,30,10);
    Sleep(200);
    erase_block8(Block8,30,10);
    print_block9(Block9,30,10);
    Sleep(200);
    erase_block9(Block9,30,10);
    print_block10(Block10,30,10);
    Sleep(200);
    erase_block10(Block10,30,10);
    print_block11(Block11,30,10);
    Sleep(200);
    erase_block11(Block11,30,10);
    print_block12(Block12,30,10);
    Sleep(200);
    erase_block12(Block12,30,10);
    print_block13(Block13,30,10);
    Sleep(200);

  
}


	system("pause");
	return 0;
}
