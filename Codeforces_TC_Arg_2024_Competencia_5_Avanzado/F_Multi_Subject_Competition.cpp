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
#define pto pair<int,int>
using namespace std;

const int mod = 1e8;

const int N = 1e5 + 10;

int n, m;
vector <vector<ll>> a(N);

int main() {
    int xd1, xd2;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> xd1 >> xd2;
        a[xd1].emplace_back(xd2);
    }
    for(int i = 1; i <= m; i++) {
        sort(rall(a[i]));
    }
    for(int i = 1; i <= m; i++) {
        for (int j = 1; j < a[i].size(); j++) {
            a[i][j] += a[i][j-1];
        }
    }
    // for(int i = 1; i <= m; i++) {
    //     cout << i << " : ";
    //     for (int j = 0; j < a[i].size(); j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector <ll> ans(n+1);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if(a[i][j] > 0) ans[j+1]+=a[i][j]; 
        }
    }
    ll as = 0;
    for (auto x : ans) as = max(as, x);
    cout << as << endl;
}
