#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

void solve() {
    int naci = 1, neu = 0, mad = 0;
    for (int i = 0; i < 30; i+=2) {
        int aux_naci = naci;
        int aux_neu = neu;
        int aux_mad = mad;
        neu = aux_mad;xx vc  
        naci = 3 * aux_neu;
        mad = aux_naci + aux_neu;
        cout << neu + naci + mad << " ";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
