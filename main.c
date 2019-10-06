#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
void eliminar(int * e){
    free(e);
}
int main(){
    tLista l=NULL;
    int opcion=0;
    tPosicion p=NULL;
    int *recuperado= NULL;
    int *recuperar=NULL;
    tElemento *elem;
    while(opcion!=5){
        printf("--Pulsa 1 si quiere crear una lista-- \n");
        printf("--Pulsa 2 si quiere insertar un elemento-- \n");
        printf("--Pulsa 3 si quiere mostrar la lista-- \n");
        printf("--Pulsa 4 para imprimir el ultimo de la lista-- \n");
        printf("--Pulsa 5 para salir del programa\n");

        printf("--Seleccione alguna de las 4 opciones\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                crear_lista(&l);
                printf("La lista se creo correctamente\n");
                break;
            case 2:
                printf("Ingrese un elemento entero: ");
                scanf("%i",&elem);
                l_insertar(l,l_primera(l),elem);
                printf("Entero ingresado correctamente %i\n",elem);
                break;
            case 3:
                p=l_primera(l);
                printf("Imprimiendo elementos de la lista: \n");
                while(p!=NULL){
                    recuperado=l_recuperar(l,p);
                    printf("%i\n",recuperado);
                    p=l_siguiente(l,p);
                }
                break;
            case 4:
                recuperar=l_recuperar(l,l_ultima(l));
                printf("El ultima elemento de la lista es:%i\n",recuperar);
            case 5:
                l_destruir(&l,(void (*)(tElemento))eliminar);
                exit(0);
                break;
        }

    }
    return 0;
}
