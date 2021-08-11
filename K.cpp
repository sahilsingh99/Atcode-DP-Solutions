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
const ll MAX=4e3+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}



// logical code of program starts here.
void solve(int T) {
    int n, k;
    cin>>n>>k;
    int a[n];
    int mn = k;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        mn = min(mn, a[i]);
    }
    bool dp[k + 1];
    memset(dp, false, sizeof dp);
    for(int i = 1; i <= k; i++) {
        bool flag = false;
        for(int j = 0; j < n; j++) {
            if(a[j] <= i) {
                if(dp[i - a[j]] == false) flag = true;
            }
        }
        dp[i] = flag;
    }
    //for(int i = 0; i <= k; i++) cout<<dp[i]<<" ";
       // cout<<endl;
    if(!dp[k]) cout<<"Second\n";
    else cout<<"First\n";
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
