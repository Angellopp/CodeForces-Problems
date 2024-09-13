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


int n, m;

void solve() {
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = -1;
    if(n == 2) {cout << min(v[0], v[1]) << endl; return;}
    for (int i = 0; i+2 < n; i++) {
        int c[3] = {v[i], v[i+1], v[i+2]};
        sort(c, c+3);
        ans = max(c[1], ans);
    }
    cout << ans << endl;

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

/*


5 4 3 4 5
1 4 2 3 5
1 4 2 3 5





*/