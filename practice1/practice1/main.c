//
//  main.c
//  practice1
//
//  Created by 骏 李 on 7/14/16.
//  Copyright © 2016 Jun Li. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
long int num = 0;
void CountInv(int A[], int l, int r);
void CountSplitInv(int A[], int l,int m, int r);

int main()
{
  int A[100000], data, N = 100000;
  FILE *fp=fopen("/Users/jun/Documents/MOOC/Algorithm/Katasuba_Merge_sort/practice1/practice1/IntegerArray.txt", "r");
  if (!fp){
    printf("the file cannot be open!");
    exit(1);
  }
  
  int i = 0;
  while (!feof(fp)) {
    fscanf(fp, "%d", &data);
    A[i++] = data;
  }
  
  fclose(fp);
  
  CountInv(A, 0, N-1);
  printf("the total inversion is = %li\n",num);
  return 0;
}

void CountInv(int A[], int l, int r)
{
  int m = (int)((r+l)/2);
  printf("%d\n",m);
  if (l < r) {
  CountInv(A, l, m);
  CountInv(A, m+1, r);
  CountSplitInv(A, l, m, r);
  }
}

void CountSplitInv(int A[], int l, int m, int r)
{
  int i,k,p=0,q=0,B[m-l+1],C[r-m+1];
  
  for (i = 0; i <= m-l; i++) {
    B[i] = A[i+l];
    printf("B is %d\n",B[i]);
  }
  for (i = 0; i <= r-m-1; i++){
    /*here we need to reduce the middle number for the 2nd part*/
    C[i] = A[i+m+1];
    printf("C is %d\n",C[i]);
  }
  /* Use Merge Sort based method to count Inversion in Split part */
  for (k = l; k <= r && p <= m-l && q <= r-m-1; k++){
    if(B[p] <= C[q]) {
      A[k] = B[p++];
    }
    else{
      A[k] = C[q++];
      num = num + m-l-p+1;
    }
    }
  while (p <= m-l) {
    A[k++] = B[p++];
  }
  while (q <= r-m-1) {
    A[k++] = C[q++];
  }
}