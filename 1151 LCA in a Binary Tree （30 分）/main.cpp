#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#define N 10000+10
using namespace std;

typedef struct Node {
    Node *left;
    Node *right;
    int data;
} Node;

int inorder[N];
int preorder[N] ;
int m,n;
int u,v;
int _u,_v;

int _find = 0 ;
vector<int> path0;
vector<int> uv;

Node *createTree( int *in_begin ,int*in_end ,int *pre_begin,int *pre_end ) {
    if (in_begin > in_end) return NULL;
    if (pre_begin > pre_end) return NULL;
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = *pre_begin;
    int *p = in_begin;
    while (*p!=root->data)p++; // 中序中找到根结点
    long l_len = p - in_begin;
    long r_len = in_end - p;
    root->left = createTree(in_begin, p-1, pre_begin+1, pre_begin+l_len);
    root->right = createTree(p+1, in_end, pre_end-r_len+1, pre_end);
    return root;
}
void LCA(Node *root,vector<int> *path_vec ) {
    if (_find == 2)return;
    path_vec->push_back(root->data);
    if (root->data == u || root->data == v) {
        _find++;
        if(_find == 1) {
            path0 = *path_vec; // 备份
            if(root->data == u){
                uv.push_back(u);
                u=v;
                
            }
            if(root->data == v){
                uv.push_back(v);
                v=u;
                
            }
        }
        if (_find == 2) {
            uv.push_back(v);
            // 长度不相等，对其
            int flag = -1 ;
            if (path0.size() != path_vec->size()) {
                if(path0.size()>path_vec->size()) {
                    long  pop_n = path0.size() - path_vec->size();
                    while(pop_n--)path0.pop_back();
                    flag =0;
                }else {
                    long  pop_n = path_vec->size() -path0.size();
                    while(pop_n--)path_vec->pop_back();
                    flag =1;
                }
            }
            if(path0[path0.size()-1] == (*path_vec)[path_vec->size()-1]) {
                if(flag == 0){
                    //8 is an ancestor of 1.
                    
                    printf("%d is an ancestor of %d.\n",uv[1],uv[0]);
                }
                
                if(flag==1){
                    printf("%d is an ancestor of %d.\n",uv[0],uv[1]);
                }
            }else {
                
                while (path0.size() > 0 ) {
                    if(path0[path0.size()-1] == (*path_vec)[path_vec->size()-1])break;
                    path0.pop_back();
                    path_vec->pop_back();
                }
                //LCA of 2 and 6 is 3.
                printf("LCA of %d and %d is %d.\n",_u,_v,path0[path0.size()-1]);
                
            }
            
            return;
        }
    }
    if(root->left)LCA(root->left, path_vec);
    if(root->right)LCA(root->right, path_vec);
    path_vec->pop_back();
}
void bfs(Node *t ) {
    queue<Node *> q;
    q.push(t);
    int index = 0;
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        ++index;
        if(index == n)
            printf("%d\n",cur->data);
        else
            printf("%d ",cur->data);
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}
int main ()
{
    
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++) {
        scanf("%d",inorder+i);
    }
    for (int i=0;i<n;i++) {
        scanf("%d",preorder+i);
    }
    Node *root = createTree(inorder, inorder+n-1, preorder, preorder+n-1);
    for (int i=0;i<m;i++) {
        scanf("%d%d",&u,&v);
        _u = u;
        _v = v;
        _find = 0 ;
        path0.clear();
        uv.clear();
        vector<int>path ;
        LCA(root, &path);
        if(_find!=2) {
            if(_find == 0){
                printf("ERROR: %d and %d are not found.\n",_u,_v);
            }else {
                // remain 1
                if(_u!=_v) {
                    if( uv[0] == _u)
                        printf("ERROR: %d is not found.\n",_v);
                    else
                        printf("ERROR: %d is not found.\n",_u);
                }else {
                    printf("%d is an ancestor of %d.\n",_v,_u);
                    
                }
            }
        }
        
    }
    
    return 0;
}
