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

int pow(int a) {
    if(a <= 0) return 0;
    int ans = 0;
    while(a) {
        ans+=a%10;
        a/=10;
    }
    return ans;
}

int main() {
    fastio;
    int n;
    cin >> n;
    cout << pow(n);
}