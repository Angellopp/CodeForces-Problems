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

    int max_primo(int n) {
        int ans = n;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0 and n != i) {
                n /= i;
                ans = n;
            }
        }
        return ans;
    }

    int main() {
        fast_io;
        int tt = 1;
        // cin >> tt;
        while (tt--) {
            int n;
            cin >> n;
            
            int ans = INF;
            for (int i = n - max_primo(n) + 1; i <= n; i++) {
                int mp = max_primo(i);
                int mn = ((mp != i) ? i - mp + 1 : mp);
                ans = min(mn, ans);
            }

            cout << nn << ans << nn;
        }
        return 0;
    }