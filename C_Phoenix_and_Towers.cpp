#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int MAXN = 1e5+5;

void solve() {
    int n, m, x, aux;
    cin >> n >> m >> x;
    vector<int> v(n);
    set<pair<int,int>> s;
    for (int i = 0; i < m; i++) {
        s.insert({0, i+1});
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cin >> aux;
        int num = s.begin()->first, idx = s.begin()->second;
        cout << idx << " ";
        s.erase(s.begin());
        s.insert({num + aux, idx});
    }
    cout << endl;
    
}


int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

