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

    const int MOD = 1e9 + 7;
    const int maxn = 1e5 + 10;

    ll dp[300000 + 5];
    void fill() {
        dp[0] = 1;
        dp[1] = 1;
        fori(2, 300000+5) {
            dp[i] = (dp[i-1] + 2 * dp[i-2] * (i-1)) % MOD;
        }
    } 


    int main() {
        fast_io;
        int tt = 1;
        cin >> tt;
        fill();
        while (tt--) {
            int n, k, x1, x2;
            cin >> n >> k;
            int fil = n;
            while(k--) {
                cin >> x1 >> x2;
                fil--;
                if (x1 != x2) fil--; 
            }
            cout << dp[fil] << nn;

        }
        // f(n) = f(n-1) + 2 * f(n-2) * (n-1)
        
        return 0;
    }