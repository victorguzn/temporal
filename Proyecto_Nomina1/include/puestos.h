#include <iostream>
#ifndef PUESTOS_H
#define PUESTOS_H
using namespace std;

class Puestos
{
    public:
        public:
        void menuprincipalpuestos();
		void nuevopuesto();
		void verpuestos();
		void modificapuestos();
		void search();
		void borrapuestos();
        Puestos();
        virtual ~Puestos();

    protected:
        private:
            int ID;
            string nombrepuesto, area, segmento, salario, vacantes;
};

#endif
