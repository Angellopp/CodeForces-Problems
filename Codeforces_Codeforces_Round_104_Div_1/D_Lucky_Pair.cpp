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

int isluc(int num) {
    while (num) {
        if (num % 10 != 4 and num % 10 != 7) return false;
        num /= 10;
    }
    return true;
}

int dpt[100000]{};

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        readv(v, n);
        printv(v);
        for (int i = 2; i < 100; i++) {
            dpt[i] = 2 * dpt[i-1] + i * (i-1) / 2; 
        }
        for (int i = 1; i < 100; i++) cout << dpt[i] << " "; cout << endl;
    }        

    return 0;
}