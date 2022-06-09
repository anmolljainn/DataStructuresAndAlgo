class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        vector<int> res;
        int st=0,en=n-1;
        while(st<en){
            if(numbers[st]+numbers[en]==target){
                res.push_back(st+1);
                res.push_back(en+1);
                return res;
            }
            else if(numbers[st]+numbers[en]<target){
                st++;
            }
            else{
                en--;
            }
        }
        return res;
    }
};