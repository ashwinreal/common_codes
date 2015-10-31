#include <iostream>
using namespace std;
/*Given a binary matrix, find out the maximum size square sub-matrix with all 1s. */
int min(int a, int b, int c)
{
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}
int arr[1000][1000]= {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
int r,c;

int dp[1000][1000];
void square()
{
	for(int i=0;i<r;i++)
	dp[i][0]=0;
	for(int j=0;j<c;j++)
	dp[0][j]=0;
	
	for(int i=1;i<r;i++)
	for(int j=1;j<c;j++)
	{
		if(arr[i][j]==0)
		dp[i][j]=0;
		else
		dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
	}
	int max=-1;
	int ii,jj;
	//cout<<r<<" "<<c<<endl;
	for(int i=0;i<r;i++){	
	for(int j=0;j<c;j++)
	{
		//cout<<dp[i][j]<<" ";
		//cout<<i<<" "<<j<<" ";
		if(dp[i][j]>max)
		{
			max=dp[i][j];
			ii=i;
			jj=j;
			//cout<<max<<" "<<ii<<" "<<jj<<endl;
		}
		
	}
	//cout<<endl;
	}
	cout<<dp[ii][jj]<<" "<<ii<<" "<<jj<<endl;
}
int main()
{

	r=6;
	c=5;
	square();

	return 0;
} 
