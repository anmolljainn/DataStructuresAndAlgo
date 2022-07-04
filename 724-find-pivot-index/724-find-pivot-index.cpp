class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        for(int it=0;it<nums.size();it++){
            if(2*leftSum == sum-nums[it]){
                return it;   
            }
            leftSum+=nums[it];
        }
        return -1;
    }
};