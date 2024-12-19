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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int count = 0;
        while (curr != NULL && count != k)
        {
            curr = curr->next;
            count++;
        }
        if (count == k)
        {
            curr = reverseKGroup(curr, k);
            while (count-- > 0)
            {
                ListNode *tmp = head->next;
                head->next = curr;
                curr = head;
                head = tmp;
            }
            
            head = curr;
        }
        
        return head;
    }
};