/*
 * Name : Prithiv Dev
   CWID : 10453922
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sort.h"



int ivector_length(int* v, int n){
  int sum;
  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];
  return sum;
}

/*
 * insertion sort
 */

void insertion_sort(int** A, int n, int l, int r){ 
  int i;
  int* key;
  for (int j = l+1; j <= r; j++){
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n))){
          A[i+1] = A[i];
          i = i - 1;
        }
      A[i+1] = key;
    }
}

/*
*   TO IMPLEMENT: Improved Insertion Sort for problem 1.
*/

void insertion_sort_im(int** A, int n, int l, int r)
{  int* keyNumber; 
  int Array[r+1];
  int* vectorlen=Array;  


  int i;
  int k = 0;


  while(k<=r){
    Array[k]=(ivector_length(A[k], n));      
    k++;                                                        
  }



  for (int j = l+1; j <= r; j++)
  {
      keyNumber = A[j]; 
      i = j - 1;
      int keylength=Array[j];

while ((i >= l) && (vectorlen[i] > keylength)){ 

        //transfer
        A[i+1] = A[i];  
        Array[i+1]= Array[i]; 
        i = i - 1;

      }



      A[i+1] = keyNumber; //set 
      Array[i+1]=keylength;

      } 

}
/*
*   TO IMPLEMENT: Improved Merge Sort for problem 2.
*/

// this is the acutal merge sort, it uses helper methods.

void merge(int** A, int* Array, int l, int mp, int r, int n)
{
  int *Temp_array = new int[r-l+1];  
  int **tempA = new int*[r-l+1];  //temp array
 

 //baseline intiations
  int i = l;
  int k = 0;
  


      int j = mp + 1;// midpoint 


        while (i <= mp && j <= r){   //loop till it reaches the end point.
        if (Array[i] < Array[j]){   
            Temp_array[k] = Array[i];
            tempA[k]= A[i];
            k++;
            i++;}
        
        else{
            Temp_array[k] = Array[j];
            tempA[k] = A[j];
            k++;
            j++;}
          }


        while (i <= mp){
        Temp_array[k] = Array[i];
        tempA[k] = A[i];
        k++;
        i++;}


    while (j <= r){
        Temp_array[k] = Array[j];
        tempA[k] = A[j];
        k++;
        j++;}


for (i = l; i <= r; i++)// loop through finally to set and transfer
{
        Array[i] = Temp_array[i-l];
        A[i] = tempA[i-l];
  }


delete [] tempA;
delete [] Temp_array;

}

// the first main helper method
void merge_sort_helper(int** A, int* Array, int l, int r, int n){
     int mp;
        if(l < r){
      mp = (l + r) / 2;     //midpoint
       merge_sort_helper(A, Array, l, mp, n);   //Recursively calling (Left)
       merge_sort_helper(A, Array, mp+1, r, n); //Recursively calling (Right)


    merge(A, Array, l, mp,r, n);    //Merge
  }
}

// the first main helper method
void merge_sort_assorter(int** A, int* Ar, int l, int r, int n){
  int mp;
  if(l<=n){
    int mp = (l + r)/2;     
    merge(A, Ar, l, mp,r, n);    
  }


     else if(l>n)
  {
     merge(A, Ar, l, mp,r+1, n); 
  }
}

void merge_sort(int **A, int n, int l, int r){    
  int z = l;
  int vectorLengthArray[r+1];
  while(z<=r){
    vectorLengthArray[z] = ivector_length(A[z], n);
    z++;
    }
    merge_sort_helper(A,vectorLengthArray,l,r,n);
}
/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}

/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}

