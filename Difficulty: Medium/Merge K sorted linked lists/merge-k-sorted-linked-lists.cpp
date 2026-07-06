/*
class Node {
	public:
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
	Node* mergeKLists(vector<Node*>& lists) {
		// code here
		if (lists.size() == 0)
			return nullptr;
		
		priority_queue<pair<int, Node*>, vector<pair<int, Node*>>,
		greater<pair<int, Node*>>>
		pq;
		
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i])
				pq.push({lists[i]->data, lists[i]});
		}
		Node* dummy = new Node(-1);
		Node* temp = dummy;
		while (!pq.empty()) {
			auto a = pq.top();
			pq.pop();
			if (a.second->next)
				pq.push({a.second->next->data, a.second->next});
			
			temp->next = a.second;
			temp = a.second;
		}
		
		return dummy->next;
	}
};
