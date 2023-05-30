
//*	@file BP3_PROJE
//*	@description Girilen matris buyuklukleri ve islem tipine gore verilen matrisler uzerinden yeni matris olusturan program.
//*	@assignment Proje 1
//*	@date 13.12.2021
//*	@author Feyza Kurucay (1921221009) feyza.kurucay@stu.fsm.edu.tr

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrisoperations.h"
int main(int argc, char *argv[])
{
    if (argc == 5)
    {
        int size1 = atoi(argv[1]);
        int size2 = atoi(argv[2]);
        int processtype = atoi(argv[3]);
        int seed = atoi(argv[4]);
        int size3;
        int dolgu;
        size1 = size1_control(size1);
        size2 = size2_control(size1, size2);
        processtype = processtype_control(processtype);

        int **matris1 = makematrix(size1);
        int **matris2 = makematrix(size2);
        fillmatrix(matris1, size1, seed);
        fillmatrix(matris2, size2, seed);
        printf("First matrix :\n ");
        printmatrix(matris1, size1);
        printf("");
        printf("Second matrix :\n ");
        printmatrix(matris2, size2);
        int **matris3 = operations(matris1, matris2, processtype, size1, size2);
        if (processtype == 0)
        { //free isleminde kullanmak üzere size hesaplamak için kontrol yaptım.
            dolgu = 0;
        }
        else
        {
            dolgu = (size2 - 1) / 2;
        }
        size3 = calculatematris3size(size1, size2, dolgu);
        printmatrix(matris3, size3);
        letfreematrix(matris1, size1); //heapten aldigim yerleri iade ettim.
        letfreematrix(matris2, size2);
        letfreematrix(matris3, size3);
    }
    else
    {
        printf("Argc has to be 5.");
    }
    return 0;
}