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
#define double long double
using namespace std;

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        int n, aux;
        cin >> n;
        multiset <pair<int,int>> v;
        vector <pair<int,int>> ans;

        for(int i = 0; i < n; i++) {
            cin >> aux;
            v.insert({aux, i});
        }
        
        for (int x = n-1; x >= 1; x--) {
            vector <vector<int>> mp(n+1);

            for(auto y : v) mp[(y.F%x)].emplace_back(y.F);
            
            for(auto y : mp) {
                if (y.size() > 1) {
                    int a = y.back();
                    int b = y[0];
                    auto jj = v.lower_bound({b, 0});
                    int aux1 = jj->second;
                    v.erase(jj);
                    auto ii = v.lower_bound({a, 0});
                    ans.emplace_back(ii->second+1, aux1+1);
                    break;
                }
            }
        }
        cout << "YES\n";
        for (int i = n-2; i >= 0; i--) cout << ans[i].F << " " << ans[i].S << endl;
    }
    return 0;
}