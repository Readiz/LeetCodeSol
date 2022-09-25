
const int MIN = 0x80000000;

int divide(int dividend, int divisor){
    long long r = (long long) dividend / divisor;
    printf("%lld", r);
    if (r >= 0x7FFFFFFF) return 0x7FFFFFFF;
    if (r <= MIN) return MIN;
    return r;
}