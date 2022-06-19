/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode* node){
        int cnt=0;
        while(node!=NULL){
            cnt++;
            node=node->next;
        }
        return cnt;
    }
    int getDecimalValue(ListNode* head) {
        int sz = getSize(head);
        ListNode* temp = head;
        
        int res = 0;
        while(temp!=NULL){
            int tmp = temp->val * pow(2,--sz);
            res+=tmp;
            temp=temp->next;
        }
        
        return res;
    }
};