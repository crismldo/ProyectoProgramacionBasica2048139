#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h> //funcion new and delete
#include <vector>
#include <windows.h>
#include <stdio.h>

#define color SetConsoleTextAttribute

using namespace std;

//funciones
void ALTA();
void LISTA();
void ARCHIVO();
void ELIMINAR();
void MODIFICAR();

int alta, * numitem, * año;
float* precio, * iva, * total;
string* nombre, * status, * genero, * clasificacion, * consola, * caracteristicas, * descripcion;

int main()
{
	int opcion;
	char i=176;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\t %c%c%c%c MENU DE OPCIONES %c%c%c%c \n",i,i,i,i,i,i,i,i);
	color(hConsole, 4);
	printf("1.- Alta \n");
	color(hConsole, 6);
	printf("2.- Mostrar lista \n");
	color(hConsole, 10);
	printf("3.- Limpiar pantalla \n");
	color(hConsole, 11);
	printf("4.- Modificar \n");
	color(hConsole, 9);
	printf("5.- Eliminar \n");
	color(hConsole, 13);
	printf("6.- Salir \n");
	color(hConsole, 7);
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		ALTA();
		return main();
		break;

	case 2:
		LISTA();
		return main();
		break;

	case 3:
		system("cls");
		return main();
		break;

	case 4:
		MODIFICAR();
		return main();
		break;

	case 5:
		ELIMINAR();
		return main();
		break;

	case 6:
		ARCHIVO();
		break;

	default:
		printf("Ingrese una opcion valida: \n");
		return main();
		break;
	}
}

