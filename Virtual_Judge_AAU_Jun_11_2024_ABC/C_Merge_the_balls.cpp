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
    int n;
    cin>>n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector <ll> ans;
    for (int i = 0; i < n; i++) {
        ans.emplace_back(v[i]);
        int ss = ans.size();
        while (ans.size() > 1 and ans[ss-1] == ans[ss-2]) {
            int aux = ans[ss-1];
            ans.pop_back();
            ans.pop_back();
            ans.emplace_back(aux+1);
            ss = ans.size();
        }
    }
    cout << ans.size()<<"\n";

}