class Solution {
public:
    string reverseWords(string s) {
        int st=0,en=0;
        while(en<=s.size()){
            if(en==s.size()){
                reverse(s.begin()+st,s.end());
            }
            else if(s[en]==' '){
                reverse(s.begin()+st,s.begin()+en);
                st=en+1;
            }
            en++;
        }
        return s;
    }
};