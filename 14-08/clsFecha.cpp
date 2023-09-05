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

///CONSTRUCTOR: método que tiene
        /// el mismo nombre que la clase
        /// no devuelve nada
        /// puede aceptar parámetros
        /// se ejecuta de manera automática, en el momento que el objeto nace

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

        void mostrarDireccion(){
            cout<<this<<endl; ///this un puntero que contiene la dirección del objeto que llama al método
            ///Se suele decir que es un puntero oculto
        }
};

void Fecha::Cargar(){
    int d, m, a;
    cout<<"DIA: ";
    cin>>d;
    this->setDia(d);
    cout<<"MES: ";
    cin>>m;
    setMes(m);
    cout<<"ANIO: ";
    cin>>a;
    setAnio(a);
    ///hoy.setMes(9); fuera de la clase
}

void cargarFechas(Fecha *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].Cargar();
    }
}

void mostrarFechas(Fecha *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].mostrarEnLinea();
        cout<<endl;
    }
}

class Alumno{
private:
    ///propiedades
public:
    ///métodos
    void Mostrar();
};


int main(){
    Fecha hoy(12,10,2023), ayer, otro(15), vDias[5];
    /*cout<<"objeto hoy ";
    hoy.mostrarEnLinea();
    cout<<endl;
    cout<<"objeto ayer ";
    ayer.mostrarEnLinea();
    cout<<endl;
    cout<<"objeto otro ";
    otro.mostrarEnLinea();
    cout<<endl;
    //hoy.Cargar();
    //hoy.Mostrar();
    //cargarFechas(vDias,3);
    //mostrarFechas(vDias,3);
    vDias[1].Mostrar();


      */

    vDias->Mostrar();
    cout<<&hoy<<endl;
    hoy.mostrarDireccion();
	return 0;
}
