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
double dp[MAX][MAX];

double solve(int pos, int head, int tail, int n, double prob[]) {
    if(pos == n) {
        if(head > tail) return 1.0;
        return 0.0;
    }
    double &ans = dp[pos][head];
    if(ans != 100000.0) {
        return ans; 
    }
    ans = solve(pos + 1, head + 1, tail, n, prob) * prob[pos];
    ans += solve(pos + 1, head, tail + 1, n, prob) * ((double)1 - prob[pos]);
    return ans;
}


// logical code of program starts here.
void solve(int T) {
    int n;
    cin>>n;
    double prob[n];
    for(int i = 0; i < n; i++) cin>>prob[i];
    for(int i = 0; i < n + 10; i++)
        for(int j = 0; j < n + 10; j++)
            dp[i][j] = 100000.0;
    cout<<fixed<<setprecision(10)<<solve(0, 0, 0, n, prob)<<endl;
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
