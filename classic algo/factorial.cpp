#include<iostream>
#include<string>
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);
	
	int n;
	int fact[200],len,carry,temp;
	fact[0]=1;
	
	len=1;
	carry=0;
	for(int i =1;i<=100;i++)
	{
		for(int j=0;j<len;j++)
		{
		temp= carry + fact[j]*i;
		fact[j]=temp%10;
		carry=temp/10;
			
	}
	while(carry>0)
	{
		fact[len]=carry%10;
		carry=carry/10;
		len++;
	}
		
		
	}
	
	for(int k=len-1;k>=0;k--) 
    cout<<fact[k];
            
	
}
