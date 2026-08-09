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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* current = head;
        while (current){
            count++;
            current = current->next;
        }
        cout << "the current count is" << count;
        if (count == 1){
            head = nullptr;
            return head;
        } 
        if (count - n == 0){
            return head->next;
        }
        int countFromBeggining = count - n;
        int newCount = 0;
        current = head;
        ListNode* prev = nullptr;
        while (newCount < countFromBeggining){
            newCount++;
            prev = current;
            current = current->next;
        }
        // now we remove current from list
        ListNode* temp = current->next;
        prev->next = temp;
        current->next = nullptr;
        return head;
    }
};
