#include <iostream> 
using namespace std; 
void swap(int arr[],int i,int j)
    {
    
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

int partition(int arr[],int l, int r)
 { 
     int pivot=arr[l];
     int i=l+1;
     for(int j=l+1; j<r;j++)
       {
           if(arr[j]<pivot)
           {
               i++;
               swap(arr,i,j);
           }
       }
    swap(arr,l,i-1);
    return i-1;
 }
void quicksort(int arr[],int l, int r)
 {
     if(l<r)
      {
          int pi=partition( arr, l,  r);
           quicksort(arr,l,  pi-1);
           quicksort( arr,  pi+1,  r);
      }
 }


int main()
 {
     int arr[5]={5,4,3,2,1};
     quicksort(arr,0,5);
     for (int i = 0; i < 5; ++i) 
        cout << arr[i] << " "; 
      return 0;
 }