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

ll dp[21][MAX];

// Concept of Bit Masking Dp
ll call(vector<vector<ll>> &mt, ll mask = 0, ll pos = 0) {
    ll n = mt.size();
    //cout<<"mask "<<mask<<endl;
    if(mask == ((1LL << n) - 1)) {
        //cout<<"mask "<<mask<<endl;
        return 1;
    }
    if(pos == n) return 0;
    if(dp[pos][mask] != -1) return dp[pos][mask];
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(!mt[pos][i]) continue;
        if(mask & (1LL << i)) continue;
        ans = (ans + call(mt, mask | (1LL << i), pos + 1)) % mod;
    }
    return dp[pos][mask] = ans % mod;
}

// logical code of program starts here.
void solve(int T) {
    ll n;
    cin>>n;
    vector<vector<ll>> mt(n, vector<ll> (n, -1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>mt[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout<<call(mt) % mod<<endl;
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
