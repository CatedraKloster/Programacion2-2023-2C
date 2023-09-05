///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;
///METODOS
///CONSTRUCTOR/ES
    ///Tiene el mismo nombre que la clase
    ///No devuelve nada, ni siquiera void
    ///Se ejecuta de manera automática en el momento que el objeto nace
    ///En ese momento se ejecuta el código asociado
    ///Una de los usos más extendidos de los constructores es asignar valor inicial a las propiedades

///DESTRUCTOR
    ///Tiene el mismo nombre de la clase , antecedido por el caracter ~
    ///No devuelve nada ni recibe nada
    ///Se ejecuta de manera automática al momento de que el objeto cae fuera de su ambito

class Fecha{
private:
    int dia, mes, anio;
public:
    void Cargar();
    void Mostrar();
    /*Fecha(){
        dia=mes=anio=0;
    } */
    Fecha(int d=0, int m=0, int a=0){
        setDia(d);
        setMes(m);
        setAnio(a);
    }
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
    ~Fecha(){
        cout<<"SE MURIO EL OBJETO. VIVA EL OBJETO!!!"<< endl;
    }
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

int funcion(int valor=1){
        return valor;

}
int main(){
    Fecha obj, obj2(2,2,2023), dia(5);
    obj.Mostrar();
	cout<<endl;
	obj2.Mostrar();
	{
	    Fecha maniana(24,8,2023);
	    maniana.Mostrar();
	}
	/*cout<<funcion(5);
	cout<<endl;
	cout<<funcion();*/
	cout<<endl;
	dia.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
