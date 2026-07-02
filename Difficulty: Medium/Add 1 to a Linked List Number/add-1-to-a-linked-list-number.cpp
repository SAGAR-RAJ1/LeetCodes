class Solution {
	public:
	int solve(Node* head) {
		
		if(head==nullptr)return 1;
		
		int carry = solve(head->next);
		
		head->data+=carry;
		
		if(head->data<10)return 0;
		head->data=0;
		return 1;
	}
	Node* addOne(Node* head) {
		
		int carry = solve(head);
		
		if (carry) {
			Node * dummy = new Node(1);
			dummy->next = head;
			head = dummy;
		}
		
		return head;
	}
};
