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
    Cadena (const char *ini){
        tam=strlen(ini)+1;
        p=new char[tam];
        if(p==NULL){
            cout<<"ERROR DE MEMORIA"<<endl;
            exit(1);
        }
        strcpy(p,ini);
        p[tam-1]='\0';
    }
    ~Cadena(){delete p;}
    void Mostrar(){
        cout<<p<<endl;
    }
    void agregarCaracter(char letra){
        char *bak=new char[tam];
        if(bak==NULL)exit(1);
        strcpy(bak,p);
        delete p;
        tam=tam+1;
        p=new char[tam];
        if(p==NULL)exit(1);
        strcpy(p,bak);
        delete bak;
        p[tam-2]=letra;
        p[tam-1]='\0';
    }
    void concatenar(const char *nueva){
        char *bak=new char[tam];
        if(bak==NULL)exit(1);
        strcpy(bak,p);
        delete p;
        tam=tam+strlen(nueva);
        p=new char[tam];
        if(p==NULL)exit(1);
        strcpy(p,bak);
        delete bak;
        strcat(p,nueva);
        p[tam-1]='\0';
    }

};

///Agregar una función de nombre agregarCaracter(char ) que reciba un caracter y lo agregue a la cadena existente
///Agregar una función de nombre concatenar(const char *) que reciba una cadena y lo agregue a la existente
int main(){
    Cadena palabra("hola a todos los participantes");
    palabra.Mostrar();
    //palabra.agregarCaracter('z');
    palabra.concatenar(" del curso");
	palabra.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
