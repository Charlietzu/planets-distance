#include <iostream>

FILE *arquivo_distancias;

int main(int argc, char* argv[]) {
    if (argc > 1){
        arquivo_distancias = fopen(argv[1], "rt");
        int numeroLinhas = atoi(argv[2]);
    }

    return 0;
}