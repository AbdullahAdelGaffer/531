#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SBD.h"


bool SDB_ISFull();//checking the database is full or not
uint8 SDB_GetUsedSize();//counting the number of students in the database
bool SDB_AddEntry();//for adding a student
bool SDB_ReadEntry(uint32 id);//for deleting a student

bool SDB_IsIdExit(uint32 id);//for checking if the student is exist or not
void printList(void);//for printing data of students


student *head = NULL;//head pointer to the first node in dynamic memory allocation (global instead passing it to each function)

int main()
{
    printf("%d\n", SDB_AddEntry());
    printf("%d\n", SDB_AddEntry());
    //SDB_DeleteEntry(2);
     printf("%d\n",SDB_IsIdExit(3));
    //printList();





    return 0;
}
bool SDB_ISFull()
{
    if (SDB_GetUsedSize() == 10)//if number of students is ten?
    {
        return true;//full
    }
    else //not reaching 10?
    {
        return false;//not full
    }
}
uint8 SDB_GetUsedSize()
{
    uint8 count = 0;//for counting students
    student *ptr = head;//for traversing over the database
    while(ptr != NULL)//until reaching after the last node
    {
        count++;//incrementing for each student
        ptr = ptr->link;//to traversing through the next nodes
    }
    return count;//return the number of students
}
bool SDB_AddEntry()
{
    student *temp = malloc(sizeof(student)); //for creating a place in DMA of size structure(student)
    static uint8 count = 0;//for counting each student added

    count++;//incrementing for each student added
    if(count > 10)//maximum students is 10
    {
        return false;//not added if more than 10 students
    }

    //for the user(just a message)
    printf("Enter the data for the student %d\n",count);
    printf("Enter student ID\n"
           "Student_year\n"
           "Course1_ID\n"
           "Course1_grade\n"
           "Course2_ID\n"
           "Course2_grade\n"
           "Course3_ID\n"
           "Course3_grade\n");
    //Scanning the data for each student from the user
    scanf("%d%d%d%d%d%d%d%d", &temp->Student_ID, &temp->Student_year, &temp->Course1_ID, &temp->Course1_grade, &temp->Course2_ID, &temp->Course2_grade,
          &temp->Course3_ID, &temp->Course3_grade);

    temp->link = NULL;//each node will be created will be the last node

    if(head == NULL)//if the first node
    {
        head = temp;//assigning the head pointer to the first node
    }
    else //if it is not the first node
    {
        student *ptr = head; //for traversing the list
        while(ptr->link != NULL)//until reaching the last node to add after it
        {
            ptr = ptr->link;//traversing through the next nodes
        }
        ptr->link = temp;//linking the link part of the last node(ptr->link) with the new node (temp)
    }
    return true;
}
void SDB_DeleteEntry(uint32 id)
{
    if(head == NULL)//if the database is empty
    {
        printf("there are no students in the database!\n");
        return;
    }
    else if(head->Student_ID ==  id)//if the first student
    {
        free(head);//deleting the first student
        head = NULL;
    }
    else//if any student other than the first one
    {
        student* prev = head;//creating a pointer which points to the node before the required one
        student* current = head;//creating another pointer which points to the required one
        while(current->link != NULL)//until reaching the ID of the required student
        {
            prev = current;//to be behind the current pointer by a step
            current = current->link;//traversing the current pointer
            if(current->Student_ID == id)//if the student ID is the required one?
            {
                prev->link = current->link;//matching the previous node with the next node
                free(current);//deleting the student fro the database
                current = NULL;
                return;//no need to complete the loop after deleting the required student
            }
        }
    }
}
bool SDB_ReadEntry(uint32 id)
{
    if(head == NULL)//if the database is empty
    {
        printf("there are no students in the database!\n");
        return;
    }
    else
    {
        student* ptr = head;
        while(ptr != NULL)//until the last node
        {
            if(ptr->Student_ID == id)
            {
                //printing the whole data for the required student
                printf("the data for the student:\n");
                printf("student ID: %d\nStudent_year: %d\n"
                "Course1_ID: %d\nCourse1_grade: %d\n"
                "Course2_ID: %d\nCourse2_grade: %d\n"
                "Course3_ID: %d\nCourse3_grade: %d\n",ptr->Student_ID, ptr->Student_year , ptr->Course1_ID, ptr->Course1_grade , ptr->Course2_ID, ptr->Course2_grade, ptr->Course3_ID, ptr->Course3_grade);

                return true;
            }

            ptr = ptr->link;
        }
    }
    return false;
}

bool SDB_IsIdExit(uint32 id)
{
    if(head == NULL)//if the database is empty
    {
        printf("there are no students in the database!\n");
        return;
    }
    else
    {
        student* ptr = head;
        while(ptr != NULL)//until the last node
        {
            if(ptr->Student_ID == id)
            {
                return true;
            }
            ptr = ptr->link;
        }
    }
    return false;
}
void printList(void)
{
    uint8 i = 1; //used for showing student 1 or 2 or 3 .....
    if(head == NULL)//if the database is empty
    {
        printf("There are no students!\n");
    }
    else//if the database has students
    {
        student* ptr = head;//for traversing through the nodes
        while(ptr != NULL)//until reaching after the last node(we don't write ptr->next because in this case the last student will not be printed)
        {
            //printing the data for each student
            printf("the data for the student %d\n",i);
            printf("student ID: %d\nStudent_year: %d\n"
           "Course1_ID: %d\nCourse1_grade: %d\n"
           "Course2_ID: %d\nCourse2_grade: %d\n"
           "Course3_ID: %d\nCourse3_grade: %d\n",ptr->Student_ID, ptr->Student_year , ptr->Course1_ID, ptr->Course1_grade , ptr->Course2_ID, ptr->Course2_grade, ptr->Course3_ID, ptr->Course3_grade);

            ptr = ptr->link;//for traversing to the next nodes
            i++;//incrementing
        }
    }
}




