/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //STEP 1
        if(!head) return NULL; 
        Node* temp = head;
        while(temp){ // while temp is not null
            Node* node = new Node(temp->val);
            node->next = temp->next; 
            temp->next = node;
            temp = node->next;
        }
		
		//Step 2
        temp = head; 
        while(temp){
            temp->next->random = (temp->random)?temp->random->next:NULL; 
            temp = temp->next->next; 
        }
		
		//Step 3
        Node* final = head->next;
        temp = head->next;
        while(head){ 
            head->next = temp->next;
            head = head->next; 
            if(!head) break; 
            temp->next = head->next; 
            temp = temp->next;
        }
        return final;
        /*
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp -> val);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = newNode -> next;
        }
        temp = head;
        while(temp){
            temp -> next -> random = (temp -> random)?temp -> random -> next:NULL;
            temp -> next = temp -> next -> next;
        }
        Node* ans = head -> next;
        temp = head -> next;
        while(head){
            head -> next = temp -> next;
            head = head -> next;
            if(!head){
                break;
            }
            temp -> next = head -> next;
            temp = temp -> next;
        }
        return ans;
        */
        /*
       map<Node*, Node*> mp;
        Node* temp = head;
        while(temp){
          Node* copy = new Node(temp -> val);
            mp[temp] = copy;
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            mp[temp] -> next = mp[temp -> next];
            mp[temp] -> random = mp[temp -> random];
            temp = temp -> next;
        }
        return mp[head];
        */
    }
};