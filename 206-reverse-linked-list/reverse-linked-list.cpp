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
    ListNode* reverseList(ListNode* head) {
    //     //iterative approach 
    //     ListNode* temp =head;
    //    ListNode* prev=NULL;
    //     while(temp!=NULL){
    //        ListNode* front= temp->next;
    //         temp->next =prev;
    //         prev=temp;
    //         temp=front;

    //     }
    //     return prev;
        // recursive approach 
        

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Reverse the remaining linked list
        ListNode* newNode = reverseList(head->next);

        // Reverse the current connection
        ListNode* front = head->next;
        front->next = head;

        // Break the old connection
        head->next = NULL;

        return newNode;
        

        
    }
};