int minIncrementForUnique(int* n, int s) {
    int max = 0;
    for (int i = 0; i < s; i++) {
        max = fmax(max, n[i]);
    }
    int len = max + 1 + s, ans = 0;
    int* freq = calloc(max + 1 + s, sizeof(int));
    for (int i = 0; i < s; i++) {
        freq[n[i]]++;
    }
    for (int i = 0; i < len; i++) {
        if (freq[i] <= 1)
            continue;
        int extra = freq[i] - 1;
        freq[i + 1] += extra;
        ans += extra;
    }
    return ans;
}
