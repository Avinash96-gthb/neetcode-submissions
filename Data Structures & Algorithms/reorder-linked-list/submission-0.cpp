// expected soln path
// [0, 1, 2, 3, 4, 5, 6]
// 0->6->1
// 0->6->1->5->2
// 0->6->1->5->2->4
// 0->6->1->5->2->4->3
// assume you know head and tail
// while next != nullptr
// temp = current->next
// current->next = tail
// tail->next = temp
// tail->prev->next = nullptr
// but how do we walk backwards in singly linked list??????
// stack is 6 5 4 3 2 1 0
// so poping stack but how do we keep everything in stack so assuming
// [0, 1, 2, 3, 4, 5, 6] -> linked list
// [6, 5, 4, 3, 2, 1, 0] -> stack
// so while current exists we do
// temp = current->next
// current->next = stack(pop)
// pop value ->next temp;
// get previos value from stack
// value -> next = nullptr
// dry run
// [0, 1, 2, 3, 4, 5, 6] -> list
// [6, 5, 4, 3, 2, 1, 0] -> stack
// current = 0
// last = 6
// temp = 1
// 0-> next = 6
// 6-> next = temp = 1
// current = temp
// last = 5
// 5 -> next = nullptr
// after step 1 new list is [0,6,1,2,3,4,5] current = 1 last 5 stack [4,3,2,1,0]
// current = 1
// last 5
// temp = 2
// current->next = 1->next = last (5)
// last->next = temp (2)
// last = stack_pop(4)
// current = temp (2)
// last->next = nullptr
// after step 2 [0,6,1,5,2 (curr),3,4,] last = 4 stack (3,2,1,0)
// step 3
// current = 2
// last = 4
// temp = curr->next = 3
// current->next = last (4)
// last->next = temp (3)
// last = stack_pop(3)
// current = temp (3)
// last->next = nullptr



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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (secondHead){
            ListNode* temp = secondHead->next;
            secondHead->next = prev;
            prev = secondHead;
            secondHead = temp;
        }
        secondHead = prev;
        ListNode* first = head;
        while (secondHead){
            ListNode* temp1 = first->next;
            ListNode* temp2 = secondHead->next;
            first->next = secondHead;
            secondHead->next = temp1;
            first = temp1;
            secondHead = temp2;
        }

    }
};
