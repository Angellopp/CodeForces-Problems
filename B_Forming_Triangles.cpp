#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long 
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool ver(int i, int j, int n, int m) {
    return(0 <= i and i < n and 0 <= j and j < m);
}

int maxn = 500+4;
void solve() {
    int n, aux;
    cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        mp[-aux]++;
    }
    int taux = n;
    ll ans = 0;
    for (auto x : mp) {
        taux -= x.S;
        ans += 1ll * x.S * (x.S - 1) / 2 * taux;
        ans += 1ll * x.S * (x.S - 1) * (x.S - 2) / 6;
    }
    cout << ans << endl;

}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
