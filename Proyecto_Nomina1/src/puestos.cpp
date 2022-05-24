#include <iostream>
#include "puestos.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menus.h"

using namespace std;

Puestos::Puestos()
{
 string id,nombrepuesto, area, segmento, salario, vacantes;
}

Puestos::~Puestos()
{

}

void Puestos::menuprincipalpuestos(){

    int eleccion;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION EMPLEADOS  |"<<endl;
	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\tElige un número del 1 al 6 según lo que desees hacer"<<endl;
	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de nuevos puestos de trabajo"<<endl;
	cout<<"\t\t\t 2. Despliegue de puestos de trabajo"<<endl;
	cout<<"\t\t\t 3. Modificar puestos de trabajo"<<endl;
	cout<<"\t\t\t 4. Buscar puestos de trabajo"<<endl;
	cout<<"\t\t\t 5. Borrar puestos de trabajo"<<endl;
	cout<<"\t\t\t 6. Salir"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Elige qué deseas hacer: ";
    cin>>eleccion;
    menus pueston;

    switch(eleccion)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agregar otro puesto de trabajo(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		search();
		break;
	case 5:
		eliminar();
		break;
	case 6:
		pueston.menuGeneral();
	default:
		cout<<"\n\t\t\t Opcion no valida. Elige otro número";
	}
	getch();
    }while(eleccion!= 6);
}

void Puestos::insert(){

	system("cls");
	fstream archivo;

	cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n-------------------------------------------------Agregar puestos de trabajo ---------------------------------------------"<<endl;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"\t\t\tIngresa ID del puesto de trabajo: ";
	cin>>id;

	cout<<"\t\t\tIngresa Nombre del puesto de trabajo: ";
	cin>>nombrepuesto;

	cout<<"\t\t\tIngresa el area de trabajo: ";
	cin>>area;

	cout<<"\t\t\tIngresa segmento del puesto de trabajo: ";
	cin>>segmento;

	cout<<"\t\t\tIngresa el salario medio del puesto de trabajo: ";
	cin>>salario;

    cout<<"\t\t\tIngresa el número de vacantes disponible del puesto de trabajo: ";
	cin>>vacantes;

    archivo.open("puestosdetrabajo.dat", ios::binary | ios::app | ios::out);
	archivo<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area<< std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";

	archivo.close();
}

void Puestos::desplegar(){

	system("cls");
	fstream archivo;

	int total=0;

	cout<<"\n----------------------------------------------------------------------------------------"<<endl;
	cout<<"\n-------------------------Tabla de información de puestos de trabajo -------------------------"<<endl;
	cout<<"\n----------------------------------------------------------------------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información. Empieza a añadir desde el menú principal";
		archivo.close();
	}

	else
	{
		archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID puesto de trabajo: "<<id<<endl;
			cout<<"\t\t\t Puesto de trabajo: "<<nombrepuesto<<endl;
			cout<<"\t\t\t Area de trabajo: "<<area<<endl;
            cout<<"\n\n\t\t\t Segmento de trabajo: "<<segmento<<endl;
			cout<<"\t\t\t Salario medio: "<<salario<<endl;
			cout<<"\t\t\t Vacantes disponibles: "<<vacantes<<endl;
			archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}

		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion disponible";
		}
	}
	archivo.close();
}

void Puestos::modificar()
{
	system("cls");
	fstream archivo,archivo1;

	string buscar_id;
	int encontrar=0;

	cout<<"\n------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n-------------------Menú de modificación de datos de puestos de trabajo--------------------"<<endl;
	cout<<"\n------------------------------------------------------------------------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay informacion disponible";
		archivo.close();
	}

	else
	{
		cout<<"\n Ingrese Id del puesto de trabajo que quiere modificar: ";
		cin>>buscar_id;

		archivo1.open("puestos.dat",ios::binary|ios::app | ios::out);
		archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof()){

			if(buscar_id!=id)
			{
			 archivo1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area<< std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
			}

			else
			{
				cout<<"\t\t\tIngrese ID del puesto de trabajo: ";
				cin>>id;
				cout<<"\t\t\tIngrese nuevo puesto de trabajo: ";
				cin>>nombrepuesto;
				cout<<"\t\t\tIngrese area de trabajo: ";
				cin>>area;
				cout<<"\t\t\tIngrese segmento de trabajo: ";
				cin>>segmento;
				cout<<"\t\t\tIngrese salario medio del puesto de trabajo: ";
				cin>>salario;
				cout<<"\t\t\tIngrese numero de vacantes disponible: ";
				cin>>vacantes;
				archivo1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area<< std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
				encontrar++;
			}

			archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		}
		archivo1.close();
		archivo.close();
		remove("puestosdetrabajo.dat");
		rename("puestos.dat","puestosdetrabajo.dat");
	}
}

void Puestos::search()
{
	system("cls");
	fstream archivo;
	int encontrar=0;
	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);
	if(!archivo)
	{
	    cout<<"\n---------------------------------------------------------------------------"<<endl;
		cout<<"\n-------------------------Datos del empleado buscado------------------------"<<endl;
		cout<<"\n---------------------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion disponible";
	}

	else
	{
		string buscar_id;
		cout<<"\n---------------------------------------------------------------------------"<<endl;
		cout<<"\n-------------------------Datos del empleado buscado------------------------"<<endl;
		cout<<"\n---------------------------------------------------------------------------"<<endl;
		cout<<"\nIngrese ID del puesto de trabajo que quiere buscar: ";
		cin>>buscar_id;

		archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			if(buscar_id==id)
			{
				cout<<"\n\n\t\t\t ID puesto de trabajo: "<<id<<endl;
                cout<<"\t\t\t Puesto de trabajo: "<<nombrepuesto<<endl;
                cout<<"\t\t\t Area de trabajo: "<<area<<endl;
                cout<<"\n\n\t\t\t Segmento de trabajo: "<<segmento<<endl;
                cout<<"\t\t\t Salario medio: "<<salario<<endl;
                cout<<"\t\t\t Vacantes disponibles: "<<vacantes<<endl;
				encontrar++;
			}
			archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}
		if(encontrar==0)
		{
			cout<<"\n\t\t\t Puesto de trabajo no encontrado. Por favor verificar";
		}
		archivo.close();
	}
}


void Puestos::eliminar()
{
	system("cls");
	fstream archivo, archivo1;

	string buscar_id;
	int encontrar=0;

	cout<<"\n-----------------------------------------------------------------------------------"<<endl;
	cout<<"\n-----------------------Menú para eliminación de información-----------------------"<<endl;
	cout<<"\n-----------------------------------------------------------------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo){
		cout<<"\n\t\t\tNo hay informacion disponible";
		archivo.close();
	}

	else
	{
		cout<<"\n Ingrese el ID del puesto de trabajo que desee borrar: ";
		cin>>buscar_id;

		archivo1.open("registro.dat",ios::binary|ios::app | ios::out);

		archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			if(buscar_id!= id)
			{
				archivo1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area<< std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
			}
			else
			{
				encontrar++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			archivo >> id >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}

		if(encontrar==0)
		{
			cout<<"\n\t\t\t ID de puesto de trabajo no encontrado. Por favor, verificar";
		}

		archivo1.close();
		archivo.close();
		remove("puestosdetrabajo.dat");
		rename("puestoss.dat","puestosdetrabajo.dat");
	}
}
