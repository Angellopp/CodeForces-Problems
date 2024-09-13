#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

const int mod = 32768;
vector <int> dp(mod+10);
vector <bool> vis(mod+10);

void solve() {
    int n, xd;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> xd;
        cout << dp[xd] << " ";
    }
    cout << endl;

}

int n2(int n) {
    int ans = 0;
    while(n%2==0){n>>=1; ans++;}
    return ans;
}
int main() {
    fast_io;
    int tt=1;
    dp[0] = 0;
    for (int i = 1; i < mod; i++) {
        int xd = 100;
        for(int j = 0; j <= 15; j++) {
            xd = min(xd, j + 15 - n2(i+j));
        }
        dp[i] = xd;
    }
    while(tt--){
        solve();
    }
}