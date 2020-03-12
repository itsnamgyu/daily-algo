#include <cstdio>
#include <vector>

int main(void) {
	int n;
	scanf("%d", &n);

	auto min_steps_to = std::vector<int>(n + 1, 0);

	for (int i = n; i > 0; --i) {
		int next_step = min_steps_to[i] + 1;
		int previous;

		if (i % 3 == 0) {
			previous = min_steps_to[i / 3];
			if (!previous || next_step < previous) {
				min_steps_to[i / 3] = next_step;
			}
		}

		if (i % 2 == 0) {
			previous = min_steps_to[i / 2];
			if (!previous || next_step < previous) {
				min_steps_to[i / 2] = next_step;
			}
		}

		previous = min_steps_to[i - 1];
		if (previous == 0 || next_step < previous) {
			min_steps_to[i - 1] = next_step;
		}
	}

	printf("%d\n", min_steps_to[1]);
}
