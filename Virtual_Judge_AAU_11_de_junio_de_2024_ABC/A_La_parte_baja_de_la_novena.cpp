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
    int sum = 0, aux;
    for (int i = 0; i < 9; i++) {
        cin >> aux;
        sum += aux;
    }
    for (int i = 0; i < 8; i++) {
        cin >> aux;
        sum -= aux;
    }
    cout << sum+1 << "\n";
}