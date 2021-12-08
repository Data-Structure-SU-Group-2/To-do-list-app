#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <time.h>
#include "List.h"

using namespace std;

struct ProgressiveList
{
    string progress_title;
    string progress_desc;
};

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
                displayStackList(stacks);
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

            displayStackList(restacks);  
        }
        
        else if(menu == 4 ){
        	
        	list.displayList(new_node);
        	cout<< "Enter which number you want to delete :";
        	cin>>delnumtd;
        	list.deleteList(&new_node,delnumtd);
        	list.displayList(new_node);
			
		}
		
		else if(menu == 5 ){
        	
			//stacks.pop();        	
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

    return 0;
}
