#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "generacionnomina.h"
#include "empleados.h"
#include "menus.h"

using namespace std;

generacionnomina::generacionnomina(){
 double horast, sueldomedio, iva, sueldofinal, sueldoiva, isr, sueldoisr, igss, sueldoigss, bonificacion, sueldobonificacion, sueldocomb;
}

generacionnomina::~generacionnomina(){

}

void generacionnomina::menuprincipalgeneracionnomina()
{
    int opcion;
	int x;

	do{

	system("cls");

	cout<<"------------------------------------------------------"<<endl;
	cout<<"\t\t ||||          GENERACION DE NOMINAS           ||||"<<endl;
	cout<<"------------------------------------------------------"<<endl;

	cout<<"\t 1. Ingresar datos de nueva nomina"<<endl;
	cout<<"\t 2. Ver nominas actuales"<<endl;
	cout<<"\t 3. Salir"<<endl;

    cout<<"-"<<endl;

    cout<<"\n\t RESPUESTA: ";
    cin>>opcion;
    menus genera;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		generar();
    		cout<<"\n\t �Deseas generar una nueva nomina?"<<endl;
    		cout<<"\n\t 1. Si"<<endl;
    		cout<<"\n\t 2. No"<<endl;
    		cout<<"-"<<endl;
    		cout<<"\n\t RESPUESTA:";
    		cin>>x;
		}while(x==1);
		break;
	case 2:
		vernominas();
		break;
    case 3:
        genera.menuGeneral();
	default:
		cout<<"\n\t Por favor, elegir un numero del 1 al 5 segun dice la pantalla";
	}
	getch();
    }while(opcion!= 2);
}

void generacionnomina::generar()
{
	system("cls");
	fstream archivo, archivo2;
	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n----------------------------------- INGRESO DE DATOS ----------------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	cout<<"\tIngresa el sueldo medio: ";
	cin>>sueldomedio;

	cout<<"\tIngresa las horas trabajadas durante el mes: ";
	cin>>horast;

	iva = 0.12;
	isr = 0.5;
	bonificacion = 0;
	igss = 4.83;

	sueldoiva = sueldomedio * iva;
	sueldoisr = sueldomedio * isr;
	sueldoigss = sueldomedio * (igss * 0.01);

	sueldocomb = sueldomedio - sueldoiva - sueldoisr - sueldoigss;

	if(horast > 160){
        bonificacion = 200.00;
        sueldobonificacion = bonificacion + sueldomedio;
        sueldofinal = sueldocomb + ((horast - 160) * 50) + sueldobonificacion;
	}

	else{
        sueldofinal = sueldocomb;
	}

    archivo.open("nominasgeneradas.dat", ios::binary | ios::app | ios::out);
    archivo2.open("nominasgeneradas2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< sueldomedio <<std::left<<std::setw(15)<< horast <<std::left<<std::setw(15)<< iva <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< bonificacion << std::left<<std::setw(15)<< sueldofinal<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldomedio),
         sizeof( sueldomedio ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&horast),
         sizeof( horast ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&iva),
         sizeof( iva ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&isr),
         sizeof( isr ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&igss),
         sizeof( igss ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&bonificacion),
         sizeof( bonificacion ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&sueldofinal),
        sizeof( sueldofinal ) );
    }
}

void generacionnomina::vernominas()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- VISUALIZACION DE NOMINAS GENERADAS --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	archivo.open("nominasgeneradas.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has generado ninguna nomina al sistema";
		archivo.close();
	}

	else
	{
		archivo >> sueldomedio >> horast >> iva >> bonificacion >> isr >> igss >> sueldofinal;

		while(!archivo.eof())
		{
			total++;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"|                     CUADRO DE NOMINAS                     |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"\n| Sueldo medio:               |"<< sueldomedio <<"                            |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Horas trabajadas:           |"<< horast <<"                            |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| IVA:                        |"<< iva <<"                         |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| BONIFICACIÓN:              |"<< bonificacion <<"                         |" <<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| ISR:                        |"<< isr <<"                          |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| IGSS:                       |"<< igss <<"                            |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Sueldo final                |"<< sueldofinal <<"                       |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;

			archivo >> sueldomedio >> horast >> iva >> bonificacion >> isr >> igss >> sueldofinal;

		}
		if(total==0)
		{
			cout<<"\n\t No ha insertado informacion, por favor verifica o empieza a ingresar datos";
		}
	}

	cout<<"\t ."<<endl;
	cout<<"\t NOTA: Toma en cuenta que m�s de 160 horas laboradas durante el mes"<<endl;
	cout<<"\t implicaran 50 quetzales a�adidos en el sueldo por cada hora extra"<<endl;
	cout<<"-"<<endl;
	cout<<"\t Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion;

    if(opcion = 1){
        menuprincipalgeneracionnomina();
    }
}
