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
const int INF = 1e9;


void solve() {
    int h, m, s;
    cin >> h >> m >> s;
    cout << "00:00" << endl; 
    for (int i = 1; i < h; i++) {
        int l = (m*i-h + (h-1-1))/(h-1);
        int r = i*m/(h-1);
        if(l > r or r == m) continue;
        if(i < 10) cout << "0" << i;
        else cout << i;
        cout << ":";
        if(l < 10) cout << "0" << l;
        else cout << l;
        cout << endl;
    }
}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

