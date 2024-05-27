#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


struct Buku {
    int noref;
    string judul;
    string penulis;
};

unordered_map<int, Buku> hashTable;

void sisipBuku(int noref, string judul, string penulis) {
    if (hashTable.find(noref) != hashTable.end()) {
        cout << "Nomor referansi sudah ada" << endl;
        return;
    }

    Buku buku;
    buku.judul = judul;
    buku.penulis = penulis;
    hashTable[noref] = buku;
}

struct Node {
    Buku buku;
    Node* left;
    Node* right;
};

Node* root = nullptr;
Node* rootHapus = nullptr;

void sisipBukuBST(Node*& node, int noref, string judul, string penulis) {
    if (node == nullptr) {
        node = new Node;
        node->buku.judul = judul;
        node->buku.penulis = penulis;
        node->buku.noref = noref;
        node->left = nullptr;
        node->right = nullptr;
    } else if (noref == node->buku.noref) {
                cout << "Nomor referansi sudah ada" << endl;
                } else if (judul < node->buku.judul) {
                sisipBukuBST(node->left, noref, judul, penulis);
                } else {
                sisipBukuBST(node->right, noref, judul, penulis);
                }
}

void sisipBukuBSTHapus(Node*& node, int noref, string judul, string penulis) {
    if (node == nullptr) {
        node = new Node;
        node->buku.judul = judul;
        node->buku.penulis = penulis;
        node->buku.noref = noref;
        node->left = nullptr;
        node->right = nullptr;
    } else if (judul < node->buku.judul) {
                sisipBukuBSTHapus(node->left, noref, judul, penulis);
                } else {
                sisipBukuBSTHapus(node->right, noref, judul, penulis);
                }
}

void tampilkanBukuBST(Node* node, string judulAwal, string judulAkhir) {
    if (node == nullptr) {
        cout << "Tidak ada buku yang ditemukan" << endl;
        return;
    }

    bool found = false;

    if (node->buku.judul >= judulAwal) {
        tampilkanBukuBST(node->left, judulAwal, judulAkhir);
    }

    if (node->buku.judul >= judulAwal && node->buku.judul <= judulAkhir) {
        cout << "No. Ref: " << node->buku.noref << ", Judul: " << node->buku.judul << ", Penulis: " << node->buku.penulis << endl;
        found = true;
    }

    if (node->buku.judul <= judulAkhir) {
        tampilkanBukuBST(node->right, judulAwal, judulAkhir);
    }

    if (!found) {
        cout << "Tidak ada buku yang ditemukan" << endl;
    }
}

void cariBukuBST(string judulAwal, string judulAkhir) {
    tampilkanBukuBST(root, judulAwal, judulAkhir);
}

void PengurutanAscending(Node* node) {
    if (node == nullptr) {
        cout << "Tidak ada buku yang ditemukan" << endl;
        return;
    }

    PengurutanAscending(node->left);
    cout << "No. Ref: " << node->buku.noref << ", Judul: " << node->buku.judul << ", Penulis: " << node->buku.penulis << endl;
    PengurutanAscending(node->right);
}

void hapusBuku(int noref) {
    if (hashTable.find(noref) != hashTable.end()) {
        Buku buku = hashTable[noref];
        sisipBukuBSTHapus(rootHapus, noref, buku.judul, buku.penulis);
        hashTable.erase(noref);
    } else {
        cout << "Buku tidak ditemukan" << endl;
    }
}


void tampilkanBuku() {
    for (auto i = hashTable.begin(); i != hashTable.end(); i++) {
        cout << "No. Ref: " << i->first << ", Judul: " << i->second.judul << ", Penulis: " << i->second.penulis << endl;
    }

    if (hashTable.size() == 0) {
        cout << "Tidak ada buku yang ditemukan" << endl;
    }
}

Buku cariBuku(int noref) {
    if (hashTable.find(noref) != hashTable.end()) {
        return hashTable[noref];
    } else {
        Buku bukuNotFound;
        bukuNotFound.judul = "Buku tidak ditemukan";
        bukuNotFound.penulis = "";
        return bukuNotFound;
    }
}

