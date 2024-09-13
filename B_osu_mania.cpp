
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
    int n;
    cin >> n;
    char xd;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> xd;
            if(xd == '#') {
                // cout << 4-j << " ";
                v.push_back(j+1);
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        cout << v[i] << " ";
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
