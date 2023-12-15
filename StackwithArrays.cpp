#include <iostream>
using namespace std;

#define n 100

class stack{

    int* arr;
    int top;
    
    public:
    stack()
    {
        arr = new int[n];
        top=-1;
    }

    void push(int a)
    {
        if(top == n-1)
        {
            cout<<"Stack overflow";
            return;
        }
        top++;
        arr[top]= a;
    }

    void pop()
    {
        if(top == -1)
        {
        cout<<"Cant pop";
        return;
        }
        top--;
    }

    int Top()
    {
       if (top == -1)
       {
        return -1;
       }
       return arr[top];
    }

    bool empty()
    {
        return top==-1;
    }

    void display()
    {
        for (int i=top;i>=0;i--)
        {
        cout<< arr[i]<<endl;
        }
    }
};


main()
{
  stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.display();
  cout<<st.Top();
  st.pop();
  cout<<st.Top();

}