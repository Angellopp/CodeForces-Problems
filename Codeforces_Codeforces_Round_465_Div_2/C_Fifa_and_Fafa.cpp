#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
int mod = 1e9+7;
using namespace std;
const int maxn = 2.5e6 + 10;
int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        float r, x1, y1, x2, y2;
        cin >> r >> x1 >> y1 >> x2 >> y2;
        float dx = x1 - x2;
        float dy = y1 - y2;
        if (sqrt(dx * dx + dy * dy) > r) {
            cout << fixed << setprecision(7) << x1 << " " << y1 << " " << r << nn;
            continue;
        }
        if (dx == 0 and dy == 0) {
            cout << fixed << setprecision(7) << x1 + r / 2 << " " << y1 << " " << r / 2 << nn;
            continue;
        }
        float alfa = sqrt(r * r / (dx * dx + dy * dy));
        cout << fixed << setprecision(7) << (x1 + dx * alfa + x2) / 2  << " " << (y1 + dy * alfa + y2) / 2 << " " << (r + sqrt(dx * dx + dy * dy)) / 2 << nn;
    }
    return 0;

}


