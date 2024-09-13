




















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

const int maxn = 55;
string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = "What are you doing while sending \"";
string c = "\"? Are you busy? Will you send \"";
string d = "\"?";
int sa = a.size();
int sb = b.size();
int sc = c.size();
int sd = d.size();

vector <ull> v(maxn);
char f(int n, ll pos) {
    if (n == 0) {
        if(pos < sa) {
            return a[pos];
        }
        else return '.';
    }
    if (pos < sb) {
        // dbg("me fui a la parte B");
        return b[pos];
    }
    if (n > 54) {
        return f(n-1, pos-sb);
    }
    else {
        if (pos < sb + v[n-1]) {
            // dbg("me fui a la parte Fn-1(1)");
            return f(n-1, pos - sb);
        }
        else {
            if(pos < sb + v[n-1] + sc) {
            // dbg("me fui a la parte C");
                return c[pos - v[n-1] - sb];
            }
            else {
                if (pos < sb + v[n-1] + sc + v[n-1]) {
                    // dbg("me fui a la parte Fn-1(2)");
                    return f(n-1, pos - sb - v[n-1] - sc);
                }
                else {
                    if (pos < sb + v[n-1] + sc + v[n-1] + sd) {
                        // dbg("me fui a la parte D");
                        return d[pos - v[n-1] - sb - sc - v[n-1]];
                    }
                    else return '.';
                }
            }
        }
    }
}

int main() {
    fastio;
    int q;
    cin >> q;
    // dbg(a.size());
    v[0] = sa;
    for (int i = 1; i < maxn; i++) {
        v[i] = sd + sb + sc + 2 * v[i-1];
    }
    // dbg(v[1]);
    // for (int i = 1; i < maxn; i++) {
    //     cout << i << ": " << v[i] << endl;
    // }
    while (q--) {
        ll n, pos;
        cin >> n >> pos;
        // cout << pos << " : " << f(n, pos-1) << endl;
        cout << f(n, pos-1);
    }

}
