#ifndef INFORME_H
#define INFORME_H

using namespace std;

class informe
{
    public:
        informe();
        virtual ~informe();
        void menu();
        void insert();
		void display();
		void delet();

    protected:

    private:
        string id,fecha,nombre,apellido,puesto;
        double sueldo;
        int dias;
};

#endif // INFORME_H
