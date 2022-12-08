/*#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
       };
struct node* newNode(int data)
       {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
       }
int main()
       {
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	getchar();
	return 0;
       }*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data_element;
struct node *left, *right;
};

struct node *new_node(int data_element)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->data_element = data_element;
temp->left = temp->right = NULL;
return temp;
}

void display(struct node *root)
{
if (root != NULL)
{
display(root->left);
printf("%d \n", root->data_element);
display(root->right);
}
}

struct node* insert(struct node* node, int data_element)
{

if (node == NULL) return new_node(data_element);
if (data_element < node->data_element)
{
node->left = insert(node->left, data_element);
}
else if (data_element > node->data_element)
{
node->right = insert(node->right, data_element);
}
return node;
}

int main()
   {
    int n,x,t=0;
    struct node *root = NULL;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
      {
       if(t==0){
         scanf("%d",&x);
         root=insert(root,x);}
       else{
         scanf("%d",&x);
         insert(root,x);}
      }
       printf("\n\nTree is:");
       display(root);
       return 0;
   }

