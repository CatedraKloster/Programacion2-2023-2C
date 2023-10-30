///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

class Pila{
private:
  int *p;
  int tam;
  int tope;
public:
  Pila(int t=2){
    tam=t;
    p=new int[tam];
    if(p==NULL)exit(1);
    tope=0;
  }
  ~Pila(){
    delete p;
  }
  bool Agregar(int in){
       if(tope==tam)return false;
       p[tope]=in;
       tope++;
       return true;
  }

  bool Sacar(int &out){
       if(tope==0)return false;
       tope--;
       out=p[tope];
       return true;
  }
};

int main(){
    Pila c1(5);
    int x=1;
    cout<<"NUMERO ";
    cin>>x;
    while(c1.Agregar(x)){
        cout<<"NUMERO ";
        cin>>x;
    }
    int valor;
    while(c1.Sacar(valor)){
        cout<<valor<<endl;
    }
    if(c1.Sacar(valor)){
        cout<<valor<<endl;
    }
    else{
        cout<<"NO SE PUEDE SACAR PORQUE ESTA VACIA"<<endl;
    }
	cout<<endl;
	system("pause");
	return 0;
}
