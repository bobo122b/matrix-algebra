#include <stdio.h>
#include <stdlib.h>
#include "MxAlg.h"

// A matrix algebra library


//creates matrix
SMatrix* CreateMatrix(int nR, int nC, MFILLTYPE fillType)
{
    int r, c;
    SMatrix* pRM;
    pRM = (SMatrix*)malloc(sizeof (SMatrix));
    pRM->nR = nR;
    pRM->nC = nC;
    pRM->pValues = (double**)malloc(nR * sizeof (double*));
    for (r = 0; r < nR; r++)
        pRM->pValues[r] = (double*)malloc(nC * sizeof (double));

    if(fillType != MFT_NONE)
    {
        for (r = 0; r < nR; r++)
            for (c = 0; c < nC; c++)
            {
                switch (fillType)
                {
                case MFT_ZEROS:
                    pRM->pValues[r][c] = 0; break;
                case MFT_ONES:
                    pRM->pValues[r][c] = 1; break;
                case MFT_RAND:
                    pRM->pValues[r][c] = (rand()%100)/100.0; break;
                case MFT_IDENTITY:
                    pRM->pValues[r][c] = (r==c) ? 1 : 0; break;
                }
            }
    }
    return pRM;
}

//deletes matrix
void DestroyMatrix(SMatrix* pMatrix)
{
    int r;
    for (r = 0; r < pMatrix->nR; r++)
        free(pMatrix->pValues[r]);
    free(pMatrix->pValues);
    free(pMatrix);
}

void printMatrix(SMatrix* pMatrix)
{
    int r, c;
    for (r = 0; r < pMatrix->nR; r++)
    {
        for (c = 0; c < pMatrix->nC; c++)
            printf("%5.2lf\t", pMatrix->pValues[r][c]);
        printf("\n");
    }
}

//adds two matrices
SMatrix* MADD(SMatrix* pM1, SMatrix* pM2)
{
    int r, c;
    SMatrix* pRM;
    if (pM1->nC != pM2->nC || pM1->nR != pM2->nR)
    {
        printf("Matrix error"); exit(0);
    }
    pRM = CreateMatrix(pM1->nR, pM1->nC, MFT_NONE);
    for (r = 0; r < pRM->nR; r++)
        for (c = 0; c < pRM->nC; c++)
            pRM->pValues[r][c] = pM1->pValues[r][c] + pM2->pValues[r][c];
    return pRM;
}

//subtracts two matrices
SMatrix* MSUB(SMatrix* pM1, SMatrix* pM2)
{
    int r, c;
    SMatrix* pRM;
    if (pM1->nC != pM2->nC || pM1->nR != pM2->nR)
    {
        printf("Matrix error"); exit(0);
    }
    pRM = CreateMatrix(pM1->nR, pM1->nC, MFT_NONE);
    for (r = 0; r < pRM->nR; r++)
        for (c = 0; c < pRM->nC; c++)
            pRM->pValues[r][c] = pM1->pValues[r][c] - pM2->pValues[r][c];
    return pRM;
}

SMatrix* MMUL(SMatrix* pM1, SMatrix* pM2)
{
    int r, c, i;
    SMatrix* pRM;

    if (pM1->nC != pM2->nR) {printf("Matrix error"); exit(0);}
    pRM = CreateMatrix(pM1->nR, pM2->nC, MFT_ZEROS);

    for (r = 0; r < pRM->nR; r++)
        for (c = 0; c < pRM->nC; c++)
            for (i = 0; i < pM1->nC; i++)
                pRM->pValues[r][c] += pM1->pValues[r][i] * pM2->pValues[i][c];
    return pRM;
}

SMatrix* MTRS(SMatrix* pM)
{
    int r, c;
    SMatrix* pRM;
    pRM = CreateMatrix(pM->nC, pM->nR, MFT_NONE);
    for (r = 0; r < pRM->nR; r++)
        for (c = 0; c < pRM->nC; c++)
            pRM->pValues[r][c] = pM->pValues[c][r];
    return pRM;
}
