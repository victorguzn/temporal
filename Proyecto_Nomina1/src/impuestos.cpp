#include <iostream>

using namespace std;

#include <cstring>
#include "impuestos.h"

impuestos::impuestos(int valorNumeroId, string valorUsuario, double valorSueldo)
{
    establecerNumeroId(valorNumeroId);
    establecerUsuario(valorUsuario);
    establecerSueldo(valorSueldo);
}
int impuestos::obtenerNumeroId() const
{
    return numeroId;
}
void impuestos::establecerNumeroId(int valorNumeroId)
{
    numeroId = valorNumeroId;
}
string impuestos::obtenerUsuario() const
{
    return usuario;
}
void impuestos::establecerUsuario(string usuarioString)
{
    const char *valorUsuario = usuarioString.data();
    int longitud = strlen( valorUsuario );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( usuario, valorUsuario, longitud );

    usuario [longitud] = '\0';
}
double impuestos::obtenerSueldo() const
{
    return sueldo;
}
void impuestos::establecerSueldo(double valorSueldo)
{
    sueldo = valorSueldo;
}
