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
const ll MAX=1e6+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}


// recursive memorization
ll solve(int l, int r, vector<vector<ll>> &dp, ll arr[]) {
    if(l == r) return arr[l];
    if(l + 1 == r) {
        return abs(arr[l] - arr[r]);
    }
    ll ans = dp[l][r];
    if(ans != -1) return ans;
    ans = 0;
    if(1) {
        ll left = min(solve(l + 2, r, dp, arr) + arr[l] - arr[l + 1],
                        solve(l + 1, r - 1, dp, arr) + arr[l] - arr[r]);
        ll right = min(solve(l + 1, r - 1, dp, arr) + arr[r] - arr[l],
                        solve(l, r - 2, dp, arr) + arr[r] - arr[r - 1]);
        ans = max(left, right);
    }
    return dp[l][r] = ans;
}

// logical code of program starts here.
void solve(int T) {
    int n;
    cin>>n;
    ll arr[n];
    for(int i = 0; i < n; ++i) cin>>arr[i];
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    // iterative tabular 
    int start;
    if(n % 2) start = 1;
    else start = 2;  
    for(int l = start; l <= n; l += 2) {
        for(int i = 0; i + l <= n; i++) {
            int j = i + l - 1;
            if(l == 1) dp[i][j] = arr[i];
            else if(l == 2) dp[i][j] = abs(arr[i] - arr[j]);
            else {
                ll left = min(dp[i + 2][j] + arr[i] - arr[i + 1],
                                dp[i + 1][j - 1] + arr[i] - arr[j]);
                ll right = min(dp[i + 1][j - 1] + arr[j] - arr[i],
                                dp[i][j - 2] + arr[j] - arr[j - 1]);
                dp[i][j] = max(left, right);
            } 
        }
    }
    //cout<<solve(0, n - 1, dp, arr)<<endl;
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
