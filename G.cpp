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
const ll MAX=2e5+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}
const int MaX = 110;

int dfs(vector<vector<int>> &gp, vector<bool> &vis, int u, vector<int> &dp) {
    if(vis[u]) return dp[u];
    int ans = 0;
    vis[u] = true;
    for(int v : gp[u]) {
        if(vis[v]) {
            ans = max(ans, dp[v] + 1);
        } else {
            ans = max(ans, dfs(gp, vis, v, dp) + 1); 
        }
        // cout<<u<<" "<<v<<" "<<ans<<endl;
    }
    return dp[u] = ans;
}


// logical code of program starts here.
void solve(int T) {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> gp(n, vector<int>());
    for(int i = 0 ; i < m; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        gp[u].push_back(v);
    }
    vector<bool> vis(n, false);
    vector<int> dp(n, -1);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i] == false) {
            ans = max(ans, dfs(gp, vis, i, dp));
        }
    }
    cout<<ans<<endl;
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
