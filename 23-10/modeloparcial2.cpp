///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;


//Hacer un archivo con los deportes que tengan jugadores de todos los claustros. Los registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.

//Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.

void puntoD();
bool estanLosCuatro(int deporte);
int main(){
    puntoD();
	cout<<endl;
	system("pause");
	return 0;
}


void puntoD(){
    Deporte reg;
    ArchivoDeportes archi("deportes.dat");

    ArchivoDeportes nuevo("deportes4.dat");

    int cant=archi.contarRegistros();
    for(int i=0;i<cant;i++){
        reg=archi.leerRegistro(i);
        if(estanLosCuatro(reg.getIDdeporte())==true){
                nuevo.agregarRegistro(reg);
           }
    }

}

bool estanLosCuatro(int deporte){
    Jugador reg;
    ArchivoJugadores archi("jugadores.dat");
    int cant=archi.contarRegistros();
    int vClaustro[4]={0};

    for(int i=0;i<cant;i++){
        reg=archi.leerRegistro(i);
        if(reg.getIDdeporte()==deporte){
            vClaustro[reg.getClaustro()-1]=1;
        }
    }
    int cont=0;
    for(int i=0;i<4;i++){
        cont+=vClaustro[i];
    }
    if(cont==4)return true;
    return false;
    ///return cont==4;
    /*
    for(int i=0;i<4;i++){
        if(vClaustro[i]==0) return false;
    }
    return true*/
}
