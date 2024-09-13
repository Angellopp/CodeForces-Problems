#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int MAXN = 4e5+5; 
set<int> aa;
int FT[ MAXN ]{};
int getFT (int b){
    int v = 0;
    for (int x = b; x; x -= x & -x) v = max(v,FT[x]); 
    return v;
}
void setFT (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT[x] = max(FT[x], v);
}
int get (int a, int b) { return getFT(b) - getFT(a-1); }
void update (int x, int v) { setFT(x, v); }

const int MOD = 998244353;


int mul_mod(ll a, ll b) {
    return a * b % MOD;
}
int sum_mod(ll a, ll b) {
    return ((a + b) % MOD);
}

ll num1(ll n, ll i) {
    ll div = (1ll << i);
    ll paq = n / div;
    ll r = n % div;
    // ll ans = (paq >> 1) * div + r * (paq % 2);
    // if (paq % 2) ans += r;
    return (paq >> 1) * div + r * (paq % 2);
}

int main() {
    fastio;
    ll m, n;
    cin >> n >> m;
    vector <int> imp;
    ll ans = 0; 
    for (int i = 0; i < 60; i++) {
        if((m>>i) & 1LL) ans = sum_mod(ans, num1(n+1, i));
    }
    cout << ans ;

    // for (auto x : imp) cout << x << " ";


    
    
}