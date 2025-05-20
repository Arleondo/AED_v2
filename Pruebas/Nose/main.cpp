#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

// Nodo del árbol
struct TreeNode {
    int value;
    float x, y; // posición en pantalla
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

// Dibuja un círculo para representar un nodo
void drawCircle(float cx, float cy, float r, int segments = 32) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float dx = r * cosf(theta);
        float dy = r * sinf(theta);
        glVertex2f(cx + dx, cy + dy);
    }
    glEnd();
}

// Dibuja una línea entre dos nodos
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Dibuja recursivamente el árbol
void drawTree(TreeNode* node) {
    if (!node) return;

    float r = 0.10f;  // radio del nodo

    drawCircle(node->x, node->y, r);  // nodo

    // líneas con hijos
    if (node->left) {
        drawLine(node->x, node->y, node->left->x, node->left->y);
        drawTree(node->left);
    }
    if (node->right) {
        drawLine(node->x, node->y, node->right->x, node->right->y);
        drawTree(node->right);
    }
}

// Construye un árbol binario de ejemplo con coordenadas
TreeNode* buildExampleTree() {
    TreeNode* root = new TreeNode{1, 0.0f, 0.8f};
    root->left = new TreeNode{2, -0.5f, 0.4f};
    root->right = new TreeNode{3, 0.5f, 0.4f};
    root->left->left = new TreeNode{4, -0.7f, 0.0f};
    root->left->right = new TreeNode{5, -0.3f, 0.0f};
    root->right->left = new TreeNode{6, 0.3f, 0.0f};
    root->right->right = new TreeNode{7, 0.7f, 0.0f};
    return root;
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Árbol Binario con GLFW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Configurar sistema de coordenadas OpenGL (-1 a 1)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    TreeNode* root = buildExampleTree();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 1.0f, 1.0f); // blanco
        drawTree(root);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
