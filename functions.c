#include <stdio.h>
#include "functions.h"
#include <string.h>
void menuStart(){
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t  CHOOSE YOUR ROLE\n");
    printf("\t=====================\n");
    printf("\t[1] Admin.\n");
    printf("\t[2] Student.\n");
    printf("\t[3] Teacher. \n");
    printf("\t[0] Exit the Program.\n");
    printf("\t=====================\n");
}
void menuAdmin(){
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t          MENU\n");
    printf("\t==========================\n");
    printf("\t[1] Students management.\n");
    printf("\t[2] Classrooms management.\n");
    printf("\t[3] Teacher management.\n");
    printf("\t[4] User Guideline.\n");
    printf("\t[5] About Us.\n");
    printf("\t[0] Back.\n");
    printf("\t==========================\n");
}
void menuStudents(){
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t    STUDENT MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new student.\n");
    printf("\t[2] Show All students.\n");
    printf("\t[3] Delete A student.\n");
    printf("\t[4] Edit A student.\n");
    printf("\t[5] Search A student.\n");
    printf("\t[6] Sort A student.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}
void addStudent(int *length, struct Student sv[]){
    printf("\n\t***Add A New Student***\n");
	int newStudents;
    printf("\nAdd number of Students: ");
    scanf("%d", &newStudents);
    getchar(); 
    int i;
    for(i=*length;i<*length+newStudents;i++){
        printf("\n       Student %d\n", i + 1);
        printf("Enter the ID: ");
        fgets(sv[i].studentId, 10, stdin);
        sv[i].studentId[strcspn(sv[i].studentId, "\n")]= '\0'; 
        printf("Enter the Name: ");
        fgets(sv[i].fullName, 30, stdin);
        sv[i].fullName[strcspn(sv[i].fullName, "\n")]= '\0';
        printf("Enter the date of birth (dd / mm / yyyy): \n");
        printf("   Enter the day: ");
        scanf("%d", &sv[i].dateOfBrith.day);
        printf("   Enter the month: ");
        scanf("%d", &sv[i].dateOfBrith.month);
        printf("   Enter the year: ");
        scanf("%d", &sv[i].dateOfBrith.year);
        printf("Enter the Gender(1 for Male, 0 for Female): ");
        scanf("%d", &sv[i].gender);
        getchar(); 
        printf("Enter the Class: ");
        fgets(sv[i].classroomId, 10, stdin);
        sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
        printf("Enter the Email: ");
        fgets(sv[i].email, 30, stdin);
        sv[i].email[strcspn(sv[i].email, "\n")]= '\0';
        printf("Enter the Phone: ");
        fgets(sv[i].phone, 20, stdin);
        sv[i].phone[strcspn(sv[i].phone, "\n")]= '\0';
        printf("Enter the Password: ");
        fgets(sv[i].password, 20, stdin);
        sv[i].password[strcspn(sv[i].password, "\n")]= '\0';
    }
    *length += newStudents;
    printf("\nStudent Added Successfully.\n");
}
void printHeader(){
	printf("\n\t  ***All Student***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               | Password            |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
}
void printStudent(int length, struct Student sv[]){
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
            sv[i].studentId,
            sv[i].classroomId,
            sv[i].fullName,
            sv[i].dateOfBrith.day,
            sv[i].dateOfBrith.month,
            sv[i].dateOfBrith.year,
            sv[i].gender ? "Male" : "Female",
            sv[i].email,
            sv[i].phone,
            sv[i].password);
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|---------------------|\n");
    }
}
void saveStudentToFile(int length, struct Student sv[]){
    FILE *fptr = fopen("studentsData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(sv, sizeof(struct Student), 50, fptr);
    printf("Student data saved successfully\n");
    fclose(fptr);
}
void loadStudentFromFile(int *length, struct Student sv[]){
    FILE *fptr = fopen("studentsData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(sv, sizeof(struct Student), 50, fptr);
    fclose(fptr);
}
void deleteStudent(int *length, struct Student sv[]) {
    printf("\n\t***Delete a Student***\n");
    getchar();
	char id[10];
    printf("\nEnter the student ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(sv[i].studentId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nStudent with ID %s not found.\n", id);
    }else {
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",sv[findIndex].classroomId);
        printf("FullName: %s\n",sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",sv[findIndex].dateOfBrith.day,sv[findIndex].dateOfBrith.month,sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",sv[findIndex].email);
        printf("Phone: %s\n",sv[findIndex].phone);
        printf("Password: %s\n",sv[findIndex].password);
        for(i=findIndex;i<*length-1; i++){
            sv[i]=sv[i+1];
        }
        (*length)--;
        printf("\n\t***Updated The New Student ***\n");
        printHeader();
        printStudent(*length, sv);
        printf("\nStudent Deleted Successfully.\n");
    }
}
void editStudent(int length, struct Student sv[]) {
    printf("\n\t***Edit a Student***\n");
    getchar();
    char id[10];
    printf("\nEnter the student ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex=-1;
    int i;
    for(i=0;i<length;i++) {
        if(strcmp(sv[i].studentId, id)==0) {
            findIndex=i;
            break;
        }
    }
    if (findIndex== -1) {
        printf("\nStudent with ID %s not found.\n", id);
    }else{
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",sv[findIndex].classroomId);
        printf("FullName: %s\n",sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",sv[findIndex].dateOfBrith.day,sv[findIndex].dateOfBrith.month,sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",sv[findIndex].email);
        printf("Phone: %s\n",sv[findIndex].phone);
        printf("Password: %s\n",sv[findIndex].password);
        printf("\nEnter new Name: ");
        fgets(sv[findIndex].fullName, 30, stdin);
        sv[findIndex].fullName[strcspn(sv[findIndex].fullName, "\n")]= '\0';
        printf("Enter new date of birth (dd / mm / yyyy):\n");
        printf("   Enter new day: ");
        scanf("%d", &sv[findIndex].dateOfBrith.day);
        printf("   Enter new month: ");
        scanf("%d", &sv[findIndex].dateOfBrith.month);
        printf("   Enter new year: ");
        scanf("%d", &sv[findIndex].dateOfBrith.year);
        printf("Enter new Gender (1 for Male, 0 for Female): ");
        scanf("%d", &sv[findIndex].gender);
        getchar();
        printf("Enter new Class: ");
        fgets(sv[findIndex].classroomId, 10, stdin);
        sv[findIndex].classroomId[strcspn(sv[findIndex].classroomId, "\n")]= '\0';
        printf("Enter new Email: ");
        fgets(sv[findIndex].email, 30, stdin);
        sv[findIndex].email[strcspn(sv[findIndex].email, "\n")]= '\0';
        printf("Enter new Phone: ");
        fgets(sv[findIndex].phone, 20, stdin);
        sv[findIndex].phone[strcspn(sv[findIndex].phone, "\n")]= '\0';
        printf("Enter new Password: ");
        fgets(sv[findIndex].password, 20, stdin);
        sv[findIndex].password[strcspn(sv[findIndex].password, "\n")]= '\0';
        printf("\n\t***Updated The New Student***\n");
        printHeader();
        printStudent(length, sv);
        printf("\nStudent Edited Successfully.\n");
    }
}
void searchStudent(int length, struct Student sv[]){
    printf("\n\t***Search a Student***\n");
    getchar();
	char name[30];
    printf("\nEnter the name of the student to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(sv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nNo student found with the name %s.\n",name);
    }else{
        printf("\nStudent found with the name %s.\n",name);
        printf("Students Finded Successfully.\n\n");
	}
}
void sortStudentsByName(int length, struct Student sv[]){
    int choice4;
	do{
		printf("\n\t***Sort a Student***\n");
	    printf("\n");
	    printf("\t  SortStudents\n");
	    printf("\t=====================\n");
	    printf("\t[1] Increase.\n");
	    printf("\t[2] Reduce.\n");
	    printf("\t[0] Back.\n");
	    printf("\t=====================\n");
		printf("\tEnter the Choice: ");
	    scanf("%d", &choice4);
		switch(choice4){
			struct Student temp;
			int i,j;
			case 1:
			    printf("\n\t  Increase Sort\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)>0){
			                temp = sv[i];
			                sv[i] = sv[j];
			                sv[j] = temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents Are Placed Successfully.\n");
				break;
			case 2:
				printf("\n\t  Reduce Sort\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)<0){
			                temp=sv[i];
			                sv[i]=sv[j];
			                sv[j]=temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents Are Placed Successfully.\n");
				break;
			case 0:
				break;
			default:
				printf("\tERROR: Please try again.\n");
	    }
	}while(choice4!=0);
}
void menuTeacher(){
    printf("\n***Teacher Management System Using C***\n");
    printf("\n");
    printf("\t    TEACHER MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new Teacher.\n");
    printf("\t[2] Show All Teacher.\n");
    printf("\t[3] Delete A Teacher.\n");
    printf("\t[4] Edit A Teacher.\n");
    printf("\t[5] Search A Teacher.\n");
    printf("\t[6] Sort A Teacher.\n");
    printf("\t[7] Add Teacher to a Class.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}	
void addTeacher(int *length, struct Teacher tv[]){
    printf("\n\t***Add A New Teacher***\n");
	int newTeacher;
    printf("\nAdd number of Teacher: ");
    scanf("%d", &newTeacher);
    getchar(); 
    int i;
    for(i=*length;i<*length+newTeacher;i++){
        printf("\n       Teacher %d\n", i + 1);
        printf("Enter the ID: ");
        fgets(tv[i].teacherId, 10, stdin);
        tv[i].teacherId[strcspn(tv[i].teacherId, "\n")]= '\0'; 
        printf("Enter the Name: ");
        fgets(tv[i].fullName, 30, stdin);
        tv[i].fullName[strcspn(tv[i].fullName, "\n")]= '\0';
        printf("Enter the date of birth (dd / mm / yyyy): \n");
        printf("   Enter the day: ");
        scanf("%d", &tv[i].dateOfBrith.day);
        printf("   Enter the month: ");
        scanf("%d", &tv[i].dateOfBrith.month);
        printf("   Enter the year: ");
        scanf("%d", &tv[i].dateOfBrith.year);
        printf("Enter the Gender(1 for Male, 0 for Female): ");
        scanf("%d", &tv[i].gender);
        getchar(); 
        printf("Enter the Class: ");
        fgets(tv[i].classroomId, 10, stdin);
        tv[i].classroomId[strcspn(tv[i].classroomId, "\n")] = '\0';
        printf("Enter the Email: ");
        fgets(tv[i].email, 30, stdin);
        tv[i].email[strcspn(tv[i].email, "\n")]= '\0';
        printf("Enter the Phone: ");
        fgets(tv[i].phone, 20, stdin);
        tv[i].phone[strcspn(tv[i].phone, "\n")]= '\0';
        printf("Enter the Password: ");
        fgets(tv[i].password, 20, stdin);
        tv[i].password[strcspn(tv[i].password, "\n")]= '\0';
    }
    *length += newTeacher;
    printf("\nTeacher Added Successfully.\n");
}
void printHeader2(){
	printf("\n\t  ***All Teacher***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               | Password            |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
}		
void printTeacher(int length, struct Teacher tv[]){
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
            tv[i].teacherId,
            tv[i].classroomId,
            tv[i].fullName,
            tv[i].dateOfBrith.day,
            tv[i].dateOfBrith.month,
            tv[i].dateOfBrith.year,
            tv[i].gender ? "Male" : "Female",
            tv[i].email,
            tv[i].phone,
            tv[i].password);
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|---------------------|\n");
    }
}
void saveTeacherToFile(int length, struct Teacher tv[]){
    FILE *fptr = fopen("teachersData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(tv, sizeof(struct Teacher), 50, fptr);
    printf("Teacher data saved successfully\n");
    fclose(fptr);
}
void loadTeacherFromFile(int *length, struct Teacher tv[]){
    FILE *fptr = fopen("teachersData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(tv, sizeof(struct Teacher), 50, fptr);
    fclose(fptr);
}
void deleteTeacher(int *length, struct Teacher tv[]) {
    printf("\n\t***Delete a Teacher***\n");
    getchar();
	char id[10];
    printf("\nEnter the teacher ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(tv[i].teacherId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nTeacher with ID %s not found.\n", id);
    }else {
        printf("\nOne Teacher Found for ID: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",tv[findIndex].classroomId);
        printf("FullName: %s\n",tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",tv[findIndex].dateOfBrith.day,tv[findIndex].dateOfBrith.month,tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",tv[findIndex].email);
        printf("Phone: %s\n",tv[findIndex].phone);
        printf("Password: %s\n",tv[findIndex].password);
        for(i=findIndex;i<*length-1; i++){
            tv[i]=tv[i+1];
        }
        (*length)--;
        printf("\n\t***Updated The New Teacher ***\n");
        printHeader2();
        printTeacher(*length, tv);
        printf("\nTeacher Deleted Successfully.\n");
    }
}
void editTeacher(int length, struct Teacher tv[]) {
    printf("\n\t***Edit a Teacher***\n");
    getchar();
    char id[10];
    printf("\nEnter the teacher ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex=-1;
    int i;
    for(i=0;i<length;i++) {
        if(strcmp(tv[i].teacherId, id)==0) {
            findIndex=i;
            break;
        }
    }
    if (findIndex== -1) {
        printf("\nTeacher with ID %s not found.\n", id);
    }else{
        printf("\nOne Teacher Found for ID: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",tv[findIndex].classroomId);
        printf("FullName: %s\n",tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",tv[findIndex].dateOfBrith.day,tv[findIndex].dateOfBrith.month,tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",tv[findIndex].email);
        printf("Phone: %s\n",tv[findIndex].phone);
        printf("Password: %s\n",tv[findIndex].password);
        printf("\nEnter new Name: ");
        fgets(tv[findIndex].fullName, 30, stdin);
        tv[findIndex].fullName[strcspn(tv[findIndex].fullName, "\n")]= '\0';
        printf("Enter new date of birth (dd / mm / yyyy):\n");
        printf("   Enter new day: ");
        scanf("%d", &tv[findIndex].dateOfBrith.day);
        printf("   Enter new month: ");
        scanf("%d", &tv[findIndex].dateOfBrith.month);
        printf("   Enter new year: ");
        scanf("%d", &tv[findIndex].dateOfBrith.year);
        printf("Enter new Gender (1 for Male, 0 for Female): ");
        scanf("%d", &tv[findIndex].gender);
        getchar();
        printf("Enter new Class: ");
        fgets(tv[findIndex].classroomId, 10, stdin);
        tv[findIndex].classroomId[strcspn(tv[findIndex].classroomId, "\n")]= '\0';
        printf("Enter new Email: ");
        fgets(tv[findIndex].email, 30, stdin);
        tv[findIndex].email[strcspn(tv[findIndex].email, "\n")]= '\0';
        printf("Enter new Phone: ");
        fgets(tv[findIndex].phone, 20, stdin);
        tv[findIndex].phone[strcspn(tv[findIndex].phone, "\n")]= '\0';
        printf("Enter new Password: ");
        fgets(tv[findIndex].password, 20, stdin);
        tv[findIndex].password[strcspn(tv[findIndex].password, "\n")]= '\0';
        printf("\n\t***Updated The New Teacher***\n");
        printHeader2();
        printTeacher(length, tv);
        printf("\nTeacher Edited Successfully.\n");
    }
}
void searchTeacher(int length, struct Teacher tv[]){
    printf("\n\t***Search a Teacher***\n");
    getchar();
	char name[30];
    printf("\nEnter the name of the teacher to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(tv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nNo teacher found with the name %s.\n",name);
    }else{
        printf("\nTeacher found with the name %s.\n",name);
        printf("Teacher Finded Successfully.\n\n");
	}
}
void sortTeachersByName(int length, struct Teacher tv[]){
    int choice6;
	do{
		printf("\n\t***Sort a Teacher***\n");
	    printf("\n");
	    printf("\t  SortTeachers\n");
	    printf("\t=====================\n");
	    printf("\t[1] Increase.\n");
	    printf("\t[2] Reduce.\n");
	    printf("\t[0] Back.\n");
	    printf("\t=====================\n");
		printf("\tEnter the Choice: ");
	    scanf("%d", &choice6);
		switch(choice6){
			struct Teacher temp;
			int i,j;
			case 1:
			    printf("\n\t  Increase Sort\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(tv[i].fullName, tv[j].fullName)>0){
			                temp = tv[i];
			                tv[i] = tv[j];
			                tv[j] = temp;
			            }
			        }
			    }
			    printHeader2();
		        printTeacher(length,tv);
			    printf("\nTeachers Are Placed Successfully.\n");
				break;
			case 2:
				printf("\n\t  Reduce Sort\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(tv[i].fullName, tv[j].fullName)<0){
			                temp=tv[i];
			                tv[i]=tv[j];
			                tv[j]=temp;
			            }
			        }
			    }
			    printHeader2();
		        printTeacher(length,tv);
			    printf("\nTeachers Are Placed Successfully.\n");
				break;
			case 0:
				break;
			default:
				printf("\tERROR: Please try again.\n");
	    }
	}while(choice6!=0);
}


