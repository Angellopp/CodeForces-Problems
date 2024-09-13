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
    ll r = n - div * paq;
    ll paq1 = (paq >> 1) * div;
    if (paq % 2 == 1) paq1 += r;
    return paq1;
}
int n, m;
int v[100+2][100+2];
bool isv(int i, int j) {
    return(0 <= i and i < n and 0 <= j and j < m); 
}
void isg(int i, int j) {
    bool can = 1;
    int mn = 0;
    if(isv(i+1,j)) ((v[i][j] <= v[i+1][j]) ? can = 0: mn = max(mn, v[i+1][j]));
    if(isv(i,j+1)) ((v[i][j] <= v[i][j+1]) ? can = 0: mn = max(mn, v[i][j+1]));
    if(isv(i-1,j)) ((v[i][j] <= v[i-1][j]) ? can = 0: mn = max(mn, v[i-1][j]));
    if(isv(i,j-1)) ((v[i][j] <= v[i][j-1]) ? can = 0: mn = max(mn, v[i][j-1]));
    if(can) v[i][j] = mn;
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        int n, m;
        string ori, cam;
        cin >> n>>m;
        cin >> ori;
        vector <int> v(m);
        for (int i = 0; i < m; i++)cin >> v[i];
        cin >> cam;
        sort(all(v));
        for (int i = 0; i < m; i++) cout << v[i];

    }

    
    
}