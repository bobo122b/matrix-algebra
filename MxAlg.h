#ifndef MXALG_H
#define MXALG_H

//defining the matrix datatype
typedef struct SMatrix
{
    double** pValues;
    int nR;
    int nC;
} SMatrix;

//defining a filltype to the matrix in order to initiate it
typedef enum MFILLTYPE{MFT_NONE, MFT_ZEROS, MFT_ONES, MFT_RAND, MFT_IDENTITY} MFILLTYPE;

SMatrix* CreateMatrix(int nR, int nC, MFILLTYPE fillType);
void DestroyMatrix(SMatrix* pMatrix);
void printMatrix(SMatrix* pMatrix);
SMatrix* MADD(SMatrix* pM1, SMatrix* pM2);
SMatrix* MSUB(SMatrix* pM1, SMatrix* pM2);
SMatrix* MMUL(SMatrix* pM1, SMatrix* pM2);
SMatrix* MTRS(SMatrix* pM);


#endif // MXALG_H
