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
/*
bool grabarVector(Alumno *vAlu, int cantReg){


    fwrite(vAlu, sizeof(Alumno),cantReg,p);

}

bool grabarVector(){
    Alumno vAlu[5];
    cargarVector(vAlu, 5);
    //fwrite(vAlu, sizeof(Alumno),5,p);
    fwrite(vAlu, sizeof vAlu,1,p);

}
  */
bool grabarRegistro(){
    Alumno reg;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "ab");
    if(pAlu==NULL){
        return false;
    }
    cout<<"INGRESAR LOS VALORES DEL REGISTRO "<<endl;
    reg.Cargar();
    bool escribio=fwrite(&reg,sizeof reg,1,pAlu);
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
    Alumno vAlu[5], *pA;
    cout<<"sizeof vAlu "<<sizeof vAlu<<endl;
    cout<<"sizeof *pA "<<sizeof pA<<endl;
    system("pause");
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
