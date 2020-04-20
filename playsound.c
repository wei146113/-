#include <Windows.h>

int main(){
	
	
	BOOL PlaySound(
	
   LPCTSTR pszSound,
   HMODULE hmod,
   DWORD   fdwSound
   
);

    if (PlaySound == NULL)
    {
    	printf("音樂播放失敗");
	}
	else 
	{
		printf("成功播放");
		
	}

	PlaySound(TEXT("Tetris.wav"), NULL, SND_FILENAME|SND_SYNC);
	

	


	
	
	return 0;
}
