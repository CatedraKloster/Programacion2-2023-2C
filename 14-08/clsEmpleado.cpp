///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

//# include "clsFecha.h"

class Fecha{
    private:///lo que esta definido aquí sólo es accesible dentro de la clase
        int dia, mes, anio;///propiedades-> variables de la clase
    public:///métodos que definen el comportamiento
        ///lo que está definido acá es accesible dentro y fuera de la clase
        /*Fecha(){
            dia=0;
            mes=0;
            anio=0;
        } */
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Cargar();
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        ///sets: métodos para asignar valores a las propiedades
        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int d){
            if(d>=1 && d<=12) mes=d;
            else this->mes=-1;
        }
        void setAnio(int d){
            if(d>=1900) anio=d;
            else anio=-1;
        }

        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}


};


class Empleado{
private:
    int DNI;
    char nombre[30],  apellido[30];
    char domicilio[30];
    char email[35];
    Fecha fechaNacimiento;
    int cargo;
public:
    Empleado(int dni=0){
        DNI=dni;
    }
    ///sets()
    void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setDomicilio(const char *n){strcpy(domicilio,n);}
    void setEmail(const char *n){strcpy(email,n);}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setCargo(int c){cargo=c;}
    ///gets()
    int getDNI(){return DNI;}

    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getDomicilio(){return domicilio;}
    const char *getEmail(){return email;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    int getCargo(){return cargo;}

};


int main(){

	cout<<endl;
	system("pause");
	return 0;
}
