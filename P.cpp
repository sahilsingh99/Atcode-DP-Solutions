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
const ll MAX=3e6+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}


// concept of tree dp.
vector<ll> solve(vector<vector<ll>> &gp, vector<bool> &vis, ll u, ll v) {
    vis[u] = true;
    // for leaf node we have two choices, black & white.
    ll white = 1LL, black = 1LL;
    for(ll x : gp[u]) {
        if(x == v || vis[x]) continue;
        vector<ll> ways = solve(gp, vis, x, u);
        // when root is black, child can only have white nodes, so multiple white nodes of each children.
        black = ((ways[0]) * black) % mod;
        // when root is white, child can have two choices: white & black, so add both the choices & multiply with each children.
        white = ((ways[0] + ways[1]) * white) % mod;
    }
    // return both possible ways.
    return {white % mod, black % mod};
}

// logical code of program starts here.
void solve(int T) {
    ll n;
    cin>>n;
    vector<vector<ll>> gp(n, vector<ll>());
    for(int i = 0; i < n - 1; i++) {
        ll u, v;
        cin>>u>>v;
        u--;
        v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    ll ans = 0;
    vector<bool> vis(n, false);
    for(ll i = 0; i < n; i++) {
        if(vis[i]) continue;
        vector<ll> x = solve(gp, vis, i, -1);
        // If tree is not connected, in that case check for each tree or we can say for each component and add their answers.
        ans = (ans + x[0] + x[1]) % mod;
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
