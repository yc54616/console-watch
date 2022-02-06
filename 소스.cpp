#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

const char* digits[10][5][4]
{
    {
        { "■","■","■","■" },
        { "■","  ","  ","■" },
        { "■","  ","  ","■" },
        { "■","  ","  ","■" },
        { "■","■","■","■" }
    },
    {
        { "  ","  ","  ","■" },
        { "  ","  ","  ","■" },
        { "  ","  ","  ","■" },
        { "  ","  ","  ","■" },
        { "  ","  ","  ","■" }
    },
    {
        { "■","■","■","■" },
        { "  ","  ","  ","■" },
        { "■","■","■","■" },
        { "■","  ","  ","  " },
        { "■","■","■","■" }
    },
    {
        { "■","■","■","■" },
        { "  ","  ","  ","■" },
        { "■","■","■","■" },
        { "  ","  ","  ","■" },
        { "■","■","■","■" }
    },
    {
        { "■","  ","■","  " },
        { "■","  ","■","  " },
        { "■","■","■","■" },
        { "  ","  ","■","  " },
        { "  ","  ","■","  " }
    },
    {
        { "■","■","■","■" },
        { "■","  ","  ","  " },
        { "■","■","■","■" },
        { "  ","  ","  ","■" },
        { "■","■","■","■" },
    },
    {
        { "■","  ","  ","  " },
        { "■","  ","  ","  " },
        { "■","■","■","■" },
        { "■","  ","  ","■" },
        { "■","■","■","■" }
    },
    {
        { "■","■","■","■" },
        { "■","  ","  ","■" },
        { "■","  ","  ","■" },
        { "  ","  ","  ","■" },
        { "  ","  ","  ","■" }
    },
    {
        { "■","■","■","■" },
        { "■","  ","  ","■" },
        { "■","■","■","■" },
        { "■","  ","  ","■" },
        { "■","■","■","■" }
    },
    {
        { "■","■","■","■" },
        { "■","  ","  ","■" },
        { "■","■","■","■" },
        { "  ","  ","  ","■" },
        { "  ","  ","  ","■" }
    }
};

struct point{
    double x;
    double y;
};

struct point p1;

