#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

void crear_lista(tLista * l){
  tPosicion dummy=(tPosicion)malloc(sizeof(struct celda));
  if(!dummy){
    exit(LST_ERROR_MEMORIA);
  }
   dummy->elemento = NULL;
   dummy->siguiente = NULL;
    *l=dummy;
}
void l_insertar(tLista l,tPosicion p, tElemento e){
    if(p==NULL){
        exit(LST_POSICION_INVALIDA);
    }
    tPosicion nueva=(tPosicion)malloc(sizeof(struct celda));
    nueva->elemento=e;
    nueva->siguiente=p->siguiente;
    p->siguiente=nueva;

}
/** Recupera y retorna la primera posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).**/
tPosicion l_primera(tLista l){
   if(l==NULL){
        exit(LST_ELEMENTO_NULO);
   }
   return l;
}

tPosicion l_siguiente(tLista l, tPosicion p){
    if(p==NULL)
        exit(LST_POSICION_INVALIDA);
     if(p->siguiente==NULL)
        exit(LST_NO_EXISTE_SIGUIENTE);

    return p->siguiente;
}
/**
 Recupera y retorna el elemento en la posici�n P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
tElemento l_recuperar(tLista l, tPosicion p){
    if( p==l_fin(l)){
        exit(LST_POSICION_INVALIDA);
    }
    if((p == NULL || p->siguiente == NULL))
        exit(LST_POSICION_INVALIDA);
    tPosicion retornado=(tPosicion)malloc(sizeof(struct celda));
    retornado=p->siguiente;
    return (retornado->elemento);
}

/**
 Recupera y retorna la posici�n anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
tPosicion l_anterior(tLista l, tPosicion p){
    if(p == NULL)
        exit(LST_POSICION_INVALIDA);
    if(p == l_primera(l))
        exit(LST_NO_EXISTE_ANTERIOR);
    tPosicion aux=l;
    while(aux->siguiente != p){
        aux=aux->siguiente;
    }
    return aux;
}

 /**
 Recupera y retorna la �ltima posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_ultima(tLista l){

    if(l->siguiente==NULL){
        return l;
    }
    tPosicion aux=l;
    while(aux->siguiente->siguiente != NULL){// NULL
        aux=aux->siguiente;
    }
    return aux;
}
/**
 Recupera y retorna la posici�n fin de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_fin(tLista l){
    tPosicion aux=l;
    while(aux->siguiente != NULL){
        aux=aux->siguiente;
    }
    return aux;
}

/**
 Elimina el nodo que se encuentra en la posici�n P de L.
 El elemento almacenado en la posici�n P es eliminado mediante la funci�n fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento)){
    if(p == l_fin(l)){
        exit(LST_POSICION_INVALIDA);
    }
    tPosicion anterior=l_anterior(l,p);
    tElemento elem=p->elemento;
    anterior->siguiente = p->siguiente;
    fEliminar(elem);
    free(p);
    p=NULL;
}

/**
 Destruye la lista L, elimininando cada una de sus posiciones. Los elementos almacenados en las posiciones son eliminados mediante la funci�n fEliminar parametrizada.
**/
void l_destruir(tLista * l, void (*fEliminar)(tElemento)){
    tPosicion celda_eliminar=*l;
    tPosicion sig;
    while(celda_eliminar != NULL){
        sig=celda_eliminar->siguiente;
        celda_eliminar->siguiente=NULL;
        fEliminar(celda_eliminar->elemento);
        free(celda_eliminar);
        celda_eliminar=sig;
    }
}




