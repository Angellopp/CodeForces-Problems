#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        // vector <vector <bool>> v = {
        //     {1, 1, 1, 0, 1, 1, 1},
        //     {0, 0, 1, 0, 0, 1, 0},
        //     {1, 0, 1, 1, 1, 0, 1},
        //     {1, 0, 1, 1, 0, 1, 1},
        //     {0, 1, 1, 1, 0, 1, 0},
        //     {1, 1, 0, 1, 0, 1, 1},
        //     {1, 1, 0, 1, 1, 1, 1},
        //     {1, 0, 1, 0, 0, 1, 0},
        //     {1, 1, 1, 1, 1, 1, 1},
        //     {1, 1, 1, 1, 0, 1, 1}
        // };
        vector <int> v = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
        int n;
        cin >> n;

        int n1 = n/10;
        int n2 = n%10;
        cout << v[n1] * v[n2] << nn;
        



    




    }
    return 0;
}