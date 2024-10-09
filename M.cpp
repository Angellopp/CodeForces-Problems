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
    int n;
    cin >> n;
    vector <int> v(n);
    int s = 0, sl = 0, sr = 0;  
    for (int i = 0; i <n ; i++) {cin >> v[i]; s += v[i];}
    for (int i = 1 ; i+1 < n; i++) {
        sl += v[i-1];
        sr = s - v[i] - sl;
        if(sl == sr) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << "A cadeira, usa a cadeira!" << endl;
}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

