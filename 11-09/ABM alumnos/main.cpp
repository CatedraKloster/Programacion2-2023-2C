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
#include "reportes.h"


///Agregar al menú principal una opción para la baja física.
/// Al ejecutarse se deben eliminar los registros que tengan baja lógica.
///DEFINICION Y PASOS PARA LA BAJA FISICA
/*BAJA FISICA: consiste en volver a escribir el archivo omitiendo los
registros que se quieren borrar

1. COPIAR EL ARCHIVO EN OTRO CON UNA EXTENSION DIFERENTE (.bak)
	a. Abro el .dat con rb, y el .bak con wb. Leo un registro del .dat
	y lo escribo en el .bak.
	b. system("copy ....")

2. COPIAR EN EL ARCHIVO DAT LOS REGISTROS QUE SE QUIEREN MANTENER
	* Abro el archivo .bak con rb.
	* Abro el archivo .dat con wb.
	* Leo registro a registro el archivo .bak, y copio en el .dat
	los registros que correspondan.
  */

int main(){
    punto1();
    system("pause");
    system("cls");
    punto3();
    system("pause");
    system("cls");
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS "<<endl;
        cout<<"********************** "<<endl;
        cout<<"1. AGREGAR REGISTRO "<<endl;
        cout<<"2. BAJA LOGICA "<<endl;
        cout<<"3. MODIFICAR TITULO SECUNDARIO "<<endl;
        cout<<"4. MOSTRAR REGISTROS "<<endl;
        cout<<"5. BAJA FISICA "<<endl;
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
            case 3: if(!modificarTitulo()) cout<<"ERROR AL MODIFICAR TITULO EN EL REGISTRO"<<endl;
                    else{
                        cout<<"REGISTRO MODIFICADO"<<endl;
                    }
                break;
            case 4: if(!mostrarRegistros()) cout<<"ERROR AL LEER EL ARCHIVO DE ALUMNOS"<<endl;
                break;
            case 5: if(!bajaFisica()) cout<<"ERROR AL LEER EL ARCHIVO DE ALUMNOS"<<endl;
                break;
            case 0: return 0;
                break;

        }
        system("pause");
    }

	system("pause");
    return 0;
}
