///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;
///CLASE (class): es un molde donde se definen las propiedades y el comportamiento que tendrán los OBJETOS de esa clase
///Es un tipo de datos TDA

///OBJETO: instancia de una clase, variable de una clase.

///ENCAPSULAMIENTO: mecanismo que proveen las clases que protejen los datos almacenados en los objetos.
///A las propiedades que contienen los datos SOLO SE ACCEDE mediante METODOS definidos en la propia clase

///ESPECIFICADORES DE ACCESO
        ///PRIVATE: privado. Lo que está definido en la parte privada SOLO es accesible DENTRO DE LA CLASE.
        ///PUBLIC: público. Lo que está definido como público, es accesible tanto dentro como fuera de la clase

class Materia{
    private:///PROPIEDADES O VARIABLES DE LA CLASE
        int numeroMateria;
        int cantAlumnos, cantProfes;
        char nombre[35];
    public:///METODOS O FUNCIONES DE LA CLASE
        void Cargar(){
            int nm, alu, profe;
            char nombreMat[35];
            cout<<"NUMERO DE MATERIA ";
            cin>>nm;
            setNumeroMateria(nm);
            cout<<"NOMBRE DE MATERIA ";
            cin>>nombreMat;
            setNombreMateria(nombreMat);
            cout<<"CANTIDAD DE ALUMNOS ";
            cin>>alu;
            setCantidadAlumnos(alu);
            cout<<"CANTIDAD DE DOCENTES ";
            cin>>profe;
            setCantidadProfesores(profe);
        }
        void Mostrar();
        ///métodos para cambiar el valor de cada propiedad: set()
        void setNumeroMateria(int nm){
            if(nm>=1 && nm<=20)numeroMateria=nm;
            else numeroMateria=0;
        }
        void setNombreMateria(const char *nMat){
            strcpy(nombre, nMat);
        }
        void setCantidadAlumnos(int ca){
            if(ca>0) cantAlumnos=ca;
            else cantAlumnos=0;
        }
        void setCantidadProfesores(int ca){
            if(ca>0) cantProfes=ca;
            else cantProfes=0;
        }
        ///gets() permiten que el mundo externo conozca el valor de cada propiedad
        int getNumeroMateria(){return numeroMateria;}
        const char *getNombreMateria(){return nombre;}
        int getCantidadAlumnos(){return cantAlumnos;}
        int getCantidadProfesores(){return cantProfes;}

};
///::->operador de alcande de resolución. Indica que la función Mostrar() pertenece a la clase Materia
void Materia::Mostrar(){
    cout<<"NUMERO DE MATERIA ";
    cout<<numeroMateria<<endl;
    cout<<"NOMBRE DE MATERIA ";
    cout<<nombre<<endl;
    cout<<"CANTIDAD DE ALUMNOS ";
    cout<<cantAlumnos<<endl;
    cout<<"CANTIDAD DE DOCENTES ";
    cout<<cantProfes<<endl<<endl;
}

///FUNCIONES GLOBALES: no pertenecen a ninguna clase.
void cargarMaterias(Materia *pMat, int tam){
    int i;
    Materia obj;
    for(i=0;i<tam;i++){
        obj.Cargar();
        pMat[i]=obj;
    }
}

void mostrarMaterias(Materia *pMat, int tam){
    int i;
    for(i=0;i<tam;i++){
        pMat[i].Mostrar();
    }
}

void mostrarMateriasCantidadDocentes(Materia *vMaterias, int tamVector, int cantPro){
    int i;
    for(i=0;i<tamVector; i++){
        if(vMaterias[i].getCantidadProfesores()>cantPro){
            //vMaterias[i].Mostrar();
            cout<<vMaterias[i].getNumeroMateria()<<"\t";
            cout<<vMaterias[i].getNombreMateria()<<endl;
        }
    }

}



int main(){

    Materia vReg[5];
    cargarMaterias(vReg,5);
    mostrarMateriasCantidadDocentes(vReg, 5, 5);


    //mostrarMaterias(vReg,3);
    /*
    int i;
    for(i=0;i<3;i++){
        if(vReg[i].getCantidadAlumnos()>100)
            ///vReg[i].Mostrar();
            cout<<vReg[i].getNombreMateria()
        }
    }
     */
    /*Materia vObj;
    vObj.Cargar();
    vObj.Mostrar();
    /*cout<<endl<<endl;
    vObj.setNumeroMateria(-15);
    vObj.Mostrar();
      */

	cout<<endl;
	system("pause");
	return 0;
}
