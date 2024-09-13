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

vector<int> pot;

int mod = 1e9 + 7;
void solve() {
    int l, r;
    cin >> l >> r;
    ll ans = 0;
    int xd = l;
    while(xd) {
        xd/=3;
        ans+=2;
    }
    l++;
    xd = l;
    int pp = 0;
    while(xd) {
        xd/=3;
        pp++;;
    }
    vector <int> x;
    x.emplace_back(l);
    for (int i = 0; i < pot.size(); i++) {
        if(l < pot[i] and pot[i] <= r) {
            x.emplace_back(pot[i]);
        }
    }
    x.emplace_back(r+1);
    for (int i = 1; i < x.size(); i++) {
        ans += 1ll * (x[i] - x[i-1]) * (pp);
        pp++;
    }
    cout << ans << endl;



}

int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    pot.emplace_back(1);
    for (int i = 0; pot.back() * 3 <=2e6; i++) {
        pot.emplace_back(pot.back()*3);
    }
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
