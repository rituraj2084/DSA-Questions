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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        ListNode* current = head;
        while(current != NULL){
            nex = current -> next;
            current -> next = prev;
            prev = current;
            current = nex;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL ){
            return false;
        }
        ListNode *slow = head, *fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next; 
        }
        slow -> next = reverse(slow -> next);
        slow = slow -> next;
        ListNode* temp = head;
        while(slow){
            if(slow -> val != temp -> val){
                return false;
            }
            slow = slow -> next;
            temp = temp -> next;
        }
        return true;
        /*
        vector<int> arr;
        ListNode *temp = head;
        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        int l = 0, e = arr.size() - 1;
        while(l <= e){
            if(arr[l] != arr[e]){
                return false;
            }
            l++;
            e--;
        }
        return true;
        */
    }
};