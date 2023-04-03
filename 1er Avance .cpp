#include <iostream>

using  namespace std;

int main()
{
    char nombre[20], desc[40], genero[20], clasif[20], consola[15];
    int item,precio,opcion,desicion;

    cout << "\t ***MENU DE OPCIONES***" << endl; // \t es tabulador
    cout << "1.-Alta" << endl;
    cout << "2.-Modificacion" << endl;
    cout << "3-Baja" << endl;
    cout << "4.-Lista" << endl;
    cout << "5.-Limpiar Pantalla" << endl;
    cout << "6.-Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1: //ALTA
        printf("Ingrese el numero de Item\n");
        cin >> item;
        printf("Ingrese el nombre del articulo\n");
        cin >> nombre;
        printf("Ingrese la descripcion\n");
        cin >> desc;
        printf("Genero\n");
        cin >> genero;
        printf("Clasificacion\n");
        cin >> clasif;
        printf("Consola\n");
        cin >> consola;
        printf("Precio unitario:\n");
        cin >> precio;
        precio=precio+(precio*0.16)
        //agregar otro articulo
        printf("Desea ingresar otro articulo? 1.Si 2.No\n");
        cin >> desicion;
        if (desicion == 1)
        {
            return main();
        }
        else
        {
            printf("Gracias :)\n");
        }
        break;

    case 2:
        printf("\t *PROXIMAMENTE*");
        break;

    case 3:
        printf("\t *PROXIMAMENTE*");
        break;

    case 4:
        printf("\t *PROXIMAMENTE*");
        break;

    case 5:
        system("cls"); // limpiar pantalla
        return main();
        break;
    case 6:
        exit(1); // cierra la pantalla
        break;

    }
}