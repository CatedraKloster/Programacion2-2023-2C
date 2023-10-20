///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=i+1;
    }
}

void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}

void copiarVector(int *destino,int *origen, int tam){
    int i;
    for(i=0;i<tam;i++){
        destino[i]=origen[i];
    }

}
	///Sólo se deben cargar los elementos nuevos.
void cargarNuevos(int *v, int tamViejo,int tamNuevo){
    int i;
    for(i=tamViejo;i<tamNuevo;i++){
        v[i]=i+1;
    }
}

int main(){
    int tamLista;
    cout<<"INGRESE LA CANTIDAD DE NUMEROS DE LA LISTA ";
    cin>>tamLista;
    ///int vec[tamLista]; no se puede de esta manera
    int *vec;
    vec=new int[tamLista];
    ///???? habrá podido acceder a la memoria solicitada
    if(vec==NULL){
        cout<<"NO SE PUDO ASIGNAR LA MEMORIA"<<endl;
        return -1;
    }

    cargarVector(vec, tamLista);
    mostrarVector(vec,tamLista);
	cout<<endl;
	int agregar;
	cout<<"INGRESE LA CANTIDAD DE COMPONENTES A AGREGARLE AL VECTOR ";
	cin>>agregar;
	///hago un nuevo vector de enteros con un tamaño que sume lo que tenía más lo que se agrega
	int *nuevo=new int[tamLista+agregar];
	if(nuevo==NULL){
        cout<<"ERROR DE MEMORIA";
        delete vec;
        return -1;
	}
	///cargar y mostrar de nuevo el vector pero ahora con su nuevo tamaño
	copiarVector(nuevo, vec,tamLista);
	///Sólo se deben cargar los elementos nuevos.
   	cargarNuevos(nuevo, tamLista,tamLista+agregar);
	///Si es necesario se pueden hacer otras funciones
	delete vec;
    mostrarVector(nuevo,tamLista+agregar);
    delete nuevo;
	system("pause");
	return 0;
}
