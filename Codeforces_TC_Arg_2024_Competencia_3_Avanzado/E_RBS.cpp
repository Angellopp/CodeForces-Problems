




















#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

pair<bool, int> f(string& cadena) {
    int ans = 0;
    stack<char> pila;
    for (char c : cadena) {
        if (c == '(') pila.push(c);
        else {
            if (!pila.empty() && pila.top() == '(') {
                pila.pop();
                if(pila.empty()) ans++;
            }
            else return {0, ans};
        }
    }
    return {1, ans};
}
int main() {
    fastio;
    int n;
    cin>> n;
    vector <string> ss(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        auto aa = f(ss[i]);
        if(aa.F) ans += aa.S;
    }
    cout << ans << endl;


}
