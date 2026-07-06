class Node {
    public:
        string url;
        Node* next;
        Node* prev;

        Node(string s) {
            url = s;
            next = nullptr;
            prev = nullptr;
        }
    };

class BrowserHistory {
public:
    
    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);

        curr->next = newNode;
        newNode->prev = curr;

        curr = newNode;
    }
    
    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }

        return curr->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }

        return curr->url;
    }
};