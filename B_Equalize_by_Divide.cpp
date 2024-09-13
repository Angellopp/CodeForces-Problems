#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long 
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

bool eq(vector <pair<int,int>>& v) {
    int e = v[0].F, n = v.size();
    for (int i = 1; i < n; i++) {
        if(v[i].F != e) return 0;
    }
    return 1;
}

int maxn = 500+4;
void solve() {
    int n, aux;
    cin >> n;
    vector <pair<int,int>> v;
    bool uno = 1, can = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.emplace_back(aux, i);
        if(aux != 1) uno = 0;
        if(aux == 1) can = 1;
    }
    if(n == 1) {cout << 0 << endl; return;} 
    if(can) {
        if(uno) cout << 0 << endl;
        else cout << -1 << endl;
        return;
    }
    sort(all(v));
    vector <pair<int,int>> ans;
    while(!eq(v)) {
        int e = v[0].F;
        for (int i = 1; i < n; i++) {
            if(v[i].F != e) {
                v[i].F = (v[i].F + e - 1) / e;
                ans.emplace_back(v[i].S+1, v[0].S+1);
            }
        }
        sort(all(v));
    }
    cout << ans.size() << endl;
    for (auto x : ans){
        cout << x.F << " " << x.S << endl;
    }



}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}




// 9
// 4 2
// 2 1
// 1 2
// 1 2
// 3 2
// 3 2
// 1 4
// 2 4
// 3 4

// 19 40 19 55
// 19 40 19 2
// 19  3 19 2
//  7  3 19 2
//  3  3  7 2
//  3  3  3 2
//  2  2  2 2