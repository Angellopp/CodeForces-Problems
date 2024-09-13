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


int mod = 1e9 + 7;
void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    vector <pair<int,int>> v(n+2);
    v[0] = {0,0};
    v[n+1] = {m, m};
    for (int i = 1; i <= n; i++) cin >> v[i].F >> v[i].S;
    for (int i = 1; i <= n+1; i++) {
        if(v[i].F - v[i-1].S >= s){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
