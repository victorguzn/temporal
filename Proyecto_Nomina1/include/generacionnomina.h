#include <iostream>
#ifndef GENERACIONNOMINA_H
#define GENERACIONNOMINA_H

using namespace std;

class generacionnomina
{
    public:
        public:
        void menuprincipalgeneracionnomina();
		void generar();
		void vernominas();
        generacionnomina();
        virtual ~generacionnomina();

    protected:
        private:
            double horast, sueldomedio, iva, sueldofinal, sueldoiva, bonificacion, sueldobonificacion, isr, sueldoisr, igss, sueldoigss, sueldocomb;
};

#endif // GENERACIONNOMINA_H
