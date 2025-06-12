#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxaccount 10

struct Account {
    char account_name[50];
    char username[50];
    char password[50];
    char gmail[50];
    char app_name[50];
};

struct Account accounts[maxaccount];
int count = 0;

void check_character_criteria(char a[], int *has_upper, int *has_lower, int *has_digit, int *has_special) {
    *has_upper = *has_lower = *has_digit = *has_special = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (isupper(a[i])) *has_upper = 1;
        else if (islower(a[i])) *has_lower = 1;
        else if (isdigit(a[i])) *has_digit = 1;
        else if (ispunct(a[i])) *has_special = 1;

    }
}

int notaccepted(char a[]) {
    char *notacc[10] = {"password", "12345678", "qwerty", "abc123","welcome", "iloveyou", "admin", "12345"};
    int size = sizeof(notacc) / sizeof(notacc[0]);
    for (int i = 0; i < size; i++) {
        if (strcmp(a, notacc[i]) == 0)
            return 1;
    }
    return 0;
}

int sequence(char a[]) {
    int len = strlen(a);
    for (int i = 0; i <= len-5; i++) {
        if (a[i + 1] - a[i] == 1 &&
            a[i + 2] - a[i + 1] == 1 &&
            a[i + 3] - a[i + 2] == 1 &&
            a[i + 4] - a[i + 3] == 1)
            return 1;

        if (a[i] - a[i + 1] == 1 &&
            a[i + 1] - a[i + 2] == 1 &&
            a[i + 2] - a[i + 3] == 1 &&
            a[i + 3] - a[i + 4] == 1)
            return 1;
    }
    return 0;
}


int length(char a[]) {
    return strlen(a) >= 8 && strlen(a) <= 64;
}

void passwordstrength(char a[]) {
    int has_upper, has_lower, has_digit, has_special;
    check_character_criteria(a, &has_upper, &has_lower, &has_digit, &has_special);

    int Criteria1 = has_upper;
    int Criteria2 = has_lower;
    int Criteria3 = has_digit;
    int Criteria4 = has_special;
    int Criteria5 = !sequence(a);
    int Criteria6 = !notaccepted(a);
    int Criteria7 = length(a);
    int totalCriteria = Criteria1 + Criteria2 + Criteria3 + Criteria4 + Criteria5 + Criteria6 + Criteria7;

    if (!Criteria7) printf("(length must be between 8 to 64)\n");
    if (!Criteria5) printf("(contains sequence)\n");
    if (!Criteria6) printf("(common password)\n");

    if (totalCriteria >= 6)
        printf("Strong\n");
    else if (totalCriteria == 5)
        printf("Medium\n");
    else if (totalCriteria == 4)
        printf("Weak\n");
    else
        printf("Very Weak\n");
}

void add_account() {
    if (count >= maxaccount) {
        printf("Account limit reached.\n");
        return;
    }
    printf("Enter account name: ");
    scanf("%49s", accounts[count].account_name);
    printf("Enter username: ");
    scanf("%49s", accounts[count].username);
    printf("Enter password: ");
    scanf("%49s", accounts[count].password);
    printf("Enter Gmail: ");
    scanf("%49s", accounts[count].gmail);
    printf("Enter app name: ");
    scanf("%49s", accounts[count].app_name);
    count++;
}

char* retrieve_password(char account_name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(account_name, accounts[i].account_name) == 0) {
            return accounts[i].password;
        }
    }
    return NULL;
}

void check_password_strength() {
    char password[50];
    printf("Enter password to check strength: ");
    scanf("%49s",password);
    passwordstrength(password);
}

void print_all_accounts() {
    printf("Account Name        Username           Password           Gmail              App Name\n");
    for (int i = 0; i < count; i++) {
        printf("%-18s   %-16s   %-16s   %-16s   %-16s\n", accounts[i].account_name, accounts[i].username, accounts[i].password, accounts[i].gmail, accounts[i].app_name);
    }
}

void display(int *p) {
    printf("At most %d accounts can be saved\n", *p);
}

int main() {
    printf("Introducing DroidPass: Your Ultimate Password Management Solution\n");
    int choice;
    int x = 10;
    display(&x);
    while (1) {
        printf("1. Add account\n");
        printf("2. Retrieve password\n");
        printf("3. Check strength for password\n");
        printf("4. Print all accounts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2: {
                char account_name[50];
                printf("Enter the account name to retrieve password: ");
                scanf("%49s", account_name);
                char *password = retrieve_password(account_name);
                if (password) {
                    printf("Password for account '%s' is: %s\n", account_name, password);
                } else {
                    printf("Account '%s' not found.\n");
                }
                break;
            }
            case 3:
                check_password_strength();
                break;
            case 4:
                print_all_accounts();
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}

