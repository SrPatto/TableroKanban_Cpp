// Rodriguez Valera Luis Adrian || 2NV21
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;

struct nodo
{
    string tarea;
    nodo *siguiente;
    nodo *atras;
} *primero, *ultimo;

// Prototipos de Funciones
void gotoxy(int, int);
void limpiarConsola();
string pedirDato(const char *);
void menu_tablero();
void tablero();
int menu(const char *, const char *opciones[], int);
void menu_principal();
void crearTarea();
void modificarTarea();
void avanzarTarea();
void eliminarTarea();
// Funciones de la cola
void insertarNodo(string);
void desplegarLista();

// Variables Globales
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
int y = 10, x = 34;

int main()
{
    menu_tablero();

    system("pause>null");
    return 0;
}

// Funciones
void gotoxy(int x, int y)
{
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void limpiarConsola()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 10; j < 30; j++)
        {
            gotoxy(i, j);
            cout << " ";
        }
    }
    for (int i = 34; i < 56; i++)
    {
        for (int j = 10; j < 20; j++)
        {
            gotoxy(i, j);
            cout << " ";
        }
    }
    y = 10;
}

string pedirDato(const char *texto)
{
    string tarea;

    gotoxy(3, 14);
    cout << texto;
    gotoxy(3, 16);
    getline(cin, tarea);

    return tarea;
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
    const char *tituloMenu = "\tBienvenido";
    const char *opciones[] = {"Crear nueva tarea", "Modificar tarea", "Avanzar tarea", "Eliminar tarea", "Salir"};
    int n = 5;

    do
    {
        opcion = menu(tituloMenu, opciones, n);

        switch (opcion)
        {
        case 1:
            crearTarea();
            limpiarConsola();
            desplegarLista();

            break;
        case 2:
            modificarTarea();
            limpiarConsola();

            break;
        case 3:
            avanzarTarea();
            limpiarConsola();

            break;
        case 4:
            eliminarTarea();
            limpiarConsola();

            break;
        case 5:
            system("cls");
            gotoxy(2, 2);
            cout << "Adios" << endl;
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

void menu_tablero()
{
    tablero();
    SetConsoleTextAttribute(hCon, 7);
    menu_principal();
}

void crearTarea()
{
    string tarea;

    const char *texto = "Ingrese la nueva tarea: ";
    tarea = pedirDato(texto);

    insertarNodo(tarea);

    gotoxy(3, 20);
    cout << "Nueva Tarea Agregada";
    getch();
}

void modificarTarea()
{
    string NombreTareaAntiguo, NombreTareaNuevo;

    const char *texto1 = "Nombre de la tarea: ";
    const char *texto2 = "Nuevo nombre: ";

    NombreTareaAntiguo = pedirDato(texto1);
    limpiarConsola();
    NombreTareaNuevo = pedirDato(texto2);

    gotoxy(3, 20);
    cout << "Tarea Modificada";
    getch();
}

void avanzarTarea()
{
    string tarea;

    const char *texto = "Nombre de la tarea: ";
    tarea = pedirDato(texto);

    gotoxy(3, 20);
    cout << "La Tarea Ha Avanzado";
    getch();
}

void eliminarTarea()
{
    string tarea;

    const char *texto = "Nombre de la tarea: ";
    tarea = pedirDato(texto);

    gotoxy(3, 20);
    cout << "Tarea Eliminada";
    getch();
}

// Funciones de la Cola
void insertarNodo(string nombreTarea)
{
    nodo *nuevo = new nodo();
    nuevo->tarea = nombreTarea;

    if (primero == NULL)
    {
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = primero;
        primero->atras = ultimo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->atras = ultimo;
        nuevo->siguiente = primero;
        ultimo = nuevo;
        primero->atras = ultimo;
    }
}

void desplegarLista()
{
    nodo *actual = new nodo();
    actual = primero;

    if (primero != NULL)
    {
        do
        {
            string tarea = actual->tarea;
            int n_Tarea = 0;
            int sizeTarea = tarea.size();

            // Imprime el titulo de la tarea
            while (y < 20 && n_Tarea < sizeTarea)
            {
                while (x < 56 && n_Tarea < sizeTarea)
                {
                    gotoxy(x, y);
                    cout << tarea[n_Tarea];
                    n_Tarea++;
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
            actual = actual->siguiente;
        } while (actual != primero);
    }
    // else{
    //     gotoxy(3, 14);
    //     cout << "El tablero esta vacio";
    // }
}