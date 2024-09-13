
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
    ll x,y,k;
    cin >> x >> y >> k;
    // int nim = min(x, y);
    // 
    ll d1 = (x+k-1 )/ k;
    ll d2 = (y+k-1) / k;
    // cout << d2  << endl;
    if(d2 > d1) {
        cout << 2*d2 << endl; 
    }
    else {
        cout << 2*d1-1 << endl; 
    }
    // if(x < y) {

    // }
    
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
