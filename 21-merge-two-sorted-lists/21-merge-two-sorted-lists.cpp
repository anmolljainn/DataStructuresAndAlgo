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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        ListNode *it1=list1,*it2=list2;
        while(it1!=NULL && it2!=NULL){
            if(it1->val < it2->val){
                temp->next=it1;
                it1=it1->next;
            }else{
                temp->next=it2;
                it2=it2->next;
            }
            
            temp=temp->next;
        }
        while(it1!=NULL){
            temp->next=it1;
            it1=it1->next;
            temp=temp->next;
        }
        while(it2!=NULL){
            temp->next=it2;
            it2=it2->next;
            temp=temp->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
};