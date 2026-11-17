#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// membuat node baru
Node* buatNode(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = nullptr;
    return baru;
}

// menampilkan seluruh isi list
void tampilkan(const char* judul, Node* head) {
    cout << judul;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// tambah node di depan
void tambahDepan(Node*& head, Node*& tail, int nilai) {
    Node* baru = buatNode(nilai);
    baru->next = head;
    head = baru;
    if (tail == nullptr) { 
        tail = baru;
    }
}

// tambah node di belakang
void tambahBelakang(Node*& head, Node*& tail, int nilai) {
    Node* baru = buatNode(nilai);
    if (head == nullptr) {   
        head = baru;
        tail = baru;
        return;
    }
    tail->next = baru;
    tail = baru;
}

// tambah node setelah nilai tertentu
// return true jika berhasil, false jika nilai target tidak ditemukan
bool tambahSetelah(Node* head, Node*& tail, int target, int nilai) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;  
    }

    if (temp == nullptr) {  
        return false;
    }

    Node* baru = buatNode(nilai);
    baru->next = temp->next;   
    temp->next = baru;         

    if (temp == tail) {        
        tail = baru;
    }
    return true;
}

// hapus node berdasarkan nilai
// return true jika berhasil, false jika nilai tidak ditemukan
bool hapusNilai(Node*& head, Node*& tail, int nilai) {
    if (head == nullptr) {   
        return false;
    }

    // kasus 1: node yang dihapus adalah head
    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        if (head == nullptr) {   
            tail = nullptr;
        }
        delete hapus;
        return true;
    }

    // kasus 2: node yang dihapus ada di tengah atau di belakang
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != nilai) {
        temp = temp->next;   
    }

    if (temp->next == nullptr) {
        return false;
    }

    Node* hapus = temp->next;
    temp->next = hapus->next;
    if (hapus == tail) {
        tail = temp;
    }
    delete hapus;
    return true;
}

// membebaskan seluruh memori list
void bebaskan(Node*& head, Node*& tail) {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // isi 10 nilai mahasiswa
    int nilaiAwal[10] = {100, 92, 45, 87, 71, 99, 95, 60, 55, 88};
    for (int i = 0; i < 10; i++) {
        tambahBelakang(head, tail, nilaiAwal[i]);
    }

    tampilkan("Data awal : ", head);

    // tambah node di depan (70)
    tambahDepan(head, tail, 70);
    tampilkan("Setelah menambah node baru di depan (70) : ", head);

    // tambah node di belakang (50)
    tambahBelakang(head, tail, 50);
    tampilkan("Setelah menambah node baru di belakang (50) : ", head);

    // tambah node (0) setelah nilai 45
    if (tambahSetelah(head, tail, 45, 0)) {
        tampilkan("Setelah menambah node (0) setelah 45 : ", head);
    } else {
        cout << "Nilai 45 tidak ditemukan, node tidak ditambahkan." << endl;
    }

    // hapus node 99
    if (hapusNilai(head, tail, 99)) {
        tampilkan("Setelah menghapus node (99) : ", head);
    } else {
        cout << "Nilai 99 tidak ditemukan, tidak ada node yang dihapus." << endl;
    }

    // hapus node 60
    if (hapusNilai(head, tail, 60)) {
        tampilkan("Setelah menghapus node (60) : ", head);
    } else {
        cout << "Nilai 60 tidak ditemukan, tidak ada node yang dihapus." << endl;
    }

}