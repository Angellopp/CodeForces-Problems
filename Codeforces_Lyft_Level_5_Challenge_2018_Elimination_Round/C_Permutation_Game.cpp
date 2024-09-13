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
            int n;
            cin >> n;
            vector<int> v(n);
            vector<char> dp(n+1, 'B');
            vector<int> pos(n+1);
            
            readv(v, n);
            for (int i = 0; i < n; i++) pos[v[i]] = i+1;  

            for (int i = n; i >= 1; i--) {
                for (int j = pos[i] - i; j >= 1; j-=i) {
                    if (v[j-1] > i and dp[j] == 'B') {
                        dp[pos[i]] = 'A';
                        break;
                    }
                }
                for (int j = pos[i] + i; j <= n; j+=i) {
                    if (v[j-1] > i and dp[j] == 'B') {
                        dp[pos[i]] = 'A';
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                cout << dp[pos[v[i]]];
            }
            cout << nn;

        }
        return 0;

    }


