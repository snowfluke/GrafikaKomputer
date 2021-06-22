//* Memasukan library yang diperlukan yaitu iostream, stdio dan glut
#include <iostream>
#include </usr/include/GL/glut.h> //! GLUT di Ubuntu
#include <stdio.h>

//* Mendefinisikan fungsi kosong bernama dot
void dot();

//* Membuat fungsi utama main yang
// mempunyai parameter integer serta character
int main(int argc, char** argv){
    glutInit(&argc,argv); // Menginisialisasi glut

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Mengatur mode layar tunggal dan mode warna RGB
    glutInitWindowSize(400,400); // Membuat jendela 400px x 400px
    glutInitWindowPosition(100,100); // Posisi jendela di layar x=100, y=100

    glutCreateWindow("Praktikum 3_Awal Ariansyah"); // Nama jendela
    glClearColor(0,0,0,0); // Warna background RGB & Alfa(transparansi)
    
    glMatrixMode(GL_PROJECTION); // Mengoperasikan mode matriks berupa proyeksi
    
    glOrtho(1,1,1,1,-1,1); // transformasi yang menghasilkan proyeksi paralel
    glutDisplayFunc(dot); // Fungsi ketika akan menggambar ulang di jendela (redisplay event)
    
    glutMainLoop(); // Pemrosesan glut secara berulang
}

//! Membuat fungsi dot yang mengembalikan nilai kosong(void)

void dot(){
    glClear(GL_COLOR_BUFFER_BIT);   // Membersihkan piksel layar
    glBegin(GL_POLYGON); // Menggambar poligon

    glColor3f(1,1,0); // Memberi warna RGB pada fill berupa kuning
    glVertex2f(-0.2,-0.35); //* Titik A bawah kiri

    glColor3f(1,1,0); // Memberi warna RGB pada fill berupa kuning
    glVertex2f(0.2,-0.35); //* Titik B bawah kanan

    glColor3f(1,1,0); // Memberi warna RGB pada fill berupa kuning
    glVertex2f(0.4,0); //* Titik C tengah kanan

    glColor3f(1,1,0); // Memberi warna RGB pada fill berupa kuning
    glVertex2f(0.2,0.35); //* Titik D atas kanan

    glColor3f(1,1,0); // Memberi warna RGB pada fill berupa kuning
    glVertex2f(-0.2,0.35); //* Titik E atas kiri

    glColor3f(1,1,0); // Memberi warna RGB pada fill berupa kuning
    glVertex2f(-0.4,0); //* Titik F tengah kiri

    glPointSize(50); // Mengatur ukuran titik
    glLineWidth(50); // Mengatur ukuran lebar garis

    glEnd(); // Selesai menggambar
    glFlush(); // Memastikan semua perintah sudah dijalankan
}

// TODO: perintah mengcompile => g++ heksagon.cpp -o heksagon -lGL -lGLU -lglut
// TODO: perintah menjalankan => ./heksagon
