/*
Prithiv Dev
10453922
*/
#include <cstdlib>
#include <iostream>
#include "sort.h"
using namespace std;

/* 
 * HW 2 part
 */
int string_compare(char* s1, char *s2)
{ 
/*
 * We assume that s1 and s2 are non-null pointers
 */
  int i;
  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
    i++;

  if (s1[i] == s2[i])
    return 0;
  else
    {
      if (s1[i] < s2[i])
	return -1;
      else
	return 1;
    }
} /*>>>*/



int string_compare_digit(char* s1, char *s2, int A_len, int key_len, int d)
{ 
/*
  We assume that s1 and s2 are non-null pointers
*/
  if(d<=A_len && d<=key_len)

  {       //d is present in the string
    if(s1[d-1] == s2[d-1])
    {        //d-1 postion
      return 0;
    }
    else
    {
      if (s1[d-1] < s2[d-1])
      {    //While char at d in s1 is smaller then char at d in s2
        return -1;
      }
      else{
        return 1;
      }
    }
  }
  else if(d>A_len && d>key_len)
  {    //when in both the strings given position d is not present, d is greater then its length
    return 0;
  }
  else{
    if(d>A_len && d<=key_len)
    {    //When position d is empty in
      return -1;
    }
    else if(d>key_len && d<=A_len)
    {
      return 1;
    }
  }
} 



void insertion_sort_digit(char** A, int* A_len, int l, int r, int d)
{ 
  int i;
  char* key;
  int key_len;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      key_len = A_len[j];
      i = j - 1;
      while ((i >= l) && (string_compare_digit(A[i], key, A_len[i], key_len, d) > 0)) 
        {
          A[i+1] = A[i];
          A_len[i+1] = A_len[i];
          i = i - 1;
        }
      A[i+1] = key;
      A_len[i+1] = key_len;
    }

}



void insertion_sort(char** A, int l, int r)
{ 
  int i;
  char* key;
  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;
      while ((i >= l) && (string_compare(A[i], key) > 0))
        {
          A[i+1] = A[i];
          i = i - 1;
        }
      A[i+1] = key;
    }

}



void radix_sort_is(char** A, int* A_len, int n, int m)
{
  for(int d = m ; d>0; d--)

  {
    insertion_sort_digit(A, A_len, 0, n-1, d);
  }
}





//Counting Sort algorith

void counting_sort_digit(char** A, int* A_len, char** B, int* B_len, int n, int d)
{
 int max = 256;  


 
   int *countInteger  = new int[max];      //ixed size storage array.
        //sized storage array 

        for(int i = 0; i<=max; i++)

        {
    countInteger [i] = 0;
  }



  for(int i = 0; i < n; i++)

  {
    if(d>A_len[i]){       //dth position
      countInteger [0]++;
    }
    else{
      countInteger[A[i][d-1]]++; //d-1
    }
  }
  for(int i = 1; i<=max; i++)

  {
    countInteger [i] += countInteger[i-1]; 
  }
  for(int i = n-1; i>=0; i--)

  {
    if(d<=A_len[i]){
      B[countInteger [A[i][d-1]]-1] = A[i];
      B_len[countInteger[A[i][d-1]]-1] = A_len[i];
      countInteger[A[i][d-1]] -= 1;
    }
    else
    {             
      B[countInteger [0]-1] = A[i];
      B_len[countInteger [0]-1] = A_len[i];
      countInteger [0] -= 1;
    }
  }
            for(int i = 0; i<n; i++)
    {
    A[i] = B[i]; //store temporaryly 
    A_len[i] = B_len[i];
  }
delete[] countInteger ;   //Free mem
}



void radix_sort_cs(char** A, int* A_len, int n, int m)
{
      char** outputArray= new char*[n];    
  int* outputLenght = new int[n];   
  
  for(int d = m ; d>0; d--)

  {
    counting_sort_digit(A, A_len, outputArray, outputLenght, n, d);
  }



  delete[] outputArray;  //free mem
  delete[] outputLenght;    
}
/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(char** A, int l, int r)
{
  for (int i = l+1; i < r; i++)
    if (string_compare(A[i-1],A[i]) > 0)
      return false;
  return true;
}
