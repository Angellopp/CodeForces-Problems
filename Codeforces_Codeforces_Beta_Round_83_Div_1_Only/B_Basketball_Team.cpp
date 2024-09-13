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

int main() {
    fast_io;

    int tt = 1;
    while (tt--) {
        int m, n, h, aux, vh;
        cin >> n >> m >> h;
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            cin >> aux;
            if (i == h) vh = aux;
            sum += aux;
        }
        if (n > sum) {
            cout << -1 << nn;
            continue;
        }
        float prob = 1;
        float x = sum - 1;
        for (int i = 0; i < n - 1; i++) {
            prob *= (x - vh + 1 - i) / (x - i);
        }
        cout << fixed << setprecision(7) << 1 - prob << nn;
    }
    return 0;

}


