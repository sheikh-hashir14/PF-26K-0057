#include <stdio.h>

int main(){
    int q;
    float p, d, t;
    float s, a, final_bill;

    printf("Enter quantity: ");
    scanf("%d", &q);
    printf("Enter price per item: ");
    scanf("%f", &p);
    printf("Enter discount percentage: ");
    scanf("%f", &d);
    printf("Enter tax percentage: ");
    scanf("%f", &t);

    if (q <= 0){
        printf("Invalid quantity: must be greater than 0\n");
    }

    else if (p <= 0){
        printf("Invalid price: must be greater than 0\n");
    }

    else if (d < 0 || d >= 100){
        printf("Invalid discount: must be from 0 to below 100\n");
    }

    else if (t < 0 || t >= 100){
        printf("Invalid tax: must be from 0 to below 100\n");
    }

    else{
        s = q * p;
        a = s - (s * d) / 100;
        final_bill = a + (a * t) / 100;

        printf("\n----- BILL -----\n");
        printf("Subtotal = %.2f\n", s);
        printf("Discount (%%) = %.2f\n", d);
        printf("Discounted amount = %.2f\n", a);
        printf("Tax (%%) = %.2f\n", t);
        printf("Final bill = %.2f\n", final_bill);
    }

    return 0;
}