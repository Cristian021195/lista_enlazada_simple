#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct nodo{
	int dato;
	struct nodo *siguiente;
}nodo;

//funciones
void esListaVacia(nodo *lista);
nodo * crearLista(nodo *lista);//funciones de tipo puntero
nodo * insertarNodoInicio(int valor,nodo *lista);
nodo * insertarNodoFinal(int valor,nodo *lista);
nodo * retirarNodoInicio(nodo *lista);
nodo * retirarNodoFinal(nodo *lista);
nodo * primerElemento(nodo *lista);
nodo * ultimoElemento(nodo *lista);
//void logitud(nodo *lista);
void logitudLista(nodo *lista);
void imprimirLista(nodo *lista);
void perteneceALista(nodo *lista, int num);
 
int main(){
	nodo *lista;
	int cond = 0; int val;
	lista = crearLista(lista);//es normal que de lista sin inicializar.
	
	do{
		printf("\nINSERTAR ELEMENTO A LA LISTA:\n 1 al inicio \n 2 Al final \n 3 ver elementos de lista \n 4 retirar nodo del comienzo \n 5 retirar nodo del final: \n 6 Chequear Vacia: \n 7 Primer Elemetno: \n 8 Ultimo Elemetno: \n 9 Longitud Lista: \n 10 Pertenece elemento: _ ");
		scanf("%d", &cond);fflush(stdin); 
		
		if(cond == 1){
			system("cls");
			printf("\nIntroduzca el valor a agregar al inicio: ");
			scanf("%d", &val);fflush(stdin);
			lista = insertarNodoInicio(val, lista);
		}else if(cond == 2){
			system("cls");
			printf("\nIntroduzca el valor a agregar al final: ");
			scanf("%d", &val);fflush(stdin);
			lista = insertarNodoFinal(val, lista);
		}else if(cond == 3){
			system("cls");
			imprimirLista(lista);			
		}else if(cond == 4){
			system("cls");
			lista = retirarNodoInicio(lista);
		}else if(cond == 5){
			system("cls");
			lista = retirarNodoFinal(lista);
		}else if(cond == 6){
			system("cls");
			esListaVacia(lista);
		}else if(cond == 7){
			system("cls");
			printf("El primer elemento es: %d", primerElemento(lista)->dato); 
		}else if(cond == 8){
			system("cls");
			printf("El ultimo elemento es: %d", ultimoElemento(lista)->dato); 
		}else if(cond == 9){
			system("cls");
			logitudLista(lista);			
		}else if(cond == 10){
			system("cls");
			printf("\nIntroduzca el valor a consultar: ");
			scanf("%d", &val);fflush(stdin);
			perteneceALista(lista, val);
		}

	}while(cond != 11);
	
	imprimirLista(lista);
	
return 0;
}

void esListaVacia(nodo *lista){
	if(lista == NULL){
		printf("Esta vacia");
	}else{
		printf("Tiene elementos");
	}
}

void logitudLista(nodo *lista){
	int tamanio_nodo = sizeof(nodo); int contador = 0;
	nodo *nodoAuxiliar;
	nodoAuxiliar = lista;
	while(nodoAuxiliar != NULL){//mientras haya algo en la memoria de nodo aux
		nodoAuxiliar = nodoAuxiliar->siguiente;//actua como contador
		contador++;
	}

	printf("El tamanio de la lista es de %d elementos y %d bytes",contador, (tamanio_nodo*contador));
}

void perteneceALista(nodo *lista, int num){
	int tamanio_nodo = sizeof(nodo);
	nodo *nodoAuxiliar;
	nodoAuxiliar = lista;
	while(nodoAuxiliar != NULL){//mientras haya algo en la memoria de nodo aux

		if(num == nodoAuxiliar->dato){
			printf("Existe elemento");
		}else{
			printf("No Existe elemento");
		}
		nodoAuxiliar = nodoAuxiliar->siguiente;//actua como contador
	}
}

