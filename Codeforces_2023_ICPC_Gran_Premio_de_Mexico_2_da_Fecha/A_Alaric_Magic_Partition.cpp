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

int fact[1000]{};

int pow(int i, int k) {
    int ans = 1;
    for (int j = 0; j < k; j++){
        ans *= i;
    }
    return ans;
}

int main() {
    fastio;
    int n = 10, k = 2;
    fact[0] = fact[1] = 1;
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i-1] + fact[i-2];
    }
    for (int i = 1; i <= 10; i++) {
        ll ans = 0;
        for (int j = 0; j < i; j++) {
            ans += pow(fact[j],k);
        }
        dbg(ans);
    }
    

    return 0;
}