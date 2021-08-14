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

// Binary Index Tree
// Reference -> https://www.geeksforgeeks.org/longest-increasing-subsequence-using-bit/
ll query(ll bits[], ll x) {
    ll res = 0;
    while(x) {
        res = max(bits[x], res);
        x -= (x & (-x)); 
    }
    return res;
}

void upd(ll bits[], ll x, ll val, ll n) {
    while(x <= n) {
        bits[x] = max(bits[x], val);
        x += (x & (-x));
    }
}

// logical code of program starts here.
void solve(int T) {
    ll n;
    cin>>n;
    pair<ll, pair<ll, ll>> arr[n];
    ll bits[n + 1];
    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        arr[i].first = x;
        bits[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        arr[i].second = {x, i};
    }
    bits[n] = 0;
    // Sort according to height of flowers.
    sort(arr, arr + n, [](pair<ll, pair<ll, ll>> &a, pair<ll, pair<ll, ll>> &b) {
        return a.first < b.first;
    });
    for(int i = 0; i < n; i++) {
        ll val = arr[i].second.first;
        // original index of the height.
        ll idx = arr[i].second.second + 1;
        // Find max value till now from bit.
        // Max value of LIC (Longest Increasing Subsequence) if current height is last.
        ll ansTillNow = query(bits, idx) + val;
        // Update new value in bit.
        // Add value of current height into bit, so that it can contribute to others./
        upd(bits, idx, ansTillNow, n);
    }
    ll res = 0;
    // Find max value from bit.
    for(int i = 1; i <= n; i++) {
        res = max(res, bits[i]);
    }
    cout<<res<<endl;
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
