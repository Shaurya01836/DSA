#include <stdio.h>

void readPoly(int X[], int x)
{
  X[0] = x;
  for (int i = 1; i < (2 * x); i = i + 2)
  {
    printf("Enter the exponent of term : ");
    scanf("%d", &X[i]);
    printf("Enter the coefficient of term : ");
    scanf("%d", &X[i + 1]);
  }
}

void display(int A[])
{
  for (int i = 1; i < ((A[0] * 2) + 1); i = i + 2)
  {
    printf("%d", A[i + 1]);
    if (A[i] > 1)
      printf("x^%d + ", A[i]);
    else if (A[i] == 1)
      printf("x + ");
  }
  printf("\n");
}
int pAdd(int A[], int B[], int C[])
{
  int m, n;
  // A[0 : 2*m], B[0 : 2*n], C[0 : 2*(m+n)];
  m = A[0];
  n = B[0];
  int p, q, r;
  p = q = r = 1;
  while (p <= 2 * m && q <= 2 * n)
  {
    if (A[p] == B[q])
    {
      C[r + 1] = A[p + 1] + B[q + 1];
      if (C[r + 1] != 0)
      {
        C[r] = A[p];
        r = r + 2;
      }
      p = p + 2;
      q = q + 2;
    }
    else if (A[p] > B[q])
    {
      C[r + 1] = A[p + 1];
      C[r] = A[p];
      p = p + 2;
      r = r + 2;
    }
    else
    {
      C[r + 1] = B[q + 1];
      C[r] = B[q];
      q = q + 2;
      r = r + 2;
    }
  }
  while (p <= 2 * m)
  {
    C[r] = A[p];
    C[r + 1] = A[p + 1];
    p = p + 2;
    r = r + 2;
  }
  while (q <= 2 * n)
  {
    C[r] = B[q];
    C[r + 1] = B[q + 1];
    q = q + 2;
    r = r + 2;
  }
  C[0] = (r / 2);
  return 0;
}
int main()
{
  int m, n;
  int A[200], B[200], C[400];
  printf("Enter the no. of terms in 1st polynomial : ");
  scanf("%d", &m);
  readPoly(A, m);
  display(A);
  printf("Enter the no. of terms in 2nd polynomial : ");
  scanf("%d", &n);
  readPoly(B, n);
  display(B);
  printf("\n");
  printf("Sum of these polynomials : \n");
  pAdd(A, B, C);
  display(C);
  return 0;
}