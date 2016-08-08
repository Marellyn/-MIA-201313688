#ifndef DISCOS_H
#define DISCOS_H
#include <time.h>
typedef struct MBR{
    int mbr_tamano;
    char* mbr_fecha_creacion;
    int mbr_disk_signature;
}MBR;

typedef struct Particion{
    char part_status;
    char part_type;
    char part_fit;
    char part_name[16];
    int part_start;
    int part_size;
}Particion;


typedef struct EBR{
    char part_status;
    char part_fit;
    char part_name[16];
    int part_start;
    int part_next;
    int part_size;
}EBR;


void NewDisc(int size, char unit, char *path, char *name);
void IniciarMBR(MBR *nuevo,int x );
void NewParticion(Particion Partic,int size,char unit, char *path, char typed, char fit, char *delet, char *name, int add);
#endif // DISCOS_H
