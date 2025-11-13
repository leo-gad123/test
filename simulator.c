#include<stdio.h>


int main(){

   int data[3][3];
   int d[3];
  printf("this is my working simulator by using c  programming \n\n");
  printf("enter the elemeny of index: ");
   for (int i=0;i<3;i++){
      printf("\n");
   for (int a=0;a<3;a++){
    scanf("%d",&data[i][a]);
   }
   }
 printf("this is for equality: ");
 for (int i=0 ;i<3;i++){
   scanf("%d",&d[i]);
 }

 printf("these are inputed element :\n");
    for (int i=0;i<3;i++){
      printf("\n\n");
        for (int a=0;a<3;a++){
           printf("%d     ",data[i][a]);
    
   }
   }
   printf("\n\n");

 int determinant =data[0][0]*(data[1][1]*data[2][2] - data[2][1]*data[1][2])
                 - data[0][1]*(data[1][0]*data[2][2] - data[2][0]*data[1][2])
                 + data[0][2]*(data[1][0]*data[2][1] - data[2][0]*data[1][1]);

 int Dx = d[0]*(data[1][1]*data[2][2] - data[2][1]*data[1][2])
       - data[0][1]*(d[1]*data[2][2] - d[2]*data[1][2])
       + data[0][2]*(d[1]*data[2][1] - d[2]*data[1][1]);


  int  Dy = data[0][0]*(d[1]*data[2][2] - d[2]*data[1][2])
       - d[0]*(data[1][0]*data[2][2] - data[2][0]*data[1][2])
       + data[0][2]*(data[1][0]*d[2] - data[2][0]*d[1]);

  int  Dz = data[0][0]*(data[1][1]*d[2] - data[2][1]*d[1])
       - data[0][1]*(data[1][0]*d[2] - data[2][0]*d[1])
       + d[0]*(data[1][0]*data[2][1] - data[2][0]*data[1][1]);
    
     
    int x=Dx/determinant;
    int y=Dy/determinant;  
    int z=Dz/determinant;         

 printf("determinant is : %d\n",determinant);
 printf("the value of x is : %d\n",x);
 printf(" the value of y is %d",z);
 printf("the value of z is %d ",y);


 printf("next time is for inverse matrix");
}