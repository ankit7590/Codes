/*
PROBLEM STATEMENT : 
-------------------
WRITE A PROGRAM TO PRINT NODES AT A DISTANCE OF 'K' FROM A GIVEN NODE IN A BINARY TREE

*/

#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

node* createnode(int data)
{
	node *n = (node*)malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}



void printkDistNodeDown(node*n, int k)
{
	if(n==NULL)
		return;
	if(k==0)
	{
		cout << n->data << endl;
		return;
	}
	printkDistNodeDown(n->left,k-1);
	printkDistNodeDown(n->right,k-1);
}



void printkDistNodeDown_fromUp(node*target, int *k)
{
	if(target==NULL)
		return;
	if(*k==0)
	{
		cout << target->data<<endl;
		return;
	}
	else
	{
		int val = *k;
		printkDistNodeDown(target,val-1);
	}

}


int printkDistNodeUp(node*root,node*n,int *k)
{
	if(root==NULL)
		return 0;
	if(root->data == n->data)
		return 1;

	int pl = printkDistNodeUp(root->left,n,k);
	int pr = printkDistNodeUp(root->right,n,k);

	if(pl)
	{
		(*k)-- ;
		if(*k == 0)
		{
			cout << root->data << endl;
		}
		else
		{
			printkDistNodeDown_fromUp(root->right,k);
			return 1;
		}
	}

	if(pr)
	{
		(*k)-- ;
		if(*k == 0)
		{
			cout << root->data << endl;
		}
		else
		{
			printkDistNodeDown_fromUp(root->left,k);
			return 1;
		}
	}
	return 0;
}





void printkDistNode(node* root,node* n, int k)
{
	if(root==NULL)
		return;
	int val=k;
	printkDistNodeUp(root,n,&k);
	printkDistNodeDown(n,val);


}



int main()
{
	node * root = createnode(5);
	root ->left = createnode(2);
	root ->right = createnode(8);
	node* n =root->right;
	n->left = createnode(6);

	n->right = createnode(9);
	n=n->left;
	root -> left -> left = createnode(-4);
	root -> left -> right = createnode(4);


	cout << "At Distance 1 : " << endl;
	printkDistNode(root,n,2);
	/*
	cout << endl << endl << "At Distance 2 : " << endl;
	printkDistNode(root,n,2);

	cout << endl << endl << "At Distance 3 : " << endl;
	printkDistNode(root,n,3);
	*/


}