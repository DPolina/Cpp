#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class List{
private:
    class Node{
    public:
        string name;
        int heshID;
        Node* pNext;
        Node(string name, int heshID, Node* pNext = nullptr){
            this->name = name;
            this->heshID = heshID;
            this->pNext = pNext;
        }
    };
    Node* head;
    int isize;
    
    public:

    List(){
        head = nullptr;
        isize = 0;
    }

    void push_back(string name, unsigned int heshId){
        if(head == nullptr){
            head = new Node(name, heshId);
        } else {
            Node* current = this->head;
            while(current->pNext != nullptr){
                current = current->pNext;
            }
            current->pNext = new Node(name, heshId);
        }
        isize++;
    }
    
    void Print(){
        Node* it = head;
        while(it != nullptr){
            cout << it->name << "(" << it->heshID << ")" << " | ";
            it = it->pNext;
        }
        cout << endl;
    }

    string Find(unsigned int hesh){
        Node* it = head;
        while(it->heshID != hesh){
            it = it->pNext;
        }
        return it->name;
    }

};

class HashTable{
private:
    List* arr;
    int isize;
public:

    HashTable(){
        isize = 20;
        arr = new List[isize];
    }
    
    void Insert(string name, string value){
        unsigned int hesh = GetHesh(name);
        int ID = hesh % isize;
        arr[ID].push_back(value, hesh);
    }

    unsigned int GetHesh(string name){
        unsigned int value = 0;
        for(int i = 0, Id = 99; i < name.size(); i++, Id--){
            value += name.at(i) * Id;
        }
        return value;
    }

    void Print(){
        for(int i = 0; i< isize; i++){
            cout << " i = " << i << " : ";
            arr[i].Print();
        }
    }

    string GetInfo(string name){
        unsigned int hesh = GetHesh(name);
        int Id = hesh % isize;
        return arr[Id].Find(hesh);
    }
};

int main(){
    HashTable a;

    a.Insert("Fitz Nobody", "Green one");
    a.Insert("Vilen Galton", "Blue one");  
    a.Insert("Agata Nita", "Purple one");
    a.Insert("Sir Bronski", "Red one");  
    a.Insert("Flinn Pond", "Black one");  
    a.Insert("Gelitsia Aubvielts", "Propaganda committee");
    a.Insert("Sir Past", "Pimp");
    a.Insert("Kandia Letta", "Extractor. Red one");
    a.Insert("Evelina Van-Keyn", "Rector of the SAoP&CoB");
    a.Insert("Kamilla Voinich", "Detective agency");
    a.Insert("Alan Haimse", "Professor-commissar");  
    a.Insert("Milena Canih", "Occultist");
    a.Insert("Mark Dine", "Fucking genius");
    a.Insert("Dara River", "Symbol of rebellion");
    a.Insert("Wisper", "Servant of Morok");
    a.Insert("Brothers Jeabbs", "inventor and PR man");
    a.Insert("Sir O", "Orange one");
    a.Insert("Pim", "Burglar");
    a.Insert("Pyatno", "Usless member");
    a.Insert("Esta Van-Galts", "Boy-woman");
    a.Insert("Vespa", "Serpar-Burglar");
    a.Insert("Geyl River", "Usefull idiot");
    a.Insert("Sabaka", "Really good manager");
    a.Insert("Maxim Galton", "Sir with good manners");
    a.Insert("Salomeya", "Douther of the Maecenas");
    a.Insert("Ulphic Sebas", "Convict warden");
    a.Insert("Voicex Grabov", "Mental maniac");
    
    string b = a.GetInfo("Dara River");

    //a.Print();

    cout << b << endl;

    return 0;
}