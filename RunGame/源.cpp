#include"GameController.h"
#include<Windows.h>
int main() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con cols=100 lines=22");//调整控制台的宽度cols和高度lines
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息 
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态 
	GameController::GetInstance()->GameRun();
	return 0;
}