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

void hideCursor() { //깜박이는 커서 숨김
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void gotoxy(int x, int y) { //x, y 좌표 설정
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(consoleHandle, pos);
}
void printCountdown(int seconds) { //카운트다운 출력
    printf("\r%d seconds ", seconds); //공백으로 덮어쓰기
    fflush(stdout); //출력버퍼 지우기
}
int keyControl()//키보드 이벤트 처리
{
    char temp = _getch();//키보드 입력
    if (temp == 'w' || temp == 'W') return UP;
    else if (temp == 'a' || temp == 'A') return LEFT;
    else if (temp == 's' || temp == 'S') return DOWN;
    else if (temp == 'd' || temp == 'D') return RIGHT;
    else if (temp == ' ') return SUBMIT;
}
int drawMenu() {
    int x = 35, y = 20; //메뉴 위치 설정
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
        int n = keyControl();//키보드 입력
        switch (n)
        {
        case UP: //메뉴 위아래 범위 지정
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
            return y - 20;// 0, 1, 2로 메뉴코드 반환
        }
    }
}

void HowtoPlay() { //게임정보출력
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
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("▲\n");
    gotoxy(x + 54, y + 11);
    printf("○\n");
    gotoxy(x+25, y + 15);
    printf("↑ Abandoned baby\n");
    gotoxy(x+25, y+17);
    printf("↓ Abandoned elderly person\n");
}
int question_2() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("●\n");
    gotoxy(x + 54, y + 11);
    printf("○\n");
    gotoxy(x + 10, y + 15);
    printf("↑ A man who has rap sheets but who can doing 10 people's job\n");
    gotoxy(x + 10, y + 17);
    printf("↓ A man who can't doing even 1 person's job\n");
}
int question_3() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("○○\n");
    gotoxy(x + 54, y + 11);
    printf("○○\n");
    gotoxy(x + 5, y + 15);
    printf("↑ Poor white parents placed their child in an orphanage with heavy heart\n");
    gotoxy(x + 5, y + 17);
    printf("↓ Wealthy Asian parent who places excessive pressure on their child, \n       causing stress\n");
}
int question_4() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("○\n");
    gotoxy(x + 54, y + 11);
    printf("○○○○○\n");
    gotoxy(x + 30, y + 15);
    printf("↑ A person\n");
    gotoxy(x + 30, y + 17);
    printf("↓ 5 people\n");
}
int question_5() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("◐\n");
    gotoxy(x + 54, y + 11);
    printf("○○○○○\n");
    gotoxy(x + 30, y + 15);
    printf("↑ 1 disabled person\n");
    gotoxy(x + 30, y + 17);
    printf("↓ 5 healthy man\n");
}
int question_6() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("●●●●●\n");
    gotoxy(x + 54, y + 11);
    printf("●\n");
    gotoxy(x + 25, y + 15);
    printf("↑ 5 corrupt politicians\n");
    gotoxy(x + 25, y + 17);
    printf("↓ 1 corrupt CEO\n");
}
int question_7() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("♥\n");
    gotoxy(x + 54, y + 11);
    printf("▲▲▲▲▲\n");
    gotoxy(x + 25, y + 15);
    printf("↑ ♡♥AdOrAbLe kItTy♥♡ \n");
    gotoxy(x + 25, y + 17);
    printf("↓ 5 children\n");
}
int question_8() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("▮▮▮▮▮▮▮▮▮▮\n");
    gotoxy(x + 54, y + 11);
    printf("◎\n");
    gotoxy(x + 25, y + 15);
    printf("↑ 10 Beautiful Trees\n");
    gotoxy(x + 25, y + 17);
    printf("↓ Dead, Cold meats 22 pounds(10kg)\n");
}
int question_9() {
    int x = 0, y = 0;
    gotoxy(x + 54, y + 7);
    printf("▣\n");
    gotoxy(x + 54, y + 10);
    printf("○○○○○\n");
    gotoxy(x + 25, y + 15);
    printf("↑ The only perfect quantum computer in the world\n");
    gotoxy(x + 25, y + 17);
    printf("↓ 5 hardworking developers\n");
}
int question_10() {
    int x = 0 , y = 0;
    gotoxy(x + 54, y + 7);
    printf("○\n");
    gotoxy(x + 54, y + 10);
    printf("○\n");
    gotoxy(x + 25, y + 15);
    printf("↑ your old friend\n");
    gotoxy(x + 25, y + 17);
    printf("↓ your old friend's cousin\n");
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
    printf("|▣▣▣▣▣▣▣|\n");
    gotoxy(x, y+2);
    printf(" _◎◎◎__◎◎◎\n");
}
void playGame() {
    int x = 0, y = 0;
    srand(time(NULL));
    time_t sTime, cTime;
    int c = 1;
    int keyinput;
    while (c <= 10) {
        system("cls");
        sTime = time(NULL) + 10;
        int timerE = 0;
        switch (c) {
        case 1:
            question_1();
            break;
        case 2:
            question_2();
            break;
        case 3:
            question_3();
            break;
        case 4:
            question_4();
            break;
        case 5:
            question_5();
            break;
        case 6:
            question_6();
            break;
        case 7:
            question_7();
            break;
        case 8:
            question_8();
            break;
        case 9:
            question_9();
            break;
        case 10:
            question_10();
            break;
        }
        track();
        trolley();
        

        do{//timer
            cTime = time(NULL);
            if (sTime - cTime >= 0) { 
                gotoxy(x, y);
                printCountdown(sTime - cTime);  
                Sleep(1000);
            }
            else {
                timerE = 1;
                break;
            }
        } while (1);

        if (timerE) {
            c++;
        }
       Sleep(1000);
       system("cls");
    }
}