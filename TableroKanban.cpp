// Rodriguez Valera Luis Adrian || 2NV21
#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

void pintar()
{
    // lineas horizontales
    for (int i = 2; i < 78; i++)
    {
        gotoxy(i, 3);
        printf("%c", 205);
        gotoxy(i, 8);
        printf("%c", 205);
        gotoxy(i, 23);
        printf("%c", 205);
    }
    // lineas verticales
    for (int i = 4; i < 23; i++)
    {
        gotoxy(2, i);
        printf("%c", 186);
        gotoxy(27, i);
        printf("%c", 186);
        gotoxy(52, i);
        printf("%c", 186);
        gotoxy(77, i);
        printf("%c", 186);
    }
    // vertices
    gotoxy(2, 3);
    printf("%c", 201);
    gotoxy(2, 23);
    printf("%c", 200);
    gotoxy(77, 3);
    printf("%c", 187);
    gotoxy(77, 23);
    printf("%c", 188);
    gotoxy(27, 3);
    printf("%c", 203);
    gotoxy(52, 3);
    printf("%c", 203);
    gotoxy(27, 23);
    printf("%c", 202);
    gotoxy(52, 23);
    printf("%c", 202);
    gotoxy(2, 8);
    printf("%c", 204);
    gotoxy(77, 8);
    printf("%c", 185);
    gotoxy(27, 8);
    printf("%c", 206);
    gotoxy(52, 8);
    printf("%c", 206);
}

int main()
{
    pintar();
    gotoxy(1, 24);
    system("pause>null");
    return 0;
}