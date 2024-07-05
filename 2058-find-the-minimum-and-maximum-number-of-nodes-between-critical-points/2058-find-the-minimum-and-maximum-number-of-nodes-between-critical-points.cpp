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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         ListNode* previous=head;
        ListNode* current=head->next;
        int currentPosition=1;
        int previousCriticalPosition=0;
        int firstCriticalPosition=0;
        int mini=INT_MAX;
        while(current->next!=NULL){
            if(current->val > previous->val && current->val > current->next->val ||
            current->val < previous->val && current->val < current->next->val
            )
            {
                if(previousCriticalPosition==0){
                    previousCriticalPosition=currentPosition;
                    firstCriticalPosition=currentPosition;
                }
                else{
                    mini=min(mini,currentPosition-previousCriticalPosition);
                    previousCriticalPosition=currentPosition;
                }
                
            }
            currentPosition++;
            previous=current;
            current=current->next;
        }
        if(mini==INT_MAX){
            return {-1,-1};
        }
        else{
            int maxi=previousCriticalPosition-firstCriticalPosition;
            return{mini,maxi};
        }
    }
};