///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
/*# include<cstdlib>
# include<cstring>
# include<cstdio>*/

using namespace std;

#include "herencia1.cpp"

bool grabarRegistro(){
    const int CANT_REG=1;
    Alumno reg;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "ab");
    if(pAlu==NULL){
        return false;
    }
    cout<<"INGRESAR LOS VALORES DEL REGISTRO "<<endl;
    reg.Cargar();
    bool escribio=fwrite(&reg,sizeof reg,CANT_REG,pAlu);
    ///sizeof reg*CANT_REG-> cantidad de bytes que se van a escribir en el archivo
	fclose(pAlu);
    return escribio;
}

bool mostrarRegistros(){
    Alumno reg;
    FILE *pAlu;
    pAlu=fopen("alumno.dat", "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pAlu);
    return true;
}

int main(){

    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS "<<endl;
        cout<<"********************** "<<endl;
        cout<<"1. AGREGAR REGISTRO "<<endl;
        cout<<"2. MOSTRAR REGISTROS "<<endl;
        cout<<"0. SALIR DEL PROGRAMA "<<endl;
        cout<<"********************** "<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(grabarRegistro()) cout<<"REGISTRO AGREGADO"<<endl;
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    break;

            case 2: if(!mostrarRegistros()) cout<<"ERROR AL LEER EL ARCHIVO DE ALUMNOS"<<endl;
                break;
            case 0: return 0;
                break;

        }
        system("pause");
    }

	system("pause");
	return 0;
}
