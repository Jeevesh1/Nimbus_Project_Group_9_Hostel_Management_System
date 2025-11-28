#include <stdio.h>

#define MAXR 50
#define MAXS 50

struct roominfo{
    int rno;
    int count;
    int money;
};

struct studinfo{
    int sid;
    char sname[50];
    int rno;
};

void addstud(struct studinfo s[], int *n);

int main(){
    return 0;
}

void addstud(struct studinfo s[], int *n){
     printf("Enter student id: ");
    scanf("%d",&s[*n].sid);
    printf("Enter student name: ");
    scanf("%s",s[*n].sname);
    s[*n].rno = -1;
    (*n)++;
}

