///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;



class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Cargar();
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
        int getMes(){return mes;}strcpy(nombre,n);
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
        cout<<DNI<<endl;
        cout<<nombre<<endl;
        cout<<apellido<<endl;
        fechaNacimiento.Mostrar();
    }

};


int main(){
    Empleado reg;
    reg.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
