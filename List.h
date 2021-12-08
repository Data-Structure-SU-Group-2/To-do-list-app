#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <time.h>
using namespace std;

class List{
    public:
        void insertList (struct list_todo** headRef, int day, int month, int year, int hour, int minute, string title, string desc);
        void displayList (struct list_todo* list);
        void sortlist(struct list_todo *unsorted_node);
        void deleteList(struct list_todo ** headRef, int position);
};
#endif
