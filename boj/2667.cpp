#include <cstdio>
#include <vector>
#include <algorithm>

int get_location(int x, int y, int n) {
    bool out_of_bounds = -1 < x && x < n && -1 < y && y < n;
    if (!out_of_bounds) return -1;
    else return x + y * n;
}

int wipe(int x, int y, int n, std::vector<int> &board) {
    /* Wipe out the group that is connected to x, y (from top left)
     * and return the size of that group.
     */
    int location = get_location(x, y, n);
    if (location == -1) return 0;
    if (!board[location]) return 0;

    // Count and search around if occupied
    board[location] = 0;
	int size = 1;
    size += wipe(x - 1, y, n, board);
    size += wipe(x + 1, y, n, board);
    size += wipe(x, y - 1, n, board);
    size += wipe(x, y + 1, n, board);
	return size;
}

int main(void) {
    int n;
    scanf("%d", &n);
    auto board = std::vector<int>(n * n);
    auto counts = std::vector<int>(0);
    
    // Input
    for (int i = 0; i < n * n; ++i) {
        int occupied;
        scanf("%1d", &occupied);
        board[i] = occupied;
    }
    
    // Search
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            int location = x + y * n;
			int size = wipe(x, y, n, board);
			if (size) {
				// Found a group of size `size`
				counts.push_back(size);
			}
        }
    }
    
    std::sort(counts.begin(), counts.end());
    
	printf("%lu\n", counts.size());
    for (const auto count : counts) {
        printf("%d\n", count);
    }
}
