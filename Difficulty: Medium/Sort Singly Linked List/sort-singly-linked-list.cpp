/* Structure of a Linked List Node
class Node
{
    int data;
    Node next;
    Node(int d) {
       data = d;
       next = nullptr;
    }
};*/
class Solution {
  public:
    Node* sortLL(Node* head) {
        // code here
        vector<int>arr;
        Node * temp = head;
        while(temp){
            arr.push_back(temp->data);temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp=head;
        int i = 0;
        while(temp){
            temp->data=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};