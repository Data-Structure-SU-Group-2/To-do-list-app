#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

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

void insertList (struct list_todo** headRef, int day, int month, int year, int hour, int minute, string title, string desc){
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

void displayList (struct list_todo* list){
    while(list!=NULL){
        printf("%.2d-%.2d-%d\n", list->list_day,list->list_month,list->list_year);
        cout<<list->list_title;
        printf(" (%.2d:%.2d)\n", list->list_hour, list->list_minute);
        cout<<list->list_desc<<endl;
        list = list->next;
        cout<<"\n";
    }
    cout<<"\n";
}

void displayStackList (stack <list_todo*> stacks){
    while(!stacks.empty()){
        int i = 1;
        printf("%c %.2d-%.2d-%d\n",(char)254, stacks.top()->list_day,stacks.top()->list_month,stacks.top()->list_year);
        cout << i <<") "<< stacks.top()->list_title;
        printf(" (%.2d:%.2d)\n", stacks.top()->list_hour, stacks.top()->list_minute);
        cout<<"Description: "<< stacks.top()->list_desc<<endl;
        stacks.pop();
        cout<<"\n";
    }
}

int main()
{
    int day,month,year,hour,minute;
    string title, desc;
    list_todo *new_node = NULL;
    stack <list_todo*> stack;
    
    cout<<"Title: ";
    getline(cin,title);

    cout<<"Date (dd-mm-yyyy): ";
    scanf("%d-%d-%d",&day, &month, &year);
    
    cout<<"Date (hh:mm): ";
    scanf("%d:%d",&hour, &minute);

    cout<<"Description: ";
    cin.ignore();
    getline(cin,desc);
    cout<<"\n";

    insertList(&new_node, day, month, year, hour, minute, title, desc);
    stack.push(new_node);

    //ntar pake loop function biar bisa multiple input
    //ini nyoba" aja biar linkedlist ama stacknya rame
    insertList(&new_node, 12, 12, 2002, 9, 30, "apa", "aaa");
    stack.push(new_node);

    displayStackList(stack);
    
    //pake ini kalo mau liat berhasil ga bikin delete function
    //displayList(new_node);

    return 0;
}
