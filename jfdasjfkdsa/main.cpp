#include <iostream>
#include <string>

using namespace std;

class Dog{
    private:
    string name;
    string breed;
    float weight;
    int numLegs;
    char gender;

    public:
    void setName(string); //setter
    void speak();
    string getName();
};

// struct Dog{
//     string name;
//     string breed;
//     float weight;
//     int numLegs;
//     char gender;

// };

// void speak(Dog);


int main(int argc, char* argv[]){

    Dog dog1;

    dog1.setName("Novo");
    // dog1.breed = "Husky";
    // dog1.weight = 50;
    // dog1.numLegs = 4;
    // dog1.gender = 'M';

    dog1.speak();
    cout << "The name of dog1 is: "<< dog1.getName()<< endl;
    return 0;
}
// void speak(Dog dog)
// {
//     cout<< dog.name << " barks."<< endl;
// }
void Dog::setName(string newName) //setter
    {
        while(!(newName.length()< 10))
        {
            //if(newName.length()> 10)
            cout << "The name is longer than 10 characters, try again"<< endl;

            getline(cin,newName);
        }
        name = newName;
    
    
    }
string Dog::getName()
{
    return name;
}

    void Dog::speak()
{
    cout<< name << " barks."<< endl;
}