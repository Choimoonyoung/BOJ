#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	double A, B;
	scanf("%lf %lf", &A, &B);
	A /= B;
	printf("%1f", A);
}