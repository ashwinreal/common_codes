
long long pas[1001][1001];
long long mod = 1000000007;
void pascal()
{
	pas[0][0]=1;
	pas[0][1]=0;
	pas[1][0]=1;
	pas[1][1]=1;
	pas[2][0]=1;
	pas[2][1]=2;
	pas[2][2]=1;
	for(long long i=3;i<=1000;i++)
	{
		for(long long j=0;j<=i;j++)
		{
			if(j==0||j==i)
			{
				pas[i][j]=1;
			}
			else
				pas[i][j]=(pas[i-1][j-1]+pas[i-1][j])%mod;
		}
	}
}
