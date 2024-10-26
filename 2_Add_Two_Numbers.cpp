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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *root = nullptr;
        ListNode *current = new ListNode();
        ListNode *tail = current;
        bool carry = false;

        while(l1 != nullptr && l2 != nullptr){
            tail = current;
            int sum = l1->val + l2->val;

            if(carry){
                sum++;
                carry = false;
            }

            if(sum > 9){
                carry = true;
                sum-=10;
            }
            current->val = sum;
            if(l1->next != nullptr || l2->next != nullptr){
                ListNode *next = new ListNode();
                current->next =next;
            }
            if(root == nullptr)root = current;
            current = current->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2){
            l1 = l2;
        }

        while(l1 != nullptr){
            tail = current;
            int sum = l1->val;
            if(carry){
                sum++;
                carry = false;
            }
            if(sum > 9){
                carry = true;
                sum-=10;
            }
            current->val = sum;
            if(l1->next != nullptr){
                ListNode *next = new ListNode();
                current->next =next;
                current = current->next;
            }
            l1 = l1->next;

        }

        if(carry){
            ListNode *next = new ListNode();
            next->val = 1;
            tail->next = next;
        }

        return root;


    }
};
