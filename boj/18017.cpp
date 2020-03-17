#include <cstdio>
#include <cmath>

int main(void) {
	double v1, v2;
	double c = 299792458;

	scanf("%lf %lf", &v1, &v2);

	double v3 = (v1 + v2) / (1 + (v1/c) * (v2/c));
	printf("%.9lf\n", v3);

	return 0;
}
