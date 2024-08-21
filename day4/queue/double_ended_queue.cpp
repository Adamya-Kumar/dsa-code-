#include <iostream>
using namespace std;
void View();
class DoubleQueue
{
    int size;
    int front;
    int rear;
    int *arr;

public:
    DoubleQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    bool push_front(int value)
    {
        if (rear == ((front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
    }
    bool push_back(int value)
    {
        if (rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == 0)
        {
            rear++;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    void View();
    bool pop_front()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return false;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    bool pop_back()
    {
        if (rear == -1)
        {
            rear = front = 0;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    void View_back()
    {
        cout << arr[rear] << endl;
    }
};

void DoubleQueue ::View()
{
    cout << arr[front] << endl;
}
int main()
{
    DoubleQueue obj(8);
    obj.push_back(10);
    obj.push_back(20);
    obj.push_back(30);
    obj.push_back(40);
    obj.push_back(50);

    obj.View();
    obj.pop_front();
    obj.pop_back();
    obj.View();
    obj.View_back();

    return 0;
}