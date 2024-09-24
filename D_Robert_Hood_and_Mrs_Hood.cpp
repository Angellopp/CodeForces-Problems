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
    int n, d, p, x, y;
    cin >> n>> d >> p;
    vector<int> js(n + 2, 0), je(n + 2, 0);    
    for (int i = 0; i < p; i++) {
        cin >> x >> y;
        js[x]++;
        je[y+1]++;
    }
    vector<pair<int,int>> v;
    int acc = 0;
    for (int i = 1; i <= d; i++) {
        acc += js[i];
        acc -= je[i];
    }
    v.push_back({acc, 1});
    int xam = v[0].ff, nim = v[0].ff;
    for (int i = d+1; i <= n; i++) {
        acc += js[i];
        acc -= je[i-d+1];
        v.push_back({acc, i-d+1}); 
        xam = max(acc, xam);
        nim = min(acc, nim);
    }
    for (int i = 0; i < v.size(); i++) {
        if(v[i].ff == xam) {cout << v[i].ss << " ";  break;}
    }
    for (int i = 0; i < v.size(); i++) {
        if(v[i].ff == nim) {cout << v[i].ss << endl;  break;}
    }
}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

