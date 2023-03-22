#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct nodo {
    int dato;
    struct nodo * siguiente;
}nodo;


nodo * crearLista(nodo *lista);
nodo * insertarAlInicio(nodo *lista, int val, int * longitud);
void compararListas(int longA, int longB, nodo * lista1, nodo * lista2);
void mostrarLista(nodo *lista);

int main(){
    int cond, val;
    int longA  = 0; int longB = 0;
    nodo *listaA, *listaB;

    listaA = crearLista(listaA);
    listaB = crearLista(listaB);


    do
    {
        printf("\nInsertar en lista A (1)\nInsertar en lista B (2)\nMostrar lista A (3)\nMostrar lista B (4)\nComparar Listas (5)\nSalir (6)\n _ ");
        scanf("%d", &cond); fflush(stdin);

        if(cond == 1){
            system("cls");
            printf("\nInsertar en lista A _ ");
            scanf("%d", &val); fflush(stdin);
            listaA = insertarAlInicio(listaA, val, &longA);


        }else if(cond == 2){
            system("cls");
            printf("\nInsertar en lista B _ ");
            scanf("%d", &val); fflush(stdin);
            listaB = insertarAlInicio(listaB, val, &longB);

            
        }else if(cond == 3){
            system("cls");
            printf("\n === LISTA A === \n");
            mostrarLista(listaA);
            
        }else if(cond == 4){
            system("cls");
            printf("\n === LISTA B === \n");
            mostrarLista(listaB);            
        }else if(cond == 5){
            system("cls");
            compararListas(longA, longB, listaA, listaB);
        }




    } while (cond != 6);
    
}


void mostrarLista(nodo *lista){
    nodo * nodoAux;
    nodoAux = lista;
    while(nodoAux != NULL){
        printf("\n |%d| \n", nodoAux->dato);
        nodoAux = nodoAux->siguiente;
    }
}

void compararListas(int longA, int longB, nodo * lista1, nodo * lista2){
    nodo * nodoAux1; nodo * nodoAux2;
    int val1,val2;



    if(longA == longB){

        nodoAux1 = lista1;
        nodoAux2 = lista2;
    while (nodoAux1 != NULL) {
        if (nodoAux1->dato != nodoAux2->dato) {
            printf("No son iguales"); break;
        }
        nodoAux1 = nodoAux1->siguiente;
        nodoAux2 = nodoAux2->siguiente;
    }
    printf("Son iguales");
        
    }else{
        printf("No son iguales");
    }

}

nodo * insertarAlInicio(nodo *lista, int val, int * longitud){
    nodo * nodoAux;
    nodoAux = (nodo*)malloc(sizeof(nodo));

    if(nodoAux != NULL){
        *longitud = *longitud + 1;
        nodoAux->dato = val;
        nodoAux->siguiente = lista;
        lista = nodoAux;
    }    
    return lista;
}

nodo * crearLista(nodo *lista){
    lista = NULL;
    return lista;
}