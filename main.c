#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_STUDENTS 100

typedef struct {
    int roomNumber;
    int capacity;
    int occupied;
    float rent;
} Room;

typedef struct {
    int studentID;
    char name[50];
    int roomNumber;
} Student;
void addRoom(Room rooms[], int *roomCount) {
    if (*roomCount >= MAX_ROOMS) {
        printf("Maximum room limit reached!\n");
        return;
    }
    printf("Enter room number: ");
    scanf("%d", &rooms[*roomCount].roomNumber);
    printf("Enter room capacity: ");
    scanf("%d", &rooms[*roomCount].capacity);
    printf("Enter room rent: ");
    scanf("%f", &rooms[*roomCount].rent);
    rooms[*roomCount].occupied = 0;
    (*roomCount)++;
    printf("Room added successfully!\n");
}

void displayRooms(Room rooms[], int roomCount) {
    printf("\n--- Room List ---\n");
    for (int i = 0; i < roomCount; i++) {
        printf("Room %d | Capacity: %d | Occupied: %d | Rent: %.2f\n",
               rooms[i].roomNumber, rooms[i].capacity, rooms[i].occupied, rooms[i].rent);
    }
}
int allocateRoom(Room rooms[], int roomCount) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].occupied < rooms[i].capacity) {
            rooms[i].occupied++;
            return rooms[i].roomNumber;
        }
    }
    return -1; 
}

void addStudent(Student students[], int *studentCount, Room rooms[], int roomCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    int roomNo = allocateRoom(rooms, roomCount);
    if (roomNo == -1) {
        printf("No rooms available for allocation!\n");
        return;
    }
    printf("Enter student ID: ");
    scanf("%d", &students[*studentCount].studentID);
    printf("Enter student name: ");
    scanf(" %[^\n]%*c", students[*studentCount].name);
    students[*studentCount].roomNumber = roomNo;
    (*studentCount)++;
    printf("Student added and allocated to room %d successfully!\n", roomNo);
}

void displayStudents(Student students[], int studentCount) {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Name: %s | Room: %d\n",
               students[i].studentID, students[i].name, students[i].roomNumber);
    }
}

void searchStudent(Student students[], int studentCount, int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            printf("Student Found: ID: %d | Name: %s | Room: %d\n",
                   students[i].studentID, students[i].name, students[i].roomNumber);
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}
int main() {
    Room rooms[MAX_ROOMS];
    Student students[MAX_STUDENTS];
    int roomCount = 0, studentCount = 0;
    int choice;

    do {
        printf("\n--- Hostel Management System ---\n");
        printf("1. Add Room\n");
        printf("2. Display Rooms\n");
        printf("3. Add Student\n");
        printf("4. Display Students\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addRoom(rooms, &roomCount); break;
            case 2: displayRooms(rooms, roomCount); break;
            case 3: addStudent(students, &studentCount, rooms, roomCount); break;
            case 4: displayStudents(students, studentCount); break;
            case 5: {
                int id;
                printf("Enter student ID: ");
                scanf("%d", &id);
                searchStudent(students, studentCount, id);
                break;
            }
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
