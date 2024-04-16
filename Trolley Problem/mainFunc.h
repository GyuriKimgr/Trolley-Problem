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

#define MINT_COLOR 10
#define DEFALT_COLOR 15

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
void printCountdown(int seconds) { // 카운트다운 출력
    printf("\r%d seconds ", seconds); // 공백으로 덮어쓰기
    fflush(stdout); // 출력버퍼 지우기
}
void timerLoop() {
    time_t sTime, cTime;
    int c = 1;
    while (c <= 10) {
        sTime = time(NULL) + 10;
        int timerE = 0;
        do { // timer
            cTime = time(NULL);
            if (sTime - cTime >= 0) {
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
    }
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
    gotoxy(0, 0);
    int x = 0, y = 15; // 초기 위치 설정
    gotoxy(x + 54, 7);
    printf("●\n");
    gotoxy(x + 54, 11);
    printf("○\n");
    while (1) {
        // 선택지 출력 전에 해당 위치에 배경 칠하기
        gotoxy(x + 25, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ Abandoned baby\n");
        gotoxy(x + 25, 17);
        printf("↓ Abandoned elderly person\n");


        // 현재 위치에 따라 색상 변경
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 25, 15);
            printf("↑ Abandoned baby\n");
        }
        else {
            gotoxy(x + 25, 17);
            printf("↓ Abandoned elderly person\n");
        }

        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}

int question_2() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("●\n");
    gotoxy(x + 54, 11);
    printf("○\n");
    while (1) {
        gotoxy(x + 10, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ A man who has rap sheets but who can doing 10 people's job\n");
        gotoxy(x + 10, 17);
        printf("↓ A man who can't doing even 1 person's job\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 10, 15);
            printf("↑ A man who has rap sheets but who can doing 10 people's job\n");
        }
        else {
            gotoxy(x + 10, 17);
            printf("↓ A man who can't doing even 1 person's job\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_3() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("○○\n");
    gotoxy(x + 54, 11);
    printf("○○\n");
    while (1) {
        gotoxy(x + 5, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ Poor white parents placed their child in an orphanage with heavy heart\n");
        gotoxy(x + 5, 17);
        printf("↓ Wealthy Asian parent who places excessive pressure on their child, \n\tcausing stress\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 5, 15);
            printf("↑ Poor white parents placed their child in an orphanage with heavy heart\n");
        }
        else {
            gotoxy(x + 5, 17);
            printf("↓ Wealthy Asian parent who places excessive pressure on their child, \n\tcausing stress\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_4() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("○\n");
    gotoxy(x + 54, 11);
    printf("○○○○○\n");
    while (1) {
        gotoxy(x + 30, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ A person\n");
        gotoxy(x + 30, 17);
        printf("↓ 5 people\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 30, 15);
            printf("↑ A person\n");
        }
        else {
            gotoxy(x + 30, 17);
            printf("↓ 5 people\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_5() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("◐\n");
    gotoxy(x + 54, 11);
    printf("○○○○○\n");
    while (1) {
        gotoxy(x + 30, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ 1 disabled person\n");
        gotoxy(x + 30, 17);
        printf("↓ 5 healthy man\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 30, 15);
            printf("↑ 1 disabled person\n");
        }
        else {
            gotoxy(x + 30, 17);
            printf("↓ 5 healthy man\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_6() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("●●●●●\n");
    gotoxy(x + 54, 11);
    printf("●\n");
    while (1) {
        gotoxy(x + 30, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ 5 corrupt politicians\n");
        gotoxy(x + 30, 17);
        printf("↓ 1 corrupt CEO\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 30, 15);
            printf("↑ 5 corrupt politicians\n");
        }
        else {
            gotoxy(x + 30, 17);
            printf("↓ 1 corrupt CEO\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_7() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("♥\n");
    gotoxy(x + 54, 11);
    printf("▲▲▲▲▲\n");
    while (1) {
        gotoxy(x + 30, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ ♡♥AdOrAbLe kItTy♥♡ \n");
        gotoxy(x + 30, 17);
        printf("↓ 5 children\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 30, 15);
            printf("↑ ♡♥AdOrAbLe kItTy♥♡ \n");
        }
        else {
            gotoxy(x + 30, 17);
            printf("↓ 5 children\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_8() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("##########\n");
    gotoxy(x + 54, 11);
    printf("◎\n");
    while (1) {
        gotoxy(x + 25, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ 10 Beautiful Trees\n");
        gotoxy(x + 25, 17);
        printf("↓ Dead, Cold meats 22 pounds(10kg)\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 25, 15);
            printf("↑ 10 Beautiful Trees\n");
        }
        else {
            gotoxy(x + 25, 17);
            printf("↓ Dead, Cold meats 22 pounds(10kg)\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_9() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("▣\n");
    gotoxy(x + 54, 11);
    printf("○○○○○\n");
    while (1) {
        gotoxy(x + 25, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ The only perfect quantum computer in the world\n");
        gotoxy(x + 25, 17);
        printf("↓ 5 hardworking developers\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 25, 15);
            printf("↑ The only perfect quantum computer in the world\n");
        }
        else {
            gotoxy(x + 25, 17);
            printf("↓ 5 hardworking developers\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}
int question_10() {
    gotoxy(0, 0);
    int x = 0, y = 15;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x + 54, 7);
    printf("○\n");
    gotoxy(x + 54, 11);
    printf("○\n");
    while (1) {
        gotoxy(x + 25, 15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
        printf("↑ your old friend\n");
        gotoxy(x + 25, 17);
        printf("↓ your old friend's cousin\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT_COLOR);
        if (y == 15) {
            gotoxy(x + 25, 15);
            printf("↑ your old friend\n");
        }
        else {
            gotoxy(x + 25, 17);
            printf("↓ your old friend's cousin\n");
        }
        char temp = _getch();
        if (temp == 'w' || temp == 'W') {
            if (y > 15) y--;
        }
        else if (temp == 's' || temp == 'S') {
            if (y < 17) y++;
        }
        else if (temp == ' ') {
            break;
        }
    }
}

int track() {
    int x = 0, y = 8;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x, y);
    printf("                                        |---|---|---|---|---|---|---|---|---|\n");
    printf("                                    |---|---|\n");
    printf("|---|---|---|---|---|---|---|---|---|---|\n");
    printf("                                    |---|---|\n");
    printf("                                        |---|---|---|---|---|---|---|---|---|\n");
}
int trolley() {
    int x = 10, y = 7;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFALT_COLOR);
    gotoxy(x, y);
    printf(" ______________\n");
    gotoxy(x, y + 1);
    printf("|▣▣▣▣▣▣▣|\n");
    gotoxy(x, y + 2);
    printf(" _◎◎◎__◎◎◎\n");
}

void playGame() {
    srand(time(NULL));
    int g = 1;
    while (g <= 10) {
        switch (g) {
        case 1:
            system("cls");
            track();
            trolley();
            question_1();
        case 2:
            system("cls");
            track();
            trolley();
            question_2();
        case 3:
            track();
            trolley();
            question_3();
        case 4:
            system("cls");
            track();
            trolley();
            question_4();
        case 5:
            system("cls");
            track();
            trolley();
            question_5();
        case 6:
            track();
            trolley();
            question_6();
        case 7:
            system("cls");
            track();
            trolley();
            question_7();
        case 8:
            system("cls");
            track();
            trolley();
            question_8();
        case 9:
            system("cls");
            track();
            trolley();
            question_9();
        case 10:
            system("cls");
            track();
            trolley();
            question_10();
        }
        while (1) {
            if (keyControl() == SUBMIT) {
                break;
                g++;
            }
        }
        break;
    }
}