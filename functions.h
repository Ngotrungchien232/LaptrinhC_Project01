# include"datatype.h"
void menuStart();
void menuAdmin();
void menuStudents();
void inputStudent(int *length, struct Student sv[]);
void printHeader();
void printStudent(int length, struct Student sv[]);
void addStudent(int *length, struct Student sv[]);
void saveStudentToFile(int length, struct Student sv[]);
void loadStudentFromFile(int *length, struct Student sv[]);
void deleteStudent(int *length, struct Student sv[]);
void editStudent(int length, struct Student sv[]);
void searchStudent(int length, struct Student sv[]);
void sortStudentsByName(int length, struct Student sv[]);
void menuTeacher();
void printTeacher(int length, struct Teacher tv[]);
void addTeacher(int *length, struct Teacher tv[]);
void printHeader2();
void printTeacher(int length, struct Teacher tv[]);
void saveTeacherToFile(int length, struct Teacher tv[]);
void deleteTeacher(int *length, struct Teacher tv[]);
void editTeacher(int length, struct Teacher tv[]);
void searchTeacher(int length, struct Teacher tv[]);
void sortTeachersByName(int length, struct Teacher tv[]);


