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
    ListNode* partition(ListNode* head, int x) {
        ListNode * large = new ListNode(0);
        ListNode * small = new ListNode(0);
        ListNode * largep = large;
        ListNode * smallp = small;
        while(head!= NULL){
            if(head->val<x){
                smallp->next=head;
                smallp=smallp->next;

            }
            else{
                largep->next=head;
                largep=largep->next;
            }
            head =head->next;
        }
        smallp->next=large->next;
        largep->next=NULL;
        return small->next;
        
    }
};