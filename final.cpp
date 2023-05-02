#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

///////////////////////////////////////////////////////////////////
class Investigadores{
   int DNI;
   char nombre[50];
   char apellido[50];
   int numlabor;
   int cat;
   int esp;

     public:
    int getDNI(){return DNI;}
    const char* getnombre(){return nombre;}
    const char* getapellido(){return apellido;}
    int getnumlabor(){return numblabor}
    int getcat(){return cat}
    int getesp(){return esp}

    bool leerDeDisco(int );
};

 bool Investigadores::leerDeDisco(int pos){
 bool leyo;
 FILE *p;
 p=fopen("Investigadores.dat", "rb");
 if(p==NULL)exit(1);
 fseek(p,sizeof *this*pos,0);
 leyo=fread(this, sizeof *this, 1, p);
 fclose(p);
 return leyo;
 }


class Inscripciones{
    private:
 int DNI;
 int dia;
 int mes;
 int año;
 int tipoinv;
 int numproy;

    public:
    int getDNI(){return DNI;}
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getano(){return ano;}
    int gettipoinv(){return tipoinv}
    int getnumproy(){return numproy}

    bool leerDeDisco(int );
};
bool Inscripciones::leerDeDisco(int pos){
 bool leyo;
 FILE *p;
 p=fopen("Inscripciones.dat", "rb");
 if(p==NULL)exit(1);
 fseek(p,sizeof *this*pos,0);
 leyo=fread(this, sizeof *this, 1, p);
 fclose(p);
 return leyo;
 }



class inc_4_5{
    private:
      int DNI;
      char nombre[50];
      char apellido[50];
      int cantinc;
    public:

 public:
 int getDNI(){return DNI;}
 const char* getNombre(){return nombre;}
 const char* getapellido(){return apellido;}
 int getCantinc(){return cantinc;}
 bool leerDeDisco(int);
 void grabarEnDisco();
 void setDNI(int*ce){DNI=ce);}
 void setNombre(const char *ne){strcpy(nombre,ne);}
 void setapellido(const char *na){strcpy(apellido,na);}
 void setCantinc(int co){cantinc=co;}
};

bool inc_4_5::leerDeDisco(const int pos){
 bool leyo;
 FILE *p;
 p=fopen("Inc_4-5.dat", "rb");
 if(p==NULL)exit(1);
 fseek(p,sizeof *this*pos,0);
 leyo=fread(this, sizeof *this, 1, p);
 fclose(p);
 return leyo;
 }
void inc_4_5::grabarEnDisco(){
 FILE *p;
 p=fopen("Inc_4-5.dat", "ab");
 if(p==NULL)exit(1);
 fwrite(this, sizeof *this, 1, p);
 fclose(p);
 }

 ///////////////////////////////////////////////////////////////////
  void punto1();
  int contarInc(int);
  void punto2();
  void ponerCero(int *v){};
  int buscamayor(int *v){};

///////////////////////////////////////////////////////////////////

int main(){
    punto1();
    system("pause");
    punto2();
    system("pause");
    return 0;
}



///////////////////////////////////////////////////////////////////
void punto1(){
 Instructores reg;
inc_4_5 aux;
 int pos=0;
 while(reg.leerDeDisco(pos++)){
 aux.setDNI(reg.getDNI());
 aux.setNombre(reg.getnombre());
 aux.setapellido(reg.getapellido());
 aux.setCantinc(contarInc(reg.getDNI()));
 aux.grabarEnDisco();
 }
 }
int contarInc(int dni){
Inscripciones reg;
 int cant=0, pos=0;
 while(reg.leerDeDisco(pos++)){
 if(reg.getDNI == dni){
 if(reg.tipoinv == 4 or reg.tipoinv == 5) cant++;
 } }
 return cant;
}
///////////////////////////////////////////////////////////////////


void punto2(){
  Investigadores obj;
  int v[5], pos=0;
  ponerCero(v);
  while(obj.leerDeDisco(pos++)){
    v[obj.getcat()-1]++;
    }
  int maximo = buscarmayor(v);

cout<< "la categoria con mas investigadore es "<<maximo+1<<endl;
    system("pause");

  }

void ponerCero(int *v){

for(int i=0; i<5; i++){

    v[i]=0;
}
return;
}

int buscamayor(int *v){
int maximo=0;
int x=0,
for(int i=0; i<5; i++){

 if(v[i] > maximo){
			maximo = v[i];
			x = i;
}
return x;
}
///////////////////////////////////////////////////////////////////
class Felino:public Animal
	{
	 private:
		char categoria[35];
		int tamaño;
	 public:
	      const char* getcategoria(){return categoria;}
	      int gettamaño(){return tamaño;}
	     void setcategoria(const char *ne){strcpy(categoria,ne);}
	     void settamaño(int co){tamaño=co;}

	 };







