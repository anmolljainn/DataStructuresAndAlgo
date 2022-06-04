class Solution {
public:
    bool isPalindrome(int x) {
        string tmp = to_string(x);
        string tmp1 = tmp;
        reverse(tmp.begin(),tmp.end());
        return tmp==tmp1;
    }
};