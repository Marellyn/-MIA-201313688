#ifndef DISCOS_H
#define DISCOS_H
#include <time.h>
typedef struct MBR{
    int mbr_tamano;
    char* mbr_fecha_creacion;
    int mbr_disk_signature;
}MBR;
void NewDisc(int size, char unit, char *path, char *name);
void IniciarMBR(MBR *nuevo,int x );

#endif // DISCOS_H
