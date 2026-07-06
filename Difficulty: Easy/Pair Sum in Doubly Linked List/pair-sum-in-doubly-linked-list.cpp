/* Doubly linked list node class
class Node
{
	public:
	int data;
	Node *next, *prev;
	Node(int val) : data(val), next(NULL), prev(NULL)
	{
	}
};
*/

class Solution {
	public:
	vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
		// code here
		Node * start = head;
		Node * end = head;
		
		while (end->next != nullptr) {
			end = end->next;
		}
		
		vector<pair<int, int>> ans;
		
		while (start->data<end->data) {
			int sum = start->data + end->data;
			if (sum<target) {
				start = start->next;
			} else if (sum>target) {
				end = end->prev;
			} else {
				ans.push_back({start->data, end->data}); start = start->next; end = end->prev;
			}
		}
		
		return ans;
	}
};
