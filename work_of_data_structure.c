#include<stdio.h>
#include<string.h>
typedef struct {
    int id;
    char ClassName[50];
    char classCode[50];
    int numberOfStudent;
    
}TradeOptions;


int main(){
    TradeOptions c1;
    TradeOptions c2;  
    TradeOptions c3;

    c1.id=1;
    strcpy(c1.classCode,"CSA");
    strcpy(c1.ClassName,"Computer system and Architecture");
    c1.numberOfStudent=340;
    printf("This is Class Id : %d\n",c1.id);
    printf("This is Class Name : %s\n",c1.ClassName);
    printf("This is Class  Code : %s\n",c1.classCode);
    printf("This is Class Number Of Students : %d\n\n",c1.numberOfStudent);
    
    
    c2.id=2;
    strcpy(c2.classCode,"TOR");
    strcpy(c2.ClassName,"Tourism");
    c2.numberOfStudent=209;
    printf("This is Class Id : %d\n",c2.id);
    printf("This is Class Name : %s\n",c2.ClassName);
    printf("This is Class  Code : %s\n",c2.classCode);
    printf("This is Class Number Of Students : %d\n\n",c2.numberOfStudent);
    
    
     c3.id=3;
    strcpy(c3.classCode,"FBO");
    strcpy(c3.ClassName,"Food And beverage Operations");
    c3.numberOfStudent=420;
    printf("This is Class Id : %d\n",c3.id);
    printf("This is Class Name : %s\n",c3.ClassName);
    printf("This is Class  Code : %s\n",c3.classCode);
    printf("This is Class Number Of Students : %d",c3.numberOfStudent);
    
    
    
}
