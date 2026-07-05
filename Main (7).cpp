#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class MenuItem{
  int id;
  string name;
  int price;
  Public:
  MenuItem(int id,string name,int price){
    this->id=id;
    this->name=name;
    this->price=price;
  }
  string getName(){
    return name;
  }
  int getPrice(){
    return price;
  }
};

class Restaurant{
  int id;
  vector<MenuItem*>menu;
  string loc;
  public:
  Restaurant(int id,string loc){
    this->id=id;
    this->loc=loc;
  }
  void addMenu(MenuItem* m){
    menu.push_back(m);
  }
  vector<MenuItem*> getMenuFromRestaurant(){
    return menu;
  }
};

class RestaurantManager{
  vector<Restaurant*>RsManager;
  public:
  void AddRestaurant(Restaurant* r){
    RsManager.push_back(r);
};
  
class CartItem{
  MenuItem* ms;
  int qnty;
  public:
  CartItem(MenuItem* ms,int qty){
    this->ms=ms;
    this->qnty=qty;
  }
  void increaseqty(int x){
    this->qnty+=x;
  }
  string getName(){
    return ms->getname();
  }
  int getqty(){
    return qnty;
  }
};

Class Cart{
  Restaurant* restaurant;
  vector<CartItem*>items;
  public:
  Cart(){
    this->r=nullptr;
  }
  addToCart(CartItem* c){
    items.push_back(c);
  }
  void SetRestaurant(Restaurant* r1){
    this->restaurant=r1;
  }
  void AddRestaurant(Restaurant* r){
    this->restaurant=r;
  }
  Restaturant* getRestaturant(){
    return this->restaurant;
  }
  vector<CartItem*> getCartItem(){
    return items;
  }
};
  class User{
    int id;
    string name;
    string addr;
    Cart* cart;
    public:
    User(int id,string name,string addr){
      this->id=id;
      this->name=name;
      this->addr=addr;
      this->cart=new Cart();
    }
    Cart* getCart(){
      return cart;
    }
  };
enum class Status{
  PENDING,
  CONFIRMED,
  SHIPPED,
  DELIVERED,
  CANCELLED
};
class OrderItem{
  string name;
  int price;
  int qty;
  public:
  OrderItem(string name,int price,int qty){
    this->name=name;
    this->price=price;
    this->qty=qty;
  }
  string getName(){
    return name;
  }
  int getPrice(){
    return price;
  }
  int getQty(){
    return qty;
  }
};
class Order{
  Restaurant* r;
  User* u;
  vector<OrderedItem*>orderedItem;
  Status orderedstatus;
  public:
  Order(Restaurant* r1,User* u1){
    this->id=id;
    this->r=r1;
    this->u=u;
    Status::PENDING;
  }
  void addItem(orderedItem* i){
    orderedItem.push_back(i);
  }
  vector<OrderedItem*> getItem(){
    return orderedItem;
  }
  double getTotalPrice(){
      double totalprice=0;
      for(auto it:orderedItem){
        totalprice+=((it->getQty())*(it->getPrice()));
      }
      return totalprice;
  }
};

class EligibilityRules{
      public:
      virtual bool isEligible(Order* o1,double amount)=0;

      ~virtual EligibilityRules(){}
};

class MinCartValue::public EligibilityRules{
     private:
     double minimumCartValue;
     public:
     MinCartValue(int x){
        this->minimumCartValue=x;
     }
     bool isEligible(order* o1,double amount){
        return minimumCartValue>=amount;
     }
};

class DiscountStrategy{
    protected:
    EligibilityRules* rule;
     public:
     DiscountStrategy(EligibilityRules* r1){
        this->rule=r1;
     }
     virtual double discount(Order& o1,double currentamount)=0;
};

class PercentageDiscount::public DiscountStrategy{
      int p;
      public:
      PercentageDiscount(int x,EligibilityRules* rules):DiscountStrategy(rules){
        this->p=x;
      }
      double discount(order* o1,double currentamount)override{
        if(!rules->isEligible(Order* o1,double currentamount))return amount;
        return currentamount-(p*currentamount)/100;
      }
};

class FlatDiscount::public DiscountStrategy{
      int fd;
      public:
      FlatDiscount(int fd){
        this->fd=fd;
      }
      double discount(order* o1,double currentamount)override{
        return max(0,currentamount-fd);
      }
};

class Buy2get1free::public DiscountStrategy{
      public:
      double discount(order* o1,double currentamount){
        double amountoff=0;
        for(auto it:o1->getItem()){
            int i1=it->getQty()/3;
            amountoff+=it->getPrice();
        }
        return currentamount-amountoff;
      }
};

class DiscountEngine{
    vector<DiscountStrategy*>discountapplicable;
    public:
    void addDiscount(DiscountStrategy* ds){
        discountapplicable.push_back(ds);
    }
    double calculate(Order* o1){
       double amount=o1->getTotalPrice();
       for(auto it:discountapplicable){
        amount=it->discount(o1,amount);
       }
       return amount;
    }
};

class OrderService{
  static int nextOrderId;
  public:
  Order* placeOrder(User* u1){
    Cart* c2=u1->getCart();
    Order* order=new Order(c2->getRestaturant(),u1);
    for(auto CartItem:c2->getCartItem()){
      OrderItem* o1=new OrderItem(CartItem->getName(),CartItem->getPrice(),CartItem->getqty());
      order->addItem(o1);
    }
    return order;
  }
};
int OderService:nextOrderId=11;
int main() 
{   
    MenuItem* m1=new MenuItem(1,"pizza",200);
    MenuItem* m2=new MenuItem(2,"burger",120);
    Restaurant* r1=new Restaurant(3,"Kharagpur");
    r1->addMenu(m1);
    r2->addMenu(m2);
    User* u1=new User(4,"suman","bihar");
    CartItem* c1=new CartItem(m1,2);
    CartItem* c2=new CartItem(m2,3);
    Cart* ca1=u1->getCart();
    ca1->SetRestaurant(r1);
    ca1->addToCart(c1);
    ca1->addToCart(c2);
    
    return 0;
}