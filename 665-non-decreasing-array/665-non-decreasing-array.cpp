class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int idx=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(idx!=-1){
                    return false;
                }
                idx=i;
            }
        }
        return idx==-1 || idx==0 || idx==nums.size()-2 || nums[idx-1]<=nums[idx+1] || nums[idx]<=nums[idx+2];
    }
};