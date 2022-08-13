class Solution {
private:
    //size of both array
    int n, w;
    //size of each word
    int k;
    //size of valid substring
    int ss;
    unordered_map<string, int> wm;
    
    void helper(int start, string s, vector<int> &res){
        unordered_map<string, int> sm;
        int wctr=0;
        bool extra = false;
        
        for(int i=start; i<=s.size()-k; i+=k){
            string temp = "";
            for(int j=0; j<k; j++){
                temp += s[i+j];
            }
            if(wm.find(temp) == wm.end()) {
                sm.clear();
                wctr = 0;
                extra = false;
                start = i+k;
            } else {
                while(i-start == ss or extra){
                    string first = "";
                    for(int j=start; j<start+k; j++){
                        first += s[j];
                    }
                    start += k;
                    sm[first]--;
                    if(sm[first]>=wm[first]) extra = false;
                    else wctr--;
                }
                sm[temp]++;
                if(sm[temp]<=wm[temp]) wctr++;
                else extra = true;
                
                if(wctr == w and !extra) res.push_back(start);
            } 
        }
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size();
        w = words.size();
        k = words[0].size();
        ss = w*k;
        vector<int> res;
        if(k>n) return res;
        for(string s : words){
            wm[s]++;
        }
        for(int i=0; i<k; i++){
            helper(i, s, res);
        }
        return res;
    }
};