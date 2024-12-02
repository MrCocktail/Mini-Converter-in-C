#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

// Copy and paste your working directory here 👇 to test my code. Cheers 🥂
#define PATH "./"

FILE *f;
struct Date {
    int day;
    int month;
    int year;
};
char c;

// Functions Prototypes
float tempConverter(int operation, char *list[2]);
float lengthConverter(int operation, char *list[2]);
float weightConverter(int operation, char *list[2]);
float volumeConverter(int operation, char *list[2]);
void createFile();
char getHistory();
int parseDate(char *input, struct Date *date);
void getUserDate(struct Date *date);
char generatePeriodicReport();
char setPreferences();
int editPreferences();
char *apply_preferences(float num);
void save(char unitFrom[20], char unitTo[20], char * formattedValue, char *formattedResult);


void menu() {
    getHistory();
    setPreferences();
    int userChoice, operation;
    char unitFrom[20], unitTo[20];
    char *temperatureUnits[2] = {"Celsius", "Fahrenheit"};
    char *lengthUnits[2] = {"Centimeters", "Inches"};
    char *weightUnits[2] = {"Kilograms", "Pounds"};
    char *volumeUnits[2] = {"Liters", "US Gallons"};
    puts("Please choose one of the following options:\n 1. Temperature Converter\n 2. Length Converter\n 3. Weight Converter\n 4. Volume Converter\n 5. Generate a daily report\n 6. Edit Preferences\n 7. Exit\n");
    scanf(" %d", &userChoice);
    switch (userChoice) {
        case 1:
            puts("Please choose one of the following options:\n 1. Celsius to Fahrenheit\n 2. Fahrenheit to Celsius\n 3. Exit\n");
            scanf(" %d", &operation);
            tempConverter(operation, temperatureUnits);
            break;
        case 2:
            puts("Please choose one of the following options:\n 1. Centimeters to Inches\n 2. Inches to Centimeters\n 3. Exit\n");
            scanf(" %d", &operation);
            lengthConverter(operation, lengthUnits);
            break;
        case 3:
            puts("Please choose one of the following options:\n 1. Kilograms to Pounds\n 2. Pounds to Kilograms\n 3. Exit\n");
            scanf(" %d", &operation);
            weightConverter(operation, weightUnits);
            break;
        case 4:
            puts("Please choose one of the following options:\n 1. Liters to American Gallons\n 2. American Gallons to Liters\n 3. Exit\n");
            scanf(" %d", &operation);
            volumeConverter(operation, volumeUnits);
            break;
        case 5:
            generatePeriodicReport();
            break;
        case 6:
            editPreferences();
            break;
        case 7:
            puts("Goodbye!");
            // getch();
            exit(0); 
        default: 
            printf("Invalid choice. Try again in a new session.");
            return;
    }
}

float tempConverter(int operation, char *list[2]) {
    char unitFrom[20], unitTo[20], *formattedValue, *formattedResult;
    float result, startingValue;
    system(CLEAR_SCREEN);
    if (operation == 1 || operation == 2) {
        puts("Please enter the starting value: ");
        scanf(" %f", &startingValue);
    }

    switch (operation) {
        case 1:
            strcpy(unitFrom, list[0]);
            strcpy(unitTo, list[1]);
            result = startingValue * 1.8 + 32;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s degrees %s is %s degrees %s\n Press Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 2:
            strcpy(unitFrom, list[1]);
            strcpy(unitTo, list[0]);
            result = (startingValue - 32) / 1.8;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s degrees %s is %s degrees %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 3:
            printf("Goodbye!");
            result = 0;
            exit(0);
        default: 
            printf("Invalid choice. Try again in a new session.");
            break;
    }
    return result;
}

float lengthConverter(int operation, char *list[2]) {
    char unitFrom[20], unitTo[20], *formattedValue, *formattedResult;
    float result, startingValue;
    system(CLEAR_SCREEN);
    if (operation == 1 || operation == 2) {
        puts("Please enter the starting value: ");
        scanf(" %f", &startingValue);
    }

    switch (operation) {
        case 1:
            strcpy(unitFrom, list[0]);
            strcpy(unitTo, list[1]);
            result = startingValue / 2.54;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s %s is %s %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 2:
            strcpy(unitFrom, list[1]);
            strcpy(unitTo, list[0]);
            result = startingValue * 2.54;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s %s is %s %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 3:
            printf("Goodbye!");
            result = 0;
            exit(0);
        default: 
            printf("Invalid choice. Try again in a new session.");
            break;
    }
    return result;
}

