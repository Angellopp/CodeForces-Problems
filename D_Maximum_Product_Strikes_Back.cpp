#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
vector <int> v((int)2e5);
int n;
pair<int,pair<int,int>> f(int ini, int fin) {
    if(ini == fin) {
        if(v[ini] < 0) return{0, {ini+1,fin}};
    }
    int m = 1, n2 = 0;
    for (int i = ini; i <= fin; i++) {
        if(v[i] < 0) m*=-1;
        if(abs(v[i]) == 2) n2++;
    }
    if(m > 0) return {n2, {ini, fin}};
    // dbg(n2);
    int l2 = 0, r2 = 0;
    int l = ini, r = fin;
    for (l; l <= fin; l++) {
        if(abs(v[l]) == 2) l2++; 
        if(v[l] < 0) {l++; break;}
    }
    for (r; r >= ini; r--) {
        if(abs(v[r]) == 2) r2++;
        if(v[r] < 0) {r--; break;}
    }
    // dbg(l2);
    // dbg(r2);
    // dbg(l);
    // dbg(r);
    if(l2 < r2) return {n2-l2 ,{l, fin}};
    else return {n2-r2, {ini, r}};

}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    vector <pair<int,int>> p;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if(v[i] == 0) {
            if(i != 0) {p.emplace_back(k, i-1);}
            k=i+1;
        }
    }
    p.emplace_back(k, n-1);
    pair<int,pair<int,int>> ans;
    ans.F = -1;
    for (auto i : p) {
        pair<int,pair<int,int>> xd = f(i.F, i.S);
        if(xd.F > ans.F) {
            ans = xd;
        }
    }
    cout << ans.S.F << " " << n - ans.S.S - 1 << endl;


}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}