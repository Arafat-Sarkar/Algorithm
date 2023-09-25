#include<bits/stdc++.h>
using namespace std;

class Person 
 {
 public:
    string name;
    float  height;
    int   age;

    
    Person(string name, float height, int age) 
        {
        this->name = name;
        this->height = height;
        this->age = age;
    }

    
};

int main() {
    
      Person("Arafat", 165.5, 25);

    return 0;
}
