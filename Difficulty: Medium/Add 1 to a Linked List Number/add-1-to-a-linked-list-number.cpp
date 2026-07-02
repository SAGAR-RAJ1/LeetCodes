class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    Node* addOne(Node* head) {

        head = reverseList(head);
        Node * temp = head;
        int carry = 1;
        while(temp!=nullptr){
            temp->data+=carry;
            
            if(temp->data<10){
                carry=0;
                break;
            }else{
                temp->data=0;
                carry=1;
            }
            
            temp=temp->next;
        }
       head= reverseList(head);
        if(carry){
            Node * dummy = new Node(1);
            dummy->next = head;
            head= dummy;
        }
        
        return head;
    }
};