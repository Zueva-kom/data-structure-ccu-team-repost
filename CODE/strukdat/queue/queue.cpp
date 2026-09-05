#include <iostream>

const int MAX = 10;

class Queue {
private:
    int depan;
    int belakang;
    int antrian[MAX];

public:
    // Konstruktor menginisialisasi posisi depan dan belakang antrean ke indeks 0.
    Queue() {
        depan = 0;
        belakang = 0;
    }

    // Mengembalikan true jika posisi depan sama dengan belakang, yang berarti antrean kosong.
    bool isEmpty() const {
        return depan == belakang;
    }

    // Antrean dianggap penuh jika posisi setelah belakang kembali ke posisi depan.
    bool isFull() const {
        return (belakang + 1) % MAX == depan;
    }

    // Menambahkan data ke posisi belakang, lalu menggeser belakang secara melingkar.
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Antrian penuh!\n";
            return;
        }

        // Simpan nilai pada indeks belakang dan gunakan modulo agar indeks kembali ke 0
        // setelah mencapai indeks terakhir array.
        antrian[belakang] = value;
        belakang = (belakang + 1) % MAX;
    }

    // Menghapus dan mengembalikan data paling depan dari antrean.
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Antrian kosong\n";
            return -1;
        }

        // Ambil data pada posisi depan, kemudian geser depan secara melingkar.
        int value = antrian[depan];
        depan = (depan + 1) % MAX;
        return value;
    }

    // Menampilkan semua data dari posisi depan sampai sebelum posisi belakang.
    void print() const {
        if (isEmpty()) {
            std::cout << "Antrian kosong\n";
            return; // Kurung kurawal ditutup di sini
        }

        // Telusuri antrean secara melingkar sampai indeks mencapai belakang.
        int i = depan;
        while (i != belakang) {
            std::cout << antrian[i] << " ";
            i = (i + 1) % MAX;
        }
        std::cout << "\n";
    }
};

// Fungsi utama untuk menguji operasi enqueue, dequeue, dan print.
int main() {
    Queue q;

    // Algoritma pengujian: masukkan tiga nilai ke antrean, tampilkan,
    // hapus satu nilai terdepan, kemudian tampilkan isi antrean terbaru.
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();

    q.dequeue();
    q.print();

    return 0;
}