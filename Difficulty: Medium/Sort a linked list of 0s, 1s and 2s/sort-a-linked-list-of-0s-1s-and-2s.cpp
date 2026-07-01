/* Node is defined as
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
	public:
	Node* segregate(Node* head) {
		// code here
		
		Node * zero = new Node(-1);
		Node * one = new Node(-1);
		Node * two = new Node(-1);
		
		Node * zerocurr = zero;
		Node * onecurr = one;
		Node * twocurr = two;
		
		Node * temp = head;
		while (temp != nullptr) {
			
			if (temp->data == 0) {
				zerocurr->next = temp;
				zerocurr = temp;
			} else if (temp->data == 1) {
				onecurr->next = temp;
				onecurr = temp;
			} else {
				twocurr->next = temp;
				twocurr = temp;
			}
			
			temp = temp->next;
		}
		// important you forgot
		if (one->next != nullptr)
			zerocurr->next = one->next;
		else
			zerocurr->next = two->next;
		
		onecurr->next = two->next;
		twocurr->next = nullptr;
		return zero->next;
		
	}
};
