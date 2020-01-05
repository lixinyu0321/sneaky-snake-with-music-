#include "stdafx.h"
#include"StartScreen.h"
#include"Utils.h"
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

void StartScreen::Welcome(void)    //欢迎界面
{
	printf("                                                                                "); utils.color(13);
	Sleep(20);
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
	printf("                                                                                ");
	printf("                                                                                "); utils.color(14);
	printf("                                                                                ");
	printf("  ■■■■■    ■■■        ■■      ■■■      ■■     ■■  ■■■■■■ ");
	Sleep(20);
	printf("■■■■■■■  ■■■■      ■■    ■■■■■    ■■    ■■   ■■■■■■ ");
	Sleep(20);
	printf("■■■  ■■■  ■■ ■■     ■■   ■■    ■■   ■■  ■■     ■■         ");
	Sleep(20);
	printf("■■■          ■■  ■■    ■■  ■■      ■■  ■■  ■■     ■■         ");
	Sleep(20);
	printf("  ■■■■      ■■   ■■   ■■  ■■      ■■  ■■ ■■      ■■■■■■ ");
	Sleep(20);
	printf("   ■■■■■   ■■    ■■  ■■  ■■■■■■■  ■■■■       ■■■■■■ ");
	Sleep(20);
	printf("        ■■■  ■■     ■■ ■■  ■■■■■■■  ■■ ■■      ■■         ");
	Sleep(20);
	printf("■■■  ■■■  ■■      ■■■■  ■■      ■■  ■■   ■■    ■■         ");
	Sleep(20);
	printf("■■■■■■■  ■■        ■■■  ■■      ■■  ■■     ■■  ■■■■■■ ");
	Sleep(20);
	printf("  ■■■■■    ■■          ■■  ■■      ■■  ■■      ■■ ■■■■■■ ");
	printf("                                                                                ");
	printf("                                                                                "); utils.color(13);
	Sleep(20);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "); utils.color(10);
	Sleep(40);
	printf("【李新宇 2017012633】\n");
	system("pause");
	system("cls");
}