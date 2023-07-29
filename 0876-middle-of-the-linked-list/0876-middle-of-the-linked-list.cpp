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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        while(temp && temp->next){
            head = head -> next;
            temp = temp -> next -> next;
        }
        return head;
        
        // if(!head || !head->next) return head;
        // int count = 0;
        // ListNode* temp = head;
        // while(temp){
        //     count++;
        //     temp = temp -> next;
        // }
        // temp = head;
        // for(int i = 1; i < count/2; i++){
        //         temp = temp->next;
        //     }
        // head = temp->next;
        // return head;
    }
};