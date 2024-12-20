/*#ifndef STUDENT_H
#define STUDENT_H

#include "List.h"

typedef struct {
	char name[30];
	int scores[5];
}Student;

// 学生节点结构体
typedef Node StudentNode;

// 学生列表结构体
typedef LinkList StudentList;

// 初始化学生列表
void initStudentList(StudentList* list);

// 插入学生
void insertStudent(StudentList* list, const Student* student);

// 打印学生列表
void printStudentList(const StudentList* list);

// 统计某门课程的成绩
void calGrade(const StudentList* list, int Index);


#endif // !STUDENT_H
*/