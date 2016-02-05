//
// Created by seanr on 2016/2/5.
//
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int val;
    struct ListNode* next;
};

// submit the codes below

struct ListHeadNode {
    int cnt;
    struct ListNode* child;
    struct ListHeadNode* next;
    struct ListHeadNode* last;
};

void browseTree( struct ListHeadNode** pThisRankHead , struct ListHeadNode* lastRankHead  , struct TreeNode* root ) {

    if( root == NULL ) {
        return;
    }

    if( *pThisRankHead == NULL ) {
        *pThisRankHead = calloc( 1 , sizeof(struct ListHeadNode ) );
    }

    struct ListNode** pTail = NULL;
    struct ListNode** pTailPre = NULL;

    // get the tail of list for this rank
    if( (*pThisRankHead)->child == NULL ) {
        (*pThisRankHead)->child = calloc( 1 , sizeof(struct ListNode) );
        (*pThisRankHead)->child->val = root->val;
        (*pThisRankHead)->child->next = NULL;
    } else {

        pTail = &( (*pThisRankHead)->child );
        pTailPre = pTail;
        while( (*pTail) != NULL ) {
            pTailPre = pTail;
            pTail = &( (*pTail)->next );
        }
        *pTail = calloc( 1 , sizeof(struct ListNode) );
        (*pTail)->val = root->val;
        (*pTailPre)->next = *pTail;
    }

    (*pThisRankHead)->cnt += 1;
    if( (*pThisRankHead)->last == NULL ) {
        (*pThisRankHead)->last = lastRankHead;

    }

    browseTree( &( (*pThisRankHead)->next ) , *pThisRankHead , root->left );
    browseTree( &( (*pThisRankHead)->next ) , *pThisRankHead , root->right );

}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {

    struct ListHeadNode* headOfListHead = calloc( 1 , sizeof( struct ListHeadNode ) );
    browseTree( &( headOfListHead->next ) , headOfListHead , root );

    int retSize = 0;
    struct ListHeadNode* tail = headOfListHead;
    int** ret = NULL;

    while( tail->next != NULL ) {
        tail = tail->next;
        retSize += 1;
    }

    if( returnSize == NULL ) {
        returnSize = calloc( 1 , sizeof(int) );
    }
    *returnSize = retSize;
    if( *columnSizes == NULL ) {
        *columnSizes = calloc( (size_t )retSize , sizeof(int) );
    }
    ret = calloc( ( size_t )retSize , sizeof(int*) );
    int indexOfRet = 0;

    while( tail != headOfListHead ) {

        *( *columnSizes + indexOfRet ) = tail->cnt;

        *( ret + indexOfRet ) = calloc( (size_t) tail->cnt , sizeof(int) );
        struct ListNode* now = tail->child;
        int indexOfThisRank = 0;
        while( now != NULL ) {
            *( *(ret + indexOfRet) + indexOfThisRank ) = now->val;
            now = now->next;
            indexOfThisRank += 1;
        }
        free( tail->child );
        tail = tail->last;
        free( tail->next );

        indexOfRet += 1;
    }
    free( headOfListHead );
    return ret;
}

// submit the codes above

struct TreeNode* buildTree( int nodeIndex , int data[] , int arrSize ) {

    if( nodeIndex > arrSize - 1 ) {
        return NULL;
    }

    struct TreeNode* root = calloc( 1 , sizeof( struct TreeNode ) );
    root->val = data[ nodeIndex ];
    printf("building...%d\n" , root->val );
    root->left = buildTree( 2 * nodeIndex , data , arrSize  );
    root->right = buildTree(2 * nodeIndex + 1 , data , arrSize );
    return root;

}

void printArray( int* arrSize , int** colSizes ,int **arr ) {
    for( int i = 0 ; i < *arrSize ; i++ ) {
        for( int j = 0 ; j < *(*colSizes + i) ; j++ ) {
            printf("%d,", *( *( arr + i ) + j ) );
        }
        printf("\n");
    }
}



int main() {
    int arr[ 4 ] = { 0 , 1 , 2 , 3 };
    struct TreeNode* root = buildTree( 1 , arr , 4 );
    int retArrSize = 0;
    int* retArrColSizes = NULL;

    int** retArr = levelOrderBottom( root , &retArrColSizes , &retArrSize );

    printf("......array size:%d\n" , retArrSize );
    printArray( &retArrSize , &retArrColSizes , retArr );

    return 0;
}
