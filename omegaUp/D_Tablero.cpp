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
    int nn;
    vector <pair<int,int>> v(100+1);
    v[1] = {1,1}; 
    for (int i = 2; i <= 100; i++) {
        v[i].F = v[i-1].F + i * i;
        v[i].S = i * i * (i+1) * (i+1) / 4;
    }
    while(cin >> nn) {
        cout << v[nn].F << " " << v[nn].S << "\n";
    }
}