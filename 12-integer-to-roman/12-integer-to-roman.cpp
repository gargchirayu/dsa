class Solution {
public:
    string intToRoman(int num) {
        string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        for(int i=0; num!=0; i++){
            while(num >= n[i]){
                ans += rom[i];
                num -= n[i];
            }
        }
        return ans;
    }
};