#include "persona.h"
#include "pacientes.h"


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
	printf("     ======================================================================\n");

	cout<<"\t\t\t\t1. EMPLEADOS"<<endl;
	cout<<"\t\t\t\t2. PACIENTES"<<endl;
	cout<<"\t\t\t\t3. CATALOGOS"<<endl;
	cout<<"\t\t\t\t4. PROCESOS"<<endl;
	cout<<"\t\t\t\t5. INFORMES"<<endl;
	cout<<"\t\t\t\t6. EXAMENES"<<endl;
	cout<<"\t\t\t\t7. BITACORA"<<endl;
	cout<<"\t\t\t\t0. EXIT"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
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
	case 3:
		//modify();
		break;
	case 4:
	//	search();
		break;
	case 5:
		//delet();
		break;
	case 6:
		//delet();
		break;
    case 7:
		//delet();
		break;
	case 0:
		//Exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 0);
	//persona empleado;
	//empleado.menu();

	getchar();
}
