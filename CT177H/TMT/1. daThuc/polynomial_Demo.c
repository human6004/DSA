#include <stdio.h>
#include <math.h>

#define MAXLENGTH 100
typedef struct {
    double c; //coefficients
    int e;    //exponents
} ElementType;
typedef int Position;

typedef struct {
    ElementType elements[MAXLENGTH];
    Position last;
} Polynomial;

//makeNull(pL): make the polynomial be empty
Position makeNull(Polynomial *pL) {
    pL->last = 0;
    return pL->last + 1;
}

//end(pL): returns the position following the last element
Position end(Polynomial *pL) {
    return pL->last + 1;
}

//Please write a function coefficient(e, pL) to find the coefficient of the monomial with exponent e
double coefficient (int e, Polynomial *pL) {
	Position temp = (*pL);
	while (temp->next != NULL) {
		if (temp->next->e == e) {
			return temp->next->c;
		}
		temp = temp->next;
	}
	return 0.0;
	/*
	Polynomial L;
makeNull(&L);
insert(5, 3, &L);
insert(4, 4, &L);
insert(7, 0, &L);
insert(-3, 2, &L);
printPolynomial(&L);
for (int e = 10; e >= 0; e--)
    printf("The coefficient of x^%d is: %.2f\n", e, coefficient(e, &L));
	*/
}


void insert (double c, int e, Polynomial *pL) {
	for (int i = 0; i < pL->last; i++) {
		if (pL->elements[i].e == e) {
			pL->elements[i].c = c;
			return;
		}
		else if (pL->elements[i].e < e) {
			for (int j = pL->last; j >= i; j--) {
				pL->elements[j].e = pL->elements[j - 1].e;
				pL->elements[j].c = pL->elements[j - 1].c;			
			}
			pL->elements[i].e = e;
			pL->elements[i].c = c;
			pL->last++;
			return;
		}
	}
	pL->elements[pL->last].e = e;
	pL->elements[pL->last].c = c;
	pL->last++;
	/*
	Polynomial L;
	makeNull(&L);
	insert(5, 3, &L);
	insert(4, 4, &L);
	insert(7, 0, &L);
	insert(-3, 2, &L);
	printPolynomial(&L);
	*/
}

double evaluate (double val, Polynomial *pL) {
	double sum = 0;
	for (int i = 0; i < pL->last; i++) {
		sum += (pow(val, pL->elements[i].e)*(pL->elements[i].c));
	}
	return sum;
	/*
	Polynomial L;
makeNull(&L);
insert(5, 6, &L); insert(2, 2, &L);
insert(5, 4, &L);

double val = 1.0;
printf("p(x) = ");
printPolynomial(&L);
printf("p(%.2f) = %.2f\n", val, evaluate(val, &L));
	*/
}

void deletee (int e, Polynomial *pL) {
	for (int i = 0; i < pL->last; i++) {
		if (pL->elements[i].e == e) {
			for (int j = i; j < pL->last; j++) {
				pL->elements[j] = pL->elements[j + 1];
			}
			pL->last--;
			return;
		}
	}
	printf("The exponent does not appear.\n");
	/*
	Polynomial L;
makeNull(&L);
insert(5, 3, &L); insert(4, 4, &L);
insert(7, 0, &L); insert(-3, 2, &L);
printPolynomial(&L);
delete(4, &L);
printPolynomial(&L);
	*/
}

Polynomial differentiate (Polynomial *pL) {
	Polynomial new_P;
	makeNull (&new_P);
	for (int i = 0; i < pL->last; i++) {
	    if (pL->elements[i].e == 0) {
	        continue;
	    }
	    else {
	    	insert ((pL->elements[i].c)*(pL->elements[i].e), (pL->elements[i].e) - 1, &new_P);
		}
	}
	return new_P;
	/*
	Polynomial L;
makeNull(&L);
insert(5, 6, &L); insert(2, 2, &L);
insert(5, 4, &L);

Polynomial dL = differentiate(&L);
printf("p(x) = ");
printPolynomial(&L);
printf("p'(x) = ");
printPolynomial(&dL);
	*/
}

Position locate (EmementType x, List *pL) {
	for (int i = 1; i <= pL->last; i++) {
		if (pL->elements[i - 1] == x) {
			return i;
		}
	}
	return pL->last + 1;
}

void printPolynomial(Polynomial *pL) {
	if (pL->last == 0) {
		printf("\n");
		return;
	}
	for (int i = 0; i < pL->last; i++) {
		printf("(%.2lf)x^%d", pL->elements[i].c, pL->elements[i].e);
		if (i != pL->last - 1) {
			printf(" + ");
		}
	}
	printf("\n");
	/*
	Polynomial L;
makeNull(&L);
insert(5, 3, &L); insert(5, 4, &L);
insert(7, 0, &L); insert(-3, 2, &L);

printf("p(x) = ");
printPolynomial(&L);
	*/
}

int main() {
	Polynomial L;
makeNull(&L);
insert(3.25, 6, &L);

Polynomial dL = differentiate(&L);
printf("p(x) = ");
printPolynomial(&L);
printf("p'(x) = ");
printPolynomial(&dL);
}