void inorderHapus(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderHapus(node->left);
    cout << "No. Ref: " << node->buku.noref << ", Judul: " << node->buku.judul << ", Penulis: " << node->buku.penulis << endl;
    inorderHapus(node->right);
}

void preorderHapus(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << "No. Ref: " << node->buku.noref << ", Judul: " << node->buku.judul << ", Penulis: " << node->buku.penulis << endl;
    preorderHapus(node->left);
    preorderHapus(node->right);
}

void postorderHapus(Node* node) {
    if (node == nullptr) {
        return;
    }
    postorderHapus(node->left);
    postorderHapus(node->right);
    cout << "No. Ref: " << node->buku.noref << ", Judul: " << node->buku.judul << ", Penulis: " << node->buku.penulis << endl;
}



int main() {
    string kembali;
    do {
        system("cls");
        cout << "Tugas Akhir Struktur Data" << endl;
        cout << "Menu Sistem Perpustakaan" << endl;
        cout << "1. Sisip Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Tampilkan Buku" << endl;
        cout << "4. Pencarian buku menggunakan hash" << endl;
        cout << "5. Pencarian buku menggunakan ptb" << endl;
        cout << "6. Pengurutan buku ascending menggunakan ptb in order" << endl;
        cout << "7. Riwayat buku yang dihapus" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih menu : ";
        int menu;
        cin >> menu;
        switch (menu) {
            case 1: {
                system("cls");
                cout << "Jumlah buku yang ingin disisipkan: ";
                int jumlahBuku;
                cin >> jumlahBuku;
                for (int i = 0; i < jumlahBuku; i++) {
                    cout << "Masukkan nomor referensi: ";
                    int noreff;
                    cin >> noreff;
                    cin.ignore();
                    cout << "Masukkan judul buku: ";
                    string judull;
                    getline(cin>>ws, judull);
                    cout << "Masukkan penulis buku: ";
                    string penuliss;
                    getline(cin>>ws, penuliss);
                    sisipBuku(noreff, judull, penuliss);
                    sisipBukuBST(root, noreff, judull, penuliss);
                    cout << endl;
                }
            }
                break;
            case 2: {
                system("cls");
                int noreff;
                cout << "Masukkan nomor referensi: ";
                cin >> noreff;
                hapusBuku(noreff);
            }
                break;
            case 3:
                system("cls");
                tampilkanBuku();
                break;
            case 4: {
                system("cls");
                int noreff;
                cout << "Masukkan nomor referensi: ";
                cin >> noreff;
                Buku buku = cariBuku(noreff);
                cout << "No. Ref: " << noreff << ", Judul: " << buku.judul << ", Penulis: " << buku.penulis << endl;
            }
                break;
            case 5:{
                system("cls");
                cout << "Masukkan huruf awal: ";
                string judulAwal;
                cin >> judulAwal;
                cout << "Masukkan huruf akhir: ";
                string judulAkhir;
                cin >> judulAkhir;
                cariBukuBST(judulAwal, judulAkhir);
            }
                break;
            case 6:{
                system("cls");
                PengurutanAscending(root);
            }
                break;
            case 7:{
                system("cls");
                if (rootHapus == nullptr) {
                    cout << "Tidak ada buku yang dihapus" << endl;
                    break;
                } else {
                cout << "Riwayat buku yang dihapus" << endl;
                cout << "Secara inorder" << endl;
                inorderHapus(rootHapus);
                cout << endl;
                cout << "Secara preorder" << endl;
                preorderHapus(rootHapus);
                cout << endl;
                cout << "Secara postorder" << endl;
                postorderHapus(rootHapus);
                cout << endl;
            }
            }
                break;

            case 8:{
                system("cls");
                cout << "Terima kasih" << endl;
                return 0;
            }
                break;
            default:
                cout << "input salah" << endl;
        }
        cout << "Kembali ke menu? (y/n) ";
        cin >> kembali;
    } while (kembali == "y" || kembali == "Y");
    return 0;
}
