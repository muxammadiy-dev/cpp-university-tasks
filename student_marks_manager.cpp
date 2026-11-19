#include <iostream>

using namespace std;

const int MAX_MARKS = 100;

// 1. Add mark
void addMark(int marks[], int& count) {
    if (count >= MAX_MARKS) {
        cout << "Array is full!" << endl;
        return;
    }
    int mark;
    cout << "Enter mark (0-100): ";
    cin >> mark;

    if (mark < 0 || mark > 100) {
        cout << "Invalid mark!" << endl;
    }
    else {
        marks[count] = mark;
        count++;
        cout << "Mark added." << endl;
    }
}

// 2. Search mark
void searchMark(const int marks[], int count) {
    if (count == 0) {
        cout << "No marks in the array." << endl;
        return;
    }
    int target;
    cout << "Enter mark to search: ";
    cin >> target;

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (marks[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "Mark " << target << " found at index " << foundIndex << "." << endl;
    }
    else {
        cout << "Mark " << target << " not found." << endl;
    }
}

// 3. Sort marks
void sortMarks(int marks[], int count) {
    if (count == 0) {
        cout << "No marks in the array." << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }
    cout << "Marks sorted in ascending order." << endl;
}

// 4. Display all marks
void displayMarks(const int marks[], int count) {
    if (count == 0) {
        cout << "No marks in the array." << endl;
        return;
    }
    cout << "Marks:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Index " << i << ": " << marks[i] << endl;
    }
}

// 5. Largest and smallest mark 
void findLargestAndSmallest(const int marks[], int count) {
    if (count == 0) {
        cout << "No marks in the array." << endl;
        return;
    }
    int largest = marks[0];
    int smallest = marks[0];

    for (int i = 1; i < count; i++) {
        if (marks[i] > largest) {
            largest = marks[i];
        }
        if (marks[i] < smallest) {
            smallest = marks[i];
        }
    }

    cout << "Largest mark: " << largest << endl;
    cout << "Smallest mark: " << smallest << endl;
}

// 6. Average mark calculation
double calculateAverage(const int marks[], int count) {
    if (count == 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

int main() {
    int marks[MAX_MARKS];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Student Marks Manager =====" << endl;
        cout << "1. Add mark" << endl;
        cout << "2. Search mark" << endl;
        cout << "3. Sort marks" << endl;
        cout << "4. Display all marks" << endl;
        cout << "5. Largest and smallest mark" << endl;
        cout << "6. Average mark" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addMark(marks, count);
            break;
        case 2:
            searchMark(marks, count);
            break;
        case 3:
            sortMarks(marks, count);
            break;
        case 4:
            displayMarks(marks, count);
            break;
        case 5:
            findLargestAndSmallest(marks, count);
            break;
        case 6:
            if (count == 0) {
                cout << "No marks in the array." << endl;
            }
            else {
                cout << "Average mark: " << calculateAverage(marks, count) << endl;
            }
            break;
        case 7:
            cout << "Thank you! Program ended." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}