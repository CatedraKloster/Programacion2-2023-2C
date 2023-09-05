///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;


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


int main(){

	cout<<endl;
	system("pause");
	return 0;
}
