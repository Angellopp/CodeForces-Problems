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
    bool unos = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) unos = 1;
    }
    sort(all(v));
    if(!unos) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i+1 < n; i++) {
        if(v[i] + 1 == v[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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