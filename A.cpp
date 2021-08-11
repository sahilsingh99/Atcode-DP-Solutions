#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int h[n];
  for(int i = 0;i < n; i++) cin>>h[i];
  int dp[n];
  memset(dp, 0, sizeof dp);
  for(int i = 1; i < n; i++) { 
  	dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    if(i >= 2) { 
    	dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
  }
  cout<<dp[n - 1]<<endl;
}
