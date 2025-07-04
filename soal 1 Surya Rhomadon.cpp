#include <iostream>
using namespace std;

const int MAX = 10;
int antrian[MAX];
int front = -1, rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    antrian[rear] = data;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    front++;
}

void showAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << antrian[i];
        if (i < rear) cout << ", ";
    }
    cout << endl;
}

int main() {
    int jumlahData, nilai;

    cout << "Masukkan jumlah data yang ingin dienqueue (maks 10): ";
    cin >> jumlahData;

    if (jumlahData > MAX) {
        cout << "Maksimal input adalah 10!\n";
        return 0;
    }

    // Input dari user
    for (int i = 0; i < jumlahData; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilai;
        enqueue(nilai);
    }

    // Tampilkan antrian setelah enqueue
    cout << "Setelah Enqueue dan Show:\n";
    showAntrian();

    // Lakukan dequeue satu kali
    cout << "Melakukan 1x Dequeue...\n";
    dequeue();

    // Tampilkan antrian setelah dequeue
    cout << "Setelah Dequeue dan Show:\n";
    showAntrian();

    return 0;
}
