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

void solve() {
    int n;
    cin >> n;
    vector <pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].S = i+1;
    }
    sort(all(v));
    if (v[0].F == v[n-1].F) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES\n";
    int cur = v[0].F;
    for (int i = 1; i < n; i++) {
        if (v[i].F != cur) cout << v[0].S << " " << v[i].S << endl;
        else cout << v[n-1].S << " " << v[i].S << endl;
    }

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