void ALTA()
{
	char n = 164;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	color(hConsole, 4);
	printf("Ingrese el numero de registros que desea dar de alta: \n");
	scanf_s("%d", &alta);
	numitem = new int[alta];
	año = new int[alta];
	precio = new float[alta];
	iva = new float[alta];
	total = new float[alta];
	nombre = new string[alta];
	genero = new string[alta];
	clasificacion = new string[alta];
	consola = new string[alta];
	caracteristicas = new string[alta];
	descripcion = new string[alta];
	status = new string[alta];

	for (int i = 0; i < alta; i++)
	{
		color(hConsole, 7);
		printf("Ingrese el numero de item: \n");
		scanf_s("%d", &numitem[i]);
		
		for (int j = -1; j < i; j++)
		{
			if (numitem[i] == numitem[j])
			{
				do
				{
					printf("Este numero de Item ya ha sido ingresado, por favor ingrese uno diferente \n");
					scanf_s("%d", &numitem[i]);
				} while (numitem[i] == numitem[j]);
			}
		}
		while (getchar() != '\n');
		printf("Ingrese el nombre: \n");
		getline(cin, nombre[i]);
		printf("Ingrese el a%co de lanzamiento: \n",n);
		scanf_s("%d", &año[i]);
		while (getchar() != '\n');
		printf("Ingrese el genero: \n");
		getline(cin, genero[i]);
		printf("Ingrese la clasificacion: \n");
		getline(cin, clasificacion[i]);
		printf("Ingrese la consola: \n");
		getline(cin, consola[i]);
		printf("Ingrese las caracteristicas: \n");
		getline(cin, caracteristicas[i]);
		printf("Ingrese la descripcion: \n");
		getline(cin, descripcion[i]);
		printf("Ingrese el precio unitario: \n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i]*0.16;
		total[i] = precio[i] + iva[i];
	}
}

void LISTA()
{
	char flecha = 16,n=164;
	int opcion;
	string buscado;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("Desea filtrar la lista por: ");
	printf("1.- Genero \n2.-Clasificacion \n3.-Consola \n4.-Imprimir lista completa \n");
	scanf_s("%d", &opcion);
	switch (opcion)
	{
	case 1:
		printf("¿Que genero desea buscar?");
		while (getchar() != '\n');
		getline(cin, buscado);
		for (int i = 0; i < alta; i++)
		{
			if (buscado == genero[i]) 
			{
				if (status[i] == "ELIMINADO")
				{
					//No pude utilizar =! ya que me decia que status[i] debia ser tipo boleano
				}
				else
				{
					color(hConsole, 6);
					printf("%c Registro  %d \n", flecha, i + 1);
					color(hConsole, 7);
					printf("Item: %d \nNombre: %s \nA%co de Lanzamiento: %d \n", numitem[i], nombre[i].c_str(), n, año[i]);
					printf("Genero: %s \nClasificacion: %s \nconsola: %s \n", genero[i].c_str(), clasificacion[i].c_str(), consola[i].c_str());
					printf("Caracteristicas: %s \nDescripcion: %s \n", caracteristicas[i].c_str(), descripcion[i].c_str());
					printf("Precio: $ %f \nIVA: %f \nTOTAL: $ %f \n", precio[i], iva[i], total[i]);
				}
			}
		}
		break;

	case 2:
		printf("¿Que clasificacion desea buscar?");
		while (getchar() != '\n');
		getline(cin, buscado);
		for (int i = 0; i < alta; i++)
		{
			if (buscado == clasificacion[i])
			{
				if (status[i] == "ELIMINADO")
				{}
				else
				{
					color(hConsole, 6);
					printf("%c Registro  %d \n", flecha, i + 1);
					color(hConsole, 7);
					printf("Item: %d \nNombre: %s \nA%co de Lanzamiento: %d \n", numitem[i], nombre[i].c_str(), n, año[i]);
					printf("Genero: %s \nClasificacion: %s \nconsola: %s \n", genero[i].c_str(), clasificacion[i].c_str(), consola[i].c_str());
					printf("Caracteristicas: %s \nDescripcion: %s \n", caracteristicas[i].c_str(), descripcion[i].c_str());
					printf("Precio: $ %f \nIVA: %f \nTOTAL: $ %f \n", precio[i], iva[i], total[i]);
				}
			}
		}
		break;

	case 3:
		printf("¿Que consola desea buscar?");
		while (getchar() != '\n');
		getline(cin, buscado);
		for (int i = 0; i < alta; i++)
		{
			if (buscado == consola[i])
			{
				if (status[i] == "ELIMINADO")
				{}
				else
				{
					color(hConsole, 6);
					printf("%c Registro  %d \n", flecha, i + 1);
					color(hConsole, 7);
					printf("Item: %d \nNombre: %s \nA%co de Lanzamiento: %d \n", numitem[i], nombre[i].c_str(), n, año[i]);
					printf("Genero: %s \nClasificacion: %s \nconsola: %s \n", genero[i].c_str(), clasificacion[i].c_str(), consola[i].c_str());
					printf("Caracteristicas: %s \nDescripcion: %s \n", caracteristicas[i].c_str(), descripcion[i].c_str());
					printf("Precio: $ %f \nIVA: %f \nTOTAL: $ %f \n", precio[i], iva[i], total[i]);
				}
			}
		}
		break;

	case 4:
		for (int i = 0; i < alta; i++)
		{
			if (status[i] == "ELIMINADO")
			{
				color(hConsole, 12);
				printf("REGISTRO %d ELIMINADO \n", i + 1);
				color(hConsole, 7);
			}
			else
			{
				color(hConsole, 6);
				printf("%c Registro  %d \n", flecha, i + 1);
				color(hConsole, 7);
				printf("Item: %d \nNombre: %s \nA%co de Lanzamiento: %d \n", numitem[i], nombre[i].c_str(), n, año[i]);
				printf("Genero: %s \nClasificacion: %s \nconsola: %s \n", genero[i].c_str(), clasificacion[i].c_str(), consola[i].c_str());
				printf("Caracteristicas: %s \nDescripcion: %s \n", caracteristicas[i].c_str(), descripcion[i].c_str());
				printf("Precio: $ %f \nIVA: %f \nTOTAL: $ %f \n", precio[i], iva[i], total[i]);

			}
		}
		break;
	}
	
}

void ARCHIVO()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;
	float texto3;

	nombrearchivo = "Articulos.txt";
	archivo.open(nombrearchivo.c_str(), ios::out);
	if (archivo.fail())
	{
		printf("ERROR: NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}

	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO";
			texto = i+1;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			archivo << "Numero de Item: " << "\n";
			texto = numitem[i];
			archivo << texto << "\t" << "\n";
			archivo << "Nombre: " << "\n";
			texto2 = nombre[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Año de lanzamiento: " << "\n";
			texto = año[i];
			archivo << texto << "\t" << "\n";
			archivo << "Genero: " << "\n";
			texto2 = genero[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Clasificacion: " << "\n";
			texto2 = clasificacion[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Consola: " << "\n";
			texto2 = consola[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Caracteristicas: " << "\n";
			texto2 = caracteristicas[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Descripcion: " << "\n";
			texto2 = descripcion[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Precio unitario: " << "\n";
			texto3 = precio[i];
			archivo << texto3 << "\t" << "\n";
			archivo << "IVA: " << "\n";
			texto3 = iva[i];
			archivo << texto3 << "\t" << "\n";
			archivo << "Total: " << "\n";
			texto3 = total[i];
			archivo << texto3 << "\t" << "\n";
		}
	}
	archivo.close();
}

void ELIMINAR()
{
	int registro;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	color(hConsole, 9);
	printf("Ingrese el registro que desea eliminar: \n");
	scanf_s("%d", &registro);
	registro = registro - 1;
	for (int i = registro; i == registro; i++)
	{
		color(hConsole, 10);
		printf("REGISTRO %d ELIMINADO \n", registro + 1);
		printf("\n");
		status[i] = "ELIMINADO";
	}
	color(hConsole, 7);
}

void MODIFICAR()
{
	int modificar, opcion, opcion2;
	char n = 164;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		color(hConsole, 11);
		printf("Ingrese el numero de registro a modificar: \n");
		scanf_s("%d", &modificar);
		modificar = modificar - 1;
		for (int i = modificar; i == modificar; i++)
		{
			if (status[i] == "ELIMINADO")
			{
				color(hConsole, 4);
				printf("REGISTRO ELIMINADO \n");
				color(hConsole, 7);
				printf("Ingrese un registro valido \n");
				opcion2 = 1;
			}
			else
			{
				opcion2 = 2;
			}
		}
	} while (opcion2 == 1);
	color(hConsole, 7);
	printf("Ingrese que dato desea modificar: \n");
	printf("1.- Numero de item \n2.- Nombre \n3.- A%co de lanzamiento \n",n);
	printf("4.- Genero \n5.- Clasificacion \n6.- Consola \n");
	printf("7.- Caracteristicas \n8.- Descripcion \n9.- Precio \n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = modificar; i == modificar; i++)
		{
			printf("Ingrese el numero de item: \n");
			scanf_s("%d", &numitem[i]);
		}
		break;

	case 2:
		for (int i = modificar; i == modificar; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el nombre: \n");
			getline(cin, nombre[i]);
		}
		break;

	case 3:
		for (int i = modificar; i == modificar; i++)
		{
			printf("Ingrese el a%co de lanzamiento: \n",n);
			scanf_s("%d", &año[i]);
		}
		break;

	case 4:
		for (int i = modificar; i == modificar; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el genero: \n");
			getline(cin, genero[i]);
		}
		break;

	case 5:
		for (int i = modificar; i == modificar; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la clasificacion: \n");
			getline(cin, clasificacion[i]);
		}
		break;

	case 6:
		for (int i = modificar; i == modificar; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la consola: \n");
			getline(cin, consola[i]);
		}
		break;

	case 7:
		for (int i = modificar; i == modificar; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese las caracteristicas: \n");
			getline(cin, caracteristicas[i]);
		}
		break;

	case 8:
		for (int i = modificar; i == modificar; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la descripcion: \n");
			getline(cin, descripcion[i]);
		}
		break;

	case 9:
		for (int i = modificar; i == modificar; i++)
		{
			printf("Ingrese el precio: \n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * 0.16;
			total[i] = precio[i] + iva[i];
		}
		break;
		
	default:
		printf("Se ingreso una opcion no valida \n");
		break;
	}
}