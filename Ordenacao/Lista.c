int buscaBinaria(int *A, int item, int menor, int maior) {
    while (menor < maior) {
        int mid = (menor + maior) / 2;
        if (A[mid] == item) {
            return mid+1;
        } else if (A[mid] < item) {
            menor = mid + 1;
        } else {
            maior = mid - 1;
        }
    }
    return menor+1;
}

void Insercao2(int *A, int n){
    int i, j, pos;
    int x;
    for (i = 2; i <= n; i++)
    {
        x = A[i];
        j = i - 1;
        pos = buscaBinaria(A, x, 0, j);
        A[0] = x;
        while (j >= pos)
        {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = x;
    }
}
