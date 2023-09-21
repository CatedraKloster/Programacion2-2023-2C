#ifndef FGLOBALES_H_INCLUDED
#define FGLOBALES_H_INCLUDED

///PROTOTIPOS
int buscarLegajo(int legajo);
Alumno leerRegistro(int pos);
bool sobreEscribirRegistro(Alumno reg, int pos);
bool modificarTitulo();
bool bajaFisica() ;
///



void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

bool grabarRegistro(){
    /*const int CANT_REG=1;
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
    return escribio;*/

    Alumno reg;
    ArchivoAlumnos archiAlu("alumnos.dat");
    cout<<"INGRESAR LOS VALORES DEL REGISTRO "<<endl;
    reg.Cargar();
    bool escribio=archiAlu.grabarRegistro(reg);
    return escribio;

}

bool mostrarRegistros(){
    /*Alumno reg;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pAlu);
    return true;*/
    ArchivoAlumnos archi("alumnos.dat");
    bool quePaso=archi.listarRegistros();
    return quePaso;

}

bool bajaLogicaRegistro(){
    ///INGRESAR EL VALOR QUE IDENTIFICA EL REGISTRO A BORRAR
    int legajo, pos;
    cout<<"INGRESAR EL LEGAJO DEL ALUMNO A DAR DE BAJA ";
    cin>>legajo;
    ///BUSCAR SI EL LEGAJO EXISTE EN EL ARCHIVO.
    ///LA FUNCION DEVUELVE LA POSICIÓN DEL REGISTRO EN EL ARCHIVO. SI NO ENCUENTRA EL LEGAJO DEVUELVE -1
    pos=buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO EXISTE ESE LEGAJO"<<endl;
        return false;
    }
    ///LEER EL REGISTRO DEL ARCHIVO Y PONERLO EN UNA VARIABLE DE MEMORIA
    Alumno reg;
    reg=leerRegistro(pos);
    ///CAMBIAR EL CAMPO estado
    cout<<"REGISTRO A BORRAR "<<endl;
    reg.Mostrar();
    cout<<endl;
    char opc;
    cout<<"DESEA BORRARLO? (S/N) ";
    cin>>opc;
    if(opc=='s'|| opc=='S'){
        reg.setEstado(false);
        ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO EN LA MISMA POSICION QUE TENÍA
        bool quePaso=sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}

bool modificarTitulo(){
    ArchivoAlumnos archi("alumnos.dat");
    ///INGRESAR EL VALOR QUE IDENTIFICA EL REGISTRO A BORRAR
    int legajo, pos;
    cout<<"INGRESAR EL LEGAJO DEL ALUMNO A MODIFICAR ";
    cin>>legajo;
    ///BUSCAR SI EL LEGAJO EXISTE EN EL ARCHIVO.
    ///LA FUNCION DEVUELVE LA POSICIÓN DEL REGISTRO EN EL ARCHIVO. SI NO ENCUENTRA EL LEGAJO DEVUELVE -1
    pos=archi.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO EXISTE ESE LEGAJO"<<endl;
        return false;
    }
    ///LEER EL REGISTRO DEL ARCHIVO Y PONERLO EN UNA VARIABLE DE MEMORIA
    Alumno reg;
    reg=archi.leerRegistro(pos);

    cout<<"REGISTRO A MODIFICAR "<<endl;
    reg.Mostrar();
    cout<<endl;
    char opc;
    cout<<"DESEA MODIFICARLO? (S/N) ";
    cin>>opc;
    char tituloNuevo[30];
    if(opc=='s'|| opc=='S'){
        cout<<"INGRESAR NUEVO TITULO ";
        cargarCadena(tituloNuevo,29);
        reg.setTitulo(tituloNuevo);
        ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO EN LA MISMA POSICION QUE TENÍA
        bool quePaso=archi.sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}

int buscarLegajo(int legajo){
    Alumno reg;
    FILE *p;
    p=fopen("alumnos.dat", "rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(legajo==reg.getlegajo()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

Alumno leerRegistro(int pos){
    /*Alumno reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen("alumnos.dat", "rb");
    int posLectura=0;
    if(p==NULL){
        return reg;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(pos==posLectura){
            fclose(p);
            return reg;
        }
        posLectura++;
    }
    fclose(p);
    reg.setEstado(false);
    return reg;*/

    Alumno reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL){
        return reg;
    }
    ///quiero ubicarme en el registro pos del archivo
    ///fseek(pFILE,CANTIDAD_BYTES_A_MOVERSE, DESDE_DONDE);///permite ubicar el puntero en posiciones específicas dentro del archivo
    ///fseek(p,0,0)->el puntero queda al principio del archivo
    ///fseek(p,0,2)->queda al final
    ///DESDE_DONDE
        ///0 PRINCIPIO                  SEEK_SET
        ///1 LA POSICION ACTUAL         SEEK_CUR
        ///2 DESDE EL FIN DEL ARCHIVO   SEEK_END
    fseek(p,sizeof reg*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool sobreEscribirRegistro(Alumno reg, int pos){
    FILE *p;
    p=fopen("alumnos.dat", "rb+");///+ agrega al modo lo que le falta
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

bool bajaFisica(){
    ArchivoAlumnos archi("alumnos.dat");
    Alumno reg;
    int cantReg=archi.contarRegistros();
    int i;
    FILE *p;
    p=fopen("alumnos.bak", "wb");
    if(p==NULL) return false;
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        fwrite(&reg, sizeof reg,1, p);
    }
    fclose(p);

    FILE *pBak;
    pBak=fopen("alumnos.bak","rb");
    if(pBak==NULL)return false;

    p=fopen("alumnos.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);
}

#endif // FGLOBALES_H_INCLUDED
