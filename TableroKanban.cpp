// Rodriguez Valera Luis Adrian || 2NV21
#include <iostream>
#include <conio.h>
#include <windows.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;

void gotoxy(int, int);
void tablero();
int menu(const char *, const char *opciones[], int);
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
    SetConsoleTextAttribute(hCon, 7);
    mostrarColas(titulo1, describcion1);
    mostrarColas(titulo2, describcion2);
    menu_principal();

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
    bool repite = true;
    int opcion;

    // Titulo y las opciones del menu
    const char *titulo = "\tBienvenido";
    const char *opciones[] = {"Crear nueva tarea", "Mover tarea", "Eliminar tarea", "Salir"};
    int n = 4;

    do
    {
        opcion = menu(titulo, opciones, n);

        switch (opcion)
        {
        case 1:
            gotoxy(2, 16);
            cout << "hello mom";
            break;
        case 2:
            gotoxy(2, 16);
            cout << "hello dad";
            break;
        case 3:
            gotoxy(2, 16);
            cout << "hello world";
            break;
        case 4:
            system("cls");
            gotoxy(2, 2);
            cout << "Adios";
            repite = false;
            break;

        default:
            break;
        }

    } while (repite);
}

int menu(const char *titulo, const char *opciones[], int n)
{
    int opcionSeleccionada = 1;
    int tecla;
    bool repite = true;

    do
    {
        gotoxy(2, 4 + opcionSeleccionada);
        cout << "==>";
        // Imprime titulo
        gotoxy(2, 3);
        cout << titulo;
        // Imprime opciones
        for (int i = 0; i < n; i++)
        {
            gotoxy(6, 5 + i);
            cout << i + 1 << ") " << opciones[i];
        }

        do
        {
            tecla = getch();
        } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

        switch (tecla)
        {
        case TECLA_ARRIBA:
            gotoxy(2, 4 + opcionSeleccionada);
            cout << "   ";
            opcionSeleccionada--;

            if (opcionSeleccionada < 1)
            {
                opcionSeleccionada = n;
            }

            break;
        case TECLA_ABAJO:
            gotoxy(2, 4 + opcionSeleccionada);
            cout << "   ";
            opcionSeleccionada++;

            if (opcionSeleccionada > n)
            {
                opcionSeleccionada = 1;
            }

            break;
        case ENTER:
            gotoxy(2, 4 + opcionSeleccionada);
            cout << "   ";
            repite = false;
            break;

        default:
            break;
        }

    } while (repite);

    return opcionSeleccionada;
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
