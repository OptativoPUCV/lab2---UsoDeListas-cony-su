#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
  List* L = create_list();

  for(int k = 1; k < 11; k++)
  {
    int* elem = (int*)malloc(sizeof(int));
    *elem = k;
    push(L, elem);
  }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
  int sumatoria = 0;
  int* dato = first(L);

  while(dato != NULL)
  {
    sumatoria += *dato;
    dato = next(L);
  }
  
  return sumatoria;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List* L, int elem)
{
  int* elemento = first(L);
  
  while(elemento != NULL)
  {
    if(*elemento == elem) popCurrent(L);
    elemento = next(L); 
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  Stack* pila_aux = create_stack();

  void* elem = top(P1);
  
  while(elem != NULL)
  { 
    push(pila_aux, elem);
    pop(P1);
    elem = top(P1);
  }

  elem = top(pila_aux);
  
  while(elem != NULL)
  {
    push(P2, elem);
    pop(pila_aux);
    push(P1, elem);
    elem = top(pila_aux);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{
  Stack* pila = create_stack();

    
  for(int k = 0; k < strlen(cadena); k++)
  {
    if((cadena[k] == '(') || (cadena[k] == '[') || (cadena[k] == '{')) push(pila, &cadena[k]);
      
    else
    {
      if(top(pila) == NULL) return 0;

      char top_char = *(char*)top(pila);
      
      if((cadena[k] == ')' && top_char == '(') || (cadena[k] == ']' && top_char == '[') || (cadena[k] == '}'&& top_char == '{'))
      {
        pop(pila);
      }
       
    }
    
  }
  
  if(top(pila) == NULL) return 1;
  return 0;
}

  