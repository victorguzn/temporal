#include "ingreso.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<fstream>
#include <iomanip>
#include <time.h>

#define USER "VictorJJ"
#define PASS "123456"

ingreso::ingreso()
{
    //ctor
}

ingreso::~ingreso()
{
    //dtor
}
bool ingreso::loginUsuarios()
{
    string usuario, contra;
    int contador=0;
    bool ingreso=false;
    do{
        system("cls");
        cout <<"\t\t\t *********************************************"<<endl;;
        cout <<"\t\t\t             | LOGIN - Grupo #6 | "<<endl;
        cout <<"\t\t\t *********************************************"<<endl;
        cout <<"\t\t\t Usuario: ";
        getline(cin, usuario);
        cout<<"\n\t\t\t Contrasena: ";
        //getline(cin, contra);
        char caracter;
        caracter = getch();
        contra="";
        while (caracter != 13) //ASCII TECLA ENTER
        {
            if (caracter != 8) //ASCII TECLA RETROCESO
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b"; //Efecto caracter borrado en pantalla
                    contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña
        if (usuario==USER && contra==PASS){
            ingreso=true;
            //bitacora.setRegistro(usuario, "Login correcto");
        } else {
            cout<<"\n\n\t\t\t El usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;
            //bitacora.setRegistro(usuario, "Login incorrecto");
        }
    } while (ingreso==false && contador<3);
    if (ingreso==false){
        cout<<"\n\t\t\t Lo siento, no puede ingresar al sistema, sus contrasenas son invalidas o agoto intentos"<<endl;
        cin.get();
    } else {
        cout <<"\n\n\t\t\t ************** Ingreso Exitoso **************"<<endl;
        cin.get();
    }
    return ingreso;
}

/*void ingreso::bitacora(){

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
}*/

