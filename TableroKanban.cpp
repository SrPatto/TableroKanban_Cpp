// Rodriguez Valera Luis Adrian || 2NV21
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int, int);
void tablero();
void menu_principal();
void mostrarColas();

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{

    tablero();

    menu_principal();
    mostrarColas();

    system("pause>null");
    return 0;
}

void gotoxy(int x, int y)
{
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void tablero()
{
    // lineas horizontales
    for (int i = 32; i < 108; i++)
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
        gotoxy(32, i);
        printf("%c", 186);
        gotoxy(57, i);
        printf("%c", 186);
        gotoxy(82, i);
        printf("%c", 186);
        gotoxy(107, i);
        printf("%c", 186);
    }
    // vertices
    gotoxy(32, 3);
    printf("%c", 201);
    gotoxy(32, 23);
    printf("%c", 200);
    gotoxy(107, 3);
    printf("%c", 187);
    gotoxy(107, 23);
    printf("%c", 188);
    gotoxy(57, 3);
    printf("%c", 203);
    gotoxy(82, 3);
    printf("%c", 203);
    gotoxy(57, 23);
    printf("%c", 202);
    gotoxy(82, 23);
    printf("%c", 202);
    gotoxy(32, 8);
    printf("%c", 204);
    gotoxy(107, 8);
    printf("%c", 185);
    gotoxy(57, 8);
    printf("%c", 206);
    gotoxy(82, 8);
    printf("%c", 206);

    // Titulos
    gotoxy(34, 5);
    SetConsoleTextAttribute(hCon, 4);
    cout << "\tPENDIENTE";
    gotoxy(59, 5);
    SetConsoleTextAttribute(hCon, 1);
    cout << "\tEN CURSO";
    gotoxy(84, 5);
    SetConsoleTextAttribute(hCon, 2);
    cout << "\tCOMPLETADO";
}

void menu_principal()
{
    // system("cls");

    gotoxy(2, 3);
    SetConsoleTextAttribute(hCon, 7);
    cout << "\t Bienvenido\n\n";
    cout << "1- Crear nueva tarea\n";
    cout << "2- Mover tarea\n";
    cout << "3- Eliminar tarea\n";
    cout << "4- Salir";
}

void mostrarColas()
{
    string test = "Lorem ipsum dolor sit amet consectetur adipiscing elit tristique sollicitudin, imperdiet consequat integer sociosqu ullamcorper senectus feugiat magna, vel tellus fringilla eros augue pulvinar fusce proin. Morbi cursus sem ante at justo eu integer quisque sagittis nam, pulvinar himenaeos aenean erat habitasse tortor turpis nisi. Justo viverra ridiculus neque luctus diam commodo quis, augue sodales ornare curabitur nostra tortor facilisi, etiam pharetra magna vivamus porta eros.";
    int k = 0;

    for (int y = 10; y < 20; y++)
    {
        for (int x = 34; x < 56; x++)
        {
            gotoxy(x, y);
            cout << test[k];
            k++;
        }
    }
}