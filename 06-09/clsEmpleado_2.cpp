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
    ///gets()
    int getDNI(){return DNI;}

    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getDomicilio(){return domicilio;}
    const char *getEmail(){return email;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    int getCargo(){return cargo;}
    void Mostrar(){
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
void Cargar(){
        cout<<"DOCUMENTO ";
        cin>>DNI;
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
    }
};



bool cargarRegistro(){
    Empleado reg;
    FILE *pEmp;
    pEmp=fopen("empleados.dat","ab");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    reg.Cargar();
    ///¿cómo evitar registros duplicados?
    bool escribio=fwrite(&reg,sizeof(Empleado),1,pEmp);
    fclose(pEmp);
    return escribio;
}

bool mostrarRegistros(){
	Empleado reg;
    FILE *pEmp;
    pEmp=fopen("empleados.dat","rb");
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

bool cargarDeVector(){
    const int TAM=3;
    Empleado v[TAM];
    for(int i=0;i<TAM;i++){
        v[i].Cargar();
    }
    FILE *pEmp;
    pEmp=fopen("empleados.dat","ab");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(v, sizeof(Empleado),TAM,pEmp);
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


int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU EMPLEADOS"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"1. AGREGAR REGISTRO"<<endl;
        cout<<"2. MOSTRAR REGISTROS"<<endl;
        cout<<"3. AGREGAR 5 REGISTROS DESDE VECTOR"<<endl;
        cout<<"4. BUSCAR REGISTRO POR NOMBRE"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(cargarRegistro()) cout<<"REGISTRO AGREGADO";
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2: mostrarRegistros();
                break;
            case 3: cargarDeVector();
                break;
            case 4:  buscarPorNombre();
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

