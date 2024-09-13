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

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < n; i++) {
        int a, b,c ;
        cin >> a >> b >> c;
        if((a + b + c )% 9) {
            cout << "NO\n";
            continue;
        }
        int d = (a+b+c) / 9;
        if(d > min(a,min(b,c))){
            cout << "NO\n";
            continue;
        }       
        cout << "YES\n";
    }
}
