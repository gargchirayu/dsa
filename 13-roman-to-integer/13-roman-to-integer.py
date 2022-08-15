class Solution:
    def rtoi(self, s: str) ->int:
        if s[0]=='I':
            if len(s)>1 and s[1]=='V':
                return 4
            if len(s)>1 and s[1]=='X':
                return 9
            return 1
        if s=='V':
            return 5
        if s=='X':
            if len(s)>1 and s[1]=='L':
                return 40
            if len(s)>1 and s[1]=='C':
                return 90
            return 10
        if s=='L':
            return 50
        if s=='C':
            if len(s)>1 and s[1]=='D':
                return 400
            if len(s)>1 and s[1]=='M':
                return 900
            return 100
        if s=='D':
            return 500
        if s=='M':
            return 1000
        
        
    def romanToInt(self, s: str) -> int:
        ans = 0
        i=0
        while i<len(s):
            if s[i]=='I':
                if i<len(s)-1 and s[i+1]=='V':
                    ans+= 4
                    i+=1
                elif i<len(s)-1 and s[i+1]=='X':
                    ans+= 9
                    i+=1
                else:
                    ans+= 1
            elif s[i]=='V':
                ans+= 5
            elif s[i]=='X':
                if i<len(s)-1 and s[i+1]=='L':
                    ans+= 40
                    i+=1
                elif i<len(s)-1 and s[i+1]=='C':
                    ans+= 90
                    i+=1
                else:
                    ans+= 10
            elif s[i]=='L':
                ans+= 50
            elif s[i]=='C':
                if i<len(s)-1 and s[i+1]=='D':
                    ans+= 400
                    i+=1
                elif i<len(s)-1 and s[i+1]=='M':
                    ans+= 900
                    i+=1
                else:
                    ans+= 100
            elif s[i]=='D':
                ans+= 500
            elif s[i]=='M':
                ans+= 1000
            else:
                ans+=0
            i+=1
            #print(ans)
        return ans
        