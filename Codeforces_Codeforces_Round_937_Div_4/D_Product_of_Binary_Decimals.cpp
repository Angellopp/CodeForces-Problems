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

vector<int> dp;

bool comp(int x) {
    for (int y : dp) {
        while(x % y == 0) x /= y;
    }
    return (x == 1);
}

int main() {
    char aux;
    for (int i = 0; i < 21; i++) 
        for (int j = 0; j < 21; j++) {
            cin >> aux;
            cout << ((aux == '1') ? "██" : "  ");
        }
        cout << nn;
    return 0;
}