//* Memasukan library yang diperlukan
#include <iostream> // Library Input Output Stream
#include </usr/include/GL/glut.h> //! GLUT di Ubuntu
#include <stdio.h> // Library standar input output
#include <cmath> // Library untuk fungsi matematis

//* Mendefinisikan fungsi kosong bernama dot
void dot();

//* Membuat fungsi utama main yang
// mempunyai parameter integer serta character
int main(int argc, char** argv){
    glutInit(&argc,argv); // Menginisialisasi glut

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Mengatur mode layar tunggal dan mode warna RGB
    glutInitWindowSize(600,600); // Membuat jendela 400px x 400px
    glutInitWindowPosition(100,100); // Posisi jendela di layar x=100, y=100

    glutCreateWindow("UAS_Awal Ariansyah"); // Nama jendela
    glClearColor(0,0,0,0); // Warna background RGB & Alfa(transparansi)
    
    glMatrixMode(GL_PROJECTION); // Mengoperasikan mode matriks berupa proyeksi
    
    glOrtho(1,1,1,1,-1,1); // transformasi yang menghasilkan proyeksi paralel
    glutDisplayFunc(dot); // Fungsi ketika akan menggambar ulang di jendela (redisplay event)
    
    glutMainLoop(); // Pemrosesan glut secara berulang
}
 
// Membuat fungsi drawLingkaran untuk Menggambar Lingkaran yang mengembalikan nilai kosong
void drawLingkaran(){
    const float PI = 3.14159; // membuat variable nilai PI
    float incr = (float) (2 * PI / 360); //membuat nilai increment 360 derajat

    glBegin(GL_TRIANGLE_FAN); // Menggambar triangle fan untuk membuat gambar dengan 1 vertex sebagai titik tumpuan
    glVertex2f(0, 0); // Titik tumpuan 0,0

    // Looping 360 derajat untuk membuat titik 360 kali
    for(int i = 0; i < 360; i++){
        float angle = incr * i; // Mendefinisikan sudut 
        float x = (float) cos(angle) * 0.1; // Mengkalkulasi nilai x
        float y = (float) sin(angle) * 0.1; // Mengkalkulasi nilai y
                        
        if(i <= 120){ // Memberi warna merah jika index titik kurang dari 120
            glColor3f(1,0,0);
        }
        if(i <= 240 && i > 120){ // Memberi warna hijau jika index titik diantara 120 dan 240
            glColor3f(0,1,0);
        }
        if(i <= 360 && i > 240){ // Memberi warna biru jika index titik diantara 240 dan 360
            glColor3f(0,0,1);
        }
        glVertex2f(x, y); // Gambar titik di koordinat sesuai variable x dan y
    }

    glVertex2f(0.1, 0); // Menentukan radius lingkaran
    glEnd(); // Selesai menggambar
}

// Membuat fungsi drawSegitiga untuk Menggambar Segitiga yang mengembalikan nilai kosong
void drawSegitiga() {
    glBegin(GL_POLYGON); // Menggambar poligon

    glColor3f(1,0,0); // Memberi warna RGB pada fill berupa merah
    glVertex2f(-0.4,-0.1); //* Titik bawah kiri

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(-0.2,-0.1); //* Titik bawah kanan

    glColor3f(0,0,1); // Memberi warna RGB pada fill berupa biru
    glVertex2f(-0.3,0.1); //* Titik tengah atas

    glPointSize(50); // Mengatur ukuran titik
    glLineWidth(50); // Mengatur ukuran lebar garis

    glEnd(); // Selesai menggambar
}

// Membuat fungsi drawPersegi untuk Menggambar Persegi yang mengembalikan nilai kosong
void drawPersegi(){
    glBegin(GL_POLYGON); // Menggambar poligon

    glColor3f(1,0,0); // Memberi warna RGB pada fill berupa merah
    glVertex2f(0.2,-0.1); //* Titik bawah kiri

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(0.4,-0.1); //* Titik bawah kanan

    glColor3f(0,0,1); // Memberi warna RGB pada fill berupa biru
    glVertex2f(0.4,0.1); //* Titik atas kanan

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(0.2,0.1); //* Titik atas kiri

    glPointSize(50); // Mengatur ukuran titik
    glLineWidth(50); // Mengatur ukuran lebar garis

    glEnd(); // Selesai menggambar
}

void dot(){
    glClear(GL_COLOR_BUFFER_BIT);   // Membersihkan piksel layar

    // Memanggil semua fungsi yang telah didefinisikan
        drawSegitiga();
        drawPersegi();
        drawLingkaran();
    glFlush(); // Memastikan semua perintah sudah dijalankan
}

// TODO: perintah mengcompile => g++ UAS1_AwalAriansyah.cpp -o UAS1 -lGL -lGLU -lglut
// TODO: perintah menjalankan => ./UAS1
