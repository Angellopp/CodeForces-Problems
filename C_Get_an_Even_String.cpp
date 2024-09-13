#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
void solve() {
    string s;
    cin >> s;
    int xd = 0;
    int n = s.size();
    vector<bool> dp(26, 0);
    for(int i = 0; i < n; i++){
        if(dp[s[i] - 'a']){
            xd += 2;
            for(int j = 0; j < 26; j++) {
                dp[j] = 0;
            }
        }
        else dp[s[i] - 'a'] = 1;
    }

    cout << n - xd << endl;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}