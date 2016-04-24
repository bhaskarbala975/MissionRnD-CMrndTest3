/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};


int get_missing_value(struct node *root, int n)
{
	if (n == 0 || root == NULL)
		return -1;
	int i , array[100000], i1 = 0, n1 = 1,j1=0;
	for (i = 1; i <= n; i++)
		array[i] = i;
	int a[100];
	int j = 0;
	node * list[100];
	 i = 0;
	list[0] = root;
	while (i < n1) {
		node *curnode = list[i];
		if (curnode->right) {
			list[n1++] = curnode->right;
		}
		if (curnode->left) {
			list[n1++] = curnode->left;
		}
		i++;
	}
	for (int i = 0; i < n1; i++)
	{
		
		a[j] = list[i]->data;
		j++;
	}
	for (i = 1; i <= n; i++)
	{
		for (j1 = 0; j1 < j; j1++)
			if (array[i] == a[j1])
				array[i] = -12;
	}
	for (i = 1; i <= n; i++)
		if (array[i] != -12)
			return array[i];
}
