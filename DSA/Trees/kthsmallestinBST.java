class Solution{

int count  =0;
int answer =-1;

int kthSmallest(Treenode root , int k){
    inorder(root,k);
    return answer;
}


void inorder(Treenode root ,int k){
    if(root == null) return ;

    inorder(root.left , k);
    count++;

    if(count == k){
        answer = root.val;
        return;
    }


if(answer == -1){
 inorder(root.right,k);
}
   
}


}