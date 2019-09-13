/**
 * readMatrix.h
 *
 * Written by Nicholas Cannon (22241579)
 */
#ifndef PARSE_MATRIX_HEADER
#define PARSE_MATRIX_HEADER

#define MAT_INT 0
#define MAT_FLOAT 1

#define BUF_SIZE 4  // 4 char buf size

/* Coordinate Format struct */
typedef struct {
    int row;
    int col;
} COO_ENTRY_BASE;

typedef struct {
    COO_ENTRY_BASE base;
    int val;
} COO_ENTRY_INT;

typedef struct {
    COO_ENTRY_BASE base;
    float val;
} COO_ENTRY_FLOAT;

typedef struct {
    int rows;
    int cols;
    int type;  // either MAT_INT or MAT_FLOAT
    int nzsize;
    COO_ENTRY_BASE **NZ;  // non zero elements
} COO;

/* Compressed Format struct (used for both compressed col and row) */
typedef struct {
} CS_ENTRY_BASE;

typedef struct {
    CS_ENTRY_BASE base;
    int val;
} CS_ENTRY_INT;

typedef struct {
    CS_ENTRY_BASE base;
    float val;
} CS_ENTRY_FLOAT;

typedef struct {
    int rows;
    int cols;
    int type;             // either MAT_INT or MAT_FLOAT
    CS_ENTRY_BASE **NNZ;  // non-zero elments
    int nzsize;           // size of NNZ
    int *IA;
    int *JA;
} CS;

/* Function defs */
int readCOO(char *matFile, COO *mat);
int readCSR(char *matFile, CS *mat);
int readCSC(char *matFile, CS *mat);

#endif
