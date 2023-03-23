#include <iostream>
#include <fstream>
using namespace std;

class File{
public:
    void readFile(){
        ifstream file;
        file.open("Text_file.txt",ios::in);
        if(!file){
            cout << "The file you are trying to open does not exist." << endl;
            return;
        }
        string s;
        while(!file.eof()){
            getline(file,s);
            cout << s << endl;
        }
        file.close();
    }
    void writefile(){
        ofstream file;
        file.open("Text_file.txt",ios::out);
        string s;
        cout << "Enter text you wish to write in the file." << endl;
        getline(cin,s);
        file << s;
        file.close();
    }
    void addinfile(){
        ofstream file;
        file.open("Text_file.txt",ios::app);
        file << endl;
        string s;
        cout << "Enter text you wish to add onto the file." << endl;
        getline(cin,s);
        file << s;
        file.close();
    }
    void clear(){
        ofstream file;
        file.open("Text_file.txt",ios::out);
        string s = "";
        file << s;
        file.close();
    }
};

int main()
{
    File obj;
    while(true){
        cout << "1. Write on file/ Create file." << endl;
        cout << "2. Read from the file." << endl;
        cout << "3. Append onto the file." << endl;
        cout << "4. Clear the file." << endl;
        cout << "0. Exit." << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            obj.writefile();
        }
        else if(choice == 2){
            obj.readFile();
        }
        else if(choice == 3){
            obj.addinfile();
        }
        else if(choice == 4){
            obj.clear();
        }
        else if(choice == 0){
            break;
        }
        cout << "\n\n";
    }
    return 0;
}