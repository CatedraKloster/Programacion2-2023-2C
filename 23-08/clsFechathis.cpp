///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

///PUNTERO this
///Es un puntero que existe dentro de la clase, y que contiene la dirección del objeto que llama al método
///Se dice que es un puntero oculto, que se puede hacer visible si fuera útil o necesario

class Fecha{
private:
    int dia, mes, anio;
public:
    void Cargar();
    void Mostrar();
    /*Fecha(){
        dia=mes=anio=0;
    } */
    Fecha(int dia=0, int mes=0, int anio=0){
        this->dia=dia;
        this->mes=mes;
        this->anio=anio;
    }
    void mostrarThis(){
        cout<<this;
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


int main(){
    Fecha alguna(23,8,2023), obj;
    cout<<&alguna<<endl;
    alguna.mostrarThis();
	cout<<endl;
	cout<<&obj<<endl;
	obj.mostrarThis();
	cout<<endl;

	system("pause");
	return 0;
}
