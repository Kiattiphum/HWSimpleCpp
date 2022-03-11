#include <iostream>
#include <iomanip>

using namespace std;

struct Time{
  int m,h,s;
};

void getTime(struct Time &t){ 
  cout << "Example formath hour:min:sec"<<endl;  
  cin >> t.h;
  cin.ignore(1, ':');
  cin >> t.m;
  cin.ignore(1, ':');
  cin >> t.s;
}

struct Time subtract(struct Time &t2,struct Time &t1){
  
  struct Time t;
  t.s = t2.s-t1.s;
  t.m = t2.m-t1.m;
  t.h = t2.h-t1.h;
  
  if (t.s<0){
    t.m -=1;
    t.s = 60 + t.s;
    if (t.m<0){
      t.h -=1;
      t.m = 60 + t.m;
    }
  }
  else if (t.m<0){
    t.h -=1;
    t.m = 60 + t.m;
  }
  return t;
}

int main(){
  struct Time t1,t2,t3;
  cout<<"What time was it?"<<endl;
  getTime(t1);;
  cout<<"What time is it now?"<<endl;
  getTime(t2);
  t3=subtract(t2,t1);
  cout<<"Time diff is ";
  cout<<setfill('0')<<setw(2)<<t3.h<<":";
  cout<<setfill('0')<<t3.m<<":";
  cout<<setfill('0')<<t3.s<<endl;

}
