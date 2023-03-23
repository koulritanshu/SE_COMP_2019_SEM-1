#include <iostream>
#include <map>
#include <string>
using namespace std;

class MapOfIndia{
    map<string,long long int> m;
public:
    MapOfIndia(){
        m["Uttar Pradesh"] = 199812341;
        m["Maharashtra"] = 112374333;
        m["Bihar"] = 104099452;
        m["West Bengal"] = 91276115;
        m["Madhya Pradesh"] = 72626809;
        m["Tamil Nadu"] = 72147030;
        m["Rajasthan"] = 68548437;
        m["Karnataka"] = 61095297;
        m["Gujarat"] = 60439692;
        m["Andhra Pradesh"] = 49386799;
        m["JammuAndKashmir"] = 12267013;
        m["Punjab"] = 27743338;
        m["Haryana"] = 25351462;
        m["Uttarakhand"] = 10086292;
        m["Himachal Pradesh"] = 6800000;
        m["Tripura"] = 3660000;
        m["Nagaland"] = 2280000;
        m["Assam"] = 31205576;
        m["Kerala"] = 33406061;
        m["Odisha"] = 15091123;
        m["Jharkhand"] = 4109874;
        m["Telangana"] = 2875231;
        m["Meghalaya"] = 1901234;
        m["Mizoram"] = 3244510;
        m["Sikkim"] = 990987;
        m["Arunachal Pradesh"] = 9908901;
        m["Chattisgarh"] = 19865297;
        m["Manipur"] = 30865297;
    }
    void addState(){
        cout << "Enter the name of the state: ";
        string nameOfState;
        getline(cin,nameOfState);
        if(m[nameOfState]){
            cout << "State already exists." << endl;
        }
        else{
            int pop;
            cout << "Enter the population of the state: ";
            cin >> pop;
            m[nameOfState] = pop;
        }
    }
    void removeState(){
        cout << "Enter the name of the state: ";
        string n;
        getline(cin,n);
        if(m[n]){
            m[n] = 0;
        }
        else{
            cout << "State does not exist." << endl;
        }
    }
    void updatePopulation(){
        string n;
        cout << "Enter the name of the state: ";
        getline(cin,n);
        int pop;
        cout << "Enter the population of the state: ";
        cin >> pop;
        m[n] = pop;
    }
    void display(){
        cout << "---------------------------------------" << endl;
        cout << "STATE -> POPULATION" << endl;
        int x = 1;
        for(auto i:m){
            if(m[i.first]){
                cout << x << ". " << i.first << "  ==>  " << i.second << endl;
                x++;
            }
        }
        cout << "---------------------------------------" << endl;
    }
};

int main()
{
    MapOfIndia obj;
    while(true){
        cout << "1. Check states and their populations." << endl;
        cout << "2. Change population." << endl;
        cout << "3. Add state." << endl;
        cout << "4. Remove state" << endl;
        cout << "0. Exit." << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            obj.display();
        }
        else if(choice == 2){
            obj.updatePopulation();
        }
        else if(choice == 3){
            obj.addState();
        }
        else if(choice == 4){
            obj.removeState();
        }
        else if(choice == 0){
            break;
        }
        cout << "\n";
    }
    return 0;
}