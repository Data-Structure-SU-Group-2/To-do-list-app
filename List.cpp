#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <time.h>
#include "List.h"

using namespace std;

struct list_todo
{
    int list_day;
    int list_month;
    int list_year;
    int list_hour;
    int list_minute;
    string list_title;
    string list_desc;
    struct list_todo *next;
};

void List:: insertList (struct list_todo** headRef, int day, int month, int year, int hour, int minute, string title, string desc){
    list_todo* new_list = new list_todo();
    new_list->list_title = title;
    
    new_list->list_day = day;
    new_list->list_month = month;
    new_list->list_year = year;
    new_list->list_hour = hour;
    new_list->list_minute = minute;
    new_list->list_desc = desc;
    new_list->next = (*headRef);
    (*headRef) = new_list;    
}

void List::deleteList(struct list_todo **headRef, int position){
    if (*headRef == NULL){
        return;
    }

    struct list_todo *temp = *headRef;
    if (position == 1){
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 2; temp!= NULL && i<position-1; i++){
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL){
        return;
    }
    struct list_todo *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}


void List::displayList (struct list_todo* list){
    int i = 1;
    while(list!=NULL){
        printf("%d) %.2d-%.2d-%d\n",i, list->list_day,list->list_month,list->list_year);
        cout<<list->list_title;
        printf(" (%.2d:%.2d)\n", list->list_hour, list->list_minute);
        cout<<list->list_desc<<endl;
        list = list->next;
        cout<<"\n";
        i++;
    }
    cout<<"\n";
}

void List::sortlist(struct list_todo *unsorted_node){
    struct list_todo *current = unsorted_node, *index = NULL;
    int temp_year, temp_month, temp_day, temp_hour, temp_minute;
    string temp_title, temp_desc;

    while(current!=NULL){
        index = current->next;
        while (index!=NULL){
            if(current->list_year > index->list_year){
                temp_year = current->list_year;
                current->list_year = index->list_year;
                index->list_year = temp_year;

                temp_month = current->list_month;
                current->list_month = index->list_month;
                index->list_month = temp_month;

                temp_day = current->list_day;
                current->list_day = index->list_day;
                index->list_day = temp_day;
                
                temp_hour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = temp_hour;
                
                temp_minute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = temp_minute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
            }
            
            else if(current->list_year == index->list_year && current->list_month > index->list_month){
                

                temp_month = current->list_month;
                current->list_month = index->list_month;
                index->list_month = temp_month;

                temp_day = current->list_day;
                current->list_day = index->list_day;
                index->list_day = temp_day;
                
                temp_hour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = temp_hour;
                
                temp_minute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = temp_minute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
                
            }
            
            else if(current->list_year == index->list_year && current->list_month == index->list_month && current->list_day > index->list_day){
                

                temp_day = current->list_day;
                current->list_day = index->list_day;
                index->list_day = temp_day;
                
                temp_hour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = temp_hour;
                
                temp_minute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = temp_minute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
                
            }
            
            else if(current->list_year == index->list_year && current->list_month == index->list_month && current->list_day == index->list_day && current->list_hour > index->list_hour){
               
                
                temp_hour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = temp_hour;
                
                temp_minute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = temp_minute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
                
            }
            
            else if(current->list_year == index->list_year && current->list_month == index->list_month && current->list_day == index->list_day && current->list_hour == index->list_hour && current->list_minute > index->list_minute){
                
                
                temp_minute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = temp_minute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;                
            
            }

            index = index->next;
        }
        current = current->next;
    }
}
