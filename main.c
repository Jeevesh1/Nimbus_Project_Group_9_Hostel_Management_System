#include <stdio.h>

#define MAXR 50   
#define MAXS 50   
#define ROOM_CAP 4   

struct roominfo {
    int rno;            
    int count;          
    int money;          
    int capacity;       
};

struct studinfo {
    int sid;            
    char sname[50];     
    int rno;           
};

void addstud(struct studinfo s[], int *n);
void giveroom(struct studinfo s[], int ns, struct roominfo r[], int nr);
void showall(struct studinfo s[], int ns, struct roominfo r[], int nr);

int main() {
    struct studinfo studs[MAXS];
    struct roominfo rooms[MAXR];

    int nr = 0, ns = 0;

    
    for (int i = 0; i < MAXR; i++) {
        rooms[i].rno = i + 1;
        rooms[i].count = 0;
        rooms[i].money = 2000;   
        rooms[i].capacity = ROOM_CAP;
    }

    nr = MAXR;

    while (1) {
        int ch;
        printf("\n===== HOSTEL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Allocate Room to Student\n");
        printf("3. Show All Details\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            if (ns >= MAXS) {
                printf("Cannot add more students (limit reached).\n");
            } else {
                addstud(studs, &ns);
            }
        } else if (ch == 2) {
            giveroom(studs, ns, rooms, nr);
        } else if (ch == 3) {
            showall(studs, ns, rooms, nr);
        } else if (ch == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void addstud(struct studinfo s[], int *n) {
    printf("\n--- Add New Student ---\n");
    printf("Enter student id: ");
    scanf("%d", &s[*n].sid);
    printf("Enter student name: ");
    scanf("%s", s[*n].sname);

    s[*n].rno = -1; 
    (*n)++;

    printf("Student added successfully. Total students: %d\n", *n);
}

void giveroom(struct studinfo s[], int ns, struct roominfo r[], int nr) {
    int sid;
    printf("\n--- Allocate Room ---\n");
    printf("Enter Student Id: ");
    scanf("%d", &sid);

   
    int studIndex = -1;
    for (int i = 0; i < ns; i++) {
        if (s[i].sid == sid) {
            studIndex = i;
            break;
        }
    }

    if (studIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    
    if (s[studIndex].rno != -1) {
        printf("Student already has room %d\n", s[studIndex].rno);
        return;
    }

   
    for (int j = 0; j < nr; j++) {
        if (r[j].count < r[j].capacity) {
            s[studIndex].rno = r[j].rno;
            r[j].count++;
            printf("Room %d allocated to student %s (ID: %d).\n",
                   r[j].rno, s[studIndex].sname, s[studIndex].sid);
            return;
        }
    }

    
    printf("No room available. Hostel is full.\n");
}

void showall(struct studinfo s[], int ns, struct roominfo r[], int nr) {
    int i;
    int totalStudents = ns;
    int occupiedRooms = 0;
    int totalMonthlyRent = 0;

    printf("\n========== HOSTEL REPORT ==========\n");

    printf("\n--- Student List (%d students) ---\n", totalStudents);
    if (ns == 0) {
        printf("No students added yet.\n");
    } else {
        for (i = 0; i < ns; i++) {
            printf("ID: %d  Name: %s  ", s[i].sid, s[i].sname);
            if (s[i].rno == -1) {
                printf("Room: Not allocated\n");
            } else {
                printf("Room: %d\n", s[i].rno);
            }
        }
    }

    printf("\n--- Room List (%d rooms) ---\n", nr);
    for (i = 0; i < nr; i++) {
        printf("Room: %3d | Rent per student: %4d | Capacity: %d | ",
               r[i].rno, r[i].money, r[i].capacity);

        if (r[i].count == 0) {
            printf("Status: Empty\n");
        } else {
            printf("Status: Taken | Students: %d\n", r[i].count);
            occupiedRooms++;
            totalMonthlyRent += r[i].count * r[i].money;
        }
    }

    printf("\n--- Hostel Summary ---\n");
    printf("Total students           : %d\n", totalStudents);
    printf("Total rooms              : %d\n", nr);
    printf("Occupied rooms           : %d\n", occupiedRooms);
    printf("Empty rooms              : %d\n", nr - occupiedRooms);
    printf("Total monthly rent (full): %d\n", totalMonthlyRent);
    printf("===================================\n");
}
