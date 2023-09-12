#include <stdio.h>

#define TABLE_SIZE 13

// Function to calculate the first hash
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Function to calculate the second hash
int hash2(int key) {
    // Use a prime number less than TABLE_SIZE for the second hash
    return 7 - (key % 7);
}

// Function to insert a key into the hash table using double hashing
void insert(int table[], int key) {
    int index = hash1(key);
    int step = hash2(key);

    while (table[index] != -1) {
        // Collision detected, use double hashing to find the next available slot
        index = (index + step) % TABLE_SIZE;
    }

    // Insert the key into the table
    table[index] = key;
}

int main() {
    int hashTable[TABLE_SIZE];

    // Initialize the hash table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    int keys[] = {79, 69, 98, 72, 14, 50};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Insert the keys into the hash table
    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    // Print the contents of the hash table
    printf("Hash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }

    return 0;
}
