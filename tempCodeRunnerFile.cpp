/**
 * @mainpage Documentation Circular Queue
 * 
 * @file CircularQueus.cpp
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public :
    Queues () {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

    // Cek apakah antrian penuh
    if ((FRONT == 0 && REAR == max  -1) || (FRONT == REAR + 1 )) {
        cout << "\nQueue overflow\n";
        return;
    }

    // cek apakah antrian kosong
    if (FRONT == -1) {
        FRONT = 0;
        REAR = 0;
    }
    else {
        // Jika REAR berada di posisi terakhir array, kembali ke awal array
        if (REAR == max -1)
            REAR = 0;
        else 
            REAR = REAR + 1;
        }

        queue_array[REAR] = num;
}

    void remove() {
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
    cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";
    

    // Cek jika antrian hanya memiliki satu elemen 
    if (FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    }
    else {
        // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal
        if (FRONT == max - 1)
            FRONT = 0;
        else    
            FRONT = FRONT + 1; 
    }
};

void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

       cout << "\nElements in the queue are.....\n";

        // jika Front_position <= REAR_position, iterasi dari front hingga array

        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q;
    char ch;

    while (true) {
        cout << "\nMenu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> ch;
        cout << endl;

        // Menjalankan fungsi berdasarkan pilihan user
        switch (ch) {
            case 1:
                q.insert(); // Menambahkan elemen ke antrian
                break;
            case 2:
                q.remove(); // Menghapus elemen dari antrian
                break;
            case 3:
                q.display(); // Menampilkan isi antrian
                break;
            case 4:
                exit(0); // Keluar dari program
            default:
                cout << "Invalid choice\n"; // Jika pilihan tidak valid
        }
    }

    return 0;
}