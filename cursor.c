#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
/*
dwSize 1-100      �|�v�T��Ъ��j�p   100�զ�50�N�|�ܤ@�b 
bVisible 0 �� 1   0�N���|�{�{  1�h�| 

*/


HANDLE hand;

void setCursorVisable(int v){
	
	    CONSOLE_CURSOR_INFO cursor_info = {100,v};
		SetConsoleCursorInfo(hand, &cursor_info);		 
}



int main(){
	
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);
	
	system("pause");
	return 0;
}
