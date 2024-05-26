#include<iostream>
#include<vector>
using namespace std;
// Observer Interface
class Observer {
    public:
        virtual void update(float temperature,float humidity,float pressure) = 0;
};

// Subject (Weather Station) class
class WeatherStation 
{
  private:
      float temperature;
      float humidity;
      float pressure;
      vector<Observer *> observers;
  public:
      void registerObserver(Observer* observer)
      {
          observers.push_back(observer); 
      }
      void removeObserver(Observer* observer)
      {
          
      }
      void notifyObservers() 
      {
          for(Observer* observer : observers)
          {
            observer->update(temperature,humidity,pressure);
          }
      }
      void setMeasurements(float temp,float hum,float press) 
      {
          temperature = temp;
          humidity = hum;
          pressure = press;
          notifyObservers(); 
      }
 };
 
 class Display : public Observer 
 {
     public:
        void update(float temperature,float humidity,float pressure) 
        {
            cout << "Display : Temperature = " << temperature
                 << "C, Humidity = " << humidity 
                 << "%, Pressure = " << pressure << " hPa"
                 << endl;
        }
 };
 
 int main()
 {
     WeatherStation weatherStation;
     // Create display
     Display display1;
     Display display2;
     
     //Register displays as Observers
     weatherStation.registerObserver(&display1);
     weatherStation.registerObserver(&display2);
     
     //Simulate weather data updates
     weatherStation.setMeasurements(25.0,60,1013.2);
     weatherStation.setMeasurements(24.8,58,1014.5);
     
     return 0;
  }
 
 
 
 