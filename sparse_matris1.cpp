#include<stdio.h>
void input(int[][100],int,int);
void compact(int[][100],int[][3],int,int,int);
void print(int [][3],int);
int addsparse(int [][3],int [][3],int [][3],int,int , int );
int main()
{
	int sparseMatrix[100][100],add[100][3] ;
	int i,j,size1 = 0, size2=0;
	int m,n,f;
	int k = 0;
	int compactMatrix1[100][3],compactMatrix2[100][3];
	printf("note- matrix should be of same order ");
	printf("enter the size of the matrix 1 (row) :-");
	scanf("%d",&n);
	printf("enter the size of the matrix 1 (col):-");
	scanf("%d",&m);
	input(sparseMatrix,n,m);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	if (sparseMatrix[i][j] != 0)
	size1++;
	compact(sparseMatrix,compactMatrix1,n,m,size1);
	printf("enter the size of the matrix 2 (row)");
	scanf("%d",&n);
	printf("enter the size of the matrix 2 (col)");
	scanf("%d",&m);
	input(sparseMatrix,n,m);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	if (sparseMatrix[i][j] != 0)
	size2++;
	compact(sparseMatrix,compactMatrix2,n,m,size2);
	printf("\nprint the 1nd matrix inthe form of \n [i] [j] value\n");
	print(compactMatrix1,size1);
	printf("\nprint the 2nd matrix inthe form of \n [i] [j] value\n");
	print(compactMatrix2,size2);
	f=1;
	k= addsparse(compactMatrix1,compactMatrix2,add,f,size1, size2);
	printf("addition \n [i] [j] value\n");
	print(add,k);
	f=0;
	k= addsparse(compactMatrix1,compactMatrix2,add,f,size1, size2);
	printf("subtraction \n [i] [j] value\n");
	print(add,k);
	return 0;
}
void input(int a[][100],int n,int m)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
    printf("enter the element at position [%d][%d]:-",i,j);
    
scanf("%d",&a[i][j]);
}
}
void compact(int sparseMatrix[][100],int compactMatrix[][3],int n,int m,int
size)
{
int k = 0,i,j;
	for ( i = 0; i < n; i++)
	for ( j = 0; j < m; j++)
	if (sparseMatrix[i][j] != 0)
	{
		compactMatrix[k][0] = i;
		compactMatrix[k][1] = j;
		compactMatrix[k][2] = sparseMatrix[i][j];
		//printf("%d %d %d \n",
		i,j,compactMatrix[k][2];
		k++;
	}
}
void print(int compactMatrix[][3], int size)
{
for (int i=0; i<size; i++)
{
for (int j=0; j<3; j++)
printf("%d ", compactMatrix[i][j]);
printf("\n");
}
}
int addsparse(int b1[100][3],int b2[100][3],int b3[100][3],int f,int size1, int
size2)
{
int t1,t2,i,j,k;
i=j=k=0;
while(i<size1&&j<size2)
{
if(b1[i][0]<b2[j][0])
{
	b3[k][0]=b1[i][0];
	b3[k][1]=b1[i][1];
	b3[k][2]=b1[i][2];
	k++;
	i++;
}
else if(b2[j][0]<b1[i][0])
{
	b3[k][0]=b2[j][0];
	b3[k][1]=b2[j][1];
	b3[k][2]=b2[j][2];
	k++;
	j++;
}
else if(b1[i][1]<b2[j][1])
{
	b3[k][0]=b1[i][0];
	b3[k][1]=b1[i][1];
	b3[k][2]=b1[i][2];
	k++;
	i++;
}
else if(b2[j][1]<b1[i][1])
//row numbers are equal, compare column
{
	b3[k][0]=b2[j][0];
	b3[k][1]=b2[j][1];
	b3[k][2]=b2[j][2];
	k++;
	j++;
}
else
{
	b3[k][0]=b1[i][0];
	b3[k][1]=b1[i][1];
	if(f==1)
	b3[k][2]=b1[i][2]+b2[j][2];
	else
	b3[k][2]=b1[i][2]-b2[j][2];
	k++;
	i++;
	j++;
}
//printf("%d a\n",b3[k-1][2]);
}
while(i<size1)
{
	b3[k][0]=b1[i][0];
	b3[k][1]=b1[i][1];
	b3[k][2]=b1[i][2];
	i++;
	k++;
	//printf("%d\n",b3[k-1][2]);
}
while(j<size2)
{
	b3[k][0]=b2[j][0];
	b3[k][1]=b2[j][1];
	b3[k][2]=b2[j][2];
	j++;
	k++;
	//printf("%d\n",b3[k-1][2]);
}
return(k);
}
