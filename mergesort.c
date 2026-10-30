
#include <stdio.h>

int a[100], temp[100];

void merge(int l, int m, int r) {
    int i = l, j = m + 1;
    int k = l, x;

    while(i <= m && j <= r) {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= r)
        temp[k++] = a[j++];

    for(x = l; x <= r; x++)
        a[x] = temp[x];
}

void mergesort(int l, int r) {
    int m;

    if(l < r) {
        m = (l + r) / 2;

        mergesort(l, m);
        mergesort(m + 1, r);

        merge(l, m, r);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(0, n - 1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
