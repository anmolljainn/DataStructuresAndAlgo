class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=0;
        while(high<n){
            if(nums[high]==0) high++;
            else{
                //swap
                int temp = nums[high];
                nums[high]=nums[low];
                nums[low]=temp;
                high++;low++;
            }
        }
    }
};