
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_LENGTH 28

char checkvalue[10]; // CRC value for one byte
char divisor[10] = "1001";
int i, j;

void XOR() {
    for (j = 1; j < strlen(divisor); j++)
        checkvalue[j] = ((checkvalue[j] == divisor[j]) ? '0' : '1');
}

void crc(const char* data) {
    int divisor_len = strlen(divisor);
    int data_len = strlen(data);

    // Copy the first divisor_len - 1 bits of data to checkvalue
    for (i = 0; i < divisor_len; i++)
        checkvalue[i] = data[i];

    for (int data_index = divisor_len; data_index <= data_len; data_index++) {
        if (checkvalue[0] == '1')
            XOR();
        // Shift checkvalue to the left and bring in the next bit from data
        for (j = 0; j < divisor_len - 1; j++)
            checkvalue[j] = checkvalue[j + 1];
        checkvalue[j] = data[data_index];
    }

    // Ensure the checkvalue is the size of the divisor length - 1
    checkvalue[divisor_len - 1] = '\0';
}

void stringToBinary(const char* str, char* binary) {
    binary[0] = '\0';
    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];
        for (int j = 7; j >= 0; --j) {
            strcat(binary, ((ch & (1 << j)) ? "1" : "0"));
        }
    }
}

void induceRandomError(char* data) {
    int len = strlen(data);
    if (len > 0) {
        int pos = rand() % len; 
        data[pos] = (data[pos] == '0') ? '1' : '0'; 
    }
}

void processEachChar(const char* data, char* result) {
    int len = strlen(data);
    char byteData[9];
    char tempData[50]; // For padded data with CRC
    byteData[8] = '\0'; // Null-terminate the byteData string

    result[0] = '\0'; // Initialize result as empty

    for (int i = 0; i < len; i += 8) {
        strncpy(byteData, data + i, 8); // Copy 8 bits to byteData
        byteData[8] = '\0'; // Null-terminate
        cout << "\nProcessing byte: " << byteData << endl;

        // Pad the byteData with zeros (length of divisor - 1)
        int divisor_len = strlen(divisor);
        strcpy(tempData, byteData);
        int tempLen = strlen(tempData);
        for (int j = tempLen; j < tempLen + divisor_len - 1; j++)
            tempData[j] = '0';
        tempData[tempLen + divisor_len - 1] = '\0';

        cout << "Processing Byte with n-1 zeroes: " << tempData << endl;

        // Compute CRC for the padded byte
        crc(tempData);
        cout << "CRC for padded byte: " << checkvalue << endl;

        // Append CRC result to final result
        strcat(result, byteData);
        strcat(result, checkvalue);
    }
}

int main() {
    char dword[MAX_LENGTH];
    char bdata[MAX_LENGTH * 8];
    char finaldata[MAX_LENGTH * 8];

    srand(static_cast<unsigned>(time(0)));

    cout << "Enter data to be transmitted: ";
    cin >> dword;

    stringToBinary(dword, bdata);

    cout << "\nBinary representation of the input data: " << bdata << endl;

    processEachChar(bdata, finaldata);

    cout << "\n----------------------------------------";
    cout << "\nFinal data to be sent: " << finaldata;
    cout << "\n----------------------------------------\n";

    char induce_error;
    cout << "Do you want to induce a random error? (y/n): ";
    cin >> induce_error;

    if (induce_error == 'y' || induce_error == 'Y') {
        cout << "\nInducing a random error in the data...\n";
        induceRandomError(finaldata);  // Induce a random error
        cout << "\nData after inducing error: " << finaldata << endl;

        char recalculated_crc[MAX_LENGTH * 8];
        processEachChar(finaldata, recalculated_crc);
        cout << "\nRe-calculated data after error induction: " << recalculated_crc << endl;
        cout << "Error detected.\n";
    } else {
        cout << "No error induced. Data remains as:\n";
        cout << "Final data to be sent in binary form: " << finaldata << endl;
        cout << "Final data to be sent: " << dword << endl;

    }

    return 0;
}
