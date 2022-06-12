class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> st;
        int l=0,r=0,curr=0,mx=INT_MIN;
        while(l<n && r<n){
            if(r<n){
                if(st.find(nums[r])!=st.end()){
                    mx=max(mx,curr);
                    curr-=nums[l];
                    st.erase(nums[l++]);
                }else{
                    curr+=nums[r];
                    st.insert(nums[r]);
                    r++;
                }
            }
            else{
                curr-=nums[l++];
                mx=max(mx,curr);
            }
        }
        return mx=max(mx,curr);
    }
};