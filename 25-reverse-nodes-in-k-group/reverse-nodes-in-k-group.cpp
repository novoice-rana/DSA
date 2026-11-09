class Solution {
public:

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    void reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* kthNode = getKthNode(temp, k);

            // If fewer than k nodes remain
            if (kthNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            // Store next group's starting node
            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = NULL;

            // Reverse current group
            reverseLinkedList(temp);

            // Update head or connect previous group
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevLast->next = kthNode;
            }

            // Update pointers
            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};