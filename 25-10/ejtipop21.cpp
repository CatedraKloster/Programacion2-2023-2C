///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;
///se incluye el punto h necesario
# include "parcial1l.h"

/// a1. Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
///Cada registro debe tener el ID de equipo, el nombre y la categoría.

class Equipos10{
private:
    int IDequipo, IDcategoria;
    char nombre[30];
    bool estado;
public:
    void setEquipo(int e){IDequipo=e;}
    void setNombre(const char *nom){strcpy(nombre, nom);}
    void setCategoria(int cat){IDcategoria=cat;}
    void setEstado(bool e){estado=e;}
    void Mostrar(){
        cout<<"EQUIPO "<<IDequipo<<endl;
        cout<<"NOMBRE "<<nombre<<endl;
        cout<<"CATEGORIA "<<IDcategoria<<endl;
    }

};

class ArchivoEquipos10{
private:
    char nombre[30];
public:
    ArchivoEquipos10(const char *n){
        strcpy(nombre, n);
    }
    Equipos10 leerRegistro(int pos){
        Equipos10 reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipos10);
    }
    bool grabarRegistro(Equipos10 reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

int contarJugadores(int equipo){
    ArchivoJugadores archiJ("jugadores.dat");
    Jugador reg;
    int cantReg, cantJug=0;
    cantReg=archiJ.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiJ.leerRegistro(i);
        if(reg.getIDequipo()==equipo) cantJug++;
    }
    return cantJug;
}

int buscarDeporte(int equipo){
    ArchivoJugadores archiJ("jugadores.dat");
    Jugador reg;
    int cantReg;
    cantReg=archiJ.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiJ.leerRegistro(i);
        if(reg.getIDequipo()==equipo) return reg.getIDdeporte();
    }
    return -1;
}

int buscarCategoria(int deporte){
    ArchivoDeportes archiD("deportes.dat");
    Deporte reg;
    int cantReg;
    cantReg=archiD.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiD.leerRegistro(i);
        if(reg.getIDdeporte()==deporte) return reg.getIDcategoria();
    }
    return -1;
}

void puntoA1(){
    Equipos10 aux;
    ArchivoEquipos10 archiE10("equipos10.dat");
    Equipo reg;
    ArchivoEquipos archiE("equipos.dat");
    int cantReg, cantJug, categoria, deporte;
    cantReg=archiE.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiE.leerRegistro(i);
        cantJug=contarJugadores(reg.getIDequipo());
        if(cantJug>=10){
                deporte=buscarDeporte(reg.getIDequipo());
                categoria=buscarCategoria(deporte);
                aux.setEquipo(reg.getIDequipo());
                aux.setNombre(reg.getNombre());
                aux.setCategoria(categoria);
                archiE10.grabarRegistro(aux);
        }
    }

}

void puntoB1(){
    Equipos10 *v;
    ArchivoEquipos10 archiE10("equipos10.dat");
    int cantReg;
    cantReg=archiE10.contarRegistros();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }
    v=new Equipos10[cantReg];
    if(v==NULL) return;
    for(int i=0;i<cantReg;i++){
            v[i]=archiE10.leerRegistro(i);
    }
    for(int i=0;i<cantReg;i++){
        v[i].Mostrar();
    }
    delete v;
}

int main(){
    puntoA1();
    puntoB1();
	cout<<endl;
	system("pause");
	return 0;
}


///punto c1
///Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte. Debe devolver verdadero cuando coinciden los Id de deporte
///en la clase Jugador iría el código

bool operator==(const Deporte &obj){
    if(idDeporte==obj.getIDdeporte()) return true;
    return false;
}



