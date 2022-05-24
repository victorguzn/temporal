#include "conceptos.h"
#include "menus.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

conceptos::conceptos()
{
    //ctor
}

conceptos::~conceptos()
{
    //dtor
}
void conceptos::menu()
{
    int choice;
    char x;
    do

    {
    system("cls");
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t             | MENU DE CONCEPTOS |            "<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t 1. Ingresar nuevo concepto"<<endl;
    cout << "\t\t\t 2. Buscar conceptos"<<endl;
    cout << "\t\t\t 3. Desplegar Conceptos"<<endl;
    cout << "\t\t\t 4. Borrar Conceptos"<<endl;
    cout << "\t\t\t 5. Salir"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Ingresa tu opcion [1/2/3/4/5]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion: ";
    cin>>choice;
    menus punto;
    switch(choice)
        {
            case 1:
                insertar();
                break;
            case 2:
                buscar();
                break;
            case 3:
                desplegar();
                break;
            case 4:
                borrar();
                break;
            case 5:
                punto.menuGeneral();
                break;
            default:
                cout<<"\n\t\t\t Hubo un error, intentalo nuevamente"<<endl;

        }
        getch();
    }while(choice!= 5);
}
void conceptos::insertar()
{
    string id, nombre, efecto, estado, valor;
    system("cls");
    fstream archivo, archivo2;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t              | NUEVO CONCEPTO |              "<<endl;
    cout << "\t\t\t *********************************************"<<endl;

    cout << "\t\t\t Ingrese ID del concepto: ";
    cin >> id;
    cout << "\t\t\t Ingrese Nombre del Concepto: ";
    cin >> nombre;
    cout << "\t\t\t Ingrese efecto del concepto: ";
    cin >> efecto;
    cout << "\t\t\t Ingrese estado del concepto: ";
    cin >> estado;
    cout << "\t\t\t Ingrese el valor del concepto: ";
    cin >> valor;

    archivo.open("conceptos.dat", ios::binary | ios::app | ios::out);
    archivo2.open("conceptos2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< efecto <<std::left<<std::setw(15)<< estado <<std::left<<std::setw(15)<< valor<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&id),
         sizeof( id ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&efecto),
         sizeof( efecto ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&estado),
         sizeof( estado ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&valor),
        sizeof( valor ) );
    }
}
void conceptos::buscar()
{
    string id, nombre, efecto, estado, valor;
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t              | CONCEPTOS |                   "<<endl;
	cout << "\t\t\t *********************************************"<<endl;

	archivo.open("conceptos.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\t No hay ninguna informacion en el sistema";
		archivo.close();
	}

	else
	{
		string participant_id;
		cout<<"\n\t\t\t Ingrese Id del concepto que quiere buscar: ";
		cin>>participant_id;
        system("cls");

        archivo >> id >> nombre >> efecto >> estado >> valor;
		while(!archivo.eof())
	{
            if(participant_id==id)
		{

            cout << "\t\t\t *********************************************"<<endl;
            cout << "\t\t\t              | CONCEPTOS |                   "<<endl;
            cout << "\t\t\t *********************************************"<<endl;
            cout << "\n\t\t\t Id concepto : "<< id << endl;
            cout << "\t\t\t Nombre del concepto: "<< nombre <<endl;
            cout << "\t\t\t Efecto del concepto: "<< efecto <<endl;
            cout << "\t\t\t Estado del concepto: "<< estado <<endl;
            cout << "\t\t\t Valor del concepto: "<< valor <<endl;

			total++;

		}
		        archivo >> id >> nombre >> efecto >> estado >> valor;
	}

		if(total==0)
		{
			cout<<"\n\t\t\t No hay informacion almacenada";
		}
		archivo.close();
	}

}
void conceptos::desplegar()
{
    system("cls");
    string id, nombre, efecto, estado, valor;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t              | CONCEPTOS |                   "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("conceptos.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> efecto >> estado >> valor;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID del concepto: "<<id<<endl;
			cout<<"\t\t\t Nombre del concepto: "<<nombre<<endl;
			cout<<"\t\t\t Efecto del concepto: "<<efecto<<endl;
			cout<<"\t\t\t Estado del concepto: "<<estado<<endl;
			cout<<"\t\t\t Valor del concepto: "<<valor<<endl;

			archivo >> id >> nombre >> efecto >> estado >> valor;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}archivo.close();

	char ctrl;
	cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        menu();
    }
}
void conceptos::borrar()
{
    string id, nombre, efecto, estado, valor;
    system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t           | Borrar Informacion |"<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("conceptos.dat",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del concepto que quiere borrar: ";
		cin>>id_persona;
		file1.open("registro.dat",ios::binary | ios::app | ios::out);
		file >> id >> nombre >> efecto >> estado >> valor;
		while(!file.eof())
		{
			if(id_persona!= id)
			{
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< efecto <<std::left<<std::setw(10)<< estado <<std::left<<std::setw(10)<< valor <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> efecto >> estado >> valor;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("conceptos.dat");
		rename("registro.dat","conceptos.dat");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}
