#include"GameController.h"
#include<Windows.h>
int main() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con cols=100 lines=22");//��������̨�Ŀ��cols�͸߶�lines
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ 
	CursorInfo.bVisible = false; //���ؿ���̨���  
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬ 
	GameController::GetInstance()->GameRun();
	return 0;
}