/*
********************
Author : Sahil Kundu
********************
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define pb(i) push_back(i)
#define f first
#define s second
#define mk(l,r) make_pair(l,r)
#define vi vector<int>
#define vl vector<ll>
#define vch vector<char>
#define all(vc) vc.begin(),vc.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ms(i,j) memset(i,j,sizeof i)
#define w(t) while(t--)
#define len(s) s.length()
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define PI       3.14159265358979323846
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const ll MAX=1e5+5;
const ll INF=2e18;

#define INPUT_OUTPUT {\
	freopen("input.txt","r",stdin);\
	freopen("output.txt","w",stdout);\
}

// logical code of program starts here.
void solve()
{
    int n,w;
    cin>>n>>w;
    vi wt(n+1,0),val(n+1,0);
    rep(i,n)cin>>wt[i+1]>>val[i+1];
    ll dp[n+1][w+1];
    ms(dp,0);
    //cout<<dp[0][0]<<endl;
    rep(i,n+1)
    {
        rep(j,w+1)
        {
            if(i==0 or j==0)continue;
            dp[i][j]=dp[i-1][j];
            if(wt[i]<=j){
                dp[i][j]=max(dp[i][j],dp[i-1][j-wt[i]]+val[i]);
                //cout<<dp[i-1][j-wt[i]]<<endl;
                //cout<<i<<endl;
            }
        }
    }
    cout<<dp[n][w]<<endl;
}


// mian function 
int main()
{
    //INPUT_OUTPUT;//file handling
    fastIO;// fast input output
    clock_t start, end; 
    start = clock();
    int t;
    t=1;
    //cin>>t;
    w(t) solve();
    end = clock();   
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC); 
    clog << "Time taken by program is : " << fixed 
    << time_taken << setprecision(5); 
    clog << " sec " << endl;
    return 0;
}
