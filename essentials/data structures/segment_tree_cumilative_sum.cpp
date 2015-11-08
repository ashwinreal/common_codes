#include<iostream>
#include<cstdio>
using namespace std;

long long segment[2000001];

void create_segtree(long long arr[],long long start,long long end,long long index)
{
	if(start==end)
	{
		segment[index]=arr[start];
		return;
	}
	//if(start<end)
	{
	long long mid=(start+end)/2;
	create_segtree(arr,start,mid,2*index+1);
	create_segtree(arr,mid+1,end,2*index+2);
	
	segment[index]=segment[2*index+1]+segment[2*index+2]; // it will be a full tree
										 				 // so no need to worry about both of them not existing
	
	
	}	
}


void update2(long long arr[],long long index,long long chi,long long diff,long long start,long long end)
{

	if(chi>end||chi<start)
	return;
	
	segment[index]+=diff;
	if(start<end)
	{
		long long mid=(start+end)/2;
		update2(arr,2*index+1,chi,diff,start,mid);
		update2(arr,2*index+2,chi,diff,mid+1,end);
	}
	
}
void update(long long arr[],long long chi,long long chval,long long start,long long end)
{
	long diff=chval-arr[chi];
	arr[chi]+=chval;
	update2(arr,0,chi,diff,start,end);
}


long long get_sum(long long start,long long end,long long l,long long r,long long index)
{
	if(l<=start&&r>=end)
	return segment[index];
	if(r<start||l>end)
	return 0;
	long long mid=(start+end)/2;
	return get_sum(start,mid,l,r,2*index+1)+get_sum(mid+1,end,l,r,2*index+2);
}
int main()
{
	long long arr[100000]={1,2,3,4,5,6,7,8,9,10};	
	create_segtree(arr,0,9,0);
	cout<<segment[0]<<endl;
	update(arr,5,12,0,9);
	cout<<segment[0]<<endl;
	cout<<get_sum(0,9,0,4,0);
	return 0;
}
