# matrix-algebra
Matrix Algebra library in C to perform mathematical operations on matrices

The library provides:-
A matrix structure SMatrix that contains double pointer to values, number of rows, and number of columns.

## fill types:
  MFT_NONE : Leaves the matrix empty.
  
  MFT_ZEROS : fills the matrix with zeros.
  
  MFT_ONES : fills the matrix with ones.
  
  MFT_RAND : fills the matrix with random numbers.
  
  MFT_IDENTITY : makes an identity matrix.

## functions : 
  CreateMatrix(rows, columns, fill type) : creates a matrix with the fill type that you provide.
  
  DestroyMatrix(pointer to matrix) : removes the matrix you made from memory.
  
  printMatrix(pointer to matrix) : prints the matrix.
  
  MADD(matrix1, matrix2) : adds two matrices.
  
  MSUB(matrix1, matrix2) : subtracts two matrices.
  
  MMUL(matrix1, matrix2) : multiplies two matrices.
  
  MTRS(matrix) : returns the transpose of the matrix.
  
  MDET(matrix) : returns the determinant of a matrix.
