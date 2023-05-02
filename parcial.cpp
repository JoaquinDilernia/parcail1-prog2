#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "tipos.h"


struct fecha{
  int dia, mes, anio;
};

struct medico{
  int dni;
  char nombre[30];
  char apellido[30];
  char email[40];
  char telefono[20];
  int cargo, especialidad, localidad;
   bool estado;
};

struct hospital{
  int numero;
  int especialidad, region. anio;
  char nombre[45];
  int dniDirector;
  bool estado;
};

struct contrato{
  int dniMédico;
  int numeroHospital;
  int tipoContrato;
 fecha fecha_contrato;
  bool estado;
};


struct anestesistas {

int dni;
char  nombre[30];
int cantcontraros;

};


void grabarRegistro(anestesistas aux){
    FILE *p;
    p=fopen("anestesistas.dat", "ab");
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

void punto2(){
    FILE *p;
    medico reg;
    anestesistasaux;
    int cant;
    p=fopen("medico.dat", "rb");
    if(p==NULL){
        return;
    }
    while(fread(&reg, sizeof reg,1, p)==1){
        cant=contarPermanente(reg.dni);
        if(cant>0){
            aux.dni=reg.dni;
            strcpy(aux.nombre, reg.nombre);
            aux.cantcontraros=cant;
            grabarRegistro(aux);
        }
    }
    fclose(p);
    return;
}



int contarPermanente(int dni){
    FILE *p;
    contrato reg;
    int cant=0;
    p=fopen("contrato.dat", "rb");
    if(p==NULL){
        return;
    }
    while(fread(&reg, sizeof reg,1, p)==1){
        if(reg.dni==dni && reg.tipoContrato == 2) cant++;
    }
    fclose(p);
    return cant;
}




void punto1(){
   FILE *p;
   medico reg;

   int vec[135]={0};
   p=fopen("medicos.dat", "rb");
   if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
   }
   while(fread(&reg,sizeof reg,1, p)==1){

            vec[reg.localidad-1]++;

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
if(vec[i] <= 50 )
{
cant ++;
}
}


cout<< "La cantidad de municipios de residencia con menos de 50 médicos: " <<cant<<endl;
system("pause");
return;
}

