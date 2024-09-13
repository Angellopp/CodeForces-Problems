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
    vector<vector<int>> ans(50);
    vector<int> v(50, 50);
    int n, aux;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        for (int j = 0; j < q; j++) {
            cin >> aux;
            if(q < v[aux]) {
                v[aux] = q;
                ans[aux].clear();
                ans[aux].push_back(i+1);
            }
            else if(q == v[aux]) {
                ans[aux].push_back(i+1);
            }
        }
    }
    int t;
    cin >> t;
    cout << ans[t].size() << endl;
    for (auto x: ans[t]) cout << x << " ";
    cout << endl;
    
    
}