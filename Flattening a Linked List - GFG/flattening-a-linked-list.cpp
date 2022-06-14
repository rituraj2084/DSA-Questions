// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node* mergeTwoLists(Node* a, Node* b){
        Node* temp = new Node(0);
        Node* ans = temp;
        while(a != NULL && b!= NULL){
            if(a -> data < b->data){
                temp -> bottom = a;
                temp = temp -> bottom;
                a = a -> bottom;
            }
            else{
                temp -> bottom = b;
                temp = temp -> bottom;
                b = b -> bottom;
            }
        }
        if(a){
            temp -> bottom = a;
        }
        else{
            temp -> bottom = b;
        }
        return ans -> bottom;
    }
Node *flatten(Node *root)
{
    Node* nxt = root->next;
    Node* nxt2 = root;
    Node* head = new Node(0);
    head->bottom = root;
    
    while(nxt != NULL){
        Node* c1 = head;
        Node* c2 = nxt;
         
        while(c1->bottom != NULL && c2 != NULL){
            if(c1->bottom->data > c2->data){
                Node* temp1 = c1->bottom;
                Node* temp2 = c2->bottom;
                c1->bottom = c2;
                c2->bottom = temp1;
                c2 = temp2;
            }
            c1 = c1->bottom;
        }
        
        if(c1->bottom == NULL){
            c1->bottom = c2;
        }
        
        nxt = nxt->next;
        
    }
    
    return head->bottom;
    /*
  if(root == NULL || root -> next == NULL){
      return NULL;
  }
  root -> next = flatten(root -> next);
  root = mergeTwoLists(root, root-> next);
  return root;
  */
}

