class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(string word : words){
            string cur = "";
            for(char c:word){
                cur += code[c-'a'];
            }
            ans.insert(cur);
        }
        return ans.size();
    }
};