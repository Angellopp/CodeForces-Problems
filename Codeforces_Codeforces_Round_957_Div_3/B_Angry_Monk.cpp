




















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

const int mod = 1e8;

const int maxn = 1e5+3;

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> k >> n;
        vector <int> v(n);
        int sum = 0;
        for (int  i = 0;i  < n; i++){
            cin >> v[i];
            sum += v[i]; 
        } 
        sort(rall(v));
        sum -= v[0];
        for (int i = 1; i < n; i++){
            if(v[i] != 1) sum += v[i]-1; 
        }
        cout << sum << endl;

    }
}
