#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "ListaSimplementeEnlazada.c"

int main(){
    tLista *l;
    int opcion=0; int e;
    tElemento *elem;
    do{
        printf("--Pulsa 1 si quiere crear una lista-- \n");
        printf("--Pulsa 2 si quiere insertar un elemento-- \n");
        printf("--Pulsa 3 si quiere mostrar la lista-- \n");
        printf("--Pulsa 4 salir del programa-- \n");
        switch(opcion){
            case 1:
                crear_lista(&l);
                printf("La lista se creo\n");
                break;
            case 2:
                printf("Ingrese un elemento entero\n");
                scanf("%i",&e);
                *elem=&e;
                l_insertar(*l,l_primera(*l),elem);
                printf("Entero ingresado correctamente\n");
                break;
    }

    }while(opcion!=4);
    return 0;
}
