#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Instructores {
    private:
      int DNI;
      char nombre[50];
      char apellido[50];
      int codnac;
      int nivel;
      int dia, mes, ano;

    public:
    int getDNI(){return DNI;}
    const char* getnombre(){return nombre;}
    const char* getapellido(){return apellido;}
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getano(){return ano;}
    int getdia(){return dia;}
    int getcodnac(){return codnac}
    int getnivel(){return nivel}

    bool leerDeDisco(int );
};

 bool Instructores::leerDeDisco(int pos){
 bool leyo;
 FILE *p;
 p=fopen("instructores.dat", "rb");
 if(p==NULL)exit(1);
 fseek(p,sizeof *this*pos,0);
 leyo=fread(this, sizeof *this, 1, p);
 fclose(p);
 return leyo;
 }


class final{
    private:
    int DNI;
    int dia, mes,ano;
    int codavion;
    int nivel;
    int codasp;

    public:
    int getDNI(){return DNI;}
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getano(){return ano;}
    int getdia(){return dia;}
    int getcodavion(){return codavion}
    int getnivel(){return nivel}
    int getcodasp(){return codasp}
    bool leerDeDisco(int );
};
bool final::leerDeDisco(int pos){
 bool leyo;
 FILE *p;
 p=fopen("final.dat", "rb");
 if(p==NULL)exit(1);
 fseek(p,sizeof *this*pos,0);
 leyo=fread(this, sizeof *this, 1, p);
 fclose(p);
 return leyo;
 }



class final_2019{
    private:
      int DNI;
      char nombre[50];
      char apellido[50];
      int cantfinales;
    public:

 public:
 int getDNI(){return DNI;}
 const char* getNombre(){return nombre;}
 const char* getapellido(){return apellido;}
 int getCantidadfinales(){return cantfinales;}
 bool leerDeDisco(int);
 void grabarEnDisco();
 void setDNI(int*ce){DNI=ce);}
 void setNombre(const char *ne){strcpy(nombre,ne);}
 void setapellido(const char *na){strcpy(apellido,na);}
 void setCantidadfinales(int co){cantfinales=co;}
};

bool final_2019::leerDeDisco(const int pos){
 bool leyo;
 FILE *p;
 p=fopen("final_2019.dat", "rb");
 if(p==NULL)exit(1);
 fseek(p,sizeof *this*pos,0);
 leyo=fread(this, sizeof *this, 1, p);
 fclose(p);
 return leyo;
 }
void final_2019::grabarEnDisco(){
 FILE *p;
 p=fopen("final_2019.dat", "ab");
 if(p==NULL)exit(1);
 fwrite(this, sizeof *this, 1, p);
 fclose(p);
 }

  void punto1();
  int contarfinales(int);
  void punto2();
  void ponerCero(int *v){};
  void mostrar(int *v){};



int main(){
    punto1();
    system("pause");
    punto2();
    system("pause");
    return 0;
}




void punto1(){
 Instructores reg;
 final_2019 aux;
 int pos=0;
 while(reg.leerDeDisco(pos++)){
 aux.setDNI(reg.getDNI());
 aux.setNombre(reg.getnombre());
 aux.setapellido(reg.getapellido());
 aux.setCantidadfinales(contarfinales(reg.getDNI()));
 aux.grabarEnDisco();
 }
 }
int contarfinales(int dni){
 final reg;
 int cant=0, pos=0;
 while(reg.leerDeDisco(pos++)){
 if(reg.getano()==2019){
 if(reg.getDNI == dni) cant++;
 } }
 return cant;
}



void punto2(){
  Instructores obj;
  int v[15], pos=0;
  ponerCero(v);
  while(obj.leerDeDisco(pos++)){
    v[obj.getnivel()-1]++;
    }
  mostrar(v);
  }

void ponerCero(int *v){

for(int i=0; i<15; i++){

    v[i]=0;
}
return;
}

void mostrar(int *v){

for(int i=0; i<15; i++){

    cout<<endl;
    cout<<endl;
    cout<<"NIVEL:"<<i+1<<"cantidad de intructores: "<< v[i];
    cout<<endl;
    cout<<endl;
}
return;
}



