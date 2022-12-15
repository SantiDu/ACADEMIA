#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Hand {
   private:
      string material;
      double length;
   public:
       static const string DEFAULT_MATERIAL;
       static const double DEFAULT_LENGTH;
   public:
        Hand ( );
        Hand ( string m_material, double m_length );
};

class Clock {
   private: 
      Hand hand;
   public:
      Clock ( );
      Clock ( string material, double length );
};

int main() {
    return 0;
}

const string Hand::DEFAULT_MATERIAL = "Unknown";
const double Hand::DEFAULT_LENGTH = 0.0;

Hand::Hand () : material (Hand::DEFAULT_MATERIAL), length (Hand::DEFAULT_LENGTH) {}
Hand::Hand (string m_material, double m_length ) : material (m_material), length (m_length) {}
Clock::Clock (string material, double length ) : hand (material, length)  {}
Clock::Clock () {}
