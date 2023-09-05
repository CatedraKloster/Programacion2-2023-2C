///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring> ///string.h

using namespace std;
///Qué devuelve int strcmp(char *cadena1, char * cadena2)
///si son iguales las cadenas-> 0
///si la cadena1 está antes en el diccionario que la cadena2 ->-1
///si la cadena1 está después en el diccionario que la cadena2 ->1
///OJO!!! para strcmp() son distintas las palabras si tienen mayúsculas o minúsculas

void funcionPalabra(const char *prueba){
    char otra[20];
    strcpy(otra, prueba);
    cout<<otra<<endl;
}

int main(){
    char cadena[20];
    strcpy(cadena,"palabras");
    funcionPalabra(cadena);
/*
    char letra='a';
    char palabra[20];
    cout<<"CARACTER a valor ASCII "<<(int)'b'<<endl;
    cout<<"CARACTER A valor ASCII "<<(int)'B'<<endl;
    system("pause");

    cout<<(char)('a'-32)<<endl;
    strcpy(palabra,"hola"); ///permite copiar una cadena en otra
    int valorDevuelto=strcmp(palabra,"Hola");
    cout<<valorDevuelto<<endl<<endl;;
    cout<<palabra<<endl<<endl;
	cout<<endl;*/
	system("pause");
	return 0;
}
