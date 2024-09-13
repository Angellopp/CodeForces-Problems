#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

const int N = 1e4+5;
const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector <int> v(n);
    bool t0 = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] != 0) t0 = 0;
    }
    if (t0) {
        for (int i = 1; i <= n; i++) cout << i << " "; cout << endl; 
        return;
    }
    int xdd = 0;
    for (int i = 0; i < 31; i++) {
        int xd = 0;
        for (int j = 0; j < n; j++) {
            xd += (v[j]>>i & 1);
        }
        xdd =__gcd(xdd, xd);
    }
    set<int> div;
    for (int i = 1; i*i <= xdd; i++) {
        if (xdd % i == 0) {
            div.insert(i);
            div.insert(xdd/i);
        }
    }
    div.insert(xdd);
    for(auto& x : div) {
        cout << x << " ";
    }
    cout << endl;
    
}

int main() {
    fastio;
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
