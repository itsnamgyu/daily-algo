#include <cstdio>
#include <cmath>

long long get_order(long long r, long long c, long long n) {
	if (n <= 0) return 0;

	// Local row, local column, 2^n-1
	long long rr, cc;
	long long nn = pow(2, n - 1);
	rr = r / nn;
	cc = c / nn;

	long long order = (rr * 2 + cc) * nn * nn;
	return order + get_order(r % nn, c % nn, n - 1);
}

int main(void) {
	long long n, r, c;
	scanf("%lld %lld %lld", &n, &r, &c);

	long long order = get_order(r, c, n);
	printf("%lld\n", order);

	return 0;
}
