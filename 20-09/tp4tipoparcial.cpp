///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

#include "clases_SUBE_2023.h"

void puntoA();
void puntoB();
void puntoC();
void puntoD();

int main(){
    puntoA();
    puntoB();
    puntoC();
    puntoD();
	cout<<endl;
	system("pause");
	return 0;
}

 ///a) Informar para un número de tarjeta que se ingresa por teclado la cantidad de viajes realizados
 ///en cada uno de los medios de transporte el año pasado.


void puntoA(){
    ArchivoViaje archiV("viajes.dat");
    Viaje reg;
    int viajes_medio[3]={0};

    int cantReg=archiV.contarRegistros();
    int i, numeroTarjeta;
    cout<<"INGRESAR TARJETA ";
    cin>>numeroTarjeta;
    for(i=0;i<cantReg;i++){
        reg=archiV.leerRegistro(i);
        if(reg.getNroTarjeta()==numeroTarjeta && reg.getAnioViaje()==2022){
            viajes_medio[reg.getMedioTransporte()-1]++;
        }
    }
    cout<<"CANTIDAD DE VIAJES EN COLECTIVO "<<viajes_medio[0]<<endl;
    cout<<"CANTIDAD DE VIAJES EN SUBTE "<<viajes_medio[1]<<endl;
    cout<<"CANTIDAD DE VIAJES EN TREN "<<viajes_medio[2]<<endl;
}

/// b) El viaje con menor importe. Mostrar todo el registro.
void puntoB(){
    ArchivoViaje archiV("viajes.dat");
    Viaje reg, barato;
    float menorImporte;
    int cantReg=archiV.contarRegistros();
    int i;
     for(i=0;i<cantReg;i++){
        reg=archiV.leerRegistro(i);
        if(i==0){
            menorImporte=reg.getImporte();
            barato=reg;
        }
        else{
            if(reg.getImporte()<menorImporte){
                menorImporte=reg.getImporte();
                barato=reg;
            }
        }
    }
    cout<<"VIAJE DE MENOR IMPORTE ";
    barato.Mostrar();
}


///c) El mes de mayor recaudación por viajes en subte entre todos los años, sin tener en cuenta
///el año actual.

int buscarMaximo(float *v, int tam){
    return 3;
}

void puntoC(){
ArchivoViaje archiV("viajes.dat");
    Viaje reg;
    int cantReg=archiV.contarRegistros();
    int i;
    float vMeses[12]={0};
    for(i=0;i<cantReg;i++){
        reg=archiV.leerRegistro(i);
        if(reg.getAnioViaje()<2023 &&reg.getMedioTransporte()==2){
           vMeses[reg.getMesViaje()-1]+=reg.getImporte();
        }
    }
    int mayorMes=buscarMaximo(vMeses, 12);
    cout<<"EL MES DE MAYOR RECAUDACION ES "<<mayorMes<<endl;
}


///d) Generar un archivo con los registros de los viajes del año actual.

bool grabarRegistroAnioActual(Viaje aux){
    FILE *p;
    p=fopen("viajes2023.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
    return escribio;
}


void puntoD(){
ArchivoViaje archiV("viajes.dat");
    Viaje reg;
    int cantReg=archiV.contarRegistros();
    int i;
    for(i=0;i<cantReg;i++){
        reg=archiV.leerRegistro(i);
        if(reg.getAnioViaje()==2023){
            if(grabarRegistroAnioActual(reg)==false){
                cout<<"NO SE PUDO GRABAR EL REGISTRO";
                return;
            }
        }
    }
}
