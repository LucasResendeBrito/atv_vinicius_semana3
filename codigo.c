#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    int pi;

    if (low < high) {
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    int m;

    if (l < r) {
        m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void copyArray(int origem[], int destino[], int n) {
    int i;
    for (i = 0; i < n; i++)
        destino[i] = origem[i];
}

int main() {

    int n, i, opcao;
    clock_t inicio, fim;
    double tempo;

    printf("Escolha o algoritmo:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Quick Sort\n");
    printf("5 - Merge Sort\n");
    printf("0 - Executar todos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\nDigite o tamanho do array: ");
    scanf("%d", &n);

    int original[n];
    int arr[n];

    srand(time(NULL));

    for (i = 0; i < n; i++)
        original[i] = rand() % 1000;

    printf("\nArray original:\n");
    printArray(original, n);

    if (opcao == 0) {
        for (i = 1; i <= 5; i++) {

            copyArray(original, arr, n);

            inicio = clock();

            if (i == 1) bubbleSort(arr, n);
            if (i == 2) selectionSort(arr, n);
            if (i == 3) insertionSort(arr, n);
            if (i == 4) quickSort(arr, 0, n - 1);
            if (i == 5) mergeSort(arr, 0, n - 1);

            fim = clock();

            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("\nAlgoritmo %d - Tempo: %.3f segundos\n", i, tempo);
        }
    }
    else {

        copyArray(original, arr, n);

        inicio = clock();

        if (opcao == 1) bubbleSort(arr, n);
        if (opcao == 2) selectionSort(arr, n);
        if (opcao == 3) insertionSort(arr, n);
        if (opcao == 4) quickSort(arr, 0, n - 1);
        if (opcao == 5) mergeSort(arr, 0, n - 1);

        fim = clock();

        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("\nArray ordenado:\n");
        printArray(arr, n);

        printf("\nTempo de execucao: %.3f segundos\n", tempo);
    }

    return 0;
}