int divide(int dividend, int divisor){
    if(dividend == 0)
        return 0;
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if(dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    if(dividend == INT_MIN && divisor == INT_MAX)
        return -1;
    if(dividend == divisor)
        return 1;
    if(divisor == INT_MIN)
        return 0;
    int sum1 = 0,t1 = 0;
    int sum2 = 0,t2 = 0;
    int sum3 = 0,t3 = 0;
    int res = 0;
    bool flag = (dividend ^ divisor) < 0;
    int result = 0;
    if(dividend == INT_MIN){
        dividend += abs(divisor);
        result++;
    }
    int t = abs(dividend);
    int d = abs(divisor);
    for(int i = 31;i >= 0;i--){
        if((t >> i) >= d){
            result += 1 << i;
            t -= d << i;
        }
    }
    if(result == INT_MIN)
        return INT_MAX;
    else
        return flag ? -result : result;
    return 0;

    
}