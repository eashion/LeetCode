class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        long long nume = numerator;
        long long deno = denominator;
        if( (nume<0&&deno>0) || (nume>0&&deno<0) ){
            res += "-";
        }
        nume = abs(nume);
        deno = abs(deno);
        long long quotient = 0;
        long long remainder = 0;
        map<long long,int> mm;
        remainder = nume%deno;
        quotient = nume/deno;
        nume = remainder;
        res += to_string(quotient);
        if( nume != 0 ){
            res += ".";
        }
        int pos = res.length();
        while( nume != 0 ){
            nume *= 10;
            remainder = nume%deno;
            quotient = nume/deno;
            if( mm[nume] != 0 ){
                res += ")";
                res.insert(mm[nume],"(");
                break;
            }
            else{
                mm[nume] = pos++;
            }
            nume = remainder;
            res += to_string(quotient);
        }
        return res;
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) { 
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }
};
