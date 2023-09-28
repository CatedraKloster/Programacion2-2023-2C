#ifndef PERSONAALUMNO_H_INCLUDED
#define PERSONAALUMNO_H_INCLUDED

class Persona{     ///clase base
protected:
    char nombre[30], apellido[30], direccion[30];
    char email[30], telefono[30];
    int DNI;
    Fecha fechaNacimiento;
    bool estado;
public:
    void Cargar();
    void Mostrar();
    bool setDNI(int d){
        if(DNI<=0) return false;
        DNI=d;
    }

    int getDNI(){return DNI;}
    void setEstado(bool e){estado=e;}
    bool getEstado(){return estado;}

    const char *getApellido(){return apellido;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}

};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"DIRECCION: ";
    cargarCadena(direccion, 29);
    cout<<"EMAIL: ";
    cargarCadena(email, 29);
    cout<<"TELEFONO: ";
    cargarCadena(telefono, 29);
    cout<<"DNI: ";
    int doc
    cin>>doc;
    if(!setDNI(doc)){
        cout<<"NO PUEDE HABER UN DNI NEGATIVO";
        return;
    }
    DNI=doc;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();
    estado=true;
}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DIRECCION: ";
    cout<<direccion<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
}

class Alumno: public Persona{
private:
    int legajo;
    int IDCarrera;
    char tituloSecundario[30];
public:
    void Cargar();
    void Mostrar();

    void setLegajo(int l){legajo=l;}
    int getlegajo(){return legajo;}
    void setDNI(int d){DNI=d;}

    void setTitulo(const char *nt){strcpy(tituloSecundario,nt);}
};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"ID DE LA CARRERA: ";
    cin>>IDCarrera;
    cout<<"TITULO SECUNDARIO: ";
    cargarCadena(tituloSecundario,29);
}

void Alumno::Mostrar(){
    if(estado==true){
        Persona::Mostrar();
        cout<<"LEGAJO: ";
        cout<<legajo<<endl;
        cout<<"ID DE LA CARRERA: ";
        cout<<IDCarrera<<endl;
        cout<<"TITULO SECUNDARIO: ";
        cout<<tituloSecundario<<endl;
    }
}


#endif // PERSONAALUMNO_H_INCLUDED
