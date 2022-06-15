class Solution {
public:
    int lcs( string X,string Y)  
{  
    int m = X.length();
    int n = Y.length();  
    int L[m + 1][n + 1];  
    int i, j;  
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    return L[m][n];  
}  
    
     static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),compare);
        for(int i = 1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].length()-words[j].length()==1 && lcs(words[i],words[j])==words[j].length() && dp[i]<dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};