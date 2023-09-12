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


};

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
