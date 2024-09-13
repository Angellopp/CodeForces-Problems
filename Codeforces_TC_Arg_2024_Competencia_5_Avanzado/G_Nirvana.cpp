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

const int N = 2e5 + 101;

int p(int n) {
    int ans = 1;
    while(n) {
        ans *= n % 10;
        n/=10;
    }
    return ans;
}
int f(int n) {
    if(n == 0) return 1;
    if(n < 10) return n;
    int aux = p(n);
    int d = n % 10 + 1;
    n -= d;
    return max(aux, 9 * f(n / 10));
}


int main() {
    int n;
    cin >> n;
    cout << f(n) << endl; 
}
