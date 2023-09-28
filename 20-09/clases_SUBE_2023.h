//Ejercicio:
//Autor:
//Fecha:
//Comentario:


class Fecha{
    private:
        int dia, mes, anio;
    public:
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

        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};


class Tarjeta{
  private:
    int nroTarjeta;
    Fecha fechaAlta;
    int dni;
    float saldo;
    bool estado;
  public:
    int getNroTarjeta(){return nroTarjeta;}
    int getDiaAlta(){return fechaAlta.getDia();}
    int getMesAlta(){return fechaAlta.getMes();}
    int getAnioAlta(){return fechaAlta.getAnio();}
    int getDNI(){return dni;}
    float getSaldo(){return saldo;}
  };


class ArchivoTarjeta{
private:
    char nombre[30];
public:
    ArchivoTarjeta(const char *n){
        strcpy(nombre,n);
    }
    Tarjeta leerRegistro(int pos){
        FILE *p;
        Tarjeta x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
      }
      int grabarRegistro(Tarjeta x){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int escribio=fwrite(&x, sizeof x, 1, p);
        fclose(p);
        return escribio;
      }
      int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Tarjeta);
      }
};


class Viaje{
 private:
    int nroViaje;
    int nroTarjeta;
    int medio;
    Fecha fechaViaje;
    float importe;
    bool estado;
  public:
    int getNroTarjeta(){return nroTarjeta;}
    int getMedioTransporte(){return medio;}
    int getMesViaje(){return fechaViaje.getMes();}
    int getAnioViaje(){return fechaViaje.getAnio();}
    float getImporte(){return importe;}
    void Mostrar(){}
};


class ArchivoViaje{
private:
    char nombre[30];
public:
    ArchivoViaje(const char *n){
        strcpy(nombre,n);
    }
    Viaje leerRegistro(int pos){
        FILE *p;
        Viaje x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
      }
      int grabarRegistro(Viaje x){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int escribio=fwrite(&x, sizeof x, 1, p);
        fclose(p);
        return escribio;
      }
      int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Viaje);
      }
};
