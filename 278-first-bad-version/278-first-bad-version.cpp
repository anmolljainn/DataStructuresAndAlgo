// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1,e = n;
        int mn = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isBadVersion(mid)){ 
                mn=min(mn,mid);
                e=mid-1;
            }
            else s=mid+1; 
        }
        
        return mn;
    }
};