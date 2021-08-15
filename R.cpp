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

/*
**************************************************************************
Concept -> Matrix Multiplication floyd warshall. 
**************************************************************************

*/

// matrix multiplication
vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> Arr(A.size(), vector<ll> (A.size(), 0));
    int n = A.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                Arr[i][j] = (Arr[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    return Arr;
}

// concept of divie & conquer for fast exponentation.
vector<vector<ll>> matrixExponentation(vector<vector<ll>> &arr, ll k) {
    if(k == 0) {
        vector<vector<ll>> A(arr.size(), vector<ll> (arr.size(), 0));
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            A[i][i] = 1;
        }
        return A;
    }
    vector<vector<ll>> res = matrixExponentation(arr, k / 2);
    res = multiply(res, res);
    if(k & 1) res = multiply(res, arr);
    return res;
}

// logical code of program starts here.
void solve(int T) {
    ll n, k;
    cin>>n>>k;
    vector<vector<ll>> arr(n, vector<ll> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }
    vector<vector<ll>> A = matrixExponentation(arr, k);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = (ans + A[i][j]) % mod;
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
