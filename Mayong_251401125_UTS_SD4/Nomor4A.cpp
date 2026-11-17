#include <iostream>
using namespace std;

// Struktur node binary tree
struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

// Membuat node baru secara dinamis
Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->kiri = nullptr;
    baru->kanan = nullptr;
    return baru;
}

// Menyisipkan angka ke tree
Node* sisip(Node* root, int nilai) {
    if (root == nullptr) {
        return buatNode(nilai);         
    }
    if (nilai < root->data) {
        root->kiri = sisip(root->kiri, nilai);
    } else if (nilai > root->data) {
        root->kanan = sisip(root->kanan, nilai);
    } else {
        cout << "Angka " << nilai << " sudah ada di tree, diabaikan.\n";
    }
    return root;
}

// In-order : Kiri -> Root -> Kanan 
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

// Mencari angka di tree, true jika ditemukan
bool cari(Node* root, int nilai) {
    if (root == nullptr) return false;
    if (nilai == root->data) return true;
    if (nilai < root->data) return cari(root->kiri, nilai);
    return cari(root->kanan, nilai);
}

// Menghitung jumlah seluruh node
int hitungNode(Node* root) {
    if (root == nullptr) return 0;
    return 1 + hitungNode(root->kiri) + hitungNode(root->kanan);
}

// Menghitung tinggi tree (tree kosong = 0, satu node = 1)
int tinggi(Node* root) {
    if (root == nullptr) return 0;
    int tKiri = tinggi(root->kiri);
    int tKanan = tinggi(root->kanan);
    return 1 + (tKiri > tKanan ? tKiri : tKanan);
}

// Nilai terkecil ada di node paling kiri
int nilaiMin(Node* root) {
    while (root->kiri != nullptr) {
        root = root->kiri;
    }
    return root->data;
}

// Nilai terbesar ada di node paling kanan
int nilaiMax(Node* root) {
    while (root->kanan != nullptr) {
        root = root->kanan;
    }
    return root->data;
}

// Menghapus seluruh tree dari memori
void hapusTree(Node* root) {
    if (root == nullptr) return;
    hapusTree(root->kiri);
    hapusTree(root->kanan);
    delete root;
}

int main() {
    Node* root = nullptr;
    int angka;

    cout << "=== BINARY TREE DINAMIS ===\n";
    cout << "Masukkan angka satu per satu (input 0 untuk berhenti)\n\n";

    while (true) {
        cout << "Masukkan angka: ";
        cin >> angka;

        if (cin.eof()) break;           
        if (cin.fail()) 
        {                
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid, masukkan angka.\n";
            continue;
        }
        if (angka == 0) break;          

        root = sisip(root, angka);
    }

    if (root == nullptr) {
        cout << "\nTree kosong, tidak ada data yang dimasukkan.\n";
        return 0;
    }

    cout << "\nHASIL TRAVERSAL\n";

    cout << "In-order   : ";
    inOrder(root);
    cout << endl;

    cout << "\nINFORMASI TREE\n";
    cout << "Jumlah node : " << hitungNode(root) << endl;
    cout << "Tinggi tree : " << tinggi(root) << endl;
    cout << "Nilai min   : " << nilaiMin(root) << endl;
    cout << "Nilai max   : " << nilaiMax(root) << endl;

    cout << "\nCari angka (0 untuk lewati): ";
    if (cin >> angka && angka != 0) {
        if (cari(root, angka))
            cout << "Angka " << angka << " ditemukan di tree.\n";
        else
            cout << "Angka " << angka << " tidak ditemukan di tree.\n";
    }

    hapusTree(root);                     
    return 0;
}