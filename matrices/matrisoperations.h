//*	@file BP3_PROJE
//*	@description Girilen matris buyuklukleri ve islem tipine gore verilen matrisler uzerinden yeni matris olusturan program. 
//*	@assignment Proje 1
//*	@date 13.12.2021
//*	@author Feyza Kurucay (1921221009) feyza.kurucay@stu.fsm.edu.tr

#ifndef MATRISOPERATIONS_H_
#define matrisoperations_h_

int **makematrix(int);
void fillmatrix(int **, int,int);
void printmatrix(int **, int);
int valueofD(int matrixsize);
int **operations(int **, int **, int, int, int);
int **newMatriswD(int **matris1, int matris1size, int dolgudegeri);
int matrixsize(int);
int calculatematris3size(int , int , int );
int size1_control(int);
int size2_control(int , int);
int processtype_control(int);
void letfreematrix( int **, int );

#endif