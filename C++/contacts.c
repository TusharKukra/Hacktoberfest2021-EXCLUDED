
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "contacts.h"
#include "contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+


// name function begins
// name function begins
void getName(struct Name* name)
{

    int yesNo;
    printf("\n");
    printf("Please enter the contact's first name: ");
    scanf(" %30[^\n]", name->firstName);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else name->middleInitial[0] = '\0';
    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]", name->lastName);


}
// address function begins
void getAddress(struct Address* address)
{
    int yesNo;
    int num;
    printf("Please enter the contact's street number: ");
    num = getInt();
    if (num < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }
    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]", address->street);
    printf("Do you want to enter an apartment number? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's apartment number: ");
        num = getInt();
        if (num < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]", address->city);

}


// numbers function begins
void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    printf("Please enter the contact's cell phone number: ");
    //scanf("%c%*c", &numbers->cell);
    //scanf("%s", numbers->cell);
    getTenDigitPhone(numbers->cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's home phone number: ");
       // scanf("%s", numbers->home);
        getTenDigitPhone(numbers->cell);
    }
    else
    {
        strcpy(numbers->home, "\0");
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's business phone number: ");
        //scanf("%s", numbers->business);
        getTenDigitPhone(numbers->business);
    }
    else 
    {
        strcpy(numbers->home, "\0");
    }
}

//contact function begins
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

