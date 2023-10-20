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
    Cadena (const char *ini="nada"){
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
    bool operator==(const Cadena &obj){
        if(strcmp(this->p, obj.p)==0) return true;
        return false;
    }
    bool operator==(const char *cad){
        if(strcmp(this->p, cad)==0) return true;
        return false;
    }

    bool operator>(const Cadena &obj){
        if(strcmp(this->p, obj.p)>0) return true;
        return false;
    }

    bool operator<(const Cadena &obj){
        if(strcmp(this->p, obj.p)<0) return true;
        return false;
    }

    void MostrarDireccion(){
        cout<<this<<endl;
    }

    Cadena & operator=(const Cadena &obj){
        delete p;
        tam=obj.tam;
        p=new char[tam];
        if(p==NULL)exit(1);
        strcpy(p,obj.p);
        p[tam-1]='\0';
        return *this;

    }
    Cadena & operator=(const char *obj){
        delete p;
        tam=strlen(obj)+1;
        p=new char[tam];
        if(p==NULL)exit(1);
        strcpy(p,obj);
        p[tam-1]='\0';
        return *this;

    }
    void operator+=(const Cadena &aux){
        char *bak=new char[tam];
        if(bak==NULL)exit(1);
        strcpy(bak,p);
        delete p;
        tam=tam+aux.tam-1;
        p=new char[tam];
        if(p==NULL)exit(1);
        strcpy(p,bak);
        delete bak;
        strcat(p,aux.p);
        p[tam-1]='\0';

    }

    friend void soyAmiga(Cadena aux){
        cout<<aux.p;
    }

    friend ostream& operator<<(ostream &salida,const Cadena &obj){
        salida<<obj.p<<endl;
        return salida;
    }

    /*friend istream &operator>>(istream &entrada, Cadena &obj){
        char palabra[50];
        entrada.getline(palabra, 49);
        delete obj.p;
        obj.tam=strlen(palabra)+1;
        obj.p=new char[obj.tam];
        if(obj.p==NULL)exit(1);
        strcpy(obj.p,palabra);
        return entrada;

    } */

    friend istream &operator>>(istream &entrada, Cadena &obj){
        char palabra[50];
        entrada.getline(palabra, 49);
        obj=palabra;
        return entrada;

    }

    Cadena operator+(const Cadena &aux){
        Cadena sumada;
        delete sumada.p;
        sumada.tam=tam+aux.tam-1;
        sumada.p=new char[tam];
        strcpy(sumada.p,p);
        strcat(sumada.p,aux.p);
        return sumada;
    }

    Cadena operator+(const char *aux){
        Cadena sumada;
        delete sumada.p;
        sumada.tam=tam+strlen(aux);
        sumada.p=new char[tam];
        strcpy(sumada.p,p);
        strcat(sumada.p,aux);
        return sumada;
    }

};
///Agregar un método para pasar todos los caracteres a mayúscula
///Agregar un método para pasar todos los caracteres a minúscula
///Agregar un método para pasar a mayúscula la primera letra, y que el resto de las letras queden en minúscula


///Agregar una función de nombre agregarCaracter(char ) que reciba un caracter y lo agregue a la cadena existente
///Agregar una función de nombre concatenar(const char *) que reciba una cadena y lo agregue a la existente


///Sobrecargar el operador > para comparar un objeto Cadena con otro objeto Cadena (funcionalidad sea igual que para enteros)
///Va a ser mayor el objeto que llama, cuando la palabra esté más cerca del final del diccionario que la palabra que se recibe como parámetro

///Hacer lo mismo para el operador < y para el operador !=

int main(){
    Cadena palabra("Daniel"), otra, aux;
    //cin>>palabra;
    //cout<<palabra;
    cin>>palabra;
    cout<<palabra;
	cout<<endl;
	cin>>otra;
    cout<<otra;
	cout<<endl;

	aux=palabra+" "+otra;
	cout<<aux<<endl;
	system("pause");
	return 0;
}
