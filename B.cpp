#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long 
int main()
{
	ll n,k;
	cin>>n>>k;
	ll h[n];
	for(ll i=0;i<n;i++)
	{
		cin>>h[i];
	}
	ll dp[n];
	for(ll i=0;i<n;i++)
	{
		dp[i]=LLONG_MAX;
	}
	dp[0]=0;
	dp[1]=abs(h[0]-h[1]);
	//cout<<dp[0]<<endl<<dp[1]<<endl;
	for(ll i=2;i<n;i++)
	{
		if((i-k)<0)
		{
			for(ll j=0;j<i;j++)
			{
				dp[i]=min(dp[i],abs(h[i]-h[j])+dp[j]);
			}
		}
		else
		{
			for(ll j=i-k;j<i;j++)
			{
				dp[i]=min(dp[i],abs(h[i]-h[j])+dp[j]);
			}
		}
		//cout<<dp[i]<<endl;
	}
	cout<<dp[n-1]<<endl;
}
