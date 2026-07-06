/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
      Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node* rotate(Node* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;

        int elements = 0;
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            elements++;
        }
        k = k % elements;
        if(k==0)return head;
        k=elements-k;//for left 
        head = reverse(head);
        temp = head;
        k--;
        while (k--)
        temp = temp->next;
        Node* l1 = head;
        Node* l2 = temp->next;
        temp->next = nullptr;

        l1 = reverse(l1);
        l2 = reverse(l2);
        temp = l1;
        while (temp->next != nullptr)temp = temp->next;
        temp->next = l2;
        return l1;
    }

};