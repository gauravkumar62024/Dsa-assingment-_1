#include <stdio.h>
void enter(int[],int);
void printPoly(int[],int);
int max(int , int );
void add(int [],int [] ,int [], int , int);
void multiply(int [], int [],int [], int , int );
void main()
{
int A[100],D[100] ;
int B[100] ,C[100];
int m ,n,*sum,size;
printf("enter the highest power of x for 1st polynomial :- ");
scanf("%d", &n);
enter(A,n);
printf("enter the highest power of x for 2nd polynomial :- ");
scanf("%d", &m);
enter (B,m);
printf("\nFirst polynomial is \n");
printPoly(A, n);
printf("\n\nSecond polynomial is \n\n");
printPoly(B, m);
add(A,B,C, n, m);
size = max(n, m);
printf( "\n\nsum polynomial is \n\n");
printPoly(C, size);
multiply(A,B,D,n,m);
printf("\n\nmultiply polynomial is \n\n");
printPoly(D,m+n-1);
//return 0;
}
void enter(int a[], int s)
{
int i;
for(i=0;i<s;i++)
{
printf("enter the coefficient for the x^%d :- ",i);
scanf("%d",&a[i]);
}
}
void printPoly(int poly[], int n)
{
int i;
for ( i=0; i<n; i++)
{
printf("%d",poly[i]) ;
if (i != 0)
printf("x^%d",i);
if (i != n-1)
printf(" + ");
}
}
void add(int A[], int B[],int C[], int m, int n)
{
int size = max(m, n);
if(size==m)
{for (int i = 0; i<m; i++)
C[i] = A[i];
for (int i=0; i<n; i++)
C[i] += B[i];
}
if(size==n)
{for (int i = 0; i<n; i++)
C[i] = B[i];
for (int i=0; i<m; i++)
C[i] += A[i];
}
}
int max(int m, int n) { return (m > n)? m: n; }
void multiply(int A[], int B[],int D[], int m, int n)
{
for (int i = 0; i<m+n-1; i++)
D[i] = 0;
for (int i=0; i<m; i++)
{
for (int j=0; j<n; j++)
D[i+j] += A[i]*B[j];
}
}

