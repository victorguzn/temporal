#include <iostream>
#ifndef EMPLEADOS_H
#define EMPLEADOS_H
#include "menus.h"

using namespace std;

class Puestos
{
    public:
        public:
        void menuprincipalpuestos();
		void insert();
		void desplegar();
		void modificar();
		void search();
		void eliminar();
        Puestos();
        virtual ~Puestos();

    protected:
    private:string id,nombrepuesto, area, segmento, salario, vacantes;
};

#endif // EMPLEADOS_H
