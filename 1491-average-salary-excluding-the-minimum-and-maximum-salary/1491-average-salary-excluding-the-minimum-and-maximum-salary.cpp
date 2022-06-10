class Solution {
public:
    double average(vector<int>& salary) {
        int mx=0,mn=INT_MAX;
        double sm = 0;
        for(int i =0;i<salary.size();i++){
            mx=max(mx,salary[i]);
            mn=min(mn,salary[i]);
            sm+=salary[i];
        }
        sm-=(mx+mn);
        return (sm/(salary.size()-2));
    }
};