float weightConverter(int operation, char *list[2]) {
    char unitFrom[20], unitTo[20], *formattedValue, *formattedResult;
    float result, startingValue;
    system(CLEAR_SCREEN);
    if (operation == 1 || operation == 2) {
        puts("Please enter the starting value: ");
        scanf(" %f", &startingValue);
    }

    switch (operation) {
        case 1:
            strcpy(unitFrom, list[0]);
            strcpy(unitTo, list[1]);
            result = startingValue * 2.2046;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s %s is %s %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 2:
            strcpy(unitFrom, list[1]);
            strcpy(unitTo, list[0]);
            result = startingValue / 2.2046;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s %s is %s %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 3:
            printf("Goodbye!");
            result = 0;
            exit(0);
        default: 
            printf("Invalid choice. Try again in a new session.");
            break;
    }
    return result;
}

float volumeConverter(int operation, char *list[2]) {
    char unitFrom[20], unitTo[20], *formattedValue, *formattedResult;
    float result, startingValue;
    system(CLEAR_SCREEN);
    if (operation == 1 || operation == 2) {
        puts("Please enter the starting value: ");
        scanf(" %f", &startingValue);
    }

    switch (operation) {
        case 1:
            strcpy(unitFrom, list[0]);
            strcpy(unitTo, list[1]);
            result = startingValue * 3.7854;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s %s is %s %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 2:
            strcpy(unitFrom, list[1]);
            strcpy(unitTo, list[0]);
            result = startingValue / 3.7854;
            formattedResult = apply_preferences(result);
            formattedValue = apply_preferences(startingValue);
            printf("%s %s is %s %s\nPress Enter to continue...", formattedValue, unitFrom, formattedResult, unitTo);
            getch();
            save(unitFrom, unitTo, formattedValue, formattedResult);
            free(formattedResult);
            free(formattedValue);
            break;
        case 3:
            printf("Goodbye!");
            result = 0;
            exit(0);
        default: 
            printf("Invalid choice. Try again in a new session.");
            break;
    }
    return result;
}


int parseDate(char *input, struct Date *date) {
    return sscanf(input, "%d-%d-%d", &date->year, &date->month, &date->day) == 3;
}

void getUserDate(struct Date *date) {
    char input[20];
    printf("Enter the date (format YYYY-MM-DD): ");
    scanf(" %s", input);

    while (!parseDate(input, date)) {
        printf("Invalid date format. Please try again (format YYYY-MM-DD): ");
        scanf(" %s", input);
    }
}


void createFile() {
    char filename[100];
    sprintf(filename, "%shistory.txt", PATH);
    f = fopen(filename, "r");
    if (f){
        fclose(f);
    } else {
        f = fopen(filename, "w");
        if (!f) {
            printf("Failed to create History file. Press Enter to continue\n");
            c = getch();
            return;
        }
        // fprintf(f, "*** History ***\n");
        fprintf(f, "\n%-10s\t%-8s\t%-20s\t%-20s\t%10s\t%10s\n", 
        "Date", "Hour", "Unit_From", "Unit_To", "Value", "Result");
        fclose(f);
    }
}
char getHistory() {
    char fileLine[100], filename[100];
    sprintf(filename, "%shistory.txt", PATH);
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error openning history file.");
        return 1;
    } 
    if (f != 0) {
        printf("\n\n*** History ***");
        printf("\n=========================================================================================\n");
        // while (!feof(f)) {
        //     fgets(fileLine, sizeof(fileLine), f);
        //     printf("%s", fileLine);
        // }
        while (fgets(fileLine, sizeof(fileLine), f) != NULL) {
            printf("%s", fileLine);
        }
    }
    printf("\n=========================================================================================\n");
    fclose(f);
    return 0;
}

char generatePeriodicReport() {
    struct Date targetDate;
    char filename[100], report[100], date[25];
    int found = 0;
    system(CLEAR_SCREEN);
    
    sprintf(filename, "%shistory.txt", PATH);
    f = fopen(filename, "r");
    if(!f){
        printf("Error accessing your history. You have to make some computing first. Press Enter to continue");
        c = getch();
        return 1;
    }

    getUserDate(&targetDate);
    printf("\n--------------------------------------------------\n");
    printf("*** Report for %04d-%02d-%02d ***\n", targetDate.year, targetDate.month, targetDate.day);
    printf("\n%-10s\t%-8s\t%-20s\t%-20s\t%10s\t%10s\n", 
        "Date", "Hour", "Unit_From", "Unit_To", "Value", "Result");
    while (fgets(report, sizeof(report), f)) {
        struct Date logDate;
        sscanf(report, "%d-%d-%d", &logDate.year, &logDate.month, &logDate.day);

        if (logDate.year == targetDate.year &&
            logDate.month == targetDate.month &&
            logDate.day == targetDate.day) {
            printf("%s", report);
            found = 1;
        }
    }
    if (!found) {
        printf("No match found for this date. Press Enter to continue\n");
        c = getch();
    } else {
        c = getch();
    }
    printf("--------------------------------------------------\n");
    fclose(f);
    return 0;
}


