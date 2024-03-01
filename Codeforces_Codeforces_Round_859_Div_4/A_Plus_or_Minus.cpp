#include <iostream>

using namespace std;

int main() {
    int tt, a, b, c; 
    cin >> tt;
    while (tt--){
        cin >> a >> b >> c;
        (a+b == c) ? cout << "+\n" : cout << "-\n";
    }
    return 0;
}