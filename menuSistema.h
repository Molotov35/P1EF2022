<<<<<<< HEAD
#include "Catalogo.h"
#include "reportes.h"


void menuSistema() {
    int choice;
	char x;
	do
    {
	system("cls");
	printf("\n     ======================================================================\n");
	printf("\t\t    BIENVENIDO AL SISTEMA\n");
	printf("\t\t    LABORATORIO CLINICO LabClinico\n");
	printf("\t\t    Edwin Adony Montejo Martínez 9491-21-3898\n");
	printf("     ======================================================================\n\n");
	cout<<"\t\t\t\t1. CATALOGOS"<<endl;
	cout<<"\t\t\t\t2. PROCESOS"<<endl;
	cout<<"\t\t\t\t3. REPORTES"<<endl;
	cout<<"\t\t\t\t0. CERRAR SESION"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[0/1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
		catalogo();
		break;
	case 2:

		break;
	case 3:
		reporte();
		break;
	case 0:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 0);
	//persona empleado;
	//empleado.menu();
=======
#include "persona.h"


void menuSistema() {
	system("cls");
	printf("\n     ======================================================================\n");
	printf("\t\t\t     BIENVENIDO AL SISTEMA\n");
	printf("\t\t    Sistema de Nominas\n");
	printf("\t\t    Programacion 2022 | Grupo no.3\n");
	printf("     ======================================================================\n");

	persona estudiante;
	estudiante.menu();
>>>>>>> 08e8bf2a40a47b620e8c6548e10899f986ac8b71

	getchar();
}
