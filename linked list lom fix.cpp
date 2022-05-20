#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct list_todo
{
    int key;
    string name2;
    string name;
    list_todo *next;
};

struct list
{
    struct list_todo *first;
};

int main()
{
    
    list *head = new(list);
    list_todo *new_node = NULL;
    head->first = NULL;

    for(int i = 0; i < 10; i++)
    {
        
        new_node = new(list_todo);
        
        new_node->key = i;
        new_node->name = "hello\n\n";
        new_node->name2 = "helluo\n\n";

        

        new_node->next = head->first;

        
        head->first = new_node;

    }

     
     list_todo *travel;
     travel = head->first;

     while(travel != NULL)
     {
         cout << travel->name2 << endl;
         cout << travel->name << endl;
         travel = travel->next;
     }

    
    return 0;
}
