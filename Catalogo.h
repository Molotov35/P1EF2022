#include "persona.h"
#include "pacientes.h"


int catalogo(){
    int choice;
	char x;
	do
    {
    system("cls");
	printf("\n     ======================================================================\n");
	printf("\t\t    BIENVENIDO AL SISTEMA\n");
	printf("\t\t    LABORATORIO CLINICO LabClinico\n");
	printf("\t\t    Edwin Adony Montejo Martínez 9491-21-3898\n");
	printf("     ======================================================================\n");

	cout<<"\t\t\t\t1. EMPLEADOS"<<endl;
	cout<<"\t\t\t\t2. PACIENTES"<<endl;
	cout<<"\t\t\t\t4. EXAMENES"<<endl;
	cout<<"\t\t\t\t0. EXIT"<<endl;
	cout<<"Ingresa tu Opcion: ";
	cin>>choice;
	switch(choice)
    {
    case 1:
        {
            persona empleado;
            empleado.menu();
            break;
        }
	case 2:
		{
            paciente nuevo;
            nuevo.menu();
            break;
        }
    case 0:
        return 0;
    default:
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    }
    }while(choice!= 0);
}
