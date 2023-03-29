#include <iostream>
#include <iomanip>

using namespace std;

class SaddleArea {
     private:
        string color;
        Saddle * p_saddle;
        SeatPost * p_seat_post;
     public:
        SaddleArea();
        SaddleArea(string m_color);
        SaddleArea(const SaddleArea & other);
        void Display() const;
};

class Bicycle {
    private:
        string model;
        SaddleArea * p_saddle_area;  
        Frame * p_frame;
        Wheel * p_wheel[2];
        FrontSet * p_front_set; 
    public:
        Bicycle();
        Bicycle(string m_model, string m_color);
        Bicycle(const Bicycle & other);
        void Display() const;
};

int main() { 
}




SaddleArea::SaddleArea() : color("Red") {}
SaddleArea::SaddleArea(string m_color) : color(m_color) {}
void SaddleArea::Display() const {cout << color << " Saddle Area.\n";}

SaddleArea::SaddleArea(const SaddleArea & other) {
  this->color = other.color;
  this->p_saddle = new Saddel(*(other.p_saddle));
  this->p_seat_post = new SeatPost(*(other.p_seat_post));
}

Bicycle::Bicycle() : model("Frozen"), p_saddle_area(new SaddleArea()) {}
Bicycle::Bicycle(string m_model, string m_color) : model(m_model), p_saddle_area(new SaddleArea(m_color)){}
void Bicycle::Display() const {
       cout << model << " Bicycle with ";
       p_saddle_area->Display();
}

// Bicycle::Bicycle(const Bicycle & other) {
//           this->model = other.model;   // step 1
//           this->p_saddle_area = new SaddleArea();    // step 2 
//           *(this->p_saddle_area) = *(other.p_saddle_area);   // step 3
// }

Bicycle::Bicycle(const Bicycle & other) {
      this->model = other.model;    // step 1
      this->p_saddle_area = new SaddleArea(*(other.p_saddle_area));    // step 2 + 3
      this->p_frame = new Frame(*(other.p_frame));
      this->p_front_set = new FrontSet(*(other.p_front_set));
      for (int i = 0; i < 2; ++i) {
        p_wheel[i] = new Wheel(*(other.p_wheel[i]));
      }
}