char setPreferences() {
    FILE *pf;
    int decimals, defaultSeparator;
    char filename[100];
    sprintf(filename, "%spreferences.txt", PATH);
    pf = fopen(filename, "r");
    if (pf == 0){
        system(CLEAR_SCREEN);
        puts("How many digits would you like to have in the decimal part of the results?");
        scanf(" %d", &decimals);

        printf("You prefer dot(.) or comma (,)?");
        puts("Tap 1 for dot and 0 for comma.");
        scanf(" %d", &defaultSeparator);
        while((defaultSeparator != 0) && (defaultSeparator != 1)){
            system(CLEAR_SCREEN);
            puts("You prefer dot(.) or comma (,)?");
            puts("Please choose either 1 or 0.");
            scanf(" %d", &defaultSeparator);
        }
        pf = fopen(filename, "w");
        if (pf == 0){
            printf("Error creating the preferences file. Press Enter to continue");
            c = getch();
            return 1;
        }
        fprintf(pf, "Decimal Precision: %d\n", decimals);
        fprintf(pf, "Default Separator: %d\n", defaultSeparator);
        fclose(pf);
    }
    return 0;
}

int editPreferences() {
    FILE *pf;
    int decimals, defaultSeparator;
    char filename[100];
    sprintf(filename, "%spreferences.txt", PATH);

    system(CLEAR_SCREEN);
    puts("How many digits would you like to have in the decimal part of the results?");
    scanf(" %d", &decimals);

    printf("You prefer dot(.) or comma (,)?");
    puts("Tap 1 for dot and 0 for comma.");
    scanf(" %d", &defaultSeparator);
    while((defaultSeparator != 0) && (defaultSeparator != 1)){
        system(CLEAR_SCREEN);
        puts("You prefer dot(.) or comma (,)?");
        puts("Please choose either 1 or 0.");
        scanf(" %d", &defaultSeparator);
    }
    pf = fopen(filename, "w");
    if (pf == 0){
        printf("Error updating the preferences file. Press Enter to continue");
        c = getch();
        return 1;
    }
    fprintf(pf, "Decimal Precision: %d\n", decimals);
    fprintf(pf, "Default Separator: %d\n", defaultSeparator);
    fclose(pf);
    return 0;
}

char *apply_preferences(float num) {
    FILE *fp;
    char *buffer = malloc(50);
    char filename[100], line[100];
    int precision, separator;
    sprintf(filename, "%spreferences.txt", PATH);
    fp = fopen(filename, "r");
    if(fp == 0){
        printf("Error accessing preferences file. Press Enter to continue");
        c = getch();
        return NULL;
    }

    fgets(line, sizeof(line), fp);
    sscanf(line, "Decimal Precision: %d", &precision);

    fgets(line, sizeof(line), fp);
    sscanf(line, "Default Separator: %d", &separator);

    sprintf(buffer, "%.*f", precision, num);
    char *dot = strchr(buffer, '.');
    if (dot && separator == 0) {
        *dot = ',';
    }
    return buffer;
}

void save(char unitFrom[20], char unitTo[20], char *formattedValue, char *formattedResult) {
    char filename[100], date[11], hour[10];
    createFile();
    time_t current_time = time(NULL);
    if (current_time == ((time_t)-1)) {
        fprintf(stderr, "Failed to obtain the current time. Press Enter to continue\n");
        c = getch();
        return;
    }

    struct tm *local_time = localtime(&current_time);
    if (local_time == NULL) {
        fprintf(stderr, "Failed to convert the current time. Press Enter to continue\n");
        c = getch();
        return;
    }

    strftime(date, sizeof(date), "%Y-%m-%d", local_time);
    strftime(hour, sizeof(hour), "%H:%M:%S", local_time);
    
    sprintf(filename, "%shistory.txt", PATH);
    f = fopen(filename, "a");

    if (f == NULL) {
        printf("Error accessing history file. Press Enter to continue");
        c = getch();
        return;
    }

    fprintf(f, "%-10s\t%-8s\t%-20s\t%-20s\t%10s\t%10s\n", 
        date, hour, unitFrom, unitTo, formattedValue, formattedResult);

    fclose(f);
}

int main() {
    printf("\n*** Welcome to the converter program ***\n\n");
    // free(result);

    // printf("i = %.*f", n,i);
    while (1) {
        menu();
    }
    return 0;
}
