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

ll pow(int a, int b) {
    ll ans = 1;
    for (int i = 0; i < b; i++) ans *= a;  
    return ans;
}

int main() {
    fastio;
    string s;
    while(cin >> s) {
        int ans = 0, a = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '+') ans++;
            else ans--;
            a = max(abs(ans), a); 
        }
        cout << a << "\n";
    }
}