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
    int n ;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int cur = 0;
    int i = n-1;
    while(i >= 0) {
        if(v[i] >= cur) {
            cur = v[i];
        }
        else {
            cur = v[i];
            break;
        }
        i--;
    }
    while(i >= 0) {
        if(v[i] <= cur) {
            cur = v[i];
        }
        else {
            break;
        }
        i--;
    }
    cout << i + 1 << endl;

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
