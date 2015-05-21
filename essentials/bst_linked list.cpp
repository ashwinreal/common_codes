#include<iostream>

using namespace std;

struct node
{
	int val;
	node* l;
	node* r;
};

void insert(node* root,node* newnode)        ////not working as a function!!!!!!!
{
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		if(newnode->val >= root->val )
		{
		if(root->r == NULL)
			root->r=newnode;
		else
		insert(root->r,newnode);
		}
		else
		{
		if(root->l == NULL)
			root->l=newnode;
		else
		insert(root->l,newnode);
		}	
	}
}
void traverse_inorder(node* root)
{
	if(root==NULL)
	cout<<"error\n";
	else
	{
		if(root->l!=NULL)
		traverse_inorder(root->l);
		
		cout<<root->val<<endl;
		
		if(root->r!=NULL)
		traverse_inorder(root->r);
		
	}
	
}
node* rightmost_of_l(node* root)
{
	if(root->r == NULL)
	return root;
	else
	rightmost_of_l(root->r);
}
void delit(node* root)
{
	node* temp;
	if(root->l==NULL&&root->r==NULL)
	root=NULL;
	else
	if(root->l==NULL&&root->r!=NULL)
	root=root->r;
	else
	if(root->r==NULL&&root->l!=NULL)
	root=root->l;
	else
	{
		temp=new node;
		temp=rightmost_of_l(root->l);
		delit(temp);
		root->val=temp->val;
	}
	
}
void del(node* root,int v)          //not working as a function
{
	if(root==NULL)
	cout<<"error";
	else
	{
		if(root->val==v)
		delit(root);
	else
	{
		if(v > root->val)
		del(root->r,v);
		else
		del(root->l,v);
		
	}
	}
}
void search(node* root,int v)
{
	if(root==NULL)
	cout<<"error";
	else
	if(root->val==v)
	cout<<root->val;
	else
	{
		if(v > root->val)
		search(root->r,v);
		else
		search(root->l,v);
		
	}
	
}
int main()
{
	node *root,*temp;
	root=temp=NULL;
	int a,b;
	while(1)
	{
	cin>>a;
	switch(a)
	{
		case 1://insert
			int val1;
			temp=new node;
			temp->l=NULL;
			temp->r= NULL;
			cin>>val1;
			temp->val=val1;
			//insert(root,temp);
			if(root==NULL)
	{
		root=temp;
	}
	else
	{
		if(temp->val >= root->val )
		{
		if(root->r == NULL)
			root->r=temp;
		else
		insert(root->r,temp);
		}
		else
		{
		if(root->l == NULL)
			root->l=temp;
		else
		insert(root->l,temp);
		}	
	}
			
			break;
		case 2://traverse 
		traverse_inorder(root);
		break;
		
		case 3://search
		cin>>val1;
		temp=new node;
		temp=root;
		search(temp,val1);
		break;
		
		case 4:
			cin>>val1;
			//del(root,val1);
			if(root==NULL)
	cout<<"error";
	else
	{
		if(root->val==val1)
		{
			node* temp;
	if(root->l==NULL&&root->r==NULL)
	root=NULL;
	else
	if(root->l==NULL&&root->r!=NULL)
	root=root->r;
	else
	if(root->r==NULL&&root->l!=NULL)
	root=root->l;
	else
	{
		temp=new node;
		temp=rightmost_of_l(root->l);
		delit(temp);
		root->val=temp->val;
	}
	
		}
	else
	{
		if(val1 > root->val)
		del(root->r,val1);
		else
		del(root->l,val1);
		
	}
	}
	
	
	}
	cin>>b;
	if(b==0)
	break;
}
}
