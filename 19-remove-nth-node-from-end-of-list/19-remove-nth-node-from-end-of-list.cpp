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
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i = 1; i <= n; i++){
            fast = fast -> next;
        }
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast-> next;
        }
        slow-> next = slow -> next -> next;
        return dummy->next;
        /*
       int count  = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        //cout << count<<endl;
        temp = head;
        if(n == count){
            head = head -> next;
            return head;
        }
        for(int i = 1; i < count - n; i++){
            temp = temp -> next;
        }
        
        
        if(temp -> next == NULL){
            return NULL;
        }
        ListNode* node = temp -> next;
        temp -> next = temp -> next -> next;
        delete node;
        
        return head;
        */
    }
};