#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "prototipos.h"
#include "clsFecha.h"
#include "personaAlumno.h"
#include "clsArchivoAlumnos.h"
#include "fGlobales.h"




int main(){

    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS "<<endl;
        cout<<"********************** "<<endl;
        cout<<"1. AGREGAR REGISTRO "<<endl;
        cout<<"2. BAJA LOGICA "<<endl;
        cout<<"3. MOSTRAR REGISTROS "<<endl;

        cout<<"0. SALIR DEL PROGRAMA "<<endl;
        cout<<"********************** "<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(grabarRegistro()) cout<<"REGISTRO AGREGADO"<<endl;
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    break;

            case 2: if(!bajaLogicaRegistro()) cout<<"ERROR AL DAR DE BAJA EL REGISTRO"<<endl;
                    else{
                        cout<<"REGISTRO DADO DE BAJA"<<endl;
                    }
                break;
            case 3: if(!mostrarRegistros()) cout<<"ERROR AL LEER EL ARCHIVO DE ALUMNOS"<<endl;
                break;
            case 0: return 0;
                break;

        }
        system("pause");
    }

	system("pause");
    return 0;
}
