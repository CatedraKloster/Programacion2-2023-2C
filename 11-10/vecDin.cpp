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

void copiarVector(int *destino,int *origen,int tam){
    int i;
    for(i=0;i<tam;i++){
        destino[i]=origen[i];
    }
}


void agregarValores(int *v,int ini,int fin){
    int i;
    for(i=ini;i<fin;i++){
        v[i]=i+1;
    }

}

int main(){
    int tam;
    cout<<"INGRESE EL TAMANIO DEL VECTOR ";
    cin>>tam;
    int *vec;

    vec=new int[tam];
    if(vec==NULL){
        cout<<"ERROR DE MEMORIA"<<endl;
        return -1;
    }
    cargarVector(vec, tam);
    mostrarVector(vec, tam);
	/*int masElementos, *otro;
	cout<<"INGRESE LA CANTIDAD DE ELEMENTOS A AGREGAR EN EL VECTOR ";
	cin>>masElementos;
	otro=new int[tam+masElementos];
	if(otro==NULL){
        cout<<"ERROR DE MEMORIA"<<endl;
        return -1;
	}
	copiarVector(otro, vec,tam);
    agregarValores(otro,tam, tam+masElementos);
    mostrarVector(otro, tam+masElementos);
	cout<<endl;
	system("pause");*/
	delete vec;
	//delete otro;
	return 0;
}
