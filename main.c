#include <stdio.h>
#include "MxAlg.h"

int main()
{
    SMatrix *pM1, *pM2, *pM3, *pRM;

    pM1 = CreateMatrix(4, 4, MFT_RAND);
    pM2 = CreateMatrix(4, 4, MFT_RAND);
    pM3 = CreateMatrix(4, 7, MFT_RAND);

    printf("\nM1:\n"); printMatrix(pM1);
    printf("\nM2:\n"); printMatrix(pM2);
    printf("\nM3:\n"); printMatrix(pM3);

    pRM = MADD(pM1, pM2);
    printf("\nRM = M1 + M2:\n"); printMatrix(pRM);

    pRM = MSUB(pM1, pM2);
    printf("\nRM = M1 - M2:\n"); printMatrix(pRM);

    pRM = MMUL(pM1, pM3);
    printf("\nRM = M1 * M3:\n"); printMatrix(pRM);

    pRM = MTRS(pM3);
    printf("\nRM = Transpose of M3:\n"); printMatrix(pRM);

    DestroyMatrix(pM1);
    DestroyMatrix(pM2);
    DestroyMatrix(pM3);
}
