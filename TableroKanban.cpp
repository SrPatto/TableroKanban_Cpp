// Rodriguez Valera Luis Adrian || 2NV21
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int, int);
void tablero();
void menu_principal();
void mostrarColas(string, string);

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
int k = 0, y = 10, x = 34;

int main()
{
    string titulo1 = "tarea1 ";
    string describcion1 = "Lorem ipsum dolor sit amet consectetur adipiscing elit tristique sollicitudin ";
    string titulo2 = "tarea2 ";
    string describcion2 = "Lorem ipsum dolor sit amet consectetur adipiscing elit tristique sollicitudin ";

    tablero();
    menu_principal();

    mostrarColas(titulo1, describcion1);
    mostrarColas(titulo2, describcion2);

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

void mostrarColas(string titulo, string describcion)
{
    int n_Titulo = 0, n_Describcion = 0;
    int sizeTitulo = titulo.size();
    int sizeDescribcion = describcion.size();

    // Imprime el titulo de la tarea
    while (y < 20 && n_Titulo < sizeTitulo)
    {
        while (x < 56 && n_Titulo < sizeTitulo)
        {
            gotoxy(x, y);
            cout << titulo[n_Titulo];
            n_Titulo++;
            x++;
        }
        x = 34;
        y++;
    }
    // Imprime la describcion de la tarea
    while (y < 22 && n_Describcion < sizeDescribcion)
    {
        while (x < 56 && n_Describcion < sizeDescribcion)
        {
            gotoxy(x, y);
            cout << describcion[n_Describcion];
            n_Describcion++;
            x++;
        }
        x = 34;
        y++;
    }
    // Divide tareas
    for (int i = 34; i < 56; i++)
    {
        gotoxy(i, y);
        printf("%c", 196);
    }
    y++;
}
