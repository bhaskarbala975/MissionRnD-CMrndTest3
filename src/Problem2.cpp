/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int p[100];
int counter = 0;
void inorder(struct node* root);
int is_identical(struct node_dll *head, struct node *root)
{

	if (head==NULL||root==NULL)
	return -1;
	int i=0;
	int *a;
	int *array;
	int j = 0;
	a = (int*)malloc(100 * sizeof(int));
	node * list[100];
	int n = 1;
	i = 0;
	list[0] = root;
	while (i < n)
	{
		node *curnode = list[i];
		if (curnode->right) {
			list[n++] = curnode->right;
		}
		if (curnode->left) {
			list[n++] = curnode->left;
		}
		i++;
	}

	for (int i = 0; i < n; i++) {
		node *presentnode = list[i];
		a[j] = presentnode->data;
		j++;
	}
	int flag = j;
	inorder(root);
	int flag1 = counter;
	if (flag1 != flag)
		return 0;
	for (i = 0; i < flag1 - 1; i++)
	{
		for (j = 0; j < flag1 - i - 2; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 0; i < counter; i++)
	{
		if (a[i] != p[i])
			return -1;
	}
	return 1;
}
void inorder(struct node* root)
{
	inorder(root->left);
	p[counter] = root->data;
	inorder(root->right);
}
/*here my idea is to collect data from dll and finding inorder of bst and  
 compare them if there is a mismatch i wil return -1 if there is no mismatch i will return 1*/