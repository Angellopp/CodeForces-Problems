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
using namespace std;

int main() {
    fastio;
    int n, x1, x2;
    cin >> n;
    vector <pair<int,int>> par, imp;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        int xd1 = (x1-x2) / 2, xd2 = (x1+x2) / 2; 
        if((x1 + x2) % 2) {
            // x1++; x2++;
            imp.push_back({(x1-x2+1) / 2, (x1+x2+1) / 2});
        }
        else par.push_back({xd1, xd2});
    }
    // sort(all(par));
    int n1 = par.size(), n2 = imp.size();
    vector <int> xpar, ypar, ximpar, yimpar;
    for (int i = 0; i < n1; i++) {
        xpar.emplace_back(par[i].F);
        ypar.emplace_back(par[i].S);
    }
    sort(all(xpar));
    sort(all(ypar));
    // dbg(n1);
    ll dx = 0, dy = 0;
    for (int i = 1; i < n1; i++) {
        dx += 1ll * i * xpar[i];
    }
    for (int i = 0; i+1 < n1; i++) {
        dx -= 1ll * (n1-i-1) * xpar[i];
    }
    for (int i = 1; i < n1; i++) {
        dy += 1ll * i * ypar[i];
    }
    for (int i = 0; i+1 < n1; i++) {
        dy -= 1ll * (n1-i-1) * ypar[i];
    }
    // dbg(dx);
    // dbg(dy);
    for (int i = 0; i < n2; i++) {
        ximpar.emplace_back(imp[i].F);
        yimpar.emplace_back(imp[i].S);
    }
    sort(all(ximpar));
    sort(all(yimpar));

    ll dx2 = 0, dy2 = 0;
    // for (auto x : par) {
    //     // cout << x.first << " " << x.second << " \n";
    //     dx2 += 1ll * 
    // }
    for (int i = 1; i < n2; i++) {
        dx2 += 1ll * i * ximpar[i];
    }
    for (int i = 0; i+1 < n2; i++) {
        dx2 -= 1ll * (n2-i-1) * ximpar[i];
    }
    for (int i = 1; i < n2; i++) {
        dy2 += 1ll * i * yimpar[i];
    }
    for (int i = 0; i+1 < n2; i++) {
        dy2 -= 1ll * (n2-i-1) * yimpar[i];
    }
    
    // dbg(dy2);
    cout << dx + dy + dx2 + dy2 << "\n"; 
}