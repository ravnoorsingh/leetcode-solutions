/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> NodeRegister;

    void dfs(Node* clone, Node* node){
        for(auto neighbour : node->neighbors){
            if(NodeRegister[neighbour->val] == NULL){
                Node* newNode = new Node(neighbour->val);
                clone->neighbors.push_back(newNode);
                NodeRegister[newNode->val] = newNode;
                dfs(newNode, neighbour);
            }
            else{
                clone->neighbors.push_back(NodeRegister[neighbour->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone = new Node(node->val);
        NodeRegister.resize(110,NULL);
        NodeRegister[clone->val] = clone;
        dfs(clone,node);
        return clone;
    }
};
