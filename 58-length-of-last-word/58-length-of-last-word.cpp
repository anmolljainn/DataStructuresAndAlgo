class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int st = n-1,en = n-1;
        while(st>=0 && s[st]==' '){
            st--;
        }
        en = st;
        while(en>=0 && s[en]!=' '){
            en--;
        }
        
        if(en == 0){
            return st;
        }
        
        return st-en;
    }
};