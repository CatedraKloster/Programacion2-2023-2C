///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

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
    int legajoAlumno;
    int codigoCarrera;
    char tituloSecundario[30];
    ///si se hereda de manera privada tanto las
    ///propiedades como los métodos se copian en la parte privada de la derivada


public:
    void setLegajoAlumno(int l){legajoAlumno=l; }
    void setCodigoCarrera(int cc){codigoCarrera=cc;}
    void setTituloSecundario(const char *titulo){strcpy(tituloSecundario, titulo);}

    int getLegajoAlumno(){return legajoAlumno; }
    int getCodigoCarrera(){return codigoCarrera;}
    const char *getTituloSecundario(){return tituloSecundario;}
    void Cargar(){
        Persona::Cargar();
        cout<<"LEGAJO: ";
        cin>>legajoAlumno;
        cout<<"CARRERA: ";
        cin>>codigoCarrera;
        cout<<"TITULO: ";
        cargarCadena(tituloSecundario,29);
    }
    void Mostrar(){
        Persona::Mostrar();
        cout<<"LEGAJO: ";
        cout<<legajoAlumno<<endl;
        cout<<"CARRERA: ";
        cout<<codigoCarrera<<endl;
        cout<<"TITULO: ";
        cout<<tituloSecundario<<endl;
    }
    void cambiarDNI(int d){
        DNI=d;
        ///setDNI(d);
    }
};

int main(){
    Alumno aux;
    aux.cambiarDNI(555);
	cout<<endl;
	system("pause");
	return 0;
}
