class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];
        int currSum = 0, mxSum = INT_MIN;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            mxSum=max(mxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return mxSum;
    }
};