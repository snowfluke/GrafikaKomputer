//* Memasukan library yang diperlukan
#include <iostream> // Library Input Output Stream
#include </usr/include/GL/glut.h> //! GLUT di Ubuntu
#include <stdio.h> // Library standar input output

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

// Membuat fungsi drawPersegi untuk Menggambar Persegi yang mengembalikan nilai kosong
void drawPersegi(){
    glBegin(GL_POLYGON); // Menggambar poligon

    glColor3f(1,0,0); // Memberi warna RGB pada fill berupa merah
    glVertex2f(-0.4,-0.1); //* Titik bawah kiri

    glColor3f(1,0,0); // Memberi warna RGB pada fill berupa merah
    glVertex2f(-0.2,-0.1); //* Titik bawah kanan

    glColor3f(1,0,0); // Memberi warna RGB pada fill berupa merah
    glVertex2f(-0.2,0.1); //* Titik atas kanan

    glColor3f(1,0,0); // Memberi warna RGB pada fill berupa merah
    glVertex2f(-0.4,0.1); //* Titik atas kiri

    glPointSize(50); // Mengatur ukuran titik
    glLineWidth(50); // Mengatur ukuran lebar garis

    glEnd(); // Selesai menggambar
}

// Membuat fungsi drawPersegiShear untuk menggambar transformasi persegi berupa shear
// Nilai shear adalah setengah dari panjang sisinya
void drawPersegiShear(){
    glBegin(GL_POLYGON); // Menggambar poligon

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(0.2,-0.1); //* Titik bawah kiri

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(0.4,-0.1); //* Titik bawah kanan

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(0.5,0.1); //* Titik atas kanan

    glColor3f(0,1,0); // Memberi warna RGB pada fill berupa hijau
    glVertex2f(0.3,0.1); //* Titik atas kiri

    glPointSize(50); // Mengatur ukuran titik
    glLineWidth(50); // Mengatur ukuran lebar garis

    glEnd(); // Selesai menggambar
}

void dot(){
    glClear(GL_COLOR_BUFFER_BIT);   // Membersihkan piksel layar

    // Memanggil semua fungsi yang telah didefinisikan
        drawPersegi();
        drawPersegiShear();
    glFlush(); // Memastikan semua perintah sudah dijalankan
}

// TODO: perintah mengcompile => g++ UAS2_AwalAriansyah.cpp -o UAS2 -lGL -lGLU -lglut
// TODO: perintah menjalankan => ./UAS2
