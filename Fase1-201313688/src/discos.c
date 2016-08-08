#include "discos.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void NewDisc(int size, char unit, char *path, char *name){

    //Verificar si existe el fichero
    FILE* archivo = fopen(path, "r");

    if (archivo) {
    fclose(archivo);
    printf("El archivo existe no se puede crear el nuevo disco");
    return ;
    } else {
        char *un1, *un2;
        int y=0,u=0;
        int BytesTam=size+sizeof(MBR);
        char *espacios;
        char *a = strtok_r(path, "\"", &espacios);

        while (a != NULL)
        {
          un1=a;
            a = strtok_r(NULL, "\"", &espacios);
               }


        char *espacios1;
        char *b = strtok_r(name, "\"", &espacios1);

        while (b != NULL)
        {
            if(y==0){
            un2=b;
            }
            y++;
            b = strtok_r(NULL, "\"", &espacios1);
               }
        char * ruta= (char *) malloc(1 + strlen(un1)+ strlen(un2) );
        strcpy(ruta, un1);
        strcat(ruta, un2);
         //  printf("%s ************************************************************** dato \n",ruta);

       FILE *nuevoDisco;
        nuevoDisco=fopen(ruta,"w+b");
        if(nuevoDisco != NULL){
         ftruncate(fileno(nuevoDisco),BytesTam);
         MBR *mbr=malloc(sizeof(MBR));
         IniciarMBR(mbr,BytesTam);
         fwrite(mbr,sizeof(MBR),1,nuevoDisco);


        }
   }


}

void IniciarMBR(MBR *nuevo,int x ){

    //sacar la fecha de la computadora
    struct tm *tiempo;
    int dia, mes, anio;
    char diaC[10], mesC[10], anioC[10];
    char *str4="/";

    time_t fecha_sistema;
    time(&fecha_sistema);
    tiempo=localtime(&fecha_sistema);

    anio=tiempo->tm_year + 1900;
    mes=tiempo->tm_mon + 1;
    dia=tiempo->tm_mday;

    sprintf(diaC, "%d", dia);
    sprintf(mesC, "%d", mes);
    sprintf(anioC, "%d", anio);

    char * fecha= (char *) malloc(1 + strlen(diaC)+ strlen(mesC) );
    strcpy(fecha, diaC);
    strcat(fecha, str4);
    strcat(fecha, mesC);
    strcat(fecha, str4);
    strcat(fecha, anioC);


    nuevo->mbr_disk_signature=rand()%200000;
    nuevo->mbr_fecha_creacion= fecha;
    nuevo->mbr_tamano=x;
}

