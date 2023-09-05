///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

///Clases: moldes donde se definen las propiedades y el comportamiento que tendr�n
/// los OBJETOS de esas clases.

///Objeto: una variable de una clase.





///ENCAPSULAMIENTO: s�lo se puede acceder a los datos de un objeto mediante
///m�todos de la clase dise�ados para eso


///ESPECIFICADORES DE ACCESO
    ///private: lo que esta definido aqu� s�lo es accesible dentro de la clase
    ///public: ///lo que est� definido ac� es accesible dentro y fuera de la clase


class Fecha{
    private:///lo que esta definido aqu� s�lo es accesible dentro de la clase
        int dia, mes, anio;///propiedades-> variables de la clase
    public:///m�todos que definen el comportamiento
        ///lo que est� definido ac� es accesible dentro y fuera de la clase
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
    ///m�todos
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
    hoy.Mostrar();///es llamada por un objeto de la clase Fecha. Es una funci�n de la clase Fecha o m�todo
    hoy.mostrarEnLinea();
	system("pause");
	Mostrar();///se llama de manera directa sin objeto. Es una funci�n global. No pertenece a una clase
	*/
	return 0;
}
