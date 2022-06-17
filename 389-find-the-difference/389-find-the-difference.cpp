class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<s.size();i++){
            freq1[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            freq2[t[i]-'a']++;
        }
        
        for(int i=0;i<t.size();i++){
            if(freq1[t[i]-'a']!=freq2[t[i]-'a']) return t[i];
        }
        
        return 'a';
    }
};