/*
 ============================================================================
 Name        : Assignment1.c
 Author      : Anuar Maratkhan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h> // Needed for strcmp function (Lesson 21)

typedef struct {
    // sale_id dd qty type total_cost arrangement payment delivery courier
    int sale_id;
    int dd;
    int qty;
    char type[25];
    double total_cost;
    char arrangement[25];
    char payment[25];
    int delivery;
    char courier[25];
} Sales;
// Counting how many orders were placed on the given day
void Orders(Sales array[], int day, int size) {
    int orders = 0;
    for (int i = 0; i < size; i++)
        if (day == array[i].dd)
            orders++;
    printf("%d orders were placed that day.\n", orders);
}
// Counting how many flowers were sold (quantities) on the given day
void Flowers(Sales array[], int day, int size) {
    int flowers = 0;
    for (int i = 0; i < size; i++)
        if (day == array[i].dd)
            flowers += array[i].qty;
    printf("%d flowers were sold.\n", flowers);
}
// Counting how many small bouquets and big bouquets were sold on the given day
void Bouquets(Sales array[], int day, int size) {
    int bouquets = 0;
    for (int i = 0; i < size; i++)
        if (day == array[i].dd)
            if (strcmp("small_bouquet", array[i].type) == 0 || strcmp("big_bouquet", array[i].type) == 0)
                bouquets++;
    printf("%d bouquets were sold.\n", bouquets);
}
// Counting how many gifts were sold on the given day, and what are they (if sold)
void Gifts(Sales array[], int day, int size) {
    int gifts = 0;
    for (int i = 0; i < size; i++)
        if (day == array[i].dd)
            if (strcmp("gift", array[i].type) == 0) {
                gifts++;
                printf("The gift is %s\n", array[i].type); // listing the gift
            }
    printf("%d gifts were sold.\n", gifts);
}
// Counting total cost of the orders on the given day
void Cost(Sales array[], int day, int size) {
    int total = 0;
    for (int i = 0; i < size; i++)
        if (day == array[i].dd)
            total += array[i].total_cost;
    printf("Total cost of the orders is %d\n", total);
}
// Showing the total costs broken down by payment type on the given day
void Payment(Sales array[], int day, int size) {
    // payment types
    char payments[][25] = {
        "cash",
        "Epay_kazkom",
        "halyq_bank",
        "paypal",
        "qiwi",
        "web_money",
        "yandex_money"
    };
    // payment costs
    double costs[7] = { 0.0 };
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 7; j++)
            if (day == array[i].dd)
                if (strcmp(payments[j], array[i].payment) == 0)
                    costs[j] += array[i].total_cost;
    for (int i = 0; i < 7; i++)
        printf("%d. %s:     %f\n", i, payments[i], costs[i]);
}
// Counting number of deliveries and money spent on it
void Delivery(Sales array[], int day, int size) {
    int delivery_number = 0;
    int delivery_cost = 0;
    for (int i= 0; i < size; i++)
        if (day == array[i].dd)
            if(array[i].delivery != 0) {
                delivery_number++;
                delivery_cost += array[i].delivery;;
            }
    printf("%d deliveries were made.\n", delivery_number);
    printf("%d was spent on deliveries.\n", delivery_cost);
}
// Finding which courier made most deliveries, and counting the number of deliveries of the courier on the given day
void Courier(Sales array[], int day, int size) {
    // the names of the couriers
    char names[][25] = {
        "azat",
        "shapaghat",
        "qanat_agha",
    };
    int deliveries[3] = { 0 };
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 3; j++)
            if (day == array[i].dd)
                if (strcmp(names[j], array[i].courier) == 0)
                    deliveries[j]++;
    int max = deliveries[0];
    int courier = 0;
    for (int i = 0; i < 3; i++)
        if (deliveries[i] > max) {
            max = deliveries[i];
            courier = i;
        }
    for (int i = 0; i < 3; i++)
        if (courier == i)
            printf("%s made most deliveries: %d\n", names[i], max);
}
int main(void) {
    // Variables need for program
    Sales array[200];
    int i = 0;
    int day = 1;
    int size;
    // Reading a provided file flowers_sales.txt (Lesson 11)
    FILE *flower_sales = fopen("flower_sales.txt", "r");
    // In case if file is there is a problem with file flower_sales.txt the program will stop.
    if(flower_sales == NULL) {
        printf("Error: File not found.");
        return 0;
    }
    // scanf from a file and store it in array of type Sales (Lesson 11)
    while(!feof(flower_sales)) {
        fscanf(flower_sales, "%d", &array[i].sale_id);
        fscanf(flower_sales, "%d", &array[i].dd);
        fscanf(flower_sales, "%d", &array[i].qty);
        fscanf(flower_sales, "%s", array[i].type);
        fscanf(flower_sales, "%lf", &array[i].total_cost);
        fscanf(flower_sales, "%s", array[i].arrangement);
        fscanf(flower_sales, "%s" ,array[i].payment);
        fscanf(flower_sales, "%d" ,&array[i].delivery);
        fscanf(flower_sales, "%s" ,array[i].courier);
        i++;
    }
    // Size of the array
    size = i;
    // Close file after reading it.
    fclose(flower_sales);
    // Fixing a bug with printf before scanf
    setvbuf(stdout, NULL, _IONBF, 0);
    while (1) {
        // Ask the user the number of day
        printf("Please type in the day you want to see:\n");
        scanf("%d", &day);
        if(0 < day && day < 32) {
            // Showing the information
            Orders(array, day, size);
            Flowers(array, day, size);
            Bouquets(array, day, size);
            Gifts(array, day, size);
            Cost(array, day, size);
            Payment(array, day, size);
            Delivery(array, day, size);
            Courier(array, day, size);
        } else {
            printf("Wrong input! Please run the program again and type a day in the range of 1-31.\n");
            break;
        }
    }
    return 0;
}
