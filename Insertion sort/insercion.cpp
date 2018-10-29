/**
   @file Insertion sort
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/* Insertion sort */

/**
   @brief This function sorts the array by the Insertion sort method.

   @param T: array of elements. Must have the number of elements "num_elem".
             It is MODIFIED.
   @param num_elem: number of elements in T. num_elem > 0.

*/
inline static 
void insercion(int T[], int num_elem);



/**
   @brief This function sorts part of the array by the Insertion sort method

   @param T: array of elements. It has a number of elements 
                   greater or equal than the solution.It is MODIFIED.

   @param inicial: Initial position where it is going to be sorted.
   @param final: Final position where it is going to be sorted, it will be behind the last element accesible.
		   inicial < final.
*/
static void insercion_lims(int T[], int inicial, int final);



/**
   Functions implementation
**/

inline static void insercion(int T[], int num_elem)
{
  insercion_lims(T, 0, num_elem);
}


static void insercion_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    };
  };
}



int main(int argc, char **argv)
{

    if(argc < 2){
    
        exit(-1);
    }
  

    clock_t tantes,tdespues;
    double tiempo_transcurrido;

    int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srandom(time(0));

  for (int i = 0; i < n; i++)
    {
      T[i] = random();
    };
    tantes = clock();
  insercion(T, n);
    tdespues = clock();
      tiempo_transcurrido=((double)(tdespues-tantes)/(CLOCKS_PER_SEC));

    	cout << n << " " << tiempo_transcurrido << endl;

  delete [] T;

  return 0;
};
