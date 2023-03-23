#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
    string name,dob;
    string telephone_number;
public:
    Student(){
        name = "";
        dob = "";
        telephone_number = "";
    }
    Student(string name,string dob, string telephone_number){
        this->name = name;
        this->dob = dob;
        this->telephone_number = telephone_number;
    }
    static bool cmp(Student &s1, Student &s2){
        return s1.name < s2.name;
    }
    void getValues(){
        cout << "ENTER NAME: ";
        getline(cin,name);
        cout << "ENTER DATE OF BIRTH: ";
        getline(cin,dob);
        cout << "ENTER TELEPHONE NUMBER: ";
        getline(cin,telephone_number);
    }
    void displayValues(){
        cout << "----------------------------------------" << endl;
        cout << "NAME OF STUDENT: " << name << endl;
        cout << "DATE OF BIRTH OF STUDENT: " << dob << endl;
        cout << "TELEPHONE NUMBER OF STUDENT: " << telephone_number << endl;
        cout << "----------------------------------------" << endl;
    }
    string getName(){
        return name;
    }
};

int main(){
    vector<Student> studentdata;
    while(true){
        cout << "1. Add student data." << endl;
        cout << "2. Read student data." << endl;
        cout << "3. Sort on the basis of name." << endl;
        cout << "4. Search on the basis of name." << endl;
        cout << "0. Exit." << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            Student s1;
            s1.getValues();
            studentdata.push_back(s1);
        }
        else if(choice == 2){
            for(int i=0;i<studentdata.size();i++){
                studentdata[i].displayValues();
            }
        }
        else if(choice == 3){
            sort(studentdata.begin(),studentdata.end(),Student::cmp);
        }
        else if(choice == 4){
            cout << "Enter name of the student: ";
            string n;
            getline(cin,n);
            bool present = false;
            for(int i=0;i<studentdata.size();i++){
                if(studentdata[i].getName() == n){
                    studentdata[i].displayValues();
                    present = true;
                    break;
                }
                else{
                    continue;
                }
            }
            if(!present){
                cout << "-------------------------" << endl;
                cout << "STUDENT RECORD NOT FOUND." << endl;
                cout << "-------------------------" << endl;
            }
        }
        else if(choice == 0){
            break;
        }
        cout << "\n";
    }
    return 0;
}