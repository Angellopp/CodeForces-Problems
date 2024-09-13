#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

// const int mod = 32768;
// vector <int> dp(mod+10);
// vector <bool> vis(mod+10);

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {cin >> v[i]; sum += v[i];}
    int gen;
    bool in = 0;
    map<int,int> mp;
    for (int i = 0; i < q; i++){
        int j; cin >> j;
        if(j == 1) {
            int ind, k;
            cin >> ind >> k;
            ind--;
            if(in and mp.count(ind) == 0) v[ind] = gen;
            mp[ind]++;
            sum += 1ll * (k - v[ind]);
            v[ind] = k;
        }
        else {
            cin >> gen;
            sum = 1ll * n * gen;
            in = 1;
            mp.clear();
        }
        cout << sum << endl;
    }


}

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}