#include<iostream>
using namespace std; 
class Singleton 
{
   private:
     static Singleton *instance;
     Singleton() {};
     string Name;
   public:
      static Singleton* getInstance() 
      {
          if(instance == NULL)
             instance = new Singleton();
         
          return instance;
      }
      void setName(string name)
      {
          Name = name;
      }
      string getName()
      {
          return Name;
      }
};
Singleton* Singleton::instance = NULL;
int main()
{
    Singleton::getInstance()->setName("Paarth");
    cout << Singleton::getInstance()->getName() << endl; 
    Singleton::getInstance()->setName("SaiSaran");
    cout << Singleton::getInstance()->getName() << endl;
}

Output:
Paarth
SaiSaran
