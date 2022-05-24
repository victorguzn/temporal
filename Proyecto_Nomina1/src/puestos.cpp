#include <iostream>
#include "empleados.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "puestos.h"
#include "menus.h"

using namespace std;

Puestos::Puestos(){
 int ID;
 string nombrepuesto, area, segmento, salario, vacantes;
}

Puestos::~Puestos(){

}

void Puestos::menuprincipalpuestos()
{
    int opcion;
	int x;

	do{

	system("cls");

	cout<<"----------------------------------------"<<endl;
	cout<<"\t\t |   GDUR DE PUESTOS DE TRABAJO  |"<<endl;
	cout<<"----------------------------------------"<<endl;

	cout<<"\t 1. Ingresar datos de nuevos puestos de trabajo"<<endl;
	cout<<"\t 2. Desplegar puestos de trabajo actuales"<<endl;
	cout<<"\t 3. Buscar puestos de trabajo actuales"<<endl;
	cout<<"\t 4. Modificar puestos de trabajo actuales"<<endl;
	cout<<"\t 5. Eliminar puestos de trabajo actuales"<<endl;
	cout<<"\t 6. Salir"<<endl;

    cout<<"-"<<endl;

    cout<<"\n\t RESPUESTA: ";
    cin>>opcion;
    menus pueston;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		nuevopuesto();
    		cout<<"\n\t �Agregar un nuevo puesto?"<<endl;
    		cout<<"\n\t 1. Si"<<endl;
    		cout<<"\n\t 2. No"<<endl;
    		cout<<"-"<<endl;
    		cout<<"\n\t RESPUESTA:";
    		cin>>x;
		}while(x==1);
		break;
	case 2:
		verpuestos();
		break;
    case 3:
        search();
        break;
    case 4:
        modificapuestos();
        break;
    case 5:
        borrapuestos();
        break;
    case 6:
        pueston.menuGeneral();
        break;
	default:
		cout<<"\n\t Por favor, elegir un numero del 1 al 3 segun dice la pantalla";
	}
	getch();
    }while(opcion!= 2);
}

void Puestos::nuevopuesto()
{
	system("cls");
	fstream archivo, archivo2;
	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n----------------------------------- INGRESO DE DATOS ----------------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

    cout<<"\tIngresa ID del puesto de trabajo: ";
	cin>>ID;

	cout<<"\tIngresa nombre del puesto de trabajo: ";
	cin>>nombrepuesto;

	cout<<"\tIngresa el area de trabajo de dicho puesto: ";
	cin>>area;

	cout<<"\tIngresa el segmento de dicho puesto: ";
	cin>>segmento;

	cout<<"\tIngresa el salario minimo de dicho puesto: ";
	cin>>salario;

	cout<<"\t�Hay vacantes disponibles? �Cuantas? ";
	cin>>vacantes;

    archivo.open("puestosdetrabajo.dat", ios::binary | ios::app | ios::out);
    archivo2.open("puestosdetrabajo2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< ID <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&ID),
         sizeof( ID ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombrepuesto),
         sizeof( nombrepuesto ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&area),
         sizeof( area ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&segmento),
         sizeof( segmento ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&salario),
         sizeof( salario ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&vacantes),
        sizeof( vacantes ) );
    }
}

void Puestos::verpuestos()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- VISUALIZACION DE PUESTOS ACTUALES --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has a�adido ninguna informacion al sistema";
		archivo.close();
	}

	else
	{
		archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			total++;
			cout<<"\n\n\t ID: "<< ID <<endl;
			cout<<"\n\n\t Puesto de trabajo: "<< nombrepuesto <<endl;
			cout<<"\t Area: "<< area <<endl;
			cout<<"\t Segmento: "<< segmento <<endl;
			cout<<"\t Salario minimo: "<< salario <<endl;
			cout<<"\t Vacantes: "<< vacantes <<endl;
			archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}
		if(total==0)
		{
			cout<<"\n\t No ha insertado informacion, por favor verifica o empieza a ingresar datos";
		}
	}

	cout<<"Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion;

    if(opcion = 1){
        menuprincipalpuestos();
    }
}

