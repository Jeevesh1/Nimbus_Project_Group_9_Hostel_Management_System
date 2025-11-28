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
void giveroom(struct studinfo s[], int ns, struct roominfo r[], int nr);

int main(){

    struct studinfo studs[MAXS];
    struct roominfo rooms[MAXR];

    int nr=0, ns=0;

    for (int i=0;i<MAXR; i++){
        rooms[i].rno = i+1;
        rooms[i].count = 0;
        rooms[i].money = 2000;
    }

    nr = MAXR;

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

void giveroom(struct studinfo s[], int ns, struct roominfo r[], int nr){
    int sid;
    printf("Enter Student Id:\n");
    scanf("%d", &sid);
    for(int i=0;i<ns;i++) {
        if(s[i].sid == sid) {
            if(s[i].rno != -1) {
                printf("Student already has room %d\n", s[i].rno);
                return;
            }
            
            for(int j= 0; j<nr;j++){
                if(r[j].count < 4){
                    s[i].rno = r[j].rno;
                    (r[j].count)++;
                    return;
                }
                else{
                    continue;
                }
            }
            printf("Room not Available\n");
            return;
        }
            
            
    }

    printf("student not found");     
}
