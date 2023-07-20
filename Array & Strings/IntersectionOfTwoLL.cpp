#include<bits/stdc++.h>

/*Approch 1 (HASHING) (not most optimal): TC : O(n + m), SC : max(O(n), O(m)) */
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    /* now to find intersection in LL => put all the elem of a LL in a set
    now traverse LL 2, if ith node has appeared in set : then 
    that node is intersection else intersection stays NULL */

    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    set<Node*> st;
    Node* intersection = NULL;
        
    while(temp1 != NULL) {
        st.insert(temp1);
        temp1 = temp1->next;
    }
    
    while(temp2 != NULL) {
        if(st.find(temp2) != st.end()){
            //this pointer already exists in set
            intersection = temp2;
            break;
        }
        temp2 = temp2->next;
    }
    return intersection;

}