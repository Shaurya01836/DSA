#include<stdio.h>

void readPoly(int a[]){
    printf("Enter total non zero terms :");
    scanf("%d", &a[0]);
    for(int i = 1; i <= (2*a[0]); i=i+2){
        printf("Enter exponent of term : ");
        scanf("%d", &a[i]);
        printf("Enter coefficient of term : ");
        scanf("%d" ,&(a[i+1]));
    }
}

void printPoly(int a[]){
    int i;
    printf("\n\n");
    for(i = 1; i <= (2 * a[0]); i += 2){
        printf("%d", a[i+1]); // Coefficient

        if (a[i] > 1) // Power of x
            printf("x^%d", a[i]);
        else if (a[i] == 1)
            printf("x");

        if (i + 2 < 2 * a[0]) // If not the last term
            printf(" + ");
    }
}

void addPoly(int a[], int b[], int c[]){
    int m, n, p, q, r;
    m = a[0];
    n = b[0];
    p = q = r = 1;
    while((p<=2*m) && (q<=2*n)){
        if(a[p] == b[q]){
            c[r+1] = a[p+1] + b[q+1];
            if(c[r+1] != 0){
                c[r] = a[p];
                r = r+2;
            }
            p = p+2;
            q = q+2;
        }
        else if(a[p]<b[q]){
            c[r+1] = b[q+1];
            c[r] = b[q];
            q = q+2;
            r = r+2;
        }
        else{
           c[r+1] = a[p+1];
           c[r] = a[p];
           p = p+2; 
           r = r+2;
        }
    }
    while(p<=2*m){
        c[r] = a[p];
        c[r+1] = a[p+1];
        p = p+2;
        r = r+2; 
    }
    while(q<=2*n){
        c[r] = b[q];
        c[r+1] = b[q+1];
        q = q+2;
        r = r+2; 
    }
    c[0] = (r/2);
}

int main(){
    int a[20], b[20], c[20];
    printf("Enter first polynomial : \n");
    readPoly(a);
    printPoly(a);
    printf("\n");
    printf("Enter second polynomial : \n");
    readPoly(b);
    printPoly(b);
    printf("\n");
    addPoly(a, b, c);
    printf("\n The result is : ");
    printPoly(c);

    return 0;
}