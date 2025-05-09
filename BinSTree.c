#include <stdio.h>
#include <stdlib.h> 
#include "BinSTree.h"
#include "boolean.h"

boolean IsEmpty(BinTree P) {
    return P == Nil;
}

infotype GetAkar(BinTree P) {
    if (!IsEmpty(P)) {
        return Info(P);
    }
}

BinTree GetLeft(BinTree P) {
    if (!IsEmpty(P)) {
        return Left(P);
    }
}

BinTree GetRight(BinTree P) {
    if (!IsEmpty(P)) {
        return Right(P);
    }
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(Node));
    if (P != Nil) {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
        P->parent = Nil;
    }
    return P;
}

void DeAlokasi(address P) {
    free(P);
}

void PreOrder(BinTree P) {
    BinTree current = P; 
    boolean resmi = true;

    if (current == Nil) return;

    printf("%c ", Info(current));  
    while (current != Nil) {
        if (Left(current) != Nil && resmi) {
            current = Left(current);
            printf("%c ", Info(current));
        } else if (Right(current) != Nil) {
            current = Right(current);
            printf("%c ", Info(current));
            resmi = true;
        } else {
            current = current->parent;
            resmi = false;
        }
    }
    printf("\n");
}

void InOrder(BinTree P) {
    BinTree current = P;
    boolean resmi = true;

    while (current != Nil) {
        while (Left(current) != Nil && resmi) {
            current = Left(current);
        }
        if (resmi) {
            printf("%c ", Info(current));
        }
        if (Right(current) != Nil) {
            current = Right(current);
            resmi = true;
        } else {
            current = current->parent;
            resmi = false;
            if (current != Nil && Left(current) != Nil && !resmi) {
                printf("%c ", Info(current));
            }
        }
    }
    printf("\n");
}

void PostOrder(BinTree P) {
    BinTree current = P;
    boolean resmi = true;

    while (current != Nil) {
        while (Left(current) != Nil && resmi) {
            current = Left(current);
        }
        if (Right(current) != Nil && resmi) {
            current = Right(current);
        } else {
            printf("%c ", Info(current));
            if (current != Nil) {
                BinTree parent = current->parent;
                if (parent != Nil && Left(parent) == current) {
                    resmi = false;
                }
                current = parent;
            }
        }
    }
    printf("\n");
}

void PrintTree(BinTree P, int h) {
    printf("Binary Tree Structure:\n\n");

    for (int i = 0; i < jml_maks; i++) {
        if (P[i].info != '\0') {  
            printf("Info Node: [%c]\n", P[i].info);
            
            // Print left child
            printf("Left Son: [%c]\n", (P[i].left != Nil) ? P[i].left->info : '-');
            
            // Print right child
            printf("Right Son: [%c]\n", (P[i].right != Nil) ? P[i].right->info : '-');
        }
    }
}
