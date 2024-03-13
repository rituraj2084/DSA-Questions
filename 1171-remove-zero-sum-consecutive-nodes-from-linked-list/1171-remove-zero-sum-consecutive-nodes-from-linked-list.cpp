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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> ump;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* tempHead = head;
        int prefixSum = 0;
        ump.insert(make_pair(0, dummyNode));

        while(tempHead) {
            prefixSum += tempHead->val;

            if(ump.find(prefixSum) != ump.end()) {
                ListNode* prev = ump[prefixSum];
                ListNode *removeFrom = prev->next;
                int kp = prefixSum + removeFrom->val;

                while(kp != prefixSum) {
                    ump.erase(kp);
                    removeFrom = removeFrom->next;
                    kp += removeFrom->val;
                }
                prev->next = tempHead->next;
            }

            else
                ump[prefixSum] = tempHead;

            tempHead = tempHead->next;
        }

        return dummyNode->next;
    }
};