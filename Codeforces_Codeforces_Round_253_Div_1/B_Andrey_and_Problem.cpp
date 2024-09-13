#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
using namespace std;

const int INF = 1e9 + 7;

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        double aux;
        cin >> n;
        vector <double> v;
        bool can = 0;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (aux != 1) v.emplace_back(1.0 / (1 - aux));
            else can = 1;
        }
        if (can) {
            cout << 1 << nn;
            continue;
        }
        double ans = 0;
        n = v.size();
        sort(v.rbegin(), v.rend());
        double sum = 0, prod = 1;
        for (int i = 0; i < n; i++) {
            sum += v[i] - 1;
            prod *= 1.0 / v[i];
            ans = max(ans, sum * prod);
        }

        cout << fixed << setprecision(10) << ans << nn;
    }
    return 0;
}