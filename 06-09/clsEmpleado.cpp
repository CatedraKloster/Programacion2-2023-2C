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
    int cargo;
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

///constante NULL QUE ES EL UNICO VALOR QUE SE LE PUEDE ASIGNAR "A MANO" A UN PUNTERO PARA LUEGO COMPARAR QUE CONTIENE

int main(){
    /*Empleado reg;
    const char* MODO_ESCRITURA_DESDE_CERO="wb";

    FILE *pEmp;
    pEmp=fopen("empleados.dat","ab");
    ///modo de apertura
        ///wb: write-> agregar registros (escribir) en el archivo. SIEMPRE CREA UN ARCHIVO NUEVO VACIO
        ///ab: append->agregar registros, pero los registros nuevos se escriben a continuación de los existentes.
        ///Si el archivo no existe lo crea.
        ///rb: read-> sólo lectura. El archivo tiene que existir

    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    reg.Cargar();///escribí un conjunto de valores en una variable (objeto)
    fwrite(&reg,sizeof(Empleado),1,pEmp);///llevar de la memoria al disco
    fclose(pEmp);
	cout<<endl;
	system("pause");
	return 0;  */
	////Para lectura
	Empleado reg;
    FILE *pEmp;
    pEmp=fopen("empleados.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    /*int valor;
    valor=fread(&reg,sizeof(Empleado),1,pEmp);///traer del disco a la memoria
    reg.Mostrar();
    cout<<"VALOR DEVUELTO POR fread() EN LA PRIMERA LECTURA "<<valor<<endl<<endl;
    valor=fread(&reg,sizeof(Empleado),1,pEmp);///traer del disco a la memoria
    reg.Mostrar();
    cout<<"VALOR DEVUELTO POR fread() EN LA SEGUNDA LECTURA "<<valor<<endl<<endl;
    valor=fread(&reg,sizeof(Empleado),1,pEmp);///traer del disco a la memoria
    cout<<"VALOR DEVUELTO POR fread() EN LA TERCERA LECTURA "<<valor<<endl<<endl;
    */


    fread(reg, sizeof reg,3, pEmp);

    for(int i=0;i<3;i++)
    {
        reg[i].Mostrar();
    }
    fclose(pEmp);
	cout<<endl;
	system("pause");
	return 0;
}

