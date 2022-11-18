#include<stdio.h>
int bubblesort(int a[],int n)
   {
    int temp;
    for(int i=1;i<=n;i++)
       for(int j=0;j<n-i;j++)
          if(a[j]>a[j+1])
            {
             temp=a[j+1];
             a[j+1]=a[j];
             a[j]=temp;
            }
     return 0;
    }       
int read(int a[],int n)
   {
    printf("\nEnter the elements:");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    return 0;
   }
int print(int a[],int n)
   {
    printf("sorted array:\n");
    for(int i=0;i<n;i++)
       printf("%d    ",a[i]);
    return 0;    
   }   
   
int main()
   {
    int x[100],n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    read(x,n);
    bubblesort(x,n);
    print(x,n);
    printf("\n");
    return 0;
   } 
