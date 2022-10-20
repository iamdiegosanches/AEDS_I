int buscaBinaria(int *A, int item, int menor, int maior) {
    while (menor <= maior) {
        int mid = (menor + maior) / 2;
        if (A[mid] == item) {
            return mid;
        } else if (A[mid] < item) {
            menor = mid + 1;
        } else {
            maior = mid - 1;
        }
    }
    return -1;
}

// Adaptar o algoritmo de inserção para usar a busca binária
void Insercao(int *A, int n){
  int i, j;
  int x;
  for (i = 2; i <= n; i++){
      x = A[i];
      j = i - 1;
      A[0] = x;
      while (x < A[j]){
           A[j+1] = A[j];
           j--;
      }
      A[j+1] = x;
    }
}
