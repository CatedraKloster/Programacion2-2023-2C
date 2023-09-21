#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOALUMNOS_H_INCLUDED

class ArchivoAlumnos{
private:
    char nombre[30];
public:
    ArchivoAlumnos(const char *n){
        strcpy(nombre,n);
    }
    bool listarRegistros();
    bool grabarRegistro(Alumno);
    int buscarLegajo(int legajo);
    Alumno leerRegistro(int pos);
    bool sobreEscribirRegistro(Alumno reg, int pos);
    //int contarRegistrosActivos(int );
    int contarRegistrosActivos();
    int contarRegistros();
};
/*
int ArchivoAlumnos::contarRegistros(int queContar=0){
    Alumno reg;
    int cuentaReg=0;
    FILE *p;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
            if(queContar==0){
                if(reg.getEstado()) cuentaReg++;
            }
            else{
                cuentaReg++;
            }
    }
    fclose(p);
    return cuentaReg;
}
  */

int ArchivoAlumnos::contarRegistrosActivos(){
    Alumno reg;
    int cuentaReg=0;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getEstado()) cuentaReg++;
    }
    fclose(p);
    return cuentaReg;
}

int ArchivoAlumnos::contarRegistros(){
    int cantReg=0;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0, 2);
    int cantBytes=ftell(p);/// me dice que cantidad de bytes hay desde el principio del archivo
            ///hasta la posición actual del puntero file
    fclose(p);
    cantReg=cantBytes/sizeof(Alumno);
    return cantReg;
}

bool ArchivoAlumnos::sobreEscribirRegistro(Alumno reg, int pos){
    FILE *p;
    p=fopen(nombre, "rb+");///+ agrega al modo lo que le falta
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

Alumno ArchivoAlumnos::leerRegistro(int pos){
    Alumno reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return reg;
    }
    fseek(p,sizeof reg*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

int ArchivoAlumnos::buscarLegajo(int legajo){
    Alumno reg;
    FILE *p;
    p=fopen(nombre, "rb");
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

bool ArchivoAlumnos::listarRegistros(){
    Alumno reg;
    FILE *pAlu;
    pAlu=fopen(nombre, "rb");
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

bool ArchivoAlumnos::grabarRegistro(Alumno reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);
	fclose(p);
    return escribio;
}

#endif // CLSARCHIVOALUMNOS_H_INCLUDED
