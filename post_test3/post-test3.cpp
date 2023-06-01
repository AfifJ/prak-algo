#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

void initializeQueue(Queue &queue)
{
    queue.front = nullptr;
    queue.rear = nullptr;
}

bool isEmpty(const Queue &queue)
{
    return (queue.front == nullptr);
}

void enqueue(Queue &queue, int data)
{
    // Lengkapi bagian ini
    Node *NB = new Node;
    NB->data = data;
    NB->next = NULL;

    if (isEmpty(queue))
    {
        queue.front = NB;
    }
    else
    {
        queue.rear->next = NB;
        queue.rear = NB;
        queue.rear->next = NULL;
    }
}

void dequeue(Queue &queue)
{
    // Lengkapi bagian ini
    if (isEmpty(queue))
    {
        cout << "Queue masih kosong" << endl;
        return;
    }
    Node *hapus;
    hapus = queue.front;
    queue.front = queue.front->next;
    hapus->next = NULL;

    free(hapus);
}

void display(const Queue &queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue masih kosong" << endl;
        return;
    }
    // Lengkapi bagian ini
    Node *bantu;
    bantu = queue.front;
    while (bantu != NULL)
    {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
    cout << endl;
}

int main()
{
    Queue queue1, queue2;
    initializeQueue(queue1);
    initializeQueue(queue2);
    int choice, item;

    do
    {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            /* Gunakan if else untuk menentukan yg dimasukan ganjil atau genap*/
            cout << "data baru : ";
            cin >> item;
            if (item % 2 == 0)
                enqueue(queue2, item);
            else
                enqueue(queue1, item);
            break;

        case 2:
            /* Gunakan if else untuk menentukan yg dimasukan ganjil atau genap*/
            cout << "Pilihan" << endl;
            cout << "1. Ganjil" << endl;
            cout << "2. Genap" << endl;
            cout << "Pilhan : ";
            cin >> item;
            if (item == 1)
                dequeue(queue1);
            else
                dequeue(queue2);
            break;

        case 3:

            cout << "Display : " << endl << endl;
            cout << "queue 1 : " << endl;
            display(queue1);
            cout << "queue 2 : " << endl;
            display(queue2);

            break;

        case 0:
            cout << "Exiting the program. Bye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
