string Solution::fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return "0";
    long long int n = numerator, d = denominator;
    string res = "";
    
    if (n < 0 ^ d < 0)      //Brilliant
        res += '-';
    
    n = abs(n), d = abs(d);
    
    res += to_string(n/d);
    long long int rem = n%d;
    
    if (rem == 0)
        return res;
    
    res += '.';
    
    unordered_map<int, int> m;
    
    while(rem)
    {
        if (m.find(rem) != m.end())
        {
            res.insert(m[rem], 1, '(');
            res.push_back(')');
            break;
        }
        
        m[rem] = res.size();
        rem *= 10;
        res.push_back('0' + rem/d);
        rem %= d;
    }
    return res;}
