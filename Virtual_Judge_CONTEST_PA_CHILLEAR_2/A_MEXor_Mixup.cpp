#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;


int main() {
    fastio;
    int tt;
    cin >> tt;
    vector <int> pre(1000000);
    pre[0] = 0;
    for (int i = 1; i <= 1000000; i++) {
        pre[i] = pre[i-1] ^ i;
    }
    while(tt--) {
        int a, b;
        cin >> a >> b;
        int xx = pre[a-1];
        // cout << xx << " ga";
        int aux = xx ^ b;
        if(aux != a) {
            if(xx == b) {
                cout << a << "\n";
            }
            else {
                cout << a + 1 << "\n";

            }
        }
        else {
            cout << a+2 << "\n";
        }
    }



}