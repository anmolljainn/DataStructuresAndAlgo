class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[1]>b[1]) return true;
        return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int res = 0;
        for(auto &it:boxTypes){
            if(truckSize>0){
            if(it[0]<=truckSize){
                res+=(it[0]*it[1]);
                truckSize-=it[0];
            }else{
                res+=(truckSize * it[1]);
                truckSize = 0;
            }
        }
    }
        return res;
    }
};