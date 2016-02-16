//
// Created by seanr on 2016/2/16.
//

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// submit the codes below

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {

    if( root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    int leftSize = 0;
    int rightSize = 0;

    char **leftRet = binaryTreePaths( root->left , &leftSize );
    char **rightRet = binaryTreePaths(root->right, &rightSize);

    int maxRootPathLen = 10;
    char *rootPathTo = calloc( (size_t)maxRootPathLen , sizeof(char) );
    sprintf( rootPathTo , "%d" , root->val );
    int rootPathToLen = strlen( rootPathTo );

    char** ret;
    if( leftSize == 0 && rightSize == 0 ) {
        *returnSize = 1;
        ret = calloc( 1 , sizeof(char*) );
        *ret = rootPathTo;
        return ret;
    }

    *returnSize = leftSize + rightSize;
    ret = calloc( (size_t)(leftSize + rightSize) , sizeof(char*) );
    for( int i = 0 ; i < leftSize + rightSize ; i++ ) {
        char* nowPath;
        if( i >= leftSize ) {
            nowPath = *( rightRet + i - leftSize );

        } else {
            nowPath = *( leftRet + i );
        }
        int nowPathLen = strlen( nowPath );
        if( nowPathLen > 0 ) {
            *( ret + i ) = calloc( (size_t)( nowPathLen + rootPathToLen + 3 ) , sizeof(char) );
            strcat( *( ret + i ) , rootPathTo );
            strcat( *( ret + i ) , "->" );
            strcat( *( ret + i ) , nowPath );
        } else {
            *( ret + i ) = calloc( (size_t)rootPathToLen , sizeof(char) );
            strcat( *( ret + i ) , rootPathTo );
        }
    }
    free( rootPathTo );
    return ret;


}

// submit the codes above

int main() {
    struct TreeNode* root = calloc( 1, sizeof(struct TreeNode) );
    root->val = 1;
    root->left = calloc( 1 , sizeof(struct TreeNode) );
    root->left->val = 2;
    int pathSize = 0;
    char **path = binaryTreePaths( root , &pathSize );
    for( int i = 0 ; i < pathSize ; i++ ) {
        printf("%s\n" , *( path + i ) );
    }
    return 0;
}

