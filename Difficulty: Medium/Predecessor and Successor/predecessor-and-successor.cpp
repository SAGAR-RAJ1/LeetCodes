/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        
        Node * pre = nullptr;
        Node * suc = nullptr;
        Node * save = root;
        while(root){
            if(root->data>=key){
                root=root->left;
            }else{
                pre = root;
                root=root->right;
            }
        }
        root=save;
        while(root){
            if(root->data<=key){
                root=root->right;
            }else{
                suc = root;
                root=root->left;
            }
        }
        
        return {pre,suc};
    }
};