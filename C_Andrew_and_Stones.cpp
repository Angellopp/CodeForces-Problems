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
    ll p = 0, imp = 0, unos = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(i != 0 and i != n-1) {
            if (v[i] % 2) {
                imp++; if (v[i] == 1) unos++;
            } 
            else p++; 
            sum += 1ll*v[i];
        }
    }
    if (n == 3) {
        cout << ((v[1] % 2) ? -1 : v[1] / 2) << endl; return;
    }
    if (unos == n-2){
        cout << -1 << endl; return;
    }
    cout << (imp + sum) / 2 << endl;


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

3 0 5 2
3 1 3 2
3 2 1 2
3 0 2 2
3 0 0 2

*/