    #include <bits/stdc++.h>
    #define ll long long
    #define F first
    #define S second
    #define nn '\n'
    #define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
    #define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
    #define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
    #define fori(ini, n) for(int i = ini; i < n; i++)
    #define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
    #define all(n) n.begin(), n.end()
    using namespace std;

    int pot(int num) {
        int ans = 0;
        while(num) {
            num >>= 1;
            ans++;
        }
        return ans-1;
    }

    const int MOD = 1e9 + 7;
    const int maxn = 1e5 + 10;
    int dp[100000][32+2]{};
    int dp2[100000][32+2]{};

    int main() {
        fast_io;
        int tt = 1;
        cin >> tt;
        while (tt--) {
            int n;
            cin >> n;
            vector <int> v(n);
            readv(v, n);
            if (n == 1) {cout << 0 << nn; continue;}

            for (int i = 0; i < 32; i++) {
                dp[0][i] = (v[0]>>i) & 1;
                dp2[n-1][i] = (v[n-1]>>i) & 1;
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 32; j++) {
                    dp[i][j] = ((v[i]>>j & 1) ? i+1 - dp[i-1][j] : dp[i-1][j]);
                    dp2[n-1-i][j] = ((v[n-1-i]>>j & 1) ? i+1 - dp2[n-i][j] :  dp2[n-i][j]);
                }
            }
            ll ans = dp2[1][pot(v[0])] + dp[n-2][pot(v[n-1])];
            for (int i = 1; i < n-1; i++) {
                int j = pot(v[i]);
                ans += (dp[i-1][j]) * 1ll * (n-i - dp2[i+1][j]);
                ans += (dp2[i+1][j]) * 1ll * (i+1 - dp[i-1][j]);
            }
            cout << ans << nn;
        }        

        return 0;
    }