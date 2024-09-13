#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, l;
    long long sum = 0;
    cin >> n >> l;
    vector <int> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
    }
    ll op = 1; 
    for (int i = l-1; i >= 0; i--) {
        sum += a[i] * op;
        op *= -1;
    }
    sum = ((sum % (n+1)) + n+1) % (n+1);
    // cout << sum << endl;
    bool can = 0;
    op = ((l % 2 == 1) ? 1 : -1);
    if (sum == 0) {
        cout << "0 0\n";
        return 0;
    }
    for (int i = 0; i < l; i++) {
        if(op == -1 ){
            if(n+1-sum <= a[i]) {
            cout << i+1 << " " << a[i]-n-1+sum << "\n";
            can = 1;
            break;
            }           
        }
        else {
            if(sum <= a[i]) {
                cout << i+1 << " " << a[i]-sum << "\n";
                can = 1;
                break;
            }
        }
        op *= -1;
    }
    if(!can) cout << "-1 -1\n";

    
    
}