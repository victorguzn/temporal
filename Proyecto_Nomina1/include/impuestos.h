#ifndef IMPUESTOS_H
#define IMPUESTOS_H
#include <iostream>

using namespace std;

class impuestos
{
    public:
        impuestos(int = 0, string = "", double = 0);

    int escribirOpcion();
    void crearArchivoCredito();
    void nuevoRegistro( fstream& );
    void consultarRegistro( fstream& );
    void buscarRegistro(fstream&);
    int obtenerId( const char * const );
    void mostrarLineaPantalla( const impuestos &);
    void actualizarRegistro( fstream& );
    void mostrarLinea( ostream&, const impuestos & );
    void eliminarRegistro( fstream& );
    void calcularSueldo(fstream&);
    void obtenerSueldo( const char * const);
    void conceptosS();

   void establecerNumeroId( int );
   int obtenerNumeroId() const;

   void establecerUsuario( string );
   string obtenerUsuario() const;

   void establecerSueldo( double );
   double obtenerSueldo() const;

    private:
        int numeroId;
        char usuario[ 10 ];
        double sueldo;
};

#endif // IMPUESTOS_H
