#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
typedef struct {
    char id[20];
    char name[50];
    int age;
    float score;
} Student;

Student students[MAX_STUDENTS];
int count=0;
void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("学生数量已达上限，无法添加！\n");
        return;
    }
    Student s;
    printf("请输入学号：");
    scanf("%s", s.id);
    printf("请输入姓名：");
    scanf("%s", s.name);
    printf("请输入年龄：");
    scanf("%d", &s.age);
    printf("请输入成绩：");
    scanf("%f", &s.score);
    students[count++] = s;
    printf("添加成功！当前学生数量：%d\n", count);
}

void insertStudent() {
    if (count >= MAX_STUDENTS) {
        printf("学生数量已达上限，无法插入！\n");
        return;
    }
    int pos;
    printf("请输入插入位置（1-%d）：", count + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1) {
        printf("位置无效！\n");
        return;
    }
    Student s;
    printf("请输入学号：");
    scanf("%s", s.id);
    printf("请输入姓名：");
    scanf("%s", s.name);
    printf("请输入年龄：");
    scanf("%d", &s.age);
    printf("请输入成绩：");
    scanf("%f", &s.score);

    for (int i = count; i >= pos; i--) {
        students[i] = students[i - 1];
    }
    students[pos - 1] = s;
    count++;
    printf("插入成功！当前学生数量：%d\n", count);
}

void deleteStudent() {
    if (count == 0) {
        printf("没有学生信息可删除！\n");
        return;
    }
    char id[20];
    printf("请输入要删除的学号：");
    scanf("%s", id);
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到该学生！\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    printf("删除成功！当前学生数量：%d\n", count);
}

void searchStudent() {
    if (count == 0) {
        printf("没有学生信息可查找！\n");
        return;
    }
    char id[20];
    printf("请输入要查找的学号：");
    scanf("%s", id);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("找到学生：\n");
            printf("学号：%s\n", students[i].id);
            printf("姓名：%s\n", students[i].name);
            printf("年龄：%d\n", students[i].age);
            printf("成绩：%.2f\n", students[i].score);
            return;
        }
    }
    printf("未找到该学生！\n");
}

void printStudents() {
    if (count == 0) {
        printf("没有学生信息可打印！\n");
        return;
    }
    printf("当前学生列表：\n");
    printf("学号\t姓名\t年龄\t成绩\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%.2f\n", 
               students[i].id, students[i].name,
               students[i].age, students[i].score);
    }
}

int main(){
    int choice;
    do {
        printf("\n=== 学生信息管理系统 ===\n");
        printf("1. 添加学生\n");
        printf("2. 插入学生\n");
        printf("3. 删除学生\n");
        printf("4. 查找学生\n");
        printf("5. 打印学生列表\n");
        printf("0. 退出\n");
        printf("请输入选择：");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: insertStudent(); break;
            case 3: deleteStudent(); break;
            case 4: searchStudent(); break;
            case 5: printStudents(); break;
            case 0: printf("退出系统...\n"); break;
            default:printf("无效选择，请重新输入！\n");
        }
    } while (choice != 0);
    return 0;
}

