

int mySqrt(int x){
    long lo = 1, hi = x;
    while (lo <= hi) {
        long mid = (hi - lo) / 2 + lo;
        mid*mid <= x ?
            (lo = mid + 1) :
            (hi = mid - 1);
    }
    return --lo;
}