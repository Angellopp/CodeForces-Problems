




















#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

const int maxn = 1e5+3;

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n>> m >> k;
        string aux;
        cin >> aux;
        string s = 'L' + aux + 'L';
        n+=2;
        vector <pair<bool,int>> dp(n+3);
        dp[0] = {1,0};

        for (int i = 1; i < n; i++) {
            if (s[i] == 'C') continue;
            if (s[i] == 'L') {
                bool can = 0;
                int minnado = k+3;
                for (int j = 1; j <= m and i-j >= 0; j++) {
                    if(dp[i-j].F == 0) continue;
                    if(s[i-j] == 'L') {
                        can = 1;
                        minnado = min(minnado, dp[i-j].S);
                    }
                    if (s[i-j] == 'W' and j == 1 and (minnado <= k or minnado == k+3)) {
                        can = 1;
                        minnado = min(minnado, dp[i-j].S);
                        // cout << "aqui " << minnado << endl;
                    }
                }
                if(can and minnado <= k) dp[i] = {1, minnado};
                else dp[i] = {0, k+3};

            }
            if(s[i] == 'W') {
                bool can = 0;
                int minnado = k+3;
                for (int j = 1; j <= m and i-j >= 0; j++) {
                    if(dp[i-j].F == 0) continue;
                    if(s[i-j] == 'L') {
                        can = 1;
                        minnado = min(minnado, dp[i-j].S+1);
                    }
                    if (s[i-j] == 'W' and j == 1 and(minnado < k or minnado == k+3)) {
                        can = 1;
                        minnado = min(minnado, dp[i-j].S+1);
                    }
                }
                if(can and minnado <= k) dp[i] = {1, minnado};
                else dp[i] = {0, k+3};
            }
            
        }
        // for (int i = 0; i < n; i++) {
        //     cout << i << ":" << dp[i].F << " " << dp[i].S << endl;
        // }
        cout << ((dp[n-1].F) ? "YES\n" : "NO\n");

    }
}
