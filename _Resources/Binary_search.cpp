// Binary search.cpp

bool f(int n){
    // do something
}

// Primer f() = 0
// 1 1 1 1 ... 1 |0| 0 .... 0
int lower_bound(int i, int n){
    int lo = i;
    int hi = n; 
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(f(mid)) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

// Ultimo f() = 1
// 1 1 1 1 ... |1| 0 0 .... 0
int upper_bound(int i, int n){
    int lo = i;
    int hi = n;
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(f(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}