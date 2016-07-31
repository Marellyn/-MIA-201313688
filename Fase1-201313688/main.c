#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("****************Creacion de Discos*************\n");
    char *Entrada;
    int Error=0;
    int si=0,un=0,pa=0,na=0,typ=0,fit=0,del=0,add=0;
    int mdisk=0,rmdisk=0,fdisk=0,mount=0,umount=0;
    size_t bufsize = 32;
    size_t characters;


    //valor a guardar

    Entrada= (char *)malloc(bufsize * sizeof(char));
    if( Entrada == NULL)
    {
        perror("No se a escrito ningun comando");
    }

    characters = getline(&Entrada,&bufsize,stdin);
    printf("Lo que se escribo fue: %s \n",Entrada);

    char *espacios;
    char *a = strtok_r(Entrada, " ", &espacios);

    while (a != NULL)
    {
        char *dospuntos;
        printf("a = %s\n", a);
        char *token = strtok_r(a, "::", &dospuntos);
        int cont=0,i=0,j=0;

        i = strcasecmp(a,"mkdisk");
             if (i == 0){
                 printf("Cadena correcta \n");
                 mdisk=1;
             }
       i = strcasecmp(a,"rmdisk");
              if (i == 0){
                 printf("Cadena correcta \n");
                 rmdisk=1;
             }
        i = strcasecmp(a,"fdisk");
              if (i == 0){
                  printf("Cadena correcta \n");
                  fdisk=1;
             }
        i = strcasecmp(a,"mount");
            if (i == 0){
                printf("Cadena correcta \n");
                mount=1;
           }
        i = strcasecmp(a,"umount");
            if (i == 0){
                printf("Cadena correcta \n");
                umount=1;
           }

            Error=0;
        while (token != NULL)
        {

           i = strcasecmp(token,"–Size");
           j = strcasecmp(token,"-Size");
                if (i == 0 || j==0){
                    printf("Cadena correcta \n");
                    si=1;
                    Error=1;
                }else if(Error==1){
                    printf("Valor cuardado = %s \n",token);
                }

           i = strcasecmp(token,"+unit");
                     if (i == 0){
                         printf("Cadena correcta \n");
                         un=1;
                          Error=2;
                }else if(Error==2){
                     printf("Valor cuardado = %s \n",token);
                     }
           i = strcasecmp(token,"–path");
           j = strcasecmp(token,"-path");
                 if (i == 0 || j== 0){
                        printf("Cadena correcta \n");
                        pa=1;
                         Error=3;
                }else if(Error==3){
                   printf("Valor cuardado = %s \n",token);
                 }
           i = strcasecmp(token,"-name");
           j = strcasecmp(token,"–name");
                       if (i == 0 || j == 0){
                              printf("Cadena correcta \n");
                              na=1;
                             Error=4;
                      }else if(Error==4){
                        printf("Valor cuardado = %s \n",token);
                  }
             i = strcasecmp(token,"+type");
                          if (i == 0){
                           printf("Cadena correcta \n");
                           typ=1;
                           Error=5;
                       }else if(Error==5){
                         printf("Valor cuardado = %s \n",token);
                   }
              i = strcasecmp(token,"+fit");
                             if (i == 0){
                             printf("Cadena correcta \n");
                             fit=1;
                             Error=6;
                       }else if(Error==6){
                         printf("Valor cuardado = %s \n",token);
                    }
            i = strcasecmp(token,"+delete");
                            if (i == 0){
                            printf("Cadena correcta \n");
                            del=1;
                            Error=7;
                      }else if(Error==7){
                        printf("Valor cuardado = %s \n",token);
                   }
            i = strcasecmp(token,"+add");
                            if (i == 0){
                            printf("Cadena correcta \n");
                            add=1;
                            Error=8;
                      }else if(Error==8){
                        printf("Valor cuardado = %s \n",token);
                   }
            i = strcasecmp(token,"+add");
                            if (i == 0){
                            printf("Cadena correcta \n");
                            add=1;
                            Error=9;
                      }else if(Error==9){
                        printf("Valor cuardado = %s \n",token);
                   }
            cont++;
            token = strtok_r(NULL, "::", &dospuntos);
        }
        a = strtok_r(NULL, " ", &espacios);
    }


    if( mdisk==1 & na==1 & pa==1 & si==1){
       printf("Su disco fue generado\n");
    }else{
         if(mdisk==1){
       printf("No se puede crear el disco por falta de informacion \n");
         }
    }

    if( rmdisk==1 & pa==1 ){
       printf("Su disco fue eliminado\n");
    }else{
       if(rmdisk==1){
           printf("No se puede eliminar el disco por falta de informacion \n");

       }
    }
    if( fdisk==1 & na==1 & pa==1 & si==1){
       printf("Su particion fue generado\n");
    }else{
         if(fdisk==1){
       printf("No se puede crear la particion por falta de informacion \n");
         }
    }
    if( mount==1 & na==1 & pa==1){
       printf("Su partición del disco en el sistema fue montada\n");
    }else{
         if(mount==1){
       printf("No se puede montar la particion por falta de informacion \n");
         }
    }

}
