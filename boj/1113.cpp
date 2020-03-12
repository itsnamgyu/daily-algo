#include <cstdio>
#include <vector>

int pour(int x, int y, int z, int w, int h, std::vector<int> &pool, std::vector<bool> &used) {
	// Pour water starting from x, y, z and return the volume of water filled.
	// Negative volume will be returned if it overflows.
	// w = M, h = N
	if (x < 0 || w <= x || y < 0 || h <= y) return -25000;  // overflow

	int index = x + y * w;
	int volume;
	if (pool[index] < z) {
		volume = z - pool[index];
		used[index] = 1;
		pool[index] = z;
	} else {
		return 0;
	}

	// If this block is fillable, water should flow to adjacent blocks
	volume += pour(x + 1, y, z, w, h, pool, used);
	volume += pour(x - 1, y, z, w, h, pool, used);
	volume += pour(x, y + 1, z, w, h, pool, used);
	volume += pour(x, y - 1, z, w, h, pool, used);

	return volume;
}

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int w = M, h = N;

	auto pool = std::vector<int>(N * M, 0);
	for (int i = 0; i < N * M; ++i) {
		int n;
		scanf("%1d", &n);
		pool[i] = n;
	}

	int total_volume = 0;
	for (int z = 10; z; --z) {
		auto p = pool;  // refill pool every time we reduce target z
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				auto used = std::vector<bool>(N * M);
				int volume = pour(x, y, z, w, h, p, used);
				if (volume > 0) {
					total_volume += volume;
					// Apply pour to original pool
					for (int i = 0; i < N * M; ++i) {
						if (used[i]) pool[i] = z;
					}
				}
			}
		}
	}

	printf("%d\n", total_volume);
}
