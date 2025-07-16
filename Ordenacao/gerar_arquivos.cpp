#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // shuffle
#include <random>    // random_device, mt19937
#include <chrono>    // para seed aleatória
using namespace std;

void geraArquivos(int tamanho) {
    // Vetor quase ordenado (0 a tamanho-1)
    vector<int> quaseOrdenado(tamanho);
    for (int i = 0; i < tamanho; ++i)
        quaseOrdenado[i] = i;

    // Faz algumas trocas aleatórias para desordenar um pouco (~5%)
    int swaps = tamanho * 0.05;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, tamanho - 1);

    for (int i = 0; i < swaps; ++i) {
        int a = dis(gen);
        int b = dis(gen);
        swap(quaseOrdenado[a], quaseOrdenado[b]);
    }

    // Vetor totalmente aleatório com valores entre -tamanho e +tamanho
    vector<int> aleatorio(tamanho);
    uniform_int_distribution<> dis_val(-tamanho, tamanho);
    for (int i = 0; i < tamanho; ++i) {
        aleatorio[i] = dis_val(gen);
    }

    // Vetor em ordem reversa
    vector<int> reverso(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        reverso[i] = tamanho - i;
    }

    // Salva arquivos
    ofstream f1("Elem." + to_string(tamanho) + ".almost.in");
    for (int v : quaseOrdenado) f1 << v << "\n";
    f1.close();

    ofstream f2("Elem." + to_string(tamanho) + ".random.in");
    for (int v : aleatorio) f2 << v << "\n";
    f2.close();

    ofstream f3("Elem." + to_string(tamanho) + ".reverse.in");
    for (int v : reverso) f3 << v << "\n";
    f3.close();

    cout << "Arquivos gerados para tamanho " << tamanho << "\n";
}

int main() {
    vector<int> tamanhos = {1000, 10000, 100000};
    for (int t : tamanhos) {
        geraArquivos(t);
    }
    cout << "Todos os arquivos foram gerados!\n";
    return 0;
}
