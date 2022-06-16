#include<iomanip>

//#include "sueldos.h"
//#include "Puestos.h"
//#include "niveldeestudio.h"

//#include "hora.h"




	class persona
    {
        private:
            string id,name,apellido,phone,DPI,address,fechanac;
        public:
            void menu();
            void insert();
            void display();
            void modify();
            void search();
            void delet();
    };


void persona::menu(){
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PERSONAS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Empleados"<<endl;
	cout<<"\t\t\t 2. Despliegue Empleados"<<endl;
	cout<<"\t\t\t 3. Modifica Empleados"<<endl;
	cout<<"\t\t\t 4. Busca Empleados"<<endl;
	cout<<"\t\t\t 5. Borra Empleados"<<endl;
	//cout<<"\t\t\t 10. Mostrar bitacora"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void persona::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Empleados ---------------------------------------------"<<endl;
	cout<<"\t\t\tId        : ";
	cin>>id;
	cout<<"\t\t\tNombre    : ";
	cin>>name;
	cout<<"\t\t\tApellido : ";
	cin>>apellido;
	cout<<"\t\t\tTelefono  : ";
	cin>>phone;
	cout<<"\t\t\tDireccion : ";
	cin>>address;
	cout<<"\t\t\tFecha de nacimiento: ";
	cin>>fechanac;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< fechanac  << "\n";
	file.close();
	hora();
	string filename("bitacora.dat");
	ofstream file_out;
	file_out.open("bitacora.dat", std::ios_base::app);
	file_out <<"el ultimo usuario logueado ingreso un nuevo registro con id:  "<< id;


}
void persona::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Empleados -------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> apellido >> phone >>  address >> fechanac;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id            : "<<id<<endl;
			cout<<"\t\t\t Nombre        : "<<name<<endl;
			cout<<"\t\t\t Apellido      : "<<apellido<<endl;
			cout<<"\t\t\t Telefono      : "<<phone<<endl;
			cout<<"\t\t\t Direccion     : "<<address<<endl;
			cout<<"\t\t\t fecha de nacimiento     : "<<fechanac<<endl;
			file >> id >> name >> apellido >> phone >>  address >> fechanac;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	getch();
}
void persona::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles de Empleados-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Empleado que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> apellido >> phone >>  address >> fechanac;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
             file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< fechanac  << "\n";
            }
			else
			{
                cout<<"\t\t\tId        : ";
                cin>>id;
                cout<<"\t\t\tNombre    : ";
                cin>>name;
                cout<<"\t\t\tApellido : ";
                cin>>apellido;
                cout<<"\t\t\tTelefono  : ";
                cin>>phone;
                cout<<"\t\t\tDireccion : ";
                cin>>address;
                cout<<"\t\t\tFecha de nacimiento: ";
                cin>>fechanac;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< fechanac  << "\n";
				found++;


				hora();
				string filename("bitacora.dat");
	    		ofstream file_out;
    			file_out.open("bitacora.dat", std::ios_base::app);
    			file_out <<"el ultimo usuario logueado modifico el registro con id  "<<id;

			}
			file >> id >> name >> apellido >> phone >>  address >> fechanac;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
void persona::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Empleado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Empleado------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> apellido >> phone >>  address >> fechanac;
		while(!file.eof())
		{
			if(participant_id==id)
			{
                cout<<"\n\n\t\t\t Id            : "<<id<<endl;
                cout<<"\t\t\t Nombre        : "<<name<<endl;
                cout<<"\t\t\t Apellido      : "<<apellido<<endl;
                cout<<"\t\t\t Telefono      : "<<phone<<endl;
                cout<<"\t\t\t Direccion     : "<<address<<endl;
                cout<<"\t\t\t fecha de nacimiento     : "<<fechanac<<endl;
                found++;
				hora();
				string filename("bitacora.dat");
	    		ofstream file_out;
    			file_out.open("bitacora.dat", std::ios_base::app);
    			file_out <<"se consulto la persona "<<name << "con el id: " << id ;
			}
			file >> id >> name >> apellido >> phone >>  address >> fechanac;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void persona::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles del Empleado Borrar-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Empleado que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> apellido >> phone >>  address >> fechanac;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< fechanac  << "\n";
			}
			else
			{
				found++;

				hora();
				string filename("bitacora.dat");
    			ofstream file_out;
    			file_out.open("bitacora.dat", std::ios_base::app);
    			file_out <<"el ultimo usuario logueado elimino el registro con id  "<<id;
				cout << "\n\t\t\tBorrado de informacion exitoso";


			}
			file >> id >> name >> apellido >> phone >>  address >> fechanac;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}

		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
		file1.close();
		file.close();
	}
}
