/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void bfs(Node* n){
        queue<Node*>q;
        if(n==NULL)return;
        q.push(n);
        q.push(NULL);
        while(q.size()>1){
            Node* nod=q.front();
            q.pop();
            if(nod==NULL){
                q.push(NULL);
                continue;
            }
            nod->next=q.front();
            if(nod->left!=NULL){
                q.push(nod->left);
            }
            if(nod->right!=NULL){
                q.push(nod->right);
            }
        }
        
    }
    
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};