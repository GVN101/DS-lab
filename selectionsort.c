#include<stdio.h>
void selectionsort(int a[],int n)
   {
    int i,j,small,ind,temp;
    for(i=0;i<n-1;i++)
       {
        small=a[i];
        ind=i;
        for(j=i+1;j<n;j++)
            if(a[j]<small)
              {
               small=a[j];
               ind=j;
              }
            temp=a[i];
            a[i]=a[ind];
            a[ind]=temp;
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
    selectionsort(x,n);
    print(x,n); 
   }                        
