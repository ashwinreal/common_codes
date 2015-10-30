#include <iostream>
using namespace std;


 KMP algorithm
 !!!! : KMP algorithm we don’t need to have all the string T in memory, 
 we can read it character by character, and determine all the occurrences
 of a pattern P in an online way
  

long long f[100000]={0};  //size should be same as sub  // Let f[i] be the length of the largest border of P[0...i]
void failure_function(char sub[])
{
	f[0]=0;
	int i=1;    //start from 1 not 0 as f[0]=0
	int j=0;
	while(sub[i]!='\0')
	{
		while(j>=0 && sub[j]!=sub[i])
		{
			if(j>=1)
				j=f[j-1];
			else
				j=j-1;
		}
		j=j+1;
		f[i]=j;
		i++;
	}
}
void find(char s[],char sub[])
{
	int i,j;
	i=j=0;
	int 	lensub=0;
	for(;sub[lensub]!='\0';lensub++);
	while(s[i]!='\0')
	{
			while(j>=0 && s[i]!=sub[j])
			{
				if(j>=1)
					j=f[j-1];
				else
					j=j-1;
			}
			j=j+1;
			if(j==lensub)
			{
				j=f[lensub-1];
				cout<<i-lensub	+1<<endl;
			}
			i++;
	}
	
}
int main()
{
	
	char s[]="ABABDABACDABABCABAB";
	char sub[]="ABABCABAB";
	failure_function(sub);
	find(s ,sub);
	return 0;
}

