///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

class Cola{
private:
  int *p;
  int tam;
  int pcio, fin;
public:
  Cola(int t=2){
    tam=t;
    p=new int[tam];
    if(p==NULL)exit(1);
    pcio=fin=0;
  }
  ~Cola(){
    delete p;
  }
  bool Agregar(int in){
       if(pcio==tam)return false;
       p[pcio]=in;
       pcio++;
       return true;
  }

  bool Sacar(int &out){
       if(pcio==fin)return false;
       out=p[fin];
       fin++;
       return true;
  }
};

int main(){
    Cola c1(5);
    int x=5;
    while(c1.Agregar(x)){
        x--;
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
