#include<iomanip>

//#include "sueldos.h"
//#include "Puestos.h"
//#include "niveldeestudio.h"

//#include "hora.h"




	class paciente
    {
        private:
            string id,name,apellidos,fechanac, Genero, phone,address,estado;
        public:
            void menu();
            void insert();
            void display();
            void modify();
            void search();
            void delet();
    };


void paciente::menu(){
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PACIENTES  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Pacientes"<<endl;
	cout<<"\t\t\t 2. Despliegue Pacientes"<<endl;
	cout<<"\t\t\t 3. Modifica Pacientes"<<endl;
	cout<<"\t\t\t 4. Busca Pacientes"<<endl;
	cout<<"\t\t\t 5. Borra Pacientes"<<endl;
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
    		cout<<"\n\t\t\t Agrega otro Paciente(Y,N): ";
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
void paciente::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Pacients ---------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\tCodigo                 : ";
	cin>>id;
	cout<<"\t\t\tNombre                 : ";
	cin>>name;
	cout<<"\t\t\tApellidos              : ";
	cin>>apellidos;
	cout<<"\t\t\Fecha de nacimiento     : ";
	cin>>fechanac;
	cout<<"\t\t\tGénero                 : ";
	cin>>name;
	cout<<"\t\t\tTelefono               : ";
	cin>>phone;
	cout<<"\t\t\tDireccion              : ";
	cin>>address;
	cout<<"\t\t\tEstado               : ";
	cin>>estado;
	file.open("registropacientes.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellidos <<std::left<<std::setw(15)<< fechanac <<std::left<<std::setw(15)<< Genero <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< estado << "\n";
	file.close();
	hora();
	string filename("bitacora.dat");
	ofstream file_out;
	file_out.open("bitacora.dat", std::ios_base::app);
	file_out <<"el ultimo usuario logueado ingreso un nuevo registro de paciente con codigo:  "<< id;


}
void paciente::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Pacientes -------------------------"<<endl;
	file.open("registropacientes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n";
			cout<<"\t\t\t Id            : "<<id<<endl;
			cout<<"\t\t\t Nombre        : "<<name<<endl;
			cout<<"\t\t\t apellido      : "<<apellidos<<endl;
			cout<<"\t\t\t fecha de nacimiento        : "<<fechanac<<endl;
			cout<<"\t\t\t Genero        : "<<Genero<<endl;
			cout<<"\t\t\t Telefono      : "<<phone<<endl;
			cout<<"\t\t\t Direccion     : "<<address<<endl;
			cout<<"\t\t\t estado        : "<<estado<<endl;

			file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	getch();
}
void paciente::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles de Pacientes-------------------------"<<endl;
	file.open("registropacientes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Empleado que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record2.txt",ios::app | ios::out);
		file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
             file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellidos <<std::left<<std::setw(15)<< fechanac <<std::left<<std::setw(15)<< Genero <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< estado << "\n";
            }
			else
			{
                cout<<"\t\t\tCodigo                 : ";
                cin>>id;
                cout<<"\t\t\tNombre                 : ";
                cin>>name;
                cout<<"\t\t\tApellidos              : ";
                cin>>apellidos;
                cout<<"\t\t\Fecha de nacimiento     : ";
                cin>>fechanac;
                cout<<"\t\t\tGénero                 : ";
                cin>>name;
                cout<<"\t\t\tTelefono               : ";
                cin>>phone;
                cout<<"\t\t\tDireccion              : ";
                cin>>address;
                cout<<"\t\t\tEstado               : ";
                cin>>estado;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellidos <<std::left<<std::setw(15)<< fechanac <<std::left<<std::setw(15)<< Genero <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< estado << "\n";
				found++;


				hora();
				string filename("bitacora.dat");
	    		ofstream file_out;
    			file_out.open("bitacora.dat", std::ios_base::app);
    			file_out <<"el ultimo usuario logueado modifico el registro con id  "<<id;

			}
			file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;

		}
		file1.close();
		file.close();
		remove("registropacientes.txt");
		rename("Record2.txt","registropacientes.txt");
	}
}
void paciente::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("registropacientes.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Paciente------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Paciente------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n";
                cout<<"\t\t\t Id            : "<<id<<endl;
                cout<<"\t\t\t Nombre        : "<<name<<endl;
                cout<<"\t\t\t apellido      : "<<apellidos<<endl;
                cout<<"\t\t\t fecha de nacimiento        : "<<fechanac<<endl;
                cout<<"\t\t\t Genero        : "<<Genero<<endl;
                cout<<"\t\t\t Telefono      : "<<phone<<endl;
                cout<<"\t\t\t Direccion     : "<<address<<endl;
                cout<<"\t\t\t estado        : "<<estado<<endl;
				found++;
				hora();
				string filename("bitacora.dat");
	    		ofstream file_out;
    			file_out.open("bitacora.dat", std::ios_base::app);
    			file_out <<"se consulto la persona "<<name << "con el id: " << id ;
			}
			file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void paciente::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles del Empleado Borrar-------------------------"<<endl;
	file.open("registropacientes.txt",ios::in);
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
		file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< apellidos <<std::left<<std::setw(15)<< fechanac <<std::left<<std::setw(15)<< Genero <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< estado << "\n";
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
			file >> id >> name >> apellidos >> fechanac >> Genero >> phone >> address >> estado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}

		remove("registropacientes.txt");
		rename("Record2.txt","registropacientes.txt");
		file1.close();
		file.close();
	}
}
