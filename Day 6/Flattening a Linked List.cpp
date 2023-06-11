
Node *merge(Node *a,Node *b){
    
    Node* dummy = new Node(0);
    Node* curr = dummy;
    
    while(a != NULL && b != NULL){
        if(a->data < b->data){
            curr->bottom = a;
            curr = curr->bottom;
            a = a->bottom;
        }
        else{
            curr->bottom = b;
            curr = curr->bottom;
            b = b->bottom;
        }
    }
    
    if(a != NULL){
        curr->bottom = a;
    }
    else{
        curr->bottom = b;
    }
    
    return dummy->bottom;
}
Node *flatten(Node *root)
{
    
    if(root == NULL || root->next == NULL){
        return root;
    }
   root->next = flatten(root->next);
   
   root = merge(root,root->next);
   
   return root;
}
