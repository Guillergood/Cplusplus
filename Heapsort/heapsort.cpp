/**
   @file Heapsort
*/
   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>



/* ************************************************************ */ 
/*  Heapsort method  */

/**
   @brief This function sorts the elements by heapsort method

   @param T: collection of integer elements. Must have number of elements "num_elem".
             It is MODIFICATED.
   @param num_elem: number of elements from T. num_elem > 0.
*/
inline static 
void heapsort(int T[], int num_elem);



/**
   @brief Readjust part of the vector to make it a heap.

   @param T: collection of integer elements. Must have number of elements "num_elem".
             It is MODIFICATED.
   @param num_elem: number of elements from T. num_elem > 0.
   @param k: index of the element, which is taken as a root

*/
static void reajustar(int T[], int num_elem, int k);




/**
   Function implementation
**/


static void heapsort(int T[], int num_elem)
{
  int i;
  for (i = num_elem/2; i >= 0; i--)
    reajustar(T, num_elem, i);
  for (i = num_elem - 1; i >= 1; i--)
    {
      int aux = T[0];
      T[0] = T[i];
      T[i] = aux;
      reajustar(T, i, 0);
    }
}
  

static void reajustar(int T[], int num_elem, int k)
{
  int j;
  int v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO)
    {
      j = k + k + 1;
      if ((j < (num_elem - 1)) && (T[j] < T[j+1]))
	j++;
      if (v >= T[j])
	esAPO = true;
      T[k] = T[j];
      k = j;
    }
  T[k] = v;
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

  // escribe_vector(T, n);
  tantes=clock();
  heapsort(T, n);
  tdespues=clock();
  // escribe_vector(T, n);
      tiempo_transcurrido=((double)(tdespues-tantes)/(CLOCKS_PER_SEC));

    	cout << n << " " << tiempo_transcurrido << endl;

  delete [] T;

  return 0;
};
