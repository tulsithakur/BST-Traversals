#include<stdio.h>

struct tree{
 int info;
 struct tree *left;
 struct tree *right;
 };
 struct tree *insert(struct tree *, int);
 void inorder(struct tree *);
 void postorder(struct tree *);
 void preorder(struct tree *);
 struct tree *delet(struct tree *, int);
 struct tree *search(struct tree *);
 int main(void){
 struct tree *root;
 int choice=0, item, item_no, i, n;
 root = NULL;
 clrscr();
 do{

   do{
   printf("\n\n\n By Tulsi Thakur");
   printf("\n\n Binary Tree Operations");
   printf("\n1. Insertion in BST");
   printf("\n2. Deletion in BST");
   printf("\n3. Inorder Traversal");
   printf("\n4. Postorder Traversal");
   printf("\n5. Preorder traversal");
   printf("\n6. Searching & Replacing in BST");
   printf("\n7. Exit ");
   printf("\n\t Enter your choice : ");
   scanf("%d", &choice);
   }
   while(choice<1 || choice>7);
   switch(choice){
   case 1:
   root=NULL;
   printf("\n\nBST of how many nodes ? ");
   scanf("%d", &n);
   for(i=1; i<=n; i++)
   {
   printf("\nEnter data for node %d : ", i);
   scanf("%d", &item);
   root = insert(root, item);
   }
   printf("\n root is %d", root->info);

   break;
   case 2:
   printf("\n Enter element to be deleted :");
   scanf("%d", &item_no);
   root= delet(root, item_no);

   break;

   case 3:

  printf("\nInorder Traversal is :");
  inorder(root);
  break;

  case 4:
  printf("\n Postorder Traversal is :");
  postorder(root);
  break;

  case 5:
  printf("\n Preorder Traversal is :");
  preorder(root);
  break;

  case 6:
  printf("\n Searching and Replacing of node");
  root=search(root);
  break;
  default :
  printf("\n End of Program");

  }

  }

  while(choice !=7);
  return(0);

  }

  struct tree *insert(struct tree *root, int x){
  if(!root){
  root=(struct tree*)malloc(sizeof(struct tree));
  root->info = x;
  root->left = NULL;
  root->right = NULL;
  return(root);
  }

  if(root->info>x)
  root->left = insert(root->left, x); else{
  if(root->info<x)
  root->right= insert(root->right, x);
  }
  return(root);
  }

  void inorder(struct tree *root){
  if(root != NULL){
  inorder(root->left);
  printf(" %d ", root->info);
  inorder(root->right);
  }
  return;
  }
  void postorder(struct tree *root){
  if(root != NULL){
  postorder(root->left);
  postorder(root->right);
  printf(" %d ", root->info);
  }
  return;
  }
  void preorder(struct tree *root){
  if(root !=NULL){
  printf(" %d ", root->info);
  preorder(root->left);
  preorder(root->right);
  }
  return;
  }
  /*function to delete a node from BST*/

  struct tree *delet(struct tree *ptr, int x){
  struct tree *p1, *p2;
  if(!ptr){
  printf("\n Node not found ");
  return(ptr);
  }
  else
  {
  if(ptr->info<x){
  ptr->right = delet(ptr->right, x);
  }
  else if(ptr->info>x){
  ptr->left= delet(ptr->left, x);
  return ptr;
  }
  else
  {
  if(ptr->info==x){
  if(ptr->left == ptr->right){
  free(ptr);
  return(NULL);
  }
  else if(ptr->left==NULL)
  {
  p1= ptr->right;
  free(ptr);
  return p1;
  }
  else if(ptr->right == NULL)
  {
  p1=ptr->left;
  free(ptr);
  return p1;
  }
  else {
  p1=ptr->right;
  p2=ptr->right;
  while(p1->left != NULL)
  p1=p1->left;
  p1->left=ptr->left;
  free(ptr);
  return(p2);
  }
  }
  }
  }
  return(ptr);
  }
  struct tree *search(struct tree *root){
  int no, i, ino;
  struct tree *ptr;
  ptr=root;
  printf("\n Enter the element to be searched :");
  scanf("%d", &no);
  fflush(stdin);
  while(ptr){
  if(no>ptr->info)
  ptr=ptr->right; else if(no<ptr->info)
  ptr= ptr->left; else
  break;
  }

  if(ptr){
  printf("\n Element %d is found ", no);
  printf("\n Do you want to replace it, press 1 for yes :");
  scanf("%d", &i);
  if(i==1){
  printf("\n Enter new element :");
  scanf( "%d", &ino);
  ptr->info=ino;
  }


  }
  else
  printf("\n Element %d does not exist", no);

 return(root);
 }