void ConsoleSetting() {
    system("mode con:cols=130 lines=30");
    system("title 콘솔 아날로그 시계 (v 1.0)");
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void drawCircle() {
    for (int i = 0; i < 7; i++) {
        gotoxy(4, 10 + i);
        printf("■");
    }
    gotoxy(6, 9);
    printf("■");
    gotoxy(6, 8);
    printf("■");
    gotoxy(8, 7);
    printf("■");
    gotoxy(8, 6);
    printf("■");
    gotoxy(10, 5);
    printf("■");
    gotoxy(12, 4);
    printf("■");
    gotoxy(14, 3);
    printf("■");
    gotoxy(16, 3);
    printf("■");
    gotoxy(18, 2);
    printf("■");
    gotoxy(20, 2);
    printf("■");
    for (int i = 0; i < 7; i++) {
        gotoxy(22+(i*2), 1);
        printf("■");
    }
    gotoxy(36, 2);
    printf("■");
    gotoxy(38, 2);
    printf("■");
    gotoxy(40, 3);
    printf("■");
    gotoxy(42, 3);
    printf("■");
    gotoxy(44, 4);
    printf("■");
    gotoxy(46, 5);
    printf("■");
    gotoxy(48, 6);
    printf("■");
    gotoxy(48, 7);
    printf("■");
    gotoxy(50, 8);
    printf("■");
    gotoxy(50, 9);
    printf("■");
    for (int i = 0; i < 7; i++) {
        gotoxy(52, 10 + i);
        printf("■");
    }
    gotoxy(50, 17);
    printf("■");
    gotoxy(50, 18);
    printf("■");
    gotoxy(48, 19);
    printf("■");
    gotoxy(48, 20);
    printf("■");
    gotoxy(46, 21);
    printf("■");
    gotoxy(44, 22);
    printf("■");
    gotoxy(42, 23);
    printf("■");
    gotoxy(40, 23);
    printf("■");
    gotoxy(38, 24);
    printf("■");
    gotoxy(36, 24);
    printf("■");
    for (int i = 0; i < 7; i++) {
        gotoxy(34-(i*2), 25);
        printf("■");
    }
    gotoxy(20, 24);
    printf("■");
    gotoxy(18, 24);
    printf("■");
    gotoxy(16, 23);
    printf("■");
    gotoxy(14, 23);
    printf("■");
    gotoxy(12, 22);
    printf("■");
    gotoxy(10, 21);
    printf("■");
    gotoxy(8, 20);
    printf("■");
    gotoxy(8, 19);
    printf("■");
    gotoxy(6, 18);
    printf("■");
    gotoxy(6, 17);
    printf("■");
}

void coordinate(int n, struct point* p1){
    if (n == 0) {
        p1->x = 28;
        p1->y = 2;
    }
    else if (n == 1) {
        p1->x = 30;
        p1->y = 2;
    }
    else if (n == 2) {
        p1->x = 32;
        p1->y = 3;
    }
    else if (n == 3) {
        p1->x = 34;
        p1->y = 3;
    }
    else if (n == 4) {
        p1->x = 36;
        p1->y = 4;
    }
    else if (n == 5) {
        p1->x = 38;
        p1->y = 4;
    }
    else if (n == 6) {
        p1->x = 40;
        p1->y = 5;
    }
    else if (n == 7) {
        p1->x = 42;
        p1->y = 5;
    }
    else if (n == 8) {
        p1->x = 44;
        p1->y = 6;
    }
    else if (n == 9) {
        p1->x = 44;
        p1->y = 7;
    }
    else if (n == 10) {
        p1->x = 46;
        p1->y = 8;
    }
    else if (n == 11) {
        p1->x = 46;
        p1->y = 9;
    }
    else if (n == 12) {
        p1->x = 48;
        p1->y = 10;
    }
    else if (n == 13) {
        p1->x = 48;
        p1->y = 11;
    }
    else if (n == 14) {
        p1->x = 50;
        p1->y = 12;
    }
    else if (n == 15) {
        p1->x = 50;
        p1->y = 13;
    }
    else if (n == 16) {
        p1->x = 50;
        p1->y = 14;
    }
    else if (n == 17) {
        p1->x = 48;
        p1->y = 15;
    }
    else if (n == 18) {
        p1->x = 48;
        p1->y = 16;
    }
    else if (n == 19) {
        p1->x = 46;
        p1->y = 17;
    }
    else if (n == 20) {
        p1->x = 46;
        p1->y = 18;
    }
    else if (n == 21) {
        p1->x = 44;
        p1->y = 19;
    }
    else if (n == 22) {
        p1->x = 44;
        p1->y = 20;
    }
    else if (n == 23) {
        p1->x = 42;
        p1->y = 21;
    }
    else if (n == 24) {
        p1->x = 40;
        p1->y = 21;
    }
    else if (n == 25) {
        p1->x = 38;
        p1->y = 22;
    }
    else if (n == 26) {
        p1->x = 36;
        p1->y = 22;
    }
    else if (n == 27) {
        p1->x = 34;
        p1->y = 23;
    }
    else if (n == 28) {
        p1->x = 32;
        p1->y = 23;
    }
    else if (n == 29) {
        p1->x = 30;
        p1->y = 24;
    }
    else if (n == 30) {
        p1->x = 28;
        p1->y = 24;
    }
    else if (n == 31) {
        p1->x = 26;
        p1->y = 24;
    }
    else if (n == 32) {
        p1->x = 24;
        p1->y = 23;
    }
    else if (n == 33) {
        p1->x = 22;
        p1->y = 23;
    }
    else if (n == 34) {
        p1->x = 20;
        p1->y = 22;
    }
    else if (n == 35) {
        p1->x = 18;
        p1->y = 22;
    }
    else if (n == 36) {
        p1->x = 16;
        p1->y = 21;
    }
    else if (n == 37) {
        p1->x = 14;
        p1->y = 21;
    }
    else if (n == 38) {
        p1->x = 12;
        p1->y = 20;
    }
    else if (n == 39) {
        p1->x = 12;
        p1->y = 19;
    }
    else if (n == 40) {
        p1->x = 10;
        p1->y = 18;
    }
    else if (n == 41) {
        p1->x = 10;
        p1->y = 17;
    }
    else if (n == 42) {
        p1->x = 8;
        p1->y = 16;
    }
    else if (n == 43) {
        p1->x = 8;
        p1->y = 15;
    }
    else if (n == 44) {
        p1->x = 6;
        p1->y = 14;
    }
    else if (n == 45) {
        p1->x = 6;
        p1->y = 13;
    }
    else if (n == 46) {
        p1->x = 6;
        p1->y = 12;
    }
    else if (n == 47) {
        p1->x = 8;
        p1->y = 11;
    }
    else if (n == 48) {
        p1->x = 8;
        p1->y = 10;
    }
    else if (n == 49) {
        p1->x = 10;
        p1->y = 9;
    }
    else if (n == 50) {
        p1->x = 10;
        p1->y = 8;
    }
    else if (n == 51) {
        p1->x = 12;
        p1->y = 7;
    }
    else if (n == 52) {
        p1->x = 12;
        p1->y = 6;
    }
    else if (n == 53) {
        p1->x = 14;
        p1->y = 5;
    }
    else if (n == 54) {
        p1->x = 16;
        p1->y = 5;
    }
    else if (n == 55) {
        p1->x = 18;
        p1->y = 4;
    }
    else if (n == 56) {
        p1->x = 20;
        p1->y = 4;
    }
    else if (n == 57) {
        p1->x = 22;
        p1->y = 3;
    }
    else if (n == 58) {
        p1->x = 24;
        p1->y = 3;
    }
    else if (n == 59) {
        p1->x = 26;
        p1->y = 2;
    }
}

void PrintLine_x(double x, double y) {
    int i, j;
    double x0 = 28;
    double y0 = 13;
    double temp;
    if (x < x0) {
        temp = x;
        x = x0;
        x0 = temp;
        temp = y;
        y = y0;
        y0 = temp;
    }
    for (i = round(x0); i <= x; i++) {
        j = round(((y0 - y) / (x0 - x)) * (i - x0) + y0);//직선에방정식에 x좌표를 넣어서 y값을 찾고 반올림
        gotoxy(i, j);
        printf("*");
    }
}
void PrintLine_y(double x, double y) {
    int i, j;
    double x0 = 28;
    double y0 = 13;
    double temp;
    if (y < y0) {
        temp = x;
        x = x0;
        x0 = temp;
        temp = y;
        y = y0;
        y0 = temp;
    }
    for (j = round(y0); j <= y; j++) {
        i = round(((x - x0) / (y - y0)) * (j - y0) + x0);//직선 역함수에 y좌표를 넣어서 x값을 찾고 반올림
        gotoxy(i, j);
        printf("*");
    }
}

int main(void){
    double x0 = 28;
    double y0 = 13;
    double tmp, start, end;

    ConsoleSetting();
    CursorView();
    while (1) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        int s = tm.tm_sec;
        int m = tm.tm_min;
        int o = tm.tm_hour;
        drawCircle();
        coordinate(s, &p1);
        if (s >= 6 && s <= 24 || s >= 36 && s <= 54) {
            PrintLine_x(p1.x, p1.y);
        }
        else {
            PrintLine_y(p1.x, p1.y);
        }
        coordinate(m, &p1);
        if (m >= 6 && m <= 24 || m >= 36 && m <= 54) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            PrintLine_x(p1.x, p1.y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            PrintLine_y(p1.x, p1.y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        coordinate(o * 5 % 60, &p1);
        if (o * 5 % 60 >= 6 && o * 5 % 60 <= 24 || o * 5 % 60 >= 36 && o * 5 % 60 <= 54) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            PrintLine_x(p1.x, p1.y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            PrintLine_y(p1.x, p1.y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        for (int j = 0; j < 5; j++) {
            gotoxy(60, 11+j);
            for (int k = 0; k < 4; k++) {
                printf("%s", digits[o / 10][j][k]);
            }
            printf("\n");
        }
        for (int j = 0; j < 5; j++) {
            gotoxy(70, 11 + j);
            for (int k = 0; k < 4; k++) {
                printf("%s", digits[o % 10][j][k]);
            }
            printf("\n");
        }
        gotoxy(80, 12);
        printf("■");
        gotoxy(80, 14);
        printf("■");
        for (int j = 0; j < 5; j++) {
            gotoxy(84, 11 + j);
            for (int k = 0; k < 4; k++) {
                printf("%s", digits[m / 10][j][k]);
            }
            printf("\n");
        }
        for (int j = 0; j < 5; j++) {
            gotoxy(94, 11 + j);
            for (int k = 0; k < 4; k++) {
                printf("%s", digits[m % 10][j][k]);
            }
            printf("\n");
        }
        gotoxy(104, 12);
        printf("■");
        gotoxy(104, 14);
        printf("■");
        for (int j = 0; j < 5; j++) {
            gotoxy(108, 11 + j);
            for (int k = 0; k < 4; k++) {
                printf("%s", digits[s / 10][j][k]);
            }
            printf("\n");
        }
        for (int j = 0; j < 5; j++) {
            gotoxy(118, 11 + j);
            for (int k = 0; k < 4; k++) {
                printf("%s", digits[s % 10][j][k]);
            }
            printf("\n");
        }
        Sleep(1000);
        system("cls");
    }
    
    system("pause");

    return 0;
}