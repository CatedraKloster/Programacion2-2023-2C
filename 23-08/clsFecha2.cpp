///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

/*class NombreClase{
private:
       ///sólo se accede desde la clase
       ///propiedades: son aquellas cosas que se distinguen e identifican al objeto.
       ///variables de la clase
       ///Todas tienen un valor
       ///La razón por la que ponemos las propiedades acá es para garantizar el ENCAPSULAMIENTO
       ///esto es la protección de los valores que contienen las propiedades
public:
        ///métodos: determinan el comportamiento de los objetos de la clase.
        ///funciones de la clase
        ///accesible tanto fuera como dentro de la clase
};

DISEÑO DE UNA CLASE:
        Dentro de la clase hay que desarrollar todo lo que necesita UN OBJETO DE LA CLASE.

  */

class Fecha{
private:
    int dia, mes, anio;
public:
    void Cargar();
    void Mostrar();
    ///sets()
    void setDia(int var){
        if(var>0 && var<=31) dia=var;
        else dia=0;
    }
    void setMes(int var){
        if(var>0 && var<=12) mes=var;
        else mes=0;
    }
    void setAnio(int var){
        if(var>0) anio=var;
        else anio=0;
    }
    ///gets()
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};

void Fecha::Cargar(){
    int d, m, a;
    cout<<"DIA ";
    cin>>d;
    setDia(d);
    cout<<"MES ";
    cin>>m;
    setMes(m);
    cout<<"ANIO ";
    cin>>a;
    setAnio(a);
}

void Fecha::Mostrar(){
    cout<<"DIA ";
    cout<<dia<<endl;
    cout<<"MES ";
    cout<<mes<<endl;
    cout<<"ANIO ";
    cout<<anio<<endl;
}

///funciones globales
void CargarFechasFinales(Fecha *vF, int tam){
    int i;
    for(i=0;i<tam;i++)
        vF[i].Cargar();
}
void MostrarFechasFinales(Fecha *vF, int tam){
    for(int i=0;i<tam;i++){
        vF[i].Mostrar();
        cout<<endl;
    }

}
///

void cargarPalabra(char *pal){
    cin>>pal;
}

char *devolverPalabra(char *pal){
    return pal;
}

int main(){
    ///almacenar y mostrar las 3 fechas de examen final de PR2 de diciembre
    ///7, 14 y 21/12 de 2023
    /*Fecha vFinales[3];
    CargarFechasFinales(vFinales, 3);
    MostrarFechasFinales(vFinales, 3);*/
    ///
    char cadena[20];
    cargarPalabra(cadena);
    cout<<devolverPalabra(cadena);
	cout<<endl;
	system("pause");
	return 0;
}