nodo *crearLista(nodo *lista){
	return lista = NULL;    //lista siempre sera null al comienzo del programa
}

nodo * primerElemento(nodo *lista){
	nodo *nodoAuxiliar;
	
	if(lista == NULL){
		printf("No hay nodos en la lista");
	}else{
		nodoAuxiliar = lista;
	}
	return lista;
}

nodo * ultimoElemento(nodo *lista){
	nodo *nodoAuxiliar, *nodoAnterior;
	if(lista == NULL){
		printf("No hay elementos en la lista!");
	}else{
		nodoAuxiliar = lista;
		while(nodoAuxiliar->siguiente != NULL){
			nodoAnterior = nodoAuxiliar;
			nodoAuxiliar = nodoAnterior->siguiente;
		}
		//nodoAnterior->siguiente=NULL;
	}
	return nodoAuxiliar;
}

nodo *insertarNodoInicio(int valor, nodo *lista){
	nodo *nodoNuevo;
	nodoNuevo = (nodo*)malloc(sizeof(nodo));
	if(nodoNuevo != NULL){              // si pudo asignar la cantidad de memoria
		nodoNuevo->dato = valor;    
		nodoNuevo->siguiente = lista;   //hacemos que nodo apunte a donde lista, ambos son puteros
		lista = nodoNuevo;  //lista apunta al nodo creado
	}
	return lista;           //devolvemos el nodo
}
nodo *insertarNodoFinal(int valor, nodo *lista){
	nodo *nodoNuevo, *nodoAuxiliar;
	nodoNuevo = (nodo*)malloc(sizeof(nodo));

	if(nodoNuevo != NULL){
		nodoNuevo->dato = valor;
		nodoNuevo->siguiente = NULL;    //le damos null porque queremosque vaya al final.
		if(lista == NULL){              //si no habia nada en la lista
			lista = nodoNuevo;          //el nuevo nodo que apunta a null, es el unico contenido de la lista.
		}else{
			nodoAuxiliar = lista;       //nodoauxiliar es la lista
			while(nodoAuxiliar->siguiente != NULL)
				nodoAuxiliar = nodoAuxiliar->siguiente;
				nodoAuxiliar->siguiente = nodoNuevo;
		}
	}
	return lista;
}
nodo *retirarNodoInicio(nodo *lista){
	nodo *nodoAuxiliar;
	int dato;
	
	if(lista == NULL){
		printf("No hay nodos en la lista");
	}else{
		nodoAuxiliar = lista;
		dato = nodoAuxiliar->dato;
		lista=nodoAuxiliar->siguiente;
		printf("Se ha retirado el elemento: %d", dato);
		free(nodoAuxiliar);
	}
	return lista;
}
nodo *retirarNodoFinal(nodo *lista){
	nodo *nodoAuxiliar, *nodoAnterior;
	int dato;
	if(lista == NULL){
		printf("No hay elementos en la lista!");
	}else{
		nodoAuxiliar = lista;
		while(nodoAuxiliar->siguiente != NULL){
			nodoAnterior = nodoAuxiliar;
			nodoAuxiliar = nodoAnterior->siguiente;
		}
		dato = nodoAuxiliar->dato;
		nodoAnterior->siguiente=NULL;
		
		printf("Se ha retirado el elemento: %d", dato);
		free(nodoAuxiliar);
	}
	return lista;
}
void imprimirLista(nodo *lista){
	nodo *nodoAuxiliar;
	nodoAuxiliar = lista;
	printf("+++ INICIO +++\n");
	printf("___\n");
	while(nodoAuxiliar != NULL){//mientras haya algo en la memoria de nodo aux
		printf("|%d|\n", nodoAuxiliar->dato);
		nodoAuxiliar = nodoAuxiliar->siguiente;//actua como contador
	}
	printf("NULL!\n");
}
