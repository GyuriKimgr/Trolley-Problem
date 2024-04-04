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

#define DELAY 10000

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
int question_1() {
    printf("�� Abandoned baby\n");
    printf("�� Abandoned elderly person\n");
}
int question_2() {
    printf("�� A man who has rap sheets but who can doing 10 people's job\n");
    printf("�� A man who can't doing even 1 person's job\n");
}
int question_3() {
    printf("�� Poor white parents placed their child in an orphanage with heavy heart\n");
    printf("�� Wealthy Asian parent who places excessive pressure on their child, causing stress\n");
}
int question_4() {
    printf("�� A person\n");
    printf("�� 5 people\n");
}
int question_5() {
    printf("�� 1 disabled person\n");
    printf("�� 5 healthy man\n");
}
int question_6() {
    printf("�� 5 corrupt politicians\n");
    printf("�� 1 corrupt CEO\n");
}
int question_7() {
    printf("�� ����AdOrAbLe kItTy���� \n");
    printf("�� 5 children\n");
}
int question_8() {
    printf("�� 10 Beautiful Trees\n");
    printf("�� Dead, Cold meats 22 pounds(10kg)\n");
}
int question_9() {
    printf("�� The only perfect quantum computer in the world\n");
    printf("�� 5 hardworking developers\n");
}
int question_10() {
    printf("�� your old friend\n");
    printf("�� your old friend's cousin\n");
}

int track() {
    int x = 0, y = 8;
    gotoxy(x, y);
    printf("                                        |---|---|---|---|---|---|---|---|---|\n");
    printf("                                    |---|---|\n");
    printf("|---|---|---|---|---|---|---|---|---|---|\n");
    printf("                                    |---|---|\n");
    printf("                                        |---|---|---|---|---|---|---|---|---|\n");
}
int trolley() {
    int x = 10, y = 7;
    gotoxy(x, y);
    printf(" ______________\n");
    gotoxy(x, y+1);
    printf("|�ââââââ�|\n");
    gotoxy(x, y+2);
    printf(" _�ݡݡ�__�ݡݡ�\n");
}
void playGame() {
    srand(time(NULL));
    time_t sTime, cTime;
    int keyinput;
    while (1) {
        sTime = time(NULL) + 10;
        while (1) {
            cTime = time(NULL);
            if (sTime - cTime >= 0) {
                printf("%d seconds\n", sTime - cTime);
            }
            else if (sTime - cTime < 0) {
                sTime = time(NULL) + 10;
            }
        }
        
            

        
    }
}