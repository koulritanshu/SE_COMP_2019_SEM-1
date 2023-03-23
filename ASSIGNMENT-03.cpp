#include <iostream>
using namespace std;

class Publication{
    string title;
    float price;
public:
    Publication(){
        title = "";
        price = 0;
    }
    Publication(string title, float price){
        this->title = title;
        this->price = price;
    }
    void input(){
        cout << "Enter the title: ";
        getline(cin,title);
        cout << "Enter the price: ";
        cin >> price;
    }
    void print(){
        cout << "-----------------------------------" << endl;
        cout << "TITLE = " << title << endl;
        cout << "PRICE = " << price << endl;
    }
};

class Book:public Publication{
    int pageCount;
public:
    Book(){
        pageCount = 0;
    }
    Book(int pageCount){
        try{
            if(pageCount < 0){
                cout << "An exception has been caught." << endl;
                throw(pageCount);
            }
            else{
                this->pageCount = pageCount;
            }
        }
        catch(int pageCount){
            this->pageCount = 0;
        }
    }
    void input(){
        Publication::input();
        cout << "Enter the number of pages in the book: ";
        cin >> pageCount;
        try{
            if(pageCount < 0){
                cout << "An exception has been caught." << endl;
                throw(pageCount);
            }
            else{
                cout << "Pages added successfully." << endl;
            }
        }
        catch(int pageCount){
            this->pageCount = 0;
        }
    }
    void print(){
        Publication::print();
        cout << "NUMBER OF PAGES IN THE BOOK = " << pageCount << endl;
        cout << "-----------------------------------" << endl;
    }
};
class Tape:public Publication{
    float runningTime;
public:
    Tape(){
        runningTime = 0;
    }
    Tape(float runningTime){
        try{
            if(runningTime < 0){
                cout << "An exception has been caught." << endl;
                throw(runningTime);
            }
            else{
                this->runningTime = runningTime;
            }
        }
        catch(float runningTime){
            this->runningTime = 0;
        }
    }
    void input(){
        Publication::input();
        cout << "Enter the running time of the tape: ";
        cin >> runningTime;
        try{
            if(runningTime < 0){
                cout << "An exception has been caught." << endl;
                throw(runningTime);
            }
            else{
                cout << "Time added successfully." << endl;
            }
        }
        catch(float runningTime){
            this->runningTime = 0;
        }
    }
    void print(){
        Publication::print();
        cout << "RUNNING TIME OF THE TAPE = " << runningTime << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main(){
    Book obj1;
    Tape obj2;
    int book = 0;
    int tape = 0;
    while(true){
        cout << "1. Enter information for book." << endl;
        cout << "2. Enter information for tape." << endl;
        cout << "3. Read information for book." << endl;
        cout << "4. Read information for tape." << endl;
        cout << "0. Exit." << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        if(choice == 1){
            cin.ignore();
            obj1.input();
            book = 1;
        }
        else if(choice == 2){
            cin.ignore();
            obj2.input();
            tape = 1;
        }
        else if(choice == 3){
            if(book == 0){
                cout << "Give input first." << endl;
            }
            else{
                obj1.print();
            }
        }
        else if(choice == 4){
            if(tape == 0){
                cout << "Give input first." << endl;
            }
            else{
                obj2.print();
            }
        }
        else if(choice == 5){
            break;
        }
        cout << "\n\n";
    }
}