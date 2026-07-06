class Node {
    public:
    string s;
    Node * next;
    Node * prev;
    
    Node(string a){
        s=a;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
  public:
   Node * curr;
    // constructor to initialize object with homepage
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }

    // visit current url
    void visit(string url) {
        Node * temp = new Node(url);
        temp->prev=curr;
        curr->next=temp;
        curr=temp;
    }

    // 'steps' move backward in history and return current page
    string back(int steps) {
        while(steps>0 && curr->prev){
            curr=curr->prev;
            steps--;
        }
        
        return curr->s;
    }

    // 'steps' move forward and return current page
    string forward(int steps) {
        while(steps>0 && curr->next){
            curr=curr->next;
            steps--;
        }
        
        return curr->s;
    }
};