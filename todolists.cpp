#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <time.h>

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

struct ProgressiveList
{
    string progress_title;
    string progress_desc;
};

class List{
    public:
        void insertList (struct list_todo** headRef, int day, int month, int year, int hour, int minute, string title, string desc);
        void displayList (struct list_todo* list);
        void sortlist(struct list_todo *unsorted_node);
        void deleteList(struct list_todo ** headRef, int position);

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

    if(list == NULL){
       cout<<"There is nothing here! Plan something!"<<endl; 
    }

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

void displayStackList (stack <struct ProgressiveList> stacks){
	if(stacks.empty()){
		cout<<"There is nothing here! Plan something!"<<endl;
	}
    int i = 1;
    while(!stacks.empty()){
        cout << i <<"] "<< stacks.top().progress_title <<endl;
        cout<<"Description: "<< stacks.top().progress_desc<<endl;
        i++;
        stacks.pop();
        cout<<"\n";
    }
}



int main()
{
    int day,month,year,hour,minute,num,menu,delnumtd,delnumpg;
    char submenu, again;
    string title, desc, name;
    list_todo *new_node = NULL;

    stack <ProgressiveList> stacks;
    stack <ProgressiveList> restacks;
    ProgressiveList progressivelist;

    List list; 

    char currDate[30];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    cout<<"Welcome to My-ToDoList"<<"\n\n";
    cout<<"What is your name? ";
    cin>>name;
    
    cout<<"Hi, "+name+"!"<<endl;
	sprintf(currDate, "%d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    cout<<currDate<<"\n\n";
	
	cout<<"Here are the instructions to use this app:\n"<<endl;
	
	cout<<"[1] Show my lists"<<endl;
	cout<<"[2] Create new todo-list"<<endl;
    cout<<"[3] Create progressive list"<<endl;
    cout<<"[4] Delete todo-list"<<endl;
    cout<<"[5] Delete progressive-list"<<endl;
	cout<<"[0] Exit"<<endl;
	cout<<"Enter Command: ";
	cin>>menu;
	cout<<"\n\n";
	
	if(menu==0){
		cout<<"Thank you for using our program!";
		return 0;
	}
	
	while(menu!=0){
		if(menu==1){
            cout<<"a) Show your to do list"<<endl;
            cout<<"b) Show your progressive list"<<endl;
            cout<<"Enter Command: ";
            cin>>submenu;
            cout<<endl;
            if (submenu == 'a') {
                list.displayList(new_node);}
            else if (submenu == 'b') {
                displayStackList(restacks);
            }
		}
		else if(menu == 2){
			cout<<"How many notes do you want to make? ";
	  	    cin>>num;
	    	cin.ignore();
		    
	   	    for(int i=0; i<num; i++)
		  	{
		 		cout<<"Title: ";
	  	 		getline(cin,title);
		
	 		    cout<<"Date (dd-mm-yyyy): ";
	 	 	    scanf("%d-%d-%d",&day, &month, &year);
	    	
		   		cout<<"Time (hh:mm): ";
		 	    scanf("%d:%d",&hour, &minute);
		
		  	    cout<<"Description: ";
		   	    cin.ignore();
		     	getline(cin,desc);
		     	cout<<"\n";
		
		  	    list.insertList(&new_node, day, month, year, hour, minute, title, desc);
		  	    list.sortlist(new_node);
	  		}
            
            
		}

        else if(menu == 3){
            cout<<"Progressive's list: "<<endl;
            int j = 1;
            do{
                cout<<j<<"] Title: ";
                cin.ignore();
                getline(cin,title);
                cout<<"Description: ";
                getline(cin,desc);
                cout<<"\n";

                progressivelist.progress_title = title;
                progressivelist.progress_desc = desc;

                stacks.push(progressivelist);
                cout<<"Again (y/n)?";
                cin>>again;
                j++;

            }while(again!='n');
            
            while(!stacks.empty()){
                restacks.push(stacks.top());
                stacks.pop();
            }

        }
        
        else if(menu == 4 ){
        	
        	list.displayList(new_node);
        	cout<< "Enter which number you want to delete :";
        	cin>>delnumtd;
        	list.deleteList(&new_node,delnumtd);
        	list.displayList(new_node);
			
		}
		
	else if(menu == 5 ){
        	       	
        	restacks.pop();
        	displayStackList(restacks);
			
		}
    
    cout<<"[1] Show my list"<<endl;
	cout<<"[2] Create new todo-list"<<endl;
    cout<<"[3] Create Progressive List"<<endl;
    cout<<"[4] Delete todo-list"<<endl;
    cout<<"[5] Delete progressive-list"<<endl;
	cout<<"[0] Exit"<<endl;
	cout<<"Enter Command: ";
	cin>>menu;
	cout<<"\n\n";
	}
   
    cout<<"Thank you for using our program!";

    return 0;
}
