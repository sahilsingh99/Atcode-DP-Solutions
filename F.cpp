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
#define repa(i,n) for(ll i=n;i>=0;i--)
#define repx(i,x,n) for(ll i=x;i<n;i++)
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define PI       3.14159265358979323846
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const ll MAX=1e5+5;
const ll INF=2e18;
int ans=0,l1,l2;
#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}

// logical code of program starts here.
void solve()
{
    string s,t;
    cin>>s>>t;
    l1=s.length();
    l2=t.length();
    int dp[l1+1][l2+1];
    rep(i,l1+1)
    {
        rep(j,l2+1)
        {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    string ans;
    int i=l1,j=l2;
    while(i>0 and j>0)
    {
        if(s[i-1] == t[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else j--;
    }
    reverse(all(ans));
    cout<<ans<<endl;
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
