#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#pragma once

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void hideCursor() { //�����̴� Ŀ�� ����
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void gotoxy(int x, int y) { //x, y ��ǥ ����
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
int keyControl()//Ű���� �̺�Ʈ ó��
{
    char temp = _getch();//Ű���� �Է�
    if (temp == 'w' || temp == 'W') return UP;
    else if (temp == 'a' || temp == 'A') return LEFT;
    else if (temp == 's' || temp == 'S') return DOWN;
    else if (temp == 'd' || temp == 'D') return RIGHT;
    else if (temp == ' ') return SUBMIT;
}
int drawMenu() {
    int x = 35, y = 20; //�޴� ��ġ ����
    printf("\n\n\n");
	printf("++===========================================================================++\n");
	printf("++===========================================================================++\n");
	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
	printf(" [][][][][]                          []    [] [][][]\n");
	printf(" [][][][][]              [] [] [][][] []  []  []  []                   [][][]\n");
	printf("     []    []     [][][] [] [] []      [][]   []         []            []    \n");
	printf("     []    []  [] []  [] [] [] []       []    []        [][]  [][][][] []  \n");
	printf("     []    [][]   []  [] [] [] [][][]   []    []  [][] []  [] [] [] [] [][][]\n");
	printf("     []    []     []  [] [] [] []       []    []  []   [][][] [] [] [] []\n");
	printf("     []    []     [][][] [] [] [][][]   []    [][][]   []  [] [] [] [] [][][]\n");
	printf("-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("++===========================================================================++\n");
	printf("++===========================================================================++\n");
	printf("                           >>CH00$3 TH3 M3NU<<                                   \n");
	gotoxy(x - 2, y);
	printf("> PLAY\n");
	gotoxy(x, y + 1);
	printf("H31P\n");
    gotoxy(x, y + 2);
    printf("QU1T\n");

    while (1)
    {
        int n = keyControl();//Ű���� �Է�
        switch (n)
        {
        case UP: //�޴� ���Ʒ� ���� ����
            if (y > 20)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;

        case DOWN:
            if (y < 22)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;

        case SUBMIT:
            return y - 20;// 0, 1, 2�� �޴��ڵ� ��ȯ
        }
    }
}
int track() {
    printf("                                        |---|---|---|---|---|---|---|---|---|\n");
    printf("                                    |---|---|\n");
    printf("|---|---|---|---|---|---|---|---|---|---|\n");
    printf("                                    |---|---|\n");
    printf("                                        |---|---|---|---|---|---|---|---|---|\n");
}
int trolley() {
    printf(" ______________\n");
    printf("|�ââââââ�|\n");
    printf(" _�ݡݡ�__�ݡݡ�\n");
}
void HowtoPlay() { //�����������
    system("cls");
    printf("\n\n\n");
    printf("++===========================================================================++\n");
    printf("++===========================================================================++\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
    printf("                         This is Trolley Problem Game\n");
    printf("                         Plz choose one of two opions.\n");
    printf("                    U have 10 seconds to make your choice.\n");
    printf("                          There're 10 questions.\n");
    printf("-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("++===========================================================================++\n");
    printf("++===========================================================================++\n\n");
    printf("                        Press any key to back title\n");
    while (1) {
        if (keyControl() == SUBMIT);
        break;
    }
}