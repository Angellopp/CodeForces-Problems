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

vector <vector<int>> resp(n+1), ans(n+1);

int solve(int ind) {
    
    return
}

int main() {
    fastio;
    int n;
    cin >> n;
    vector <int> v(n), aux;
    set <int> s;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }
    for (auto x : s) aux.emplace_back(x);
    
    int sz = aux.size();
    for (int i = 0; i < n; i++){
        int it = find(all(aux), v[i]) - aux.begin();
        ans[it].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        
        int mn = sz-1-i+1, mx;
        
        // while () {
        //   solve(sz-1-i+1);
        // }
        // for (int j = aux.size()-1; j >= aux.size()-1 -i+1; j--) {
        //     resp[i].emplace_back(ans[j][0]);
        // }
    }
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    
    int q;
    cin >> q;
    
}