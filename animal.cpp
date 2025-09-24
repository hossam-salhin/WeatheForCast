#include <iostream>
#include <vector>


class Animal
{
    public:
    Animal(){}
    virtual void Makesound() = 0;
    virtual~Animal()
    {
        std::cout << "animal destructor\n";
    }

    private:
};

class Cat :public Animal
{
    public:
    Cat(){}
    void Makesound()
    {
        std::cout << "cat sound\n";
    }
    ~Cat()
    {
        std::cout << "destructor of cat is called\n";
    }

};

class Dog : public Animal
{
    public:
    Dog(){}
    void Makesound()
    {
        std::cout << "Dog sound\n";
    }
    ~Dog()
    {
        std::cout << "destructor of dog is called\n";
    }
    void Dog_walking()
    {
        std::cout << "Dog is walking\n";
    }

    private:
};

void print_sound(std::vector<Animal *>& animals)
{
    for(auto animal : animals)
    {
        animal->Makesound();
        if(Dog * Dog_ptr = dynamic_cast<Dog *>(animal))
        {
            Dog_ptr->Dog_walking();
        }
    }
}

int main()
{
    std::vector<Animal *> vect;
    Dog d1, d2, d3;
    Cat c1, c2, c3;
    
    vect.push_back(&d1);
    vect.push_back(&c1);
    vect.push_back(&d2);
    vect.push_back(&c2);
    vect.push_back(&d3);
    vect.push_back(&c3);

    print_sound(vect);

    return 0;
}