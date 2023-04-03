#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using  namespace std;

struct tienda
{
   int item;
   char nombre[25], genero[20], clasificacion[20], consola[15];
   string descripcion;
   float unitario, total;
};


int main()
{
    tienda videojuegos[3];
    int opcion;
    
    do
    {
        printf("\t ***MENU DE OPCIONES*** \n");
        printf("1.-Alta \n");
        printf("2.-Modificacion \n");
        printf("3.-Baja \n");
        printf("4.-Lista \n");
        printf("5.-Limpiar pantalla \n");
        printf("6.-Salir \n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1:
            for (int i = 1; i < 4; i++)
            {
                printf("Ingrese el numero de Item \n");
                scanf_s("%d", &videojuegos[i].item);
                cin.ignore();
                printf("Ingrese el nombre:\n");
                gets_s(videojuegos[i].nombre);
                printf("Ingrese la descripcion: \n");
                getline(cin, videojuegos[i].descripcion);
                printf("Ingrese el genero: \n");
                gets_s(videojuegos[i].genero);
                printf("Ingrese la clasificacion \n");
                gets_s(videojuegos[i].clasificacion);
                printf("Ingrese la consola: \n");
                gets_s(videojuegos[i].consola);
                printf("Ingrese el precio unitario: \n");
                scanf_s("%f", &videojuegos[i].unitario);

                videojuegos[i].total = (videojuegos[i].unitario) + (videojuegos[i].unitario * 0.16);

            }
            break;

        case 2:
            printf("\t ***PROXIMAMENTE*** \n");
            break;

        case 3:
            printf("\t ***PROXIMAMENTE*** \n");
            break;

        case 4:
            for (int i = 1; i < 4; i++)
            {
                printf("\t *** ARTICULO %d *** \n", i);
                printf("ITEM: %d \n", videojuegos[i].item);
                printf("NOMBRE: %s \n", videojuegos[i].nombre);
                printf("DESCRIPCION: %s \n", videojuegos[i].descripcion.c_str());
                printf("GENERO: %s \n", videojuegos[i].genero);
                printf("CLASIFICACION: %s \n", videojuegos[i].clasificacion);
                printf("CONSOLA: %s \n", videojuegos[i].consola);
                printf("PRECIO: %f \n", videojuegos[i].total);
            }
            break;

        case 5:
            system("cls");
            break;
           
        case 6:
            exit(1);
            break;
        }

    } while (opcion != 6);
    
}
