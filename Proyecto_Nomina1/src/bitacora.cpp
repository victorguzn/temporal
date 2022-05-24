/*#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "bitacora.h"
#include "informe.h"
#include "empleados.h"
#include "puestos.h"
#include "generacionnomina.h"
#include "impuestos.h"
#include "ingreso.h"
#include "menus.h"

void bitacora::menubitacora()
{
    bitacora::limpiarpantalla();
    int opcion;

    cout<<"______________________________"<<endl;
    cout<<"---------| BITACORA |---------"<<endl;
    cout<<"______________________________"<<endl;

    cout<<"-"<<endl;
    cout<<"Bienvenido al menu de la bitacora �que deseas hacer?"<<endl;
    cout<<"Selecciona la opcion 1 o 2"<<endl;
    cout<<"   1. Visualizar registros"<<endl;
    cout<<"   2. Salir"<<endl;
    cin>>opcion;
    menus bita;

    if(opcion == 1){

        bitacora::limpiarpantalla();

        cout<<"____________________________________________"<<endl;
        cout<<"---- BITACORA (ENTRADAS REGISTRADAS) ------ "<<endl;
        cout<<"--------------------------------------------"<<endl;

        bitacora::verentradas();

        system("pause");
        return ;
    }

    if(opcion == 2){
        bita.menuGeneral();
    }
}

void bitacora::limpiarpantalla(){
    system("cls");
}

void ingreso::bitacora(){

    system("cls");

    string accion = "";

    time_t tiempo;
    tiempo = time(NULL);
    struct tm * fecha;
    fecha = localtime(&tiempo);

    string usuario = USER;
    accion = "Ha ingresado al sistema";

    ofstream archivo("BITACORA.dat", ios::binary | ios::app | ios::out);

    if(!archivo){
        cout<<"El archivo de Bitacora no existe, por lo que se ha creado uno"<<endl;
        exit(0);
    }

    archivo<<std::left<<std::setw(15)<< "Código" <<std::left<<std::setw(15)<< usuario <<std::left<<std::setw(15)<< "Acción realizada: " <<std::left<<std::setw(15)<< accion<<std::left<<std::setw(15)<< "Día: " <<std::left<<std::setw(15)<< fecha->tm_mday <<std::left<<std::setw(15)<< "Mes: " <<std::left<<std::setw(15)<< fecha->tm_mon+1<<std::left<<std::setw(15)<< "Año: " <<std::left<<std::setw(15)<< fecha->tm_year+1900<<std::left<<std::setw(15)<< "Hora: " <<std::left<<std::setw(15)<< fecha->tm_hour<<std::left<<std::setw(15)<< "Minuto: " <<std::left<<std::setw(15)<< fecha->tm_min<<std::left<<std::setw(15)<< "Segundo: " <<std::left<<std::setw(15)<< fecha->tm_sec<<"\n";

    archivo.close();
}

*/
