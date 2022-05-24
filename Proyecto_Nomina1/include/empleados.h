#include <iostream>
#ifndef EMPLEADOS_H
#define EMPLEADOS_H
using namespace std;

class empleados
{
    public:
        public:
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
        empleados();
        virtual ~empleados();

    protected:
    private:string id,nombre,telefono;
};

#endif // EMPLEADOS_H
