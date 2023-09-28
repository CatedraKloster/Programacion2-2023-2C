///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

///1. Modificar el archivo trabajado en clase de la siguiente manera:
/// Hacer un menú con las opciones:
     ///1. Cargar 1 registro
     ///2. Mostrar registros
     ///0. Salir.
     ///Usar funciones para cada opción
///2. Agregar otro opción al menú para que acepte y cargue un vector con 5 registros
///3. Agregar una opción que se llame buscar registro por nombre.
/// Si se selecciona esa opción, el programa debe pedir un nombre, y mostrar todos los registro con ese nombre

///Hacer un submenú al que se accede mediante la opción CONSULTAS del menú principal para resolver los puntos
/// que se describen a continuación

/// 4. CONSULTAS

///4. Suponiendo que hay 10 cargos para los empleados definidos entre 1 y 10, indicar cuántos empleados hay en
///cada uno de esos cargos

///5.Mostrar todos los empleados nacidos a partir de un año que se ingresa por teclado

///6. Informar cuántos empleados hay registrados en el archivo

///agregar las consultas que consideren puedan ser importantes


class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        ///sets: métodos para asignar valores a las propiedades
        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int d){
            if(d>=1 && d<=12) mes=d;
            else this->mes=-1;
        }
        void setAnio(int d){
            if(d>=1900) anio=d;
            else anio=-1;
        }

        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}


};


class Empleado{
private:
    int DNI;
    char nombre[30],  apellido[30];
    char domicilio[30];
    char email[35];
    Fecha fechaNacimiento;
    int cargo; ///1 a 10
    ///bool borrado;///true-> cuando está borrado
    bool estado;///true-> cuando no está borrado

public:
    Empleado(int dni=0, const char *n="nadie", const char *a="ninguno", int dia=2){
        DNI=dni;
        strcpy(nombre,n);
        strcpy(apellido,a);
        fechaNacimiento.setDia(2);
    }
    ///sets()
    void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setDomicilio(const char *n){strcpy(domicilio,n);}
    void setEmail(const char *n){strcpy(email,n);}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setCargo(int c){cargo=c;}
    void setEstado(bool e){estado=e;}
    ///gets()
    int getDNI(){return DNI;}

    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getDomicilio(){return domicilio;}
    const char *getEmail(){return email;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    int getCargo(){return cargo;}
    bool getEstado(){return estado;}

    void Mostrar(){
        if(estado==true){
            cout<<"DOCUMENTO ";
            cout<<DNI<<endl;
            cout<<"NOMBRE ";
            cout<<nombre<<endl;
            cout<<"APELLIDO ";
            cout<<apellido<<endl;
            cout<<"FECHA DE NACIMIENTO ";
            fechaNacimiento.Mostrar();
            cout<<"DOMICILIO ";
            cout<<domicilio<<endl;
            cout<<"EMAIL ";
            cout<<email<<endl;
            cout<<"CARGO ";
            cout<<cargo<<endl<<endl;
        }
    }

void Cargar(int d=-1){
    if(d==-1){
        cout<<"DOCUMENTO ";
        cin>>DNI;
    }
    else{
        DNI=d;
    }
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"DOMICILIO ";
    cin>>domicilio;
    cout<<"EMAIL ";
    cin>>email;
    cout<<"CARGO ";
    cin>>cargo;
    estado=true;
    }
};



class ArchivoEmpleado{
private:
    char nombre[30];
public:
    ArchivoEmpleado(const char *n){
        strcpy(nombre, n);
    }
    bool listarRegistros();
    int buscarDNI(int dni);
    Empleado leerRegistro(int pos);
    bool modificarRegistro(Empleado reg, int pos);
    bool grabarRegistro(Empleado reg);


};



///PROTOTIPOS
int buscarDNI(int dni);
///

bool cargarRegistro(){
    Empleado reg;
    ArchivoEmpleado archi("empleados.dat");

    int dni;
    cout<<"DOCUMENTO ";
    cin>>dni;
    int pos=archi.buscarDNI(dni);

    if(pos==-1){
        reg.Cargar(dni);
        bool escribio=archi.grabarRegistro(reg);
        return escribio;
    }
    return false;
}
bool ArchivoEmpleado::grabarRegistro(Empleado reg){
    FILE *p;
    p=fopen("empleados.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(Empleado),1,p);
    fclose(p);
    return escribio;
}


bool ArchivoEmpleado::listarRegistros(){
	Empleado reg;
    FILE *pEmp;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Empleado),1,pEmp)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pEmp);
    return true;
}



