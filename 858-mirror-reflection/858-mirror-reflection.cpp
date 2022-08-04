class Solution {
private:
    int gcd(int p, int q){
        while(q!=0){
            int temp = q;
            q = p%q;
            p = temp;
        }
        return p;
    }
public:
    int mirrorReflection(int p, int q) {
        while(p%2==0 and q%2==0){
            p=p>>1;
            q=q>>1;
        }
        if(p%2 == 0) return 2;
        if(q%2 == 0) return 0;
        else return 1;
    }
    
    // int mirrorReflection(int p, int q) {
    //     int lcm = (p*q)/gcd(p,q);
    //     //number of rooms
    //     int m = lcm/p;
    //     //number of reflections
    //     int n = lcm/q;
    //     if (n%2 == 0) return 2;
    //     if (m%2 == 1) return 1;
    //     return 0;
    // }
};