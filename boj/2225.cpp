#include <cstdio>


int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	auto ways_to = new int*[K+1];
	for(int i = 0; i < K + 1; ++i)
		ways_to[i] = new int[N + 1];

	// Base case
	ways_to[0][0] = 1;

	// Build ways_to[1:K][1:N]
	for (int current_k = 1; current_k <= K; ++current_k) {
		for (int current_n = 0; current_n <= N; ++current_n) {
			int w = 0;
			for (int n = 0; n <= current_n; ++n) {
				w += ways_to[current_k - 1][n];
				w %= 1000000000;
			}
			ways_to[current_k][current_n] = w;
		}
	}

	printf("%d\n", ways_to[K][N]);

	for(int i = 0; i < K + 1; ++i)
		delete [] ways_to[i];
	delete [] ways_to;

	return 0;
}

