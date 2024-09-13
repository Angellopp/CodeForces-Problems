#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

// int dp[300000+5][10+1][2]{};

int f(int n, int k, int b, vector <int>&v) {
    if(dp[n][k][b] != 0) return dp[n][k][b];
    if(k == 1) return 1;
    if (n <= 3) {
        if(b == 1) {
            
        }
    }
    int v1 = f(n-1, k-1, 1, v) + abs((v[n-1] - min(v[n-2], v[n-3])));
    int v2 = f(n-1, k-1, 0, v) + abs(v[n-1] - v[n-2]);
    int v3 = f(n-1, k, 1, v) + v[n-1];
    int v4 = f(n-1, k, 0, v) + v[n-1];
    return min({v3, v4 , v1, v2});
}

int main() {
    int tt;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        readv(v, n);
        int q;
        cin >> q;
        while(q--) {
            
        }


    }
    return 0;
}