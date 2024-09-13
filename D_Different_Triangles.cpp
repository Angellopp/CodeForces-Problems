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

int r[N];
int pre[N];
int f[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < N; i += 6) {
        for (int k = i; k < i + 6; k++) {
            r[k] = i/6 + 1;
            if (k == i + 4) r[k] = i/6 + 2;
        }
    }
    int n; cin >> n;
    if (n < 5) {
        if(n == 1) cout << 0 << endl;
        if(n == 2) cout << 0 << endl;
        if(n == 3) cout << 1 << endl;
        if(n == 4) cout << 1 << endl;
        return 0;
    }
    n -= 5;
    pre[0] = 1;
    for (int i = 1; i < N; i++) pre[i] = (pre[i - 1] + r[i - 1]) % MOD;
    f[0] = 2;
    for (int i = 1; i < N; i++) {
        int ind = i/2-1;
        int aux = (i/2 -1 < 0) ? 1 : pre[i/2-1];
        if (i & 1) f[i] = (0ll + f[i - 1] + aux + MOD) % MOD;
        else f[i] = (0ll + f[i - 1] + pre[i/2] + MOD) % MOD;
    }
    // for (int i = 0; i < 7; i++) {
    //     cout << f[i] << endl;
    // }
    cout << f[n] << endl;
    // if (n & 1) cout << f[n / 2 - 1];
    // else cout << f;

    return 0;
}