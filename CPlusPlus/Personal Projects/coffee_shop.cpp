#include <iostream>
#include <memory>
#include <map>
#include <type_traits>
#include <vector>
#include <functional>

using namespace std;

class Beverage
{
    public :
        virtual string getDescription() = 0;
        virtual double getCost() = 0;
        virtual ~Beverage() = default;
};

class Espresso : public Beverage
{ 
    public :
        string getDescription() override {return "Espresso";}
        double getCost() override {return 2.0;}
};

class Latte : public Beverage
{ 
    public :
        string getDescription() override {return "Latte";}
        double getCost() override {return 3.0;}
};

class Cappucino : public Beverage
{ 
    public :
        string getDescription() override {return "Cappucino";}
        double getCost() override {return 3.25;}
};

class Machiatto : public Beverage
{ 
    public :
        string getDescription() override {return "Machiato";}
        double getCost() override {return 4.50;}
};

class Cortado : public Beverage
{ 
    public :
        string getDescription() override {return "Cortado";}
        double getCost() override {return 2.5;}
};

class Condiments : public Beverage
{
    public :
        Condiments(shared_ptr<Beverage> coffee) : coffee_(coffee){}

        string getDescription() override
        {
            return coffee_->getDescription();
        }

        double getCost() override
        {
            return coffee_->getCost();
        }

    protected :
        shared_ptr<Beverage> coffee_{};
};

class OatMilk : public Condiments
{
    public :
        OatMilk(shared_ptr<Beverage> coffee) : Condiments(coffee){}
    
        string getDescription() override
        {
            return coffee_->getDescription() + " with Oatmilk";
        }
    
        double getCost() override
        {
            return coffee_->getCost() + 0.50;
        }
};

class RegularMilk : public Condiments
{
    public :
        RegularMilk(shared_ptr<Beverage> coffee) : Condiments(coffee){}

        string getDescription() override
        {
            return coffee_->getDescription() + " with Regular Milk";
        }

        double getCost() override
        {
            return coffee_->getCost() + 0.25;
        }
};

class HeavyCream : public Condiments
{
    public :
        HeavyCream(shared_ptr<Beverage> coffee) : Condiments(coffee){}

        string getDescription() override
        {
            return coffee_->getDescription() + " with Heavy Cream";
        }

        double getCost() override
        {
            return coffee_->getCost() + 1.0;
        }
};

template<typename T>
void displayMenu(map<int, pair<string, shared_ptr<T>>>& map)
{
    string menuHeader{};

    if(is_same<T, Beverage>::value)
    {
        menuHeader = "Select Drink";
    }
    else
    {
        menuHeader = "Select Condiment";
    }
    
    cout << menuHeader << endl << endl;
    for(const auto& pair : map)
    {
        cout << pair.first << ". " << pair.second.first << endl;
    }

    cout << endl << "Enter Choice : ";
}

template<typename T>
bool verify(int choice, map<int, pair<string, shared_ptr<T>>>& map)
{
    if(map.count(choice) == 0)
    {
        cout << "\033[2J\033[1;1H";
        cerr << "ERROR : Invalid Menu Choice. Try Again." << endl << endl; 
        return false;
    }
    return true;
}

int main()
{
    map<int, pair<string,shared_ptr<Beverage>>> beverages{};
    vector<shared_ptr<Condiments>> orders{};
    map<pair<int, int>, shared_ptr<Condiments>> combos{};
    
    beverages[1] = make_pair("Espresso", make_shared<Espresso>());
    beverages[2] = make_pair("Latte", make_shared<Latte>());
    beverages[3] = make_pair("Cappucino", make_shared<Cappucino>());
    beverages[4] = make_pair("Machiatto", make_shared<Machiatto>());
    beverages[5] = make_pair("Cortado", make_shared<Cortado>());

    map<pair<int,string>, function<shared_ptr<Condiments>(shared_ptr<Beverage>)>> condimentFactories =
    {
        {make_pair(1, "Oatmilk"), [](shared_ptr<Beverage> b) {return make_shared<OatMilk>(b);}},
        {make_pair(2, "Regular Milk"), [](shared_ptr<Beverage> b) {return make_shared<RegularMilk>(b);}},
        {make_pair(3, "Heavy Cream"), [](shared_ptr<Beverage> b) {return make_shared<HeavyCream>(b);}},
    };

    for(const auto& bev : beverages)
    {
        int bevID = bev.first;
        auto actualBev = bev.second.second;

        for(const auto& condiment : condimentFactories)
        {
            int condimentID = condiment.first.first;
            auto factory = condiment.second;

            auto combo = factory(actualBev);
            combos.insert({make_pair(bevID, condimentID), combo});
        }
    }

    int choice{}, choice2{};
    bool runProgram{true};
    char run{};
    double total{};

    while(runProgram)
    {
        do
        {
            displayMenu(beverages);
            cin >> choice;
            
        } while(!verify(choice, beverages));
        cout << "\033[2J\033[1;1H";

        while(true)
        {
            cout << "Select Condiments" << endl << endl;
            for(const auto& pair : condimentFactories)
            {
                cout << pair.first.first << ". " << pair.first.second << endl;
            }

            cout << endl << "Enter Choice : ";
            cin >> choice2;

            auto it = combos.find(make_pair(choice,choice2));
            if(it == combos.end())
            {
                cout << "\033[2J\033[1;1H";
                cerr << "ERROR : Invalid Menu Choice. Try Again." << endl << endl;
                continue;
            }
            break;
        }

        auto drink = combos.find(make_pair(choice, choice2));
        orders.emplace_back(drink->second);
        total += drink->second->getCost();
    
        cout << "\033[2J\033[1;1H";
    
        cout << "Would You Like to Order More ( Y / N ) : ";
        cin >> run;
        
        runProgram = (run == 'n' || run == 'N') ? false : true;

        cout << "\033[2J\033[1;1H";
    }

    cout << string(25, '-') << endl;
    cout << "Order(s) :" << endl;
    cout << string(25, '-') << endl;
    for(const shared_ptr<Condiments>& coffee : orders)
    {
        cout << coffee->getDescription() << endl;
        cout << "Cost : $" << coffee->getCost() << endl;
        cout << endl;
    }
    cout << string(25, '-') << endl;
    cout << "Total Cost : $" << total << endl;
    cout << string(25, '-') << endl;

    
    return 0;
}
