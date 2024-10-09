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
    int ans = 0;
    for (int i = 0; i < 12 ; i++) {
        cin >> s;
        if(s.size() == i+1) ans++;
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