#include <GL/glut.h>

float angle = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotasi monitor 3D

    glColor3f(0.5f, 0.5f, 0.5f); // Warna abu-abu untuk outline
    glutWireCube(2.0); // Gambar outline monitor 3D

    // Gambar garis melingkar dengan warna abu-abu
    glColor3f(0.5f, 0.5f, 0.5f); // Warna abu-abu
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; ++i) {
        float radian = i * (3.14159 / 180);
        glVertex3f(cos(radian) * 2.5, sin(radian) * 2.5, -1.0f);
    }
    glEnd();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        angle += 5.0f;
    }
    else if (key == GLUT_KEY_LEFT) {
        angle -= 5.0f;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Monitor Komputer 3D dengan Rotasi OpenGL");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys); // Menggunakan fungsi khusus untuk kontrol rotasi
    glutMainLoop();
    return 0;
}



}


