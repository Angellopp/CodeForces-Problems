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
        cin >> tt;
        int a[1000+2];
        int b[1000+2];
        while (tt--) {
            int n, x;
            cin >> n >> x;
            int g = 0;
            for (int i = 1; i < n; i++) {
                cin >> a[i] >> b[i];
                if (a[i] == x or b[i] == x) g++;
            }
            if (g == 1 or n == 1) {
                cout << "Ayush" << nn;
                continue;
            }
            cout << ((n % 2) ? "Ashish" : "Ayush") << nn;
        }
        return 0;
    }