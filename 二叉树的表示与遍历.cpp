/*
 * 二叉树的表示与遍历
 * 存储结构：二叉链表（lchild / rchild）
 * 建立：按先序输入字符序列，'#' 表示空子树
 * 遍历：先序、中序、后序（递归）、层次（队列）
 */

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

/* 先序建立二叉树，'#' 表示该位置为空 */
void CreateBiTree(BiTree *T)
{
    ElemType ch;
    if (scanf(" %c", &ch) != 1) {
        *T = NULL;
        return;
    }
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL) {
            fprintf(stderr, "内存分配失败\n");
            exit(1);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void DestroyBiTree(BiTree *T)
{
    if (*T) {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

/* 先序：根 - 左 - 右 */
void PreOrder(BiTree T)
{
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/* 中序：左 - 根 - 右 */
void InOrder(BiTree T)
{
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}

/* 后序：左 - 右 - 根 */
void PostOrder(BiTree T)
{
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}

#define MAX_QUEUE 100

/* 层次：自上而下、从左到右，队列辅助 */
void LevelOrder(BiTree T)
{
    BiTree queue[MAX_QUEUE];
    int front = 0;
    int rear = 0;

    if (T == NULL) {
        return;
    }
    queue[rear++] = T;
    while (front != rear) {
        BiTree p = queue[front++];
        printf("%c ", p->data);
        if (p->lchild != NULL) {
            if (rear >= MAX_QUEUE) {
                fprintf(stderr, "队列已满\n");
                return;
            }
            queue[rear++] = p->lchild;
        }
        if (p->rchild != NULL) {
            if (rear >= MAX_QUEUE) {
                fprintf(stderr, "队列已满\n");
                return;
            }
            queue[rear++] = p->rchild;
        }
    }
}

int main(void)
{
    BiTree T = NULL;

    printf("按先序输入二叉树（字符节点，'#' 表示空子树），例如：ABD##E##CF###\n");
    CreateBiTree(&T);

    printf("先序遍历：");
    PreOrder(T);
    printf("\n");

    printf("中序遍历：");
    InOrder(T);
    printf("\n");

    printf("后序遍历：");
    PostOrder(T);
    printf("\n");

    printf("层次遍历：");
    LevelOrder(T);
    printf("\n");

    DestroyBiTree(&T);
    return 0;
}

