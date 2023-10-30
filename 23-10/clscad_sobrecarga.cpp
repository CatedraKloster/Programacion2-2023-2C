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
     Cadena(const char *ini="nada"){
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
    const char *getP(){return p;}
     ~Cadena(){
        delete p;
     }
     ///SOBRECARGAS
     bool operator==(const Cadena &obj){
        if(strcmp(this->p,obj.p)==0)return true;
        return false;
     }
     bool operator==(const char *obj){
        if(strcmp(this->p,obj)==0)return true;
        return false;
     }
     bool operator>(const Cadena &obj){
        if(strcmp(this->p,obj.p)>0)return true;
        return false;
     }
     bool operator>(int tamanio){
        if(tam>tamanio)return true;
        return false;
     }

     Cadena & operator=(const Cadena &obj){
        delete p;
        tam=obj.tam;
        p=new char[tam];
        if(p==NULL) exit(1);
        strcpy(p,obj.p);
        return *this;
     }

     Cadena & operator=(const char *obj){
        delete p;
        tam=strlen(obj)+1;
        p=new char[tam];
        if(p==NULL) exit(1);
        strcpy(p,obj);
        p[tam-1]='\0';
        return *this;
     }

     friend void soyAmiga(Cadena obj){
        for(int i=0;i<obj.tam-1;i++){
            obj.p[i]='a';
        }
        cout<<obj.p<<endl;
     }

     friend ostream & operator<<(ostream &salida, const Cadena obj){
        salida<<obj.p;
        return salida;
     }

     friend istream &operator>>(istream &entrada, Cadena &obj){
        char aux[50];
        entrada>>aux;
        obj=aux;
        return entrada;
     }
};

///SOBRECARGA DE OPERADORES: ES UN MECANISMO QUE NOS PERMITE AGREGAR FUNCIONALIDAD A LOS OPERADORES EXISTENTES.
///SE CONSIGUE ESCRIBIENDO UN CÓDIGO SUJETO A CIERTAS REGLAS DENTRO DE LA CLASE.
int main(){
    Cadena palabra("zorro"), aux("zorrino"), otra;
    cin>>palabra;
    cout<<palabra<<" "<<aux<<endl;
    ////
    ///if(strcmp(palabra.getP(), aux.getP())==0){

    /*otra=palabra=aux="UNA ASIGNACION NUEVA";
    palabra.Mostrar();
    //if(palabra=="zorro")cout<<"SON IGUALES";
    //else cout<<"SON DISTINTOS";
    /*if(aux>palabra.getTam()){
        cout<<"LA PRIMERA TIENE MAS CARACTERES";
    }
    else{
        cout<<"LA PRIMERA NO TIENE MAS CARACTERES";
    } */
	cout<<endl;
	system("pause");
	return 0;
}

///Sobrecargar el operador != de manera tal que sea verdadero cuando los dos objetos a comparar sean distintos
///Sobrecargar el operador <= para dos casos: para comparar las cadenas de caracteres y para comparar el largo de la cadenas
///Sobrecargar el operador += de manera tal que se concatenen las dos cadenas
