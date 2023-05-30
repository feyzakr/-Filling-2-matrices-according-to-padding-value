//*	@file BP3_PROJE
//*	@description Girilen matris buyuklukleri ve islem tipine gore verilen matrisler uzerinden yeni matris olusturan program. 
//*	@assignment Proje 1
//*	@date 13.12.2021
//*	@author Feyza Kurucay (1921221009) feyza.kurucay@stu.fsm.edu.tr


#include <stdio.h>
#include <stdlib.h>
#include "matrisoperations.h"


int **makematrix(int rows_coulumns)
{
    int **ptr1 = (int **)malloc(rows_coulumns * sizeof(int *));
    for (int i = 0; i < rows_coulumns; i++)
    {
        ptr1[i] = (int *)malloc(rows_coulumns * sizeof(int));
    }
    return ptr1;
}

void fillmatrix(int **d, int size, int seed)
{

    int i, j;
    srand(seed);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            d[i][j] = (rand() % 10) + 1;
        }
    }
}

void printmatrix(int **pointer, int size)
{

    int a;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a = pointer[i][j];
            printf(" %d\t", a);
            if (j == size - 1)
            {
                printf("\n");
            }
        }
    }
    printf("\n"); //baskida 2 matrisin dipdibe basılmaması için bunu yaptim.
}

int valueofD(int matrixsize)
{
    //islem tipi 1 olarak girilirse hesaplama yapması icin
    int valueofD = (matrixsize - 1) / 2;
    return valueofD;
}
int calculatematris3size(int size1, int size2, int dolgu)
{
    int matris3size;
    matris3size = ((size1 - size2) + (2 * dolgu)) + 1;

    return matris3size;
}


int **operations(int **matris1, int **matris2, int IslemTipi, int matris1size, int matris2size)
{
    int valuedolgu;
    int matris3size;
    int size;
    int **tempmatris = matris1;
    if (IslemTipi == 1)
    {
        valuedolgu = valueofD(matris2size);
        tempmatris = newMatriswD(matris1, matris1size, valuedolgu);
    }

    else
    {
        valuedolgu = 0; //dolgu degeri
    }

    matris3size = calculatematris3size(matris1size, matris2size, valuedolgu);
     int **matris3 = makematrix(matris3size);
    int i;
    int j;
    int sum = 0;
    int product = 0;
    //Kucuk matrisi buyuk üzerinde gezdirebilmek icin distaki 2 for dongusunu kullandim. 
    for (int i = 0; i < matris3size; i++)
    { 
        for (j = 0; j < matris3size; j++)
        { 
            //Kucuk matrisi buyuk üzerine yerlestirdikten sonra elemanlar arasında gezebilmek icin alttaki 2 for dongusunu kullandim.
            for (int k = i; k < (matris2size + i); k++)
            { 
                for (int q = j; q < (matris2size + j); q++)
                { 
                    product = (tempmatris[k][q]) * (matris2[k - i][q - j]);
                    sum += product;
                }
            }

            matris3[i][j] = sum;
            sum = 0;
        }
    }
        printf(" Matris 3 as a result :\n");
    //printmatrix(matris3,matris3size);
    return matris3;
}

int **newMatriswD(int **matris1, int matris1size, int dolgudegeri)
{

    int newsize = matris1size + dolgudegeri * 2;//hem alta hem de uste dolgu degeri kadar satir eklenmeli o yüzden 2*dolgudegeri yaptım.(sutun icin de gecerli)
    int **temp;
    temp = (int **)calloc(newsize, sizeof(int *)); //dolgu kisimlarinin 0 olması gerekiyor o yuzden alani calloc ile aldim.
    for (int i = 0; i < newsize; i++)
    {
        temp[i] = (int *)calloc(newsize, sizeof(int));
    }
    for (int i = 0; i < newsize; i++)
    {
        for (int j = 0; j < newsize; j++)
        {
            if (i >= dolgudegeri && i < (newsize - dolgudegeri) && j >= dolgudegeri && j < (newsize - dolgudegeri))
            {
                temp[i][j] = matris1[i - dolgudegeri][j - dolgudegeri]; //matris1'in indeksleri yeni olusan matristen dolgu degeri kadar geride.
            }
        }
    }
    printf("Matrix 1 after operations :\n");
    printmatrix(temp, newsize);
    return temp;
}
int matrixsize(int size)
{

    if ((size % 2) == 0)
    {
        printf("matrix size cannot be an even number.");
        return 0;
    }
    else
    {

        return 1;
    }
}


int size1_control(int size1){
 //printf("Please enter the size of the 1st matrix (First matris has to be greater than 3)\n");
    //scanf("%d", &size1);
    int value = matrixsize(size1);

    if (value == 0 | size1 == 0 | size1 == 1 | size1 == 2 | size1 == 3)
    {
        while (value == 0 |size1 == 0 | size1 == 1 | size1 == 2 | size1 == 3)
        {
            printf("Please enter the size of the 1st matrix (First matrix has to be greater than 3) \n");
            scanf("%d", &size1);
            value = matrixsize(size1);
        }
    }
  return size1;
}
int size2_control(int size1,int size2){
    int value;
   // printf("Please enter the size of the 2nd matrix\n");
    //scanf("%d", &size2);
     value = matrixsize(size2);

    if (value == 0 | size1 <= size2 |size2 == 0| size2 == 1)
    {
        while (value == 0 | size1 <= size2 | size2 == 0| size2 == 1)
        {
            printf("Please enter the size of the 2nd matrix (Size1 has to bigger than size 2 and Size2 has to be greater than 1!!)\n");
            scanf("%d", &size2);
            value = matrixsize(size2);
        }
    }
    return size2;
}

int processtype_control(int type){
    int processtype = type;
    //printf("Please enter an process type as an 0 or 1 : ");
    //scanf("%d", &processtype);
 while (!(processtype == 0 || processtype == 1))
        {
            printf("!!Process type just could be 0 or 1 , please enter again !!  : ");
            scanf("%d", &processtype);
        }
        
            printf("CALCULATING BEGIN\n");
        
        return processtype;
}

void letfreematrix( int **matrix, int size){
    for(int i =0; i<size; i++){
        free(matrix[i]);
    }
    free(matrix);
}
