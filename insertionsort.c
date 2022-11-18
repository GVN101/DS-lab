#include<stdio.h>
void insertionsort(int a[],int n)
   {
    int key,j;
    for(int i=1;i<n;i++)
       {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
             {
              a[j+1]=a[j];
              j--;
             }
        a[j+1]=key;
       }
   }
void read(int a[],int n)
   {
    printf("enter the elements:");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
   }
void print(int a[],int n)
   {
    printf("Sorted array is:\n");
    for(int i=0;i<n;i++)
       printf("%d    ",a[i]);
    printf("\n");
   }
void main()
   {
    int x[100],n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    read(x,n);
    insertionsort(x,n);
    print(x,n); 
   }                        
