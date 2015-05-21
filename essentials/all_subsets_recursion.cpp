#include<iostream>
#include<vector>
using namespace std;
/*void printstack(vector<int> stack)
{
	for(int i=0;i<stack.size();i++)
	cout<<stack[i]<<" ";
	cout<<endl;
}
void all_subsets(int arr[],int arr_s,vector<int> stack,int k)
{
	for(int i=k;i<arr_s;i++)
	{
		stack.push_back(arr[i]);
		printstack(stack);
		all_subsets(arr,arr_s,stack,i+1);
		stack.pop_back();
		
	}
}*/
void printstack(int stack[],int s)
{
	
	for(int i=0;i<s;i++)
	cout<<stack[i]<<" ";
	cout<<endl;
}
void all_subsets(int arr[],int arr_s,int stack[],int stack_s,int k)
{
	for(int i=k;i<arr_s;i++)
	{
		
		stack[stack_s++]=arr[i];
		printstack(stack,stack_s);
		all_subsets(arr,arr_s,stack,stack_s,i+1);
		stack_s--;
		
	}
}
int main()
{
	int arr[]={1,2,3,4,5};
	//vector<int> v;
	//all_subsets(arr,3,v,0);
	int v2[100];
	all_subsets(arr,5,v2,0,0);
	
	
}
