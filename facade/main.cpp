#include <iostream>
using namespace std;

class Clothes{
    ~Clothes(){
        delete this;
    }
};

class WashingMaschine{
public:
    ~WashingMaschine(){
        delete this;
    }
    void Wet(Clothes* c){
        cout << "Wetting...\n";
    }
    void Clean(Clothes* c){
        cout << "Cleaning...\n";
    }
    void Dry(Clothes* c){
        cout << "Drying...\n";
    }
};

class Facade{
    WashingMaschine* w;
public:
    Facade(WashingMaschine* w){
        this->w = w;
    }
    void Wash(Clothes* c){
        w->Wet(c);
        w->Clean(c);
        w->Dry(c);
        cout << "Washed!\n";
    }
};

int main() {
    Clothes* c = new Clothes;
    WashingMaschine* w = new WashingMaschine;
    Facade f(w);
    f.Wash(c);
}
