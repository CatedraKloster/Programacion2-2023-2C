#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void punto1(){
    int cantReg, i;
    ArchivoAlumnos archi("alumnos.dat");
    Alumno reg;
    char apellido[30];
    cantReg=archi.contarRegistros();
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        strcpy(apellido,reg.getApellido());
        if(apellido[0]=='M' && reg.getEstado()){
            reg.Mostrar();
        }
    }
}
                         // 1980-2005->26
void punto3(){
    int cantReg, i;
    ArchivoAlumnos archi("alumnos.dat");
    Alumno reg;
    int vAnios[26]={0};
    cantReg=archi.contarRegistros();
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        if(reg.getEstado()){
            ///if(reg.getFechaNacimiento().getAnio()>=1980)
                vAnios[reg.getFechaNacimiento().getAnio()-1980]++;
        }
    }
    for(i=0;i<26;i++){
        if(vAnios[i]!=0){
            cout<<"ANIO "<<1980+i<<"\t";
            cout<<"CANTIDAD "<<vAnios[i]<<endl;
        }
    }
}

#endif // REPORTES_H_INCLUDED
