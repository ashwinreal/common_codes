#include<iostream>
using namespace std;
#define MAX 1000
int calc_cumilative(int fenwick[],int size,int i)  /// calc cumilative from 0  till index i
{
	int cum=0;
	while(i>0)
	{
		cum+=fenwick[i];
		i=i-(i&(-i));
	}
	return cum;
}
void change(int fenwick[],int size,int pos,int diff) //pass difference of new value and old value at the poition ie if 4 is replaced by 6 then pass 2
{
	int i=pos;
	
	while(i<size)
	{
		fenwick[i]+=diff;
		i=i+(i&(-i));
	}
}
int main()
{
	int fenwick[MAX],arr[MAX];
	int size;
	cin>>size;
	for(int i=0;i<size;i++)	
	{
		fenwick[i]=0;
		cin>>arr[i];
}
	
	//construct fenwick
	for(int i=1;i<size;i++)
	{
		int add=arr[i];
		int j=i;
		
		while(j<size)
		{
		fenwick[j]+=add;
		j=j+(j&(-j));
	}
	}
	/*	for(int i=0;i<size;i++)	
		cout<<fenwick[i];
	*/
	cout<<calc_cumilative(fenwick,size,16);
	cout<<calc_cumilative(fenwick,size,13);
	change(fenwick,size,6,2);
	for(int i=0;i<size;i++)	
	cout<<fenwick[i];
	
	
	
	
}
