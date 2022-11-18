#include<stdio.h>
void sort(int a[],int n);
void main()
{ int a[10], n, i,j;
printf("enter no of elements");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("the sorted array is");
sort(a,n);
printf("the sorted array is");
for(i=0;i<n;i++)
{
	printf(" %d",a[i]);

}
} 

void sort(int a[],int n)
{ int temp,i,j;
for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
			{ if(a[j]>a[j+1])
 				 { temp=a[j+1];
   				   a[j+1]=a[j];
    				   a[j]=temp;
 				 }
			}
	}

}
