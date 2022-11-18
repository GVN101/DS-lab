#include<stdio.h>
void insertion(int a[],int n);
void main()
{ int a[50],i,j,n;
  printf("enter no of elements");
  scanf("%d",&n);
  printf("enter list of array");
  for(i=0;i<n;i++)
  { 
    scanf("%d",&a[i]);
  }
  insertion(a,n);
  for(int i=0;i<n;i++)
  {
  	printf("%d",a[i]);
  }
}



void insertion(int a[],int n)
{
int x;
 for(int i=1;i<n;i++)
{ int x=a[i];
  for(int j=i-1;j>=0;j--)
  { if(x<a[j])
    a[j+1]=a[j];
    else
   	 break;
   a[j]=x;
  }
}
}

  
  
