#include <iostream>
#include <string> 
#include <vector>
using namespace std;

class Database{
    string name,date_of_birth,address;
    int roll_number,classs,division;
    static int number_of_students;
public:
    Database(){
        name = "";
        date_of_birth = "";
        address = "";
        roll_number = 0;
        classs = 0;
        division = 0;
        number_of_students++;
    }
    Database(string name,string dob,string add,int r,int c,int d){
        this->name = name;
        this->date_of_birth = dob;
        this->address = add;
        this->roll_number = r;
        this->classs = c;
        this->division = d;
        number_of_students++;
    }
    Database(Database &c){
        this->name = c.name;
        this->date_of_birth = c.date_of_birth;
        this->address = c.address;
        this->roll_number = c.roll_number;
        this->classs = c.classs;
        this->division = c.division;
        number_of_students++;
    }
    ~Database(){
        cout << "Student " << name << " has been deleted from the database." << endl;   
    } 
    static void total_students(){
        cout << "Total number of students = " << number_of_students << endl;
    }
    inline void displayName(){
        cout << "Name = " << name << endl;
    }
    inline void displayAddress(){
        cout << "Address = " << address << endl;
    }
    inline void displayDivision(){
        cout << "Division = " << division << endl;
    }
    void display(){
        cout << "----------------------------" << endl;
        cout << "NAME = " << name << endl;
        cout << "DIVISION = " << division << endl;
        cout << "ADDRESS = " << address << endl;
        cout << "DATE OF BIRTH = " << date_of_birth << endl;
        cout << "ROLL NUMBER = " << roll_number << endl;
        cout << "CLASS = " << classs << endl;
        cout << "----------------------------" << endl;
    }
    friend class Marks;
};

class Marks{
    float percentage;
public:
    Marks(){
        percentage = 0;
    }
    Marks(float percentage){
        this->percentage = percentage;
    }
};

int Database::number_of_students = 0;

int main()
{
    Database d1;
    d1.display();
    Database d2("Ritanshu", "22/10/2003", "Pune", 21167, 12, 1);
    d2.display();
    Database d3 = d2;
    d2.display();
    Database *d4 = new Database("a","b","c",1,2,3);
    d4->display();
    delete(d4);
    Database d5;
    d5.displayAddress();
    d5.displayDivision();
    d5.displayName();
    Database::total_students();
    return 0;
}