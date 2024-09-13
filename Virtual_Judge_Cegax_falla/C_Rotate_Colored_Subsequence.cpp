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

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<char>> a(m+1);
    vector <int> c(m+1, 0);
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        a[v[i]].emplace_back(s[i]);
    }
    for (int i = 1; i <= m; i++) c[i] = a[i].size()-1; 
    
    for (int i = 0; i < n; i++) {
        cout << a[v[i]][c[v[i]]];
        c[v[i]] = (c[v[i]] + 1) % a[v[i]].size();
    }
}