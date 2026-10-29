/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; */
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        vector<int>odd;
        vector<int>even;
        
        Node * temp=head;
        while(temp){
            int data = temp->data;
            
            if(data%2==0){
                even.push_back(data);
            }else{
                odd.push_back(data);
            }
            
            temp=temp->next;
        }
        
        temp=head;
        int n1 = even.size();
        int n2= odd.size();
        
        for(int i = 0 ; i<n1 ; i++){
            temp->data = even[i];
            temp=temp->next;
        }
        for(int i = 0 ; i<n2 ; i++){
            temp->data = odd[i];
            temp=temp->next;
        }
        
        return head;
    }
};