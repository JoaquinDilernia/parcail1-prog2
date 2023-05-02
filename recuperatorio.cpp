#include <iostream>
#include <cstdlib>
#include <cstdio>





struct deportista{
  int dni;
  char Nombre[45];
  char apellido [45];
  int Nacademica;
  char mail[45];
  int Especialidad;

};

struct torneo{
int Ntorneo;
char nombre[45];
int Especialidad;
int Nacademica;

};

struct inscripciones{
int DNI;
int Ntorneo;
int tipo;
int dia, mes, ano;

};


struct Punto1 {

int dni;
int Ntorneo;
int dia,mes,ano;


};


void grabarRegistro(Punto1 aux){
    FILE *p;
    p=fopen("punto1.dat", "ab");
    if(p==NULL)return;
    fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
}

using namespace std;


int main(){
    punto1();
    system("pause");
    punto2();
    system("pause");
    return 0;
}

void punto1(){
    FILE *p;
  inscripciones reg;
    Punto1 aux;
    int dni;
    int cant;
    p=fopen("inscripciones.dat", "rb");
    if(p==NULL){
        return;
    }
    cout<< "ingrese dni del deportista:"<<endl;
    cin>>dni;
    while(fread(&reg, sizeof reg,1, p)==1){

        if(dni == reg.DNI){
            aux.dni = reg.DNI;
            aux.Ntorneo = reg.Ntorneo;
            aux.dia = reg.dia;
            aux.mes = reg.mes;
            aux.ano = reg.ano;
            grabarRegistro(aux);
        }
    }
    mostrar(dni);
    fclose(p);
    return;
}

void mostrar (int dni)
{
     FILE *p;
     Punto1 reg;
         p=fopen("punto1.dat", "rb");
    if(p==NULL){
        return;
    }
      while(fread(&reg, sizeof reg,1, p)==1){

        if(dni == reg.DNI){

            cout<<endl;
            cout "-------------------------------------"<<endl;
            cout<< "DNI : "<< reg.dni<<endl;
            cout<< "NUMERO DEL TORNEO: "<< reg.Ntorneo<<endl;
            cout<< "DIA : "<<reg.dia<<endl;
            cout<< "MES : "<<reg.mes<<endl;
            cout<< "AÑO : "<<reg.ano<<endl;
            cout "-------------------------------------"<<endl;
            cout<<endl;
        }

      }
    fclose(p);
    return;
}






void punto2(){
   FILE *p;
   deportista reg;

   int vec[10]={0};
   p=fopen("deportista.dat", "rb");
   if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
   }
   while(fread(&reg,sizeof reg,1, p)==1){

            vec[reg.Especialidad-1]++;

   }
   fclose(p);
   mostrar(vec);
return;
}

void mostrar(int * vec)
{
    int cant = 0;
for(int i = 0; i < 135; i++)
{
if(vec[i] > 50 )
{
cant ++;
}
}


cout<< "La cantidad de especialidades con mas de 50 deportistas es: " <<cant<<endl;
system("pause");
return;
}

