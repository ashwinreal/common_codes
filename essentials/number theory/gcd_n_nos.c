#include<stdio.h>
#include<math.h>

long gcd(long a, long b)
{
	if(a<b)
	gcd(b,a);
	if(a%b == 0)
	return b;
	else
	{
		if(a%b < (b/2))
		gcd(b,a%b);
		else
		gcd(b,b-(a%b));
	}
	
}

long gcd_n_no(long numbers[],long n)
{
	long i;
	 long result = numbers[0];
for(i = 1; i < n; i++){
    result = gcd(result, numbers[i]);
}
return result;
	
}
int  main()
{
	long k,t,i,j,n,numbers[100],ans[10];
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld",&n);
		for(j=0;j<n;j++)
		scanf("%ld",numbers + j);
		
		ans[i]=gcd_n_no(numbers,n);
	}
	for(k=0;k<t;k++)
	if(ans[k]==1)
	printf("YES\n");
	else
	printf("NO\n");
	
}
