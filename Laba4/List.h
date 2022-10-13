#pragma once
#include <fstream>
using namespace std;
 
    class MyList{                                      
        int x,count_;
        MyList *Head, *Tail, *Next, *Prev;
    public:
        MyList():count_(0),Head(NULL),Tail(NULL){};
        
        void Add(int);
        void Show(ofstream &fout);
        int GetCount() { return count_; }
        MyList *GetHead() { return Head; }
        MyList* GetTail() { return Tail; }
        MyList* GetNext() { return Next; }
        int Get_x() { return x; }
        
        
        void Del(int);
        
        ~MyList();
    };

   void MyList::Add(int x){
        MyList *temp = new MyList;
        temp->x = x;
        temp->Next = NULL;
        count_++;
        if (!Head){
            temp->Prev = NULL;
            Head = temp;
            Tail = Head;
        } else {
            temp->Prev = Tail;                  
            Tail->Next = temp;                  
            Tail = temp;                        
        }
    }

    void MyList::Show(ofstream & fout){
        
        MyList *t = Head;
        while (t){
            fout << t->x << " ";
            t = t->Next;
        }
        fout << "\n\n";
    }

    void MyList::Del(int x){

            if ((x == 1) and (Head->Next)){                     
                MyList *temp = Head;	                        
                Head = Head->Next;	                            
                Head->Prev = NULL;	                            
                delete temp;		                           
                count_--;		                                
                return ;		                                
            } else if ((x == 1) and (Head == Tail)){            
 
                Head->Next = NULL;	                           
                Head = NULL;
                delete Head;		                            
                count_ = 0;		                                
                return;			                               
            }
 
        
        if (x==count_){
            MyList *temp = Tail;	                            
            Tail = Tail->Prev;	                                
            Tail->Next = NULL;	                                
            delete temp;	                                    
            count_--;		                                    
                return;		                                    
        }

        MyList *temp = Head, *temp2;                        
              for (int i=0; i<x-1; i++) temp = temp->Next;  
              temp2 = temp;	                                
              temp2->Prev->Next =   temp->Next;	            
              temp2->Next->Prev = temp->Prev;               
                 delete temp;                               
	      count_--;                                         
    }
 
 

    MyList::~MyList(){
     
        while (Head){
               
            Tail=Head->Next;
            delete Head;
            Head=Tail;
        }
    }