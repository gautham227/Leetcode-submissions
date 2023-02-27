/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* recur(vector<vector<int> >&grid, int r, int c, int len){
        Node* nd=new Node();
        bool flag=true;
        for(int i=r;i<r+len;i++){
            for(int j=c;j<c+len;j++){
                if(grid[i][j]!=grid[r][c]){flag=false;break;}
            }
        }
        if(flag){
            nd->val=grid[r][c];
            nd->isLeaf=true;
            return nd;
        }
        nd->topLeft=recur(grid,r,c,len/2);
        nd->bottomLeft=recur(grid,r+len/2,c,len/2);
        nd->topRight=recur(grid,r,c+len/2,len/2);
        nd->bottomRight=recur(grid,r+len/2,c+len/2,len/2);
        return nd;
    }
    
    
    Node* construct(vector<vector<int>>& grid) {
        return recur(grid,0,0,grid.size());
    }
};