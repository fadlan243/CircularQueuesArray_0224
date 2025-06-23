/**
 * @mainpage Documentation Circular Queue
 * 
 * @section Introduction 
 * Project ini merupakan project struktur data
 * menggunakan struktur data queue dengan pendekatan circular arrays
 * 
 * @section Operations 
 * - en queues for insert elements into queue 
 * - de queues for delete elements fro queues 
 * - show data / display
 * 
 * @section How to use 
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 4. Exit 
 * 
 * 
 * @author your profil
 * - Nama : Fadlan Nasrizal Parma
 * - Nim : 20240140224
 * - Kelas : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 ** @class Queues
 * @brief This class is for operation queues 
 * 
 * 
 */
class Queues {
private :
    int FRONT; /// private variable front for indicate the first element
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for maximum capasity of element
    int queue_array[5]; /// private variable queue_array to store elements

public :
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues () {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method f0r entering data into queueus 
     * 
     */
    void insert() {
        int num; /// varieble num for indicate data type number 
        cout << "Enter a number: "; /// enter number to variable num 
        cin >> num; /// enter number to variable num
        cout << endl; /// 

    // Cek apakah antrian penuh
    if ((FRONT == 0 && REAR == max  -1) || (FRONT == REAR + 1 )) { /// check if the queue is full (both normal and circular condition)
        cout << "\nQueue overflow\n"; /// display masssage when queue is full
        return; /// indicate the program ended successfully or return 0
    }

    // cek apakah antrian kosong
    if (FRONT == -1) { /// if queue is empty, initialize FRONT and REAR to 0
        FRONT = 0;
        REAR = 0;
    }
    else {
        // Jika REAR berada di posisi terakhir array, kembali ke awal array
        if (REAR == max -1) /// if REAR reaches the end of the array, wrap it to the beginning
            REAR = 0;
        else 
            REAR = REAR + 1; /// move REAR forward 
        }

        queue_array[REAR] = num; /// store the new element at REAR
}

/**
 * @brief method for removing data into a queues
 * 
 */
    void remove() { /// check if the queue is empty
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
    cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n"; /// Print the element that will be deleted 
    

    // Cek jika antrian hanya memiliki satu elemen 
    if (FRONT == REAR) { /// if only one element exists, reset the queue to empty
        FRONT = -1;
        REAR = -1;
    }
    else { /// if FRONT is at the end, wrap around to 0
        // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal
        if (FRONT == max - 1)
            FRONT = 0;
        else    
            FRONT = FRONT + 1; /// move FRONT one step forward 
    }
};

/**
 * @brief method for display data into a queues 
 * 
 */
void display() { /// check if the queue is empty 
        int FRONT = FRONT; /// position variable front in front 
        int REAR = REAR; /// position variable rear in rear 

        // cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue is empty\n"; /// display this queue is emppty 
            return; /// indicate the program ended seccesfully or return 0 
        }

       cout << "\nElements in the queue are.....\n"; /// print a massage before displaying the contents of the queue 

        // jika Front_position <= REAR_position, iterasi dari front hingga array

        if (FRONT <= REAR) { ///If queue is in linear order (no wrapping)
            for (int i = FRONT; i <= REAR; i++)
                cout << queue_array[i] << " ";
        } else { /// If queue has wrapped around, print in two parts
            for (int i = FRONT; i < max; i++)
                cout << queue_array[i] << " ";
            for (int i = 0; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        cout << endl;
    };

    /**
     * @brief main function to run the program
     * 
     * @return int 
     */

int main()
{
    Queues q; /// create 
    char ch; /// variable to store user's menu selection

    while (true) { /// infinate loop repeatedly show menu untill the user exists
        cout << "\nMenu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> ch;
        cout << endl;

        // Menjalankan fungsi berdasarkan pilihan user
        switch (ch) { /// ]Display menu options
            case 1:
                q.insert(); /// call insert function to add element 
                break;
            case 2:
                q.remove(); /// call remove function to add element 
                break;
            case 3:
                q.display(); /// call display function to add element 
                break;
            case 4:
                exit(0); // exit the program
            default:
                cout << "Invalid choice\n"; /// handle incorrect menu input 
        }
    }
    return 0; /// end of main function
}