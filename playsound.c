#include <Windows.h>

int main(){
	
	
	BOOL PlaySound(
	
   LPCTSTR pszSound,
   HMODULE hmod,
   DWORD   fdwSound
   
);

    if (PlaySound == NULL)
    {
    	printf("���ּ��񥢱�");
	}
	else 
	{
		printf("���\����");
		
	}

	PlaySound(TEXT("Tetris.wav"), NULL, SND_FILENAME|SND_SYNC);
	

	


	
	
	return 0;
}
