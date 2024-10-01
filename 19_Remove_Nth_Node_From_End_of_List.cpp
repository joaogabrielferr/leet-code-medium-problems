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

        if(head->next == nullptr)return nullptr;

        int max = 0;
        ListNode *aux = head;
        while(aux != nullptr)
        {
            max++;
            aux = aux->next;
        }

        int target_node = max - n + 1;

        if(target_node == 1)return head->next;

        aux = head;
        int count = 1;
        while(aux != nullptr){

            if(count + 1 == target_node){
                
                aux->next = aux->next->next;
                break;
            }
            aux = aux->next;
            count++;

        }

        return head;


    }
};
