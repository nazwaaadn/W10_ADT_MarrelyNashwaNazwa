#include <stdio.h>
#include "BinSTree.h"
#include "boolean.h"

boolean IsEmpty (BinTree P)
{
    return P == Nil;
}

infotype GetAkar (BinTree P)
{
    if (!IsEmpty(P))
    {
        return Info(P);
    }
    
}

BinTree GetLeft (BinTree P)
{
    if (!IsEmpty(P))
    {
        return Left(P);
    }
}

BinTree GetRight (BinTree P)
{
    if (!IsEmpty(P))
    {
        return Right(P);
    }
}

address Alokasi (infotype X)
{
    address P = (address) malloc(sizeof(Node));
    if (P != Nil)
    {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

void DeAlokasi (address P)
{
    free(P);
}
