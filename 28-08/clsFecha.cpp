///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

///Clases: moldes donde se definen las propiedades y el comportamiento que tendrán
/// los OBJETOS de esas clases.

///Objeto: una variable de una clase.





///ENCAPSULAMIENTO: sólo se puede acceder a los datos de un objeto mediante
///métodos de la clase diseñados para eso


///ESPECIFICADORES DE ACCESO
    ///private: lo que esta definido aquí sólo es accesible dentro de la clase
    ///public: ///lo que está definido acá es accesible dentro y fuera de la clase


class Fecha{
    private:///lo que esta definido aquí sólo es accesible dentro de la clase
        int dia, mes, anio;///propiedades-> variables de la clase
    public:///métodos que definen el comportamiento
        ///lo que está definido acá es accesible dentro y fuera de la clase
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }

        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        int getDia(){return dia;}
};


void Mostrar(){
    cout<<"MUESTRO UN CARTEL"<<endl;
}


class Alumno{
private:
    ///propiedades
public:
    ///métodos
    void Mostrar();
};


int main(){
    Fecha hoy;

    hoy.dia=14;
    hoy.setDia(5);
    cout<<hoy.getDia()<<endl;

    ///hoy.dia=5; no se puede acceder porque dia es privado
/*
    hoy.Cargar();
    hoy.Mostrar();///es llamada por un objeto de la clase Fecha. Es una función de la clase Fecha o método
    hoy.mostrarEnLinea();
	system("pause");
	Mostrar();///se llama de manera directa sin objeto. Es una función global. No pertenece a una clase
	*/
	return 0;
}