bool buscarPorNombre(){
    char nombre[30];
    Empleado reg;
    FILE *pEmp;
    bool existe=false;
    pEmp=fopen("empleados.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    cout<<"INGRESAR NOMBRE A BUSCAR ";
    cin>>nombre;
    while(fread(&reg,sizeof(Empleado),1,pEmp)==1){
        if(strcmp(reg.getNombre(),nombre)==0){
            reg.Mostrar();
            existe=true;
        }
    }
    fclose(pEmp);
    if(existe==false){
        cout<<"NO HAY REGISTROS CON ESE NOMBRE"<<endl;
    }
    return true;
}

int ArchivoEmpleado::buscarDNI(int dni){
    Empleado reg;
    FILE *pEmp;
    pEmp=fopen("empleados.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Empleado),1,pEmp)==1){
        if(reg.getDNI()==dni){
            fclose(pEmp);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pEmp);
    return -1;
}

/*Empleado leerRegistro(int pos){
    Empleado reg;
    reg.setDNI(-1);
    FILE *pEmp;
    pEmp=fopen("empleados.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Empleado),1,pEmp)==1){
        if(pos==posRegistro){
            fclose(pEmp);
            return reg;
        }
        posRegistro++;
    }
    fclose(pEmp);

    reg.setDNI(-1);
    return reg;
}
*/
Empleado ArchivoEmpleado::leerRegistro(int pos){
    Empleado reg;
    reg.setDNI(-1);
    FILE *pEmp;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(pEmp,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Empleado),1,pEmp);
    fclose(pEmp);

    if(leyo==0) reg.setDNI(-1);
    return reg;
}

bool ArchivoEmpleado::modificarRegistro(Empleado reg, int pos){
    FILE *pEmp;
    pEmp=fopen(nombre,"rb+");///+ le agrega al modo lo que no tiene
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pEmp,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Empleado),1,pEmp);
    fclose(pEmp);
    return escribio;
}


bool bajaLogica(){
    ///BUSCAR EL REGISTRO
    ArchivoEmpleado archi("empleados.dat");
    int dni;
    cout<<"INGRESAR EL DNI DEL EMPLEADO A DAR DE BAJA ";
    cin>>dni;
    ///VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int pos=archi.buscarDNI(dni);
    ///SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE DNI"<<endl;
        return false;
    }
    ///SI EXISTE, LEER EL REGISTRO
    Empleado reg;case 6: cargoMasEmpleados()
    reg=archi.leerRegistro(pos);
    if(reg.getDNI()==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
    }
    ///CAMBIAR EL VALOR DEL CAMPO/PROPIEDAD estado
    reg.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(reg, pos);
    return quePaso;
}

bool modificarEmail(){
///
         return true;
}

void cargoMasEmpleados(){
    ArchivoEmpleado archiEmp("empleados.dat");
    Empleado reg;
    int vCargos[10]={0};            ///hay 10 cargos definidos entre 1 y 10
    int cantRegistros=archiEmp.contarRegistros();
    int i;
    for(i=0;i<cantRegistros;i++){
        reg=archiEmp.leerRegistro(i);
        vCargos[reg.getCargo()-1]++;
    }
    int posMax=buscarMaximo(vCargos, 10);///devuelve la posición del máximo en el vector
    cout<<"EL CARGO CON MAS EMPLEADOS ES "<<posMax+1<<endl;
}

int main(){
    int opc;
    ArchivoEmpleado archiEmp("empleados.dat");
    while(true){
        system("cls");
        cout<<"MENU EMPLEADOS"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"1. ALTA REGISTRO"<<endl;
        cout<<"2. LISTADO REGISTROS"<<endl;
        cout<<"3. BAJA LOGICA REGISTRO"<<endl;
        cout<<"4. BUSCAR REGISTRO POR NOMBRE"<<endl;
        cout<<"5. MODIFICAR EMAIL"<<endl;
        cout<<"6. INFORMAR CARGO CON MAS EMPLEADOS"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(cargarRegistro()) cout<<"REGISTRO AGREGADO";
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2: archiEmp.listarRegistros();
                break;
            case 3: if(bajaLogica()==true) cout<<"REGISTRO DADO DE BAJA"<<endl;
                    else cout<<"NO SE PUDO DAR DE BAJA EL REGISTRO"<<endl;
                break;
            case 4:  buscarPorNombre();
                break;
            case 5: if(modificarEmail()==true) cout<<"REGISTRO MODIFICADO"<<endl;
                    else cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                break;
            case 6: cargoMasEmpleados();
                break;
            case 0:return 0;
                break;
        }
        cout<<endl;
        system("pause");
    }
	cout<<endl;
	system("pause");
	return 0;
}

