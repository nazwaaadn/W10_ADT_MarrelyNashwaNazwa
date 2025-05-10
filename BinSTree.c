#include <stdio.h>
#include <stdlib.h> 
#include "BinSTree.h"
#include "boolean.h"
#include <stdlib.h>
#include <string.h>


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


void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
{
    *P = Alokasi(Akar);
    if (*P != Nil)
    {
        Info(*P) = Akar;
        Left(*P) = L;
        Right(*P) = R;
    }
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri)
{
    
    if (IsEmpty(*P))
    {
        MakeTree(X, Nil, Nil, P);
    } 
    else{
        if (Info(*P) == Y)
        {
            address temp = Alokasi(X);
            if (temp != Nil)
            {
                if (Kiri && Left(*P) == Nil)
                {
                    Left(*P) = temp;
                }
                if (!Kiri && Right(*P) == Nil)
                {
                    Right(*P) = temp;
                }
                else if (Kiri)
                {
                    Left(*P) = temp;
                }
                else
                {
                    Right(*P) = temp;
                }
            }
        }
        else
        {
            AddDaun(&Left(*P), X, Y, Kiri);
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    } 
}

boolean findMorseCode(BinTree root, char target, char *buffer, int depth) {
    if (root == NULL) return false;

    if (root->info == target) {
        buffer[depth] = '\0';
        return true;
    }

    buffer[depth] = '.';
    if (findMorseCode(root->left, target, buffer, depth + 1)) return true;

    buffer[depth] = '-';
    if (findMorseCode(root->right, target, buffer, depth + 1)) return true;

    return false;
}

void StringToMorse (BinTree P, char *str, char *morse)
{
    int i;
    if (!IsEmpty(P))
    {
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == ' ') {
                morse[i] = ' ';
            } else {
                char buffer[100];
                if (findMorseCode(P, str[i], buffer, 0)) {
                    strcat(morse, buffer);
                    strcat(morse, " "); 
                } else {
                    strcat(morse, "? "); 
                }
            }
        }
    }
    
}

boolean findString(BinTree root, char *target, char *buffer, int depth) {
    if (root == NULL) return false;

    if (depth == strlen(target)) {
        buffer[0] = Info(root); // Simpan hasilnya ke buffer[0]
        buffer[1] = '\0'; // akhiri string
        return true;
    }

    if (target[depth] == '.')
    {
        return findString(root->left, target, buffer, depth + 1);
    } else if (target[depth] == '-') 
    {
        return findString(root->right, target, buffer, depth + 1);
    } else if (target[depth] == '\0') 
    {
        buffer[depth] = '\0';
        return true;
    }
    return false;
    
}

void MorseToString(BinTree P, char *str, char *morse) {
    char *token = strtok(morse, " ");  
    char buffer[10];

    while (token != NULL) {
        if (findString(P, token, buffer, 0)) {
            strcat(str, buffer);
        } else {
            strcat(str, "?");
        }
        token = strtok(NULL, " ");
    }
}


boolean Search (BinTree P, infotype X)
{
    if (!IsEmpty(P))
    {
        if (Info(P) == X)
        {
            return true;
        }
        else
        {
            return Search(Left(P), X) || Search(Right(P), X);
        }
    }
    return false;
}


void DeAlokasi (address P)
{
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
