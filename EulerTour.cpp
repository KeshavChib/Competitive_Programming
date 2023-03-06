    
// Euler tour for finding the length of tree
vector<int> st, end, depth;

    int noOfNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + noOfNodes(root->left) + noOfNodes(root->right);
    } 

    void fndDepth(TreeNode* root, int dep){
        if(root == NULL) return;
        depth[st[root->val]] = dep ;
        fndDepth(root->left, dep + 1);
        fndDepth(root->right, 1 + dep);
    }

    void eulerTour(TreeNode* root, int& ind){
        st[root->val] = ind;
        
        if(root->left){
            ind++;
            eulerTour(root->left, ind);
        }

        if(root->right){
            ind++;
            eulerTour(root->right, ind);
        }
        end[root->val] = ind;

    }
