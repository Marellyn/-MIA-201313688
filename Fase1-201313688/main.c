#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("****************Creacion de Discos*************\n");
    char *Entrada;
    int Error=0;
    int si=0,un=0,pa=0,na=0,typ=0,fit=0,del=0,add=0,aum=0,kV=0,hV=0,mV=0, iV=0,comentario=0,bandera=0;
    int mdisk=0,rmdisk=0,fdisk=0,mount=0,umount=0,df=0;
    size_t bufsize = 32;
    size_t characters;
     char *pi = NULL,*Pi = NULL,*Pd = NULL,*PD = NULL, *guio= NULL, *guion= NULL, *come=NULL, *KV1=NULL,*HV1=NULL,*MV1=NULL,*IV1=NULL;

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
                 printf("Cadena correcta mdisk \n");
                 mdisk=1;
                 if(comentario==1 || comentario==0){
                 bandera=1;
                 }
             }
       i = strcasecmp(a,"rmdisk");
              if (i == 0){
                 printf("Cadena correcta  rmdisk \n");
                 rmdisk=1;
                 if(comentario==1 || comentario==0 ){
                 bandera=1;
                 }
             }
        i = strcasecmp(a,"fdisk");
              if (i == 0){
                  printf("Cadena correcta fdisk \n");
                  fdisk=1;
                  if(comentario==1 || comentario==0 ){
                  bandera=1;
                  }
             }
        i = strcasecmp(a,"mount");
            if (i == 0){
                printf("Cadena correcta  mount \n");
                mount=1;
                if(comentario==1 || comentario==0){
                bandera=1;
                }
           }
        i = strcasecmp(a,"umount");
            if (i == 0){
                printf("Cadena correcta umont \n");
                umount=1;
                if(comentario==1 || comentario==0){
                bandera=1;
                }
           }

        i = strcasecmp(a,"df");
             if (i == 0){
                 printf("Cadena correcta df \n");
                 if(comentario==1 || comentario==0){
                 bandera=1;
                 }
                 df=1;
            }

             pi=strchr(a, 'i');
             Pi=strchr(a, 'I');
             Pd=strchr(a, 'D');
             PD=strchr(a, 'd');
             guio=strchr(a, '-');
             guion=strchr(a, '–');
             if((pi != NULL & Pd !=NULL  ) || (pi != NULL & PD !=NULL) || (Pi != NULL & Pd !=NULL) || (Pi != NULL & PD !=NULL) ){
                 if(guio !=NULL || guion !=NULL){
                 printf("Valor entra al puto if /***************");
                 aum=1;
                 Error=10;
                 }
             }else if(Error == 10){
                  printf("Valor cuardado = %s  add \n",token);
             }

             KV1=strcasecmp(a, "+k");
             HV1=strcasecmp(a, "+h");
             IV1=strcasecmp(a, "+i");
             MV1=strcasecmp(a, "+m");
             if(KV1 != NULL  ){
                    kV=1;
             }else if( HV1 !=NULL){
                 hV=1;
             }else if(MV1 !=NULL){
                 mV=1;
             }else if( IV1 !=NULL){
                 iV=1;
             }


             come=strchr(a, '#');
            if(come !=NULL){
             printf("Entra en # al if ");
            comentario=1;
            bandera=1;
            }

            if(bandera==1){
                comentario=1;
            }else{
                comentario=2;
            }


        if(comentario == 1){
            Error=0;
        while (token != NULL)
        {
        printf("b = %s\n", token);

           i = strcasecmp(token,"–Size");
           j = strcasecmp(token,"-Size");
                if (i == 0 || j==0){
                    printf("Cadena correcta size \n");
                    si=1;
                    Error=1;
                }else if(Error==1){
                    printf("Valor cuardado = %s \n",token);
                }

           i = strcasecmp(token,"+unit");
                     if (i == 0){
                         printf("Cadena correcta unit \n");
                         un=1;
                          Error=2;
                }else if(Error==2){
                     printf("Valor cuardado = %s \n",token);
                     }
           i = strcasecmp(token,"–path");
           j = strcasecmp(token,"-path");
                 if (i == 0 || j== 0){
                        printf("Cadena correcta path \n");
                        pa=1;
                         Error=3;
                }else if(Error==3){
                   printf("Valor cuardado = %s \n",token);
                 }
           i = strcasecmp(token,"-name");
           j = strcasecmp(token,"–name");
                       if (i == 0 || j == 0){
                              printf("Cadena correcta  name \n");
                              na=1;
                             Error=4;
                      }else if(Error==4){
                        printf("Valor cuardado = %s \n",token);
                  }
             i = strcasecmp(token,"+type");
                          if (i == 0){
                           printf("Cadena correcta type \n");
                           typ=1;
                           Error=5;
                       }else if(Error==5){
                         printf("Valor cuardado = %s \n",token);
                   }
              i = strcasecmp(token,"+fit");
                             if (i == 0){
                             printf("Cadena correcta fit \n");
                             fit=1;
                             Error=6;
                       }else if(Error==6){
                         printf("Valor cuardado = %s \n",token);
                    }
            i = strcasecmp(token,"+delete");
                            if (i == 0){
                            printf("Cadena correcta delete \n");
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
                        printf("Valor cuardado = %s  add \n",token);
                   }

            pi=strchr(token, 'i');
            Pi=strchr(token, 'I');
            Pd=strchr(token, 'D');
            PD=strchr(token, 'd');
            guio=strchr(token, '-');
            guion=strchr(token, '–');
            if((pi != NULL & Pd !=NULL  ) || (pi != NULL & PD !=NULL) || (Pi != NULL & Pd !=NULL) || (Pi != NULL & PD !=NULL) ){
                if(guio !=NULL || guion !=NULL){
                printf("Valor entra al puto if /***************");
                aum=1;
                Error=9;
                }
            }else if(Error == 9){
                 printf("Valor cuardado = %s  add \n",token);
            }

            cont++;
            token = strtok_r(NULL, "::", &dospuntos);
        }
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

    if( umount==1 & aum==1){
       printf("Su partición del disco en el sistema fue desmontada\n");
    }else{
         if(umount==1){
       printf("No se puede desmontar la particion por falta de informacion \n");
         }
    }

    if( (df==1 & hV==1) || (df==1 & iV==1) || (df==1 & mV==1) ||(df==1 & kV==1)){
       printf("Se mostrara ******\n");
    }else{
         if(df==1){
       printf("Se muestra todo ****\n");
         }
    }
}
