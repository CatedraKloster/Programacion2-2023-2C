///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
     Cadena(const char *ini){
        tam=strlen(ini)+1;
        p=new char[tam];
        if(p==NULL){
            cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
            exit(1);
        }
        strcpy(p,ini);
        p[tam-1]='\0';
     }
    void Mostrar(){
        cout<<p<<endl;
     }
    int getTam(){return tam;}
     ~Cadena(){
        delete p;
     }
};

int main(){
    char cadena[5];
    cin>>cadena;
    strcat(cadena,"algo");
    cout<<cadena<<endl;


    /*Cadena palabra("hola a todos los que me conocen");
    palabra.Mostrar();
    cout<<palabra.getTam()<<endl;
	cout<<endl;*/
	system("pause");
	return 0;
}

///agregarCarater-> recibe un caracter y lo agrega a la cadena existente
///concatenar->recibe una cadena y la agrega a la cadena existentes

///Agregar un constructor que reciba como par�metro un valor entero.
///Ese valor debe usarse como tama�o de la cadena, y cada posici�n del vector (menos el espacio del nulo) debe contener
///el caracter '0'

///Hacer un m�todo que se llame aMayusculas()que ponga todos los caracteres de letra en may�scula
///Hacer un m�todo que se llame aMinusculas()que ponga todos los caracteres de letra en min�scula
///VER VALOR ASCII DE LOS CARACTERES

///Hacer un m�todo tipoOracion(), que ponga la primera letra en may�scula, y el resto en min�scula
