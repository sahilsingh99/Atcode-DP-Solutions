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
    int n;
    cin>>n;
    int dp[n+1][3]={0};
    rep(i,n+1)
    {
        if(!i)continue;
        int a,b,c;
        cin>>a>>b>>c;
        dp[i][0]=max(dp[i-1][1]+b,dp[i-1][2]+c);
        dp[i][1]=max(dp[i-1][0]+a,dp[i-1][2]+c);
        dp[i][2]=max(dp[i-1][1]+b,dp[i-1][0]+a);
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
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
