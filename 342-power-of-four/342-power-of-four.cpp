class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        float ans = log2(n)/log2(4);
        if(ceil(ans) == floor(ans)) return true;
        else return false;
    }
};