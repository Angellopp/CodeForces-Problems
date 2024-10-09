#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;


// const int MAXN = 2e5+5; 
// int dif[MAXN]{};

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i+1 < 26 ; i++) {
        int idx1 = 0, idx2 = 0;
        for (int j = 0; j < 26; j++) if(s[j] == 'A' + i) idx1 = j;
        for (int j = 0; j < 26; j++) if(s[j] == 'A' + i+1) idx2 = j;
        ans += abs(idx1 - idx2);
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}