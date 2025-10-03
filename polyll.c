#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
} Node;
Node* p;
Node* prev;
Node* current;

Node* createNode(int coeff, int exp) {
    p = (Node*)malloc(sizeof(Node));
    p->coeff = coeff;
    p->exp = exp;
    p->next = NULL;
    return p;
}

void insertTerm(Node** poly, int coeff, int exp) {
    if(coeff == 0) 
	return; 
    p = createNode(coeff, exp);

    if (*poly == NULL || (*poly)->exp < exp) {
        p->next = *poly;
        *poly = p;
    } else {
         current = *poly;
        prev = NULL;

        while (current != NULL && current->exp > exp) {
            prev = current;
            current = current->next;
        }

        if (current != NULL && current->exp == exp) {
            current->coeff += coeff;
            free(p);
            if (current->coeff == 0) {
                if(prev == NULL) {
                    *poly = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            }
        } else {
            p->next = current;
            if (prev == NULL) {
                *poly = p;
            } else {
                prev->next = p;
            }
        }
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            insertTerm(&result, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void printPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    int first = 1;
    while (poly != NULL) {
        if (poly->coeff > 0 && !first) printf("+");
        if (poly->exp == 0)
            printf("%d", poly->coeff);
        else if (poly->exp == 1)
            printf("%dx", poly->coeff);
        else
            printf("%dx^%d", poly->coeff, poly->exp);
        
        first = 0;
        poly = poly->next;
    }
    printf("\n");
}

void inputPolynomial(Node** poly) {
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i+1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    printf("Input first polynomial:\n");
    inputPolynomial(&poly1);

    printf("Input second polynomial:\n");
    inputPolynomial(&poly2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum: ");
    printPolynomial(result);

    return 0;
}
