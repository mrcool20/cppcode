   ListNode* rightMost(ListNode *node, ListNode* curr) {
        while (node->right != null && node->right != curr) {
            node = node->right;
        }
        return node;
    }

    void morrisIn(ListNode* node) {
        Node* curr = node;
        int KthSmallest=INT_MIN;
        int count=0;
        while (curr != null) {
            Node* nextLeft = curr->left;
            if (nextLeft == null) {
                count++;
                if(count==k)
                 KthSmallest=curr->val;
                curr = curr->right;
                continue;
            }

            ListNode* rightMost = rightMost(nextLeft, curr);

            if (rightMost->right == null) {
                rightMost->right = curr; // thread.
                curr = curr->left;
            } else {
                rightMost->right = null; // break thread.
                count++;
                if(count==k)
                KthSmallest=curr->val; 
                curr = curr->right;
            }

        }
    }
   return KthSmallest;
