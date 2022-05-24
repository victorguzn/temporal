#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "informe.h"
#include "menus.h"

using namespace std;

informe::informe()
{
    //ctor
}

informe::~informe()
{
    //dtor
}
void informe::menu()
{
    int choice;
    char x;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t      | Informes de nomina - Grupo 6 |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Crear informes"<<endl;
        cout << "\t\t\t  2. Ver Informes"<<endl;
        cout << "\t\t\t  3. Borrar Informes"<<endl;
        cout << "\t\t\t  4. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;
        menus gomu;

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
		delet();
		break;
	case 4:
		gomu.menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 4);
}
void informe::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar datos del informe ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa la fecha         : ";
	cin>>fecha;
	cout<<"\t\t\tIngresa ID del empleado         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del empleado     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa apellido del empleado   : ";
	cin>>apellido;
	cout<<"\t\t\tIngresa puesto del empleado   : ";
	cin>>puesto;
	cout<<"\t\t\tIngresa los dias laborados   : ";
	cin>>dias;
	cout<<"\t\t\tIngresa sueldo del empleado   : Q";
	cin>>sueldo;
    file.open("registroDeInformes.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido<<std::left<<std::setw(15)<< puesto<<std::left<<std::setw(15)<< dias<<std::left<<std::setw(15)<<sueldo<< "\n";
	file.close();
	 for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&id),
         sizeof( id ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&apellido),
         sizeof( apellido ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&puesto),
         sizeof( puesto ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
        reinterpret_cast<const char*>(&dias),
        sizeof( dias ) );
    }
    for( int i = 0; i < 50; i++ ){
      file.write(
        reinterpret_cast<const char*>(&sueldo),
        sizeof( sueldo ) );
    }
}
void informe::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Informes de nomina ----------------------------------------------------------------------------"<<endl;
	file.open("registroDeInformes.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> fecha >> id >> nombre >> apellido >> puesto >> dias >> sueldo;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Fecha del informe: "<<fecha<<endl;
			cout<<"\t\t\t ID del Empleado: "<<id<<endl;
			cout<<"\t\t\t Nombre del Empleado: "<<nombre<<endl;
			cout<<"\t\t\t Apellido del Empleado: "<<apellido<<endl;
			cout<<"\t\t\t Puesto del Empleado: "<<puesto<<endl;
			cout<<"\t\t\t Dias Laborados: "<<dias<<endl;
			cout<<"\t\t\t Sueldo del Empleado: Q"<<sueldo<<endl;
			cout<<"\n------------------------------------------------------------------------------------------------------------------------";
			file >> fecha >> id >> nombre >> apellido >> puesto >> dias >> sueldo;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void informe::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Informe a Borrar-------------------------"<<endl;
	file.open("registroDeInformes.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del empleado que quiere borrar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> fecha >> id >> nombre >> apellido >> puesto >> dias >> sueldo;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file<<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido<<std::left<<std::setw(15)<< puesto<<std::left<<std::setw(15)<< dias<<std::left<<std::setw(15)<<sueldo<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> fecha >> id >> nombre >> apellido >> puesto >> dias >> sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeInformes.dat");
		rename("registro.dat","registroDeInformes.dat");
	}
}
