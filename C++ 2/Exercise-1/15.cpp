#include <iostream>
#include <iomanip>

using namespace std;

class Order {
   public:
     bool is_packed() const;
     void ShipOrder();
};

int main () {
     const int kMaxOrder = 2;
     const int kNCustomers = 1024;
     const int kNOrders = 32;
     Order orders[kNCustomers][kNOrders];
     for (Order (&customer_orders)[kNOrders] : orders) {
          int n_order = 0;
          for (Order &customer_order : customer_orders) {
               if (customer_order.is_packed()) {
                    customer_order.ShipOrder();
                    ++n_order;
                    if (n_order >= kMaxOrder) {
                         break;
                    }
               }
          }
     }
     return 0;
}