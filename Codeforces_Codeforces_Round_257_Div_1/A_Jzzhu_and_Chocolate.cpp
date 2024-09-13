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
        // cin >> tt;
        while (tt--) {
            ll n, m, k;
            cin >> n >> m >> k;
            if (n + m - 2 < k) {cout << -1 << nn; continue;}
            ll infm = max(1LL*0, k-n+1);
            ll infn = max(1LL*0, k-m+1);
            ll ans1 = m / (infm + 1) * (n / (k - infm + 1));
            ll ans2 = n / (infn + 1) * (m / (k - infn + 1));
            cout << max(ans1, ans2) << nn;
        }
        return 0;

    }


