class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alp(26, 0);
        for(char c: magazine){
            alp[c - 'a']++;
        }
        for(char c: ransomNote){
            alp[c - 'a']--;
            if(alp[c-'a'] < 0) return false;
        }
        return true;
    }
};