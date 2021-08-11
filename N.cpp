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
const ll MAX=2e6+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}

// logical code of program starts here.
void solve(int T) {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll &i : arr) cin>>i;
    ll dp[n][n];
    ll ans = 0;
    memset(dp, 0, sizeof dp);
    ll sum[n][n];
    // Matrix Chain Multiplication Dp
    for(int l = 1; l <= n; l++) {
        ll res = INT_MAX;
        for(int i = 0; i + l <= n; i++) {
            if(l == 1) {
                sum[i][i] = arr[i];
                dp[i][i] = 0;
            } else {
                sum[i][i + l - 1] = arr[i] + sum[i + 1][i + l - 1];
                dp[i][i + l - 1] = LLONG_MAX;
                for(int j = i; j < i + l; j++) {
                    dp[i][i + l - 1] = min(dp[i][j] + dp[j + 1][i + l - 1] + sum[i][i + l - 1], dp[i][i + l - 1]);
                }
            }
        }
    }
    cout<<dp[0][n - 1]<<endl;

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
