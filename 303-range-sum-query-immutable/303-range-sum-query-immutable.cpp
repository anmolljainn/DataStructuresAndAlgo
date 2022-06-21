class NumArray {
public:
    vector<int> temp;
    vector<int> sumTilli;
    NumArray(vector<int>& nums) {
        temp=nums;
        int sum = 0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
            sumTilli.push_back(sum);
        }
        
        for(int i=0;i<sumTilli.size();i++){
            cout<<sumTilli[i]<<" ";
        }
    }
    
    int sumRange(int left, int right) {
        return sumTilli[right]-sumTilli[left]+temp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */