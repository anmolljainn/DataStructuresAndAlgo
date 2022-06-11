class Solution {
public:
    int subtractProductAndSum(int n) {
        int prdct=1,sum=0;
        while(n>0){
            int ld = n%10;
            prdct*=ld;
            sum+=ld;
            n/=10;
        }
        return prdct-sum;
    }
};