///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
/*# include<cstdlib>
# include<cstring>

using namespace std;
  */
#include "clsFecha.h"

void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


class Persona{
protected:
    char nombre[30], apellido[30], direccion[30];
    char email[30], telefono[30];
    int DNI;
    Fecha fechaNacimiento;
public:
    void Cargar();
    void Mostrar();
    void setDNI(int d){DNI=d;}

    int getDNI(){return DNI;}

};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"DIRECCION: ";
    cargarCadena(direccion, 29);
    cout<<"EMAIL: ";
    cargarCadena(email, 29);
    cout<<"TELEFONO: ";
    cargarCadena(telefono, 29);
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();

}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DIRECCION: ";
    cout<<direccion<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
}

class Alumno:public Persona{
private:
    int legajo;
    int IDCarrera;
    char tituloSecundario[30];
public:
    void Cargar();
    void Mostrar();

    void setLegajo(int l){legajo=l;}
    int getlegajo(){return legajo;}
    void modificarDNI(int d){DNI=d;}
};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"ID DE LA CARRERA: ";
    cin>>IDCarrera;
    cout<<"TITULO SECUNDARIO: ";
    cargarCadena(tituloSecundario,29);
}

void Alumno::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO: ";
    cout<<legajo<<endl;
    cout<<"ID DE LA CARRERA: ";
    cout<<IDCarrera<<endl;
    cout<<"TITULO SECUNDARIO: ";
    cout<<tituloSecundario<<endl;
}


