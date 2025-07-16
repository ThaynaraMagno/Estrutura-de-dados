#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>  // para sleep_for
using namespace std;
using namespace chrono;

long long tempo_ms_insertion, tempo_ns_insertion;
long long tempo_ms_selection, tempo_ns_selection;

// Função de ordenação por inserção
void ordenarPorInsercao(int* arr, int n) {
    auto inicio = high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }

    if (n <= 1000) {
        this_thread::sleep_for(milliseconds(1)); // equivalente ao Sleep(1) no Linux
    }

    auto fim = high_resolution_clock::now();
    auto duracao = fim - inicio;
    tempo_ns_insertion = duration_cast<nanoseconds>(duracao).count();
    tempo_ms_insertion = duration_cast<milliseconds>(duracao).count();
}

// Função de ordenação por seleção
void ordenarPorSelecao(int* arr, int n) {
    auto inicio = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indiceMenor]) {
                indiceMenor = j;
            }
        }
        swap(arr[i], arr[indiceMenor]);
    }

    if (n <= 1000) {
        this_thread::sleep_for(milliseconds(1));
    }

    auto fim = high_resolution_clock::now();
    auto duracao = fim - inicio;
    tempo_ns_selection = duration_cast<nanoseconds>(duracao).count();
    tempo_ms_selection = duration_cast<milliseconds>(duracao).count();
}

// Carrega os dados do arquivo
bool carregarDados(const string& nomeArquivo, int*& vetor, int& tamanho) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return false;

    int valor;
    tamanho = 0;

    while (arquivo >> valor) tamanho++;

    arquivo.clear();
    arquivo.seekg(0);

    vetor = new int[tamanho];
    int i = 0;
    while (arquivo >> valor) {
        vetor[i++] = valor;
    }

    arquivo.close();
    return true;
}

int main() {
    int opcao;
    string nomeArquivo;
    int* vetorOriginal = nullptr;
    int* vetorCopia = nullptr;
    int tamanho = 0;

    cout << "Escolha um arquivo de 1 a 9: ";
    cin >> opcao;

    switch (opcao) {
        case 1: nomeArquivo = "Elem.1000.almost.in"; break;
        case 2: nomeArquivo = "Elem.1000.random.in"; break;
        case 3: nomeArquivo = "Elem.1000.reverse.in"; break;
        case 4: nomeArquivo = "Elem.10000almost.in"; break;
        case 5: nomeArquivo = "Elem.10000.random.in"; break;
        case 6: nomeArquivo = "Elem.10000.reverse.in"; break;
        case 7: nomeArquivo = "Elem.100000.almost.in"; break;
        case 8: nomeArquivo = "Elem.100000.random.in"; break;
        case 9: nomeArquivo = "Elem.100000.reverse.in"; break;
        default:
            cout << "Opção inválida.\n";
            return 1;
    }

    if (!carregarDados(nomeArquivo, vetorOriginal, tamanho)) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return 1;
    }

    vetorCopia = new int[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetorCopia[i] = vetorOriginal[i];
    }

    ordenarPorSelecao(vetorOriginal, tamanho);
    ordenarPorInsercao(vetorCopia, tamanho);

    cout << "\nTempo Selection Sort: " << tempo_ms_selection << " ms (" << tempo_ns_selection << " ns)";
    cout << "\nTempo Insertion Sort: " << tempo_ms_insertion << " ms (" << tempo_ns_insertion << " ns)";

    delete[] vetorOriginal;
    delete[] vetorCopia;

    return 0;
}