void Puestos::search(){

    system("cls");
	fstream archivo;

	int encontrado=0;

	archivo.open("puestosdetrabajo.dat",ios::app | ios::binary | ios::in);

	if(!archivo){
    cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- DATOS DE PUESTOS ACTUALES --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\tLo siento, no hay información insertada qué visualizar. Empieza a insertar datos.";
	}

	else
	{
		int busqueda_ID;
        cout<<"\n______________________________________________________________________________________"<<endl;
        cout<<"\n------------------------- DATOS DE PUESTOS ACTUALES --------------------------"<<endl;
        cout<<"\n--------------------------------------------------------------------------------------"<<endl;
		cout<<"\nIngrese ID del empleado que quiere buscar: ";
		cin>>busqueda_ID;

		archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			if(busqueda_ID==ID)
			{
				cout<<"\n\n\t\t\t ID del puesto de trabajo: "<<ID<<endl;
				cout<<"\t\t\t Nombre del puesto de trabajo: "<<nombrepuesto<<endl;
				cout<<"\t\t\t Área del puesto de trabajo: "<<area<<endl;
				cout<<"\n\n\t\t\t Segmento del puesto de trabajo: "<<segmento<<endl;
				cout<<"\t\t\t Salario medio del puesto de trabajo: "<<salario<<endl;
				cout<<"\t\t\t Vacantes disponibles: "<<vacantes<<endl;
				encontrado++;
			}

			archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}


		if(encontrado==0)
		{
			cout<<"\n\t\t\t Puesto de trabajo no encontrado. Empieza a ingresar datos.";
		}
		archivo.close();
	}

}

void Puestos::modificapuestos(){
	system("cls");

	fstream archivo, auxiliar;
	int buscar_ID;

	int encontrar = 0;

	cout<<"\n-------------------------Modificacion de Informacion de Empleados-------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo){
		cout<<"\n\t\t\tNo hay informacion..,";
		archivo.close();
	}

	else{
		cout<<"\n Ingrese Id del empleado que quiere modificar: ";
		cin>>buscar_ID;

		auxiliar.open("auxiliar.dat",ios::binary|ios::app | ios::out);

		archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			if(buscar_ID!=ID)
			{
			 auxiliar<<std::left<<std::setw(15)<< ID <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
			}

			else
			{
                cout<<"\t\t\tIngrese nuevo ID: ";
				cin>>ID;
				cout<<"\t\t\tIngrese nuevo nombre: ";
				cin>>nombrepuesto;
				cout<<"\t\t\tIngrese nueva área: ";
				cin>>area;
				cout<<"\t\t\tIngrese nuevo segmento de trabajo: ";
				cin>>segmento;
				cout<<"\t\t\tIngrese nuevo salario: ";
				cin>>salario;
                cout<<"\t\t\tIngrese nuevo número de vacantes: ";
				cin>>vacantes;
				auxiliar<<std::left<<std::setw(15)<< ID <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
				encontrar++;
			}

			archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		}
		auxiliar.close();
		archivo.close();
		remove("puestosdetrabajo.dat");
		rename("auxiliar.dat","puestosdetrabajo.dat");
	}
}


void Puestos::borrapuestos(){

    system("cls");

	fstream archivo, auxiliar;

	int buscar_ID;

	int encontrar=0;

	cout<<"\n-------------------------Informacion del Empleado a Borrar-------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		archivo.close();
	}

	else
	{
		cout<<"\n Ingrese el Id del empleado que quiere borrar: ";
		cin>>buscar_ID;

		auxiliar.open("auxiliar.dat",ios::binary|ios::app | ios::out);

		archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			if(buscar_ID!= ID){
				auxiliar<<std::left<<std::setw(15)<< ID <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
			}

			else{
				encontrar++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}

			archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}

		if(encontrar==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}

		auxiliar.close();
		archivo.close();
		remove("puestosdetrabajo.dat");
		rename("auxiliar.dat","puestosdetrabajo.dat");
	}

}


/*archivo >> ID >> nombrepuesto >> area >> segmento >> salario >> vacantes;

				cout<<"\t\t\tIngrese Id del Empleado: ";
				cin>>ID;
				cout<<"\t\t\tIngrese Nombre del Empleado: ";
				cin>>nombrepuesto;
				cout<<"\t\t\tIngrese Telefono del Empleado: ";
				cin>>area;
				cout<<"\t\t\tIngrese Nombre del Empleado: ";
				cin>>segmento;
				cout<<"\t\t\tIngrese Telefono del Empleado: ";
				cin>>salario;
                cout<<"\t\t\tIngrese Nombre del Empleado: ";
				cin>>vacantes;
				archivo3<<std::left<<std::setw(15)<< ID <<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";
				encontrar++;
*/
