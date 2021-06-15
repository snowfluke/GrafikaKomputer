// Memasukan library yang diperlukan yaitu iostream, stdio dan glut
#include <iostream>
#include </usr/include/GL/glut.h>
#include <stdio.h>

// Mendefinisikan fungsi kosong bernama dot
void dot();

// Membuat fungsi utama main yang bertipe integer,
// dan menerima parameter integer serta character
int main(int argc, char** argv){

  glutInit(&argc,argv); // Menginisialisasi glut

  // Mengatur mode layar tunggal dan mode warna RGB
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 

  glutInitWindowSize(500,400); // Membuat jendela 500px x 400px
  glutInitWindowPosition(800,100); // Posisi jendela di layar x=800, y=100

  glutCreateWindow("Praktikum  2_Awal  Ariansyah"); // Nama jendela
  glClearColor(50,0,0,0); // Warna background RGB & Alfa(transparansi)

  glMatrixMode(GL_PROJECTION); // Mengoperasikan mode matriks berupa proyeksi

  glOrtho(1.0,1.0,1.0,1.0,-1.0,1.0); // transformasi yang menghasilkan proyeksi paralel
  glutDisplayFunc(dot); // Fungsi ketika akan menggambar ulang di jendela (redisplay event)
  glutMainLoop(); // Pemrosesan glut secara berulang
  
}

// Membuat fungsi dot yang mengembalikan nilai kosong(void)
void dot(){
  glClear(GL_COLOR_BUFFER_BIT); // Membersihkan piksel layar
  glColor3f(255,255,255); // Mendefinisikan warna putih (RGB)

    glBegin(GL_TRIANGLES); // Menggambar segitiga
      glVertex2f(-0.75,-0.25); // Titik bawah kiri
      glVertex2f(-0.25,-0.25); // Titik bawah kanan
      glVertex2f(-0.5,0.25); // Titik atas tengah
    glEnd(); // Selesai menggambar

  glColor3f(0,1,0); // Mendefinisikan warna hijau (RGB)

    glBegin(GL_LINES); // Menggambar garis
    
      glVertex2f(0.25,-0.25); // Garis bawah titik kiri
      glVertex2f(0.75,-0.25); // Garis bawah titik kanan
      glVertex2f(0.75,-0.25); // Garis miring titik kanan
      glVertex2f(0.5,0.25); // Garis miring titik atas
      glVertex2f(0.5,0.25); // Garis miring titik atas
      glVertex2f(0.25,-0.25); // Garis miring titik kiri
    glEnd(); // Selesai menggambar

  glFlush(); // Memastikan semua perintah sudah dijalankan
}
