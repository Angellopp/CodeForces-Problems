
#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v, n) for (int i = 0; i < n; i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
using namespace std;

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int d1, d2, d3, d4; 
        cout << "? " << 1 << " " << 1 << nn << nn;
        cout.flush();
        cin >> d1; // x + y = 2 + d1
        cout << "? " << n << " " << m << nn << nn;
        cout.flush();
        cin >> d2; // x + y = n + m - d2 
        cout << "? " << 1 << " " << m << nn << nn;
        cout.flush();
        cin >> d3; // y - x = m - 1 - d3
        // primer punto
        int x = (3 + d1 + d3 - m) / 2; 
        int y = (m + 1 + d1 - d3) / 2;
        if (((m + 1 + d1 - d3) % 2 == 0) and ((3 + d1 + d3 - m) % 2 == 0) and  1 <= x and x <= n and 1 <= y and y <= m) {
            cout << "? " << x << " " << y << nn << nn;
            cout.flush();
            cin >> d4;
            if (d4 == 0) cout << "! " << x << " " << y << nn << nn;
            else cout << "! " << ((n + 2*m - 1 - d2 - d3) / 2) << " " << ((n - d2 + 1 + d3) / 2) << nn << nn;
            cout.flush();
        }
        else {
            cout << "! " << ((n + 2*m - 1 - d2 - d3) / 2) << " " << ((n - d2 + 1 + d3) / 2) << nn << nn;
            cout.flush();

        }
        // y = ((n + 2*m - 1 - d2 - d3) / 2);
        // x = ((n - d2 + 1 + d3) / 2);
        // sgundo punto



    }
    return 0;
}