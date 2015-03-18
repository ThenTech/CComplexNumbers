#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "cmath.h"

int main() {
	struct cNumber z;

	z = newCNmbrR(1, -1);					//	New complex number from X + Yi
	printf("\n\nZ = X+iY = ");
	toStringCNmbrR(z);						//	Display real and imaginary parts
	printf("\nZ = Z<O = ");
	toStringCNmbrP(z);						//	Display magnitude and angle

	z = newCNmbrP(M_SQRT2, 45);				//	New complex number from Z<O
	printf("\n\nZ = X+iY = ");	
	toStringCNmbrR(z);						//	Display real and imaginary parts
	printf("\nZ = Z<O = ");
	toStringCNmbrP(z);						//	Display magnitude and angle

	struct cNumber c1 = newCNmbrR(1, 1), c2 = newCNmbrR(0, 2);
	printf("\n\n--- Complex calculations ---");
	printf("\nZ1 = "); toStringCNmbrR(c1);
	printf("\nZ2 = "); toStringCNmbrR(c2);
	printf("\n  Add = ");
	toStringCNmbrR(cadd(c1, c2));			//	Display real and imaginary parts
	printf("\nSubtr = ");
	toStringCNmbrR(csub(c1, c2));			//	Display real and imaginary parts
	printf("\n Mult = ");
	toStringCNmbrR(cmul(c1, c2));			//	Display real and imaginary parts
	printf("\nDivid = ");
	toStringCNmbrR(cdiv(c1, c2));			//	Display real and imaginary parts
	printf("\n Conj = ");
	toStringCNmbrR(cconj(c1));				//	Display real and imaginary parts


	printf("\n");							//New Line on end
	system("PAUSE");						//Pause console and wait for user to exit
	return 0;
}
