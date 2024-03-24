#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;
class Node
{
private:
    int data;
    Node* next;
    Node(int value = 0, Node* ptr = nullptr)
    {
        data = value;
        next = ptr;
    }
    friend class SingleLinkedList;
};
class SingleLinkedList
{
private:
    Node* head;
    int length;
    Node* find_last()
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current;
    }
public:
    SingleLinkedList()
    {
        head = nullptr;
        length = 0;
    }
    SingleLinkedList(int value)
    {
        head = new Node(value);
        length = 1;
    }
    SingleLinkedList(initializer_list<int> input)
    {
        for (int x : input)
        {
            push_back(x);
        }
    }
    ~SingleLinkedList()
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
        int additional = newsize - length;
        for (int i = 0; i < additional; i++)
        {
            push_back(0);
        }
    }
    void push_front(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            length++;
        }
        else
        {
            Node* temp = head;
            head = new Node(value);
            head->next = temp;
            length++;
        }
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
            length--;
        }
    }
    void push_back(int value)
    {
        if (head == nullptr)
        {
            push_front(value);
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new Node(value);
            length++;
        }
    }
    int back()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return NAN;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            return current->data;
        }
    }
    void pop_back()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            length--;
        }
    }
    int size()
    {
        return length;
    }
    void print_list()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    int& operator[](int index)
    {
        if (index == 0 && length > 0)
        {
            return head->data;
        }
        if (index >= length)
        {
            cout << "List subscript out of range. Created last element" << endl;
            push_back(0);
            return find_last()->data;
        }
        Node* current = head;
        int counter = 0;
        while (current->next != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->next;
            counter++;
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
            return;
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
                counter++;
                current = current->next;
            }
            Node* temp = previous->next;
            Node* insertion = new Node(value);
            previous->next = insertion;
            insertion->next = temp;
            length++;
        }
    }
    void insert_array(int index, int* array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            insert_on_index(index + i, array[i]);
        }
    }
    void insert_array(int index, vector<int>array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            insert_on_index(index + i, array[i]);
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
                counter++;
                current = current->next;
            }
            Node* temp = previous->next;
            Node* temp2 = temp->next;
            delete temp;
            previous->next = temp2;
            length--;
            
        }
    }
    void remove_range(int index1, int index2)
    {
        if (index1 < 0 || index2 < 0 || index2 >= length)
        {
            return;
        }
        else
        {
            Node* current = head;
            int counter = 0;
            Node* previous = head;
            Node* temp = nullptr;
            while (current != nullptr)
            {
                if (counter < index1 - 1)
                {
                    previous = previous->next;
                    current = current->next;
                }
                if (counter == index1 - 1)
                {
                    current = current->next;
                }
                if (counter > index1 - 1 && counter <= index2)
                {
                    temp = current->next;
                    delete current;
                    current = temp;
                    if (index1 == 0)
                    {
                        head = temp;
                    }
                    
                }
                if (counter > index2)
                {
                    break;
                }
                counter++;
            }
            previous->next = current;
        }
        
    }
    vector<int> into_vector()
    {
        vector<int>output;
        Node* current = head;
       
        {
            output.push_back(current->data);
            current = current->next;
        }
        return output;
    }
    void reverse()
    {
        Node* current = head;
        Node* temp1 = nullptr;
        Node* extra = nullptr;
        while (current->next != nullptr)
        {
            if (current->next->next == nullptr)
            {
                extra = current;
            }
            
            Node* temp2 = current->next;
            Node* temp3 = current;
            current->next = temp1;
            current = temp2;
            temp1 = temp3;
       
        }
        head = current;
        head->next = extra;
    }
};

int main()
{
    SingleLinkedList first;
    for (int i = 0; i < 8; i++)
    {
        first.push_back(i);
    }
    first.print_list();
    first.pop_back();
    first.print_list();
    first.pop_front();
    first.print_list();
    cout << first.size() << endl;
    first.push_front(100);
    first.print_list();
    cout << "------------------" << endl;
    SingleLinkedList second;
    for (int i = 4; i < 12; i++)
    {
        second[i] = i;
    }
    second.print_list();
    for (int i = 0; i < 8; i++)
    {
        cout << second[i] << " ";
    }
    cout << endl;
    cout << second[8] << endl;
    cout << "--------------------" << endl;
    SingleLinkedList third;
    for (int i = 0; i < 10; i++)
    {
        third.push_front(i);
    }
    third.print_list();
    cout << third.front() << endl;
    cout << third.back() << endl;
    cout << third.size() << endl;
    SingleLinkedList fourth = { 0,1,2,3,4,5,6 };
    fourth.print_list();
    fourth.insert_on_index(6, 0);
    fourth.print_list();
    cout << fourth.size() << endl;
    cout << "-------------------" << endl;
    SingleLinkedList fifth = { 0,1,2,3,4,5,6,7,8 };
    fifth.print_list();
    fifth.remove(2);
    fifth.print_list();
    vector<int> vec = fifth.into_vector();
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "-------------------" << endl;
    int array[6]{ 1,1,1,1,1,1};
    SingleLinkedList sixth = { 0,1,2,3,4,5,6,7,8 };
    sixth.print_list();
    //sixth.insert_on_index(10, 0);
    //sixth.push_back(10);
    sixth.insert_array(10, array, 6);
    sixth.print_list();
    cout << "----------------" << endl;
    SingleLinkedList seventh{0,1,2,3,4,5,6,7,8,9,10,11,12};
    seventh.print_list();
    seventh.remove_range(3,6);
    seventh.print_list();
    cout << "-----------------" << endl;
    SingleLinkedList eighth = {8,7,6,5,4,3,2,1,0,-1,-2};
    eighth.print_list();
    eighth.reverse();
    eighth.print_list();
    cout << "---------------" << endl;
    SingleLinkedList ninth = { 0,1,2,3,4,5,6 };
    cout << ninth.size() << endl;
    ninth.resize(12);
    ninth.print_list();
    SingleLinkedList test1{ 0,1,2,3,4,5,6 };
    for (int i = 0; i < test1.size(); i++)
    {
        cout << test1[i] << " ";
    }
    cout << endl;
    test1.resize(10);
    for (int i = 0; i < test1.size(); i++)
    {
        cout << test1[i] << " ";
    }


}


