#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
/*
dwSize 1-100      會影響游標的大小   100調成50就會變一半 
bVisible 0 或 1   0就不會閃爍  1則會 

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
