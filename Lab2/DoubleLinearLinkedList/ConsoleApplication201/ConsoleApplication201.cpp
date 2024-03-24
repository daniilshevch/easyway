#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
class Node
{
private:
    int data;
    Node* prev;
    Node* next;
    Node(int value = 0, Node* first = nullptr, Node* second = nullptr)
    {
        data = value;
        prev = first;
        next = second;
    }
    friend class DoubleLinkedList;
};
class DoubleLinkedList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    DoubleLinkedList(int value)
    {
        Node* additional = new Node(value);
        head = additional;
        tail = additional;
        length = 1;

    }
    DoubleLinkedList(initializer_list<int> input)
    {
        for (int x : input)
        {
            push_back(x);
        }
    }
    ~DoubleLinkedList()
    {
        clear();
    }
    void clear()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
    void resize(int newsize)
    {
        if (newsize <= length)
        {
            return;
        }
        else
        {
            int additional = newsize - length;
            for (int i = 0; i < additional; i++)
            {
                push_back(0);
            }
        }
    }
    void push_front(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            Node* additional = new Node(value);
            head->prev = additional;
            additional->next = head;
            head = additional;
        }
        length++;
    }
    int front()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return NAN;
        }
        else
        {
            return head->data;
        }
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node* temp = head->next;
            delete head;
            head = temp;
            if (head == nullptr)
            {
                tail = nullptr;
                return;
            }
            head->prev = nullptr;
            length--;
            
        }
    }
    void push_back(int value)
    {
        if (tail == nullptr)
        {
            tail = new Node(value);
            head = tail;
        }
        else
        {
            Node* additional = new Node(value);
            tail->next = additional;
            additional->prev = tail;
            tail = additional;
        }
        length++;
    }
    int back()
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return NAN;
        }
        else
        {
            return tail->data;
        }
    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            return;
        }
        else
        {
            if (tail->prev == nullptr)
            {
                head = nullptr;
                tail = nullptr;
                length--;
            }
            else
            {
                Node* temp = tail->prev;
                delete tail;
                tail = temp;
                tail->next = nullptr;
                length--;
            }
        }
    }
    void print_list()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node* current = head;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
    int size()
    {
        return length;
    }
    int& operator[](int index)
    {
        if (index >= length)
        {
            cout << "List subscript out of range. Created last element" << endl;
            push_back(0);
            return tail->data;
        }
        if (index == 0 && length > 0)
        {
            return head->data;
        }
        if (index == length - 1)
        {
            return tail->data;
        }
        Node* current = head;
        int counter = 0;
        while (current->next != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            counter++;
            current = current->next;
        }
    }
    void insert_on_index(int index, int value)
    {
        if (index >= length)
        {
            push_back(value);
            return;
        }
        else if (index < 0)
        {
            return;
        }
        else if (index == 0)
        {
            push_front(value);
        }
        else
        {
            Node* current = head;
            Node* previous = nullptr;
            int counter = 0;
            while (current->next != nullptr)
            {
                if (counter == index - 1)
                {
                    previous = current;
                }
                current = current->next;
                counter++;
            }
            Node* after = previous->next;
            Node* additional = new Node(value);
            previous->next = additional;
            additional->prev = previous;
            additional->next = after;
            after->prev = additional;
            length++;
        }
    }
    void remove(int index)
    {
        if (index >= length)
        {
            return;
        }
        if (index == 0)
        {
            pop_front();
            return;
        }
        if (index == length - 1)
        {
            pop_back();
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        int counter = 0;
        while (current->next != nullptr)
        {
            if (counter == index - 1)
            {
                previous = current;
            }
            current = current->next;
            counter++;
        }
        Node* temp = previous->next;
        Node* temp2 = temp->next;
        delete temp;
        previous->next = temp2;
        temp2->prev = previous;
        length--;
        
    }
};

int main()
{
    DoubleLinkedList first;
    first.push_back(1);
    for (int i = 2; i < 10; i++)
    {
        first.push_back(i);
    }
    first.print_list();
    cout << first.size() << endl;
    first.push_front(0);
    first.push_front(3);
    first.print_list();
    first.pop_back();
    first.pop_back();
    first.pop_back();
    first.pop_front();
    first.print_list();
    cout << first.size() << endl;
    cout << "----------------------" << endl;
    DoubleLinkedList second = { 0,1,2,3,4,5,6,7,8 };
    second.print_list();
    cout << second.size() << endl;
    second.insert_on_index(4, 0);
    second.print_list();
    cout << "--------------------" << endl;
    DoubleLinkedList third = { 0,1,2,3,4,5,6,7,8,9 };
    third.print_list();
    cout << third.size() << endl;
    third.remove(4);
    third.print_list();
    

   
    

    
    
}

