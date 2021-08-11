// nhi btane ka h bhidu
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007
#define w(t) while(t--)
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define PI 3.14159265358979323846
#define el cout<<endl;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const ll MAX=1e5+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}
ll dp[101][MAX];
void solve(int t) {
    ll n, k;
    cin>>n>>k;
    ll arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1LL;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j <= arr[i - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            } else {
                dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) % mod + mod - dp[i - 1][j - arr[i - 1] - 1]) % mod;
            }
        }
    }
    // if(k) {
    //     dp[n][k] = ( (dp[n][k]+ mod +(mod- dp[n][k-1])%mod )%mod + mod)%mod;
    // }
    cout<<dp[n][k]<<endl;
}

// mian function 
int main() {

    #ifndef ONLINE_JUDGE
    INPUT_OUTPUT;//file handlings
    #endif
    fastIO;// fast input output
    int t;
    t=1;
    //cin>>t;
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}


