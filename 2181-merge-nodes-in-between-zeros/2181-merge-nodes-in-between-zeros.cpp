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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1= new ListNode(-1);
        ListNode* temp=head;
        ListNode* temp1=head1;
        int sum=0;
        while(temp!=NULL){
            if(temp->val==0){
                if(sum!=0){
                    ListNode* nnode=new ListNode(sum);
                    temp1->next=nnode;
                    temp1=temp1->next;
                    sum=0;
                }
            }
            sum+=temp->val;
            temp=temp->next;
        }
        return head1->next;
    }
};