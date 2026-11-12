#include <iostream>
#include <string>
using namespace std;

int main() {
    system("clear");
    
    string correctUsername = "ali";
    string correctPassword = "1234";
    string username;
    string password;
    int attempts = 0;
    bool loggedIn = false;

    cout << "========== Welcome to the School Management System ==========\n";

    
    while (attempts < 3 && loggedIn == false) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (username == correctUsername && password == correctPassword) {
            loggedIn = true;
            cout << "Login successful!\n";
            cout << "Welcome to the School Management System\n";
        } else {
            attempts++;
            cout << "Incorrect username or password.\n";
            if (attempts < 3) {
                cout << "Attempts remaining: " << 3 - attempts << "\n";
            }
        }
    }

    if (loggedIn == true) {
        
        string studentName = "";
        int studentAge = 0;
        string studentClass = "";
        int phone;
        bool studentDataEntered = false;

        
        const int MAX_STUDENTS = 100;
        double grades[MAX_STUDENTS];
        int numberOfGrades = 0;
        bool gradesEntered = false;

        
        int presentCount = 0;
        int absentCount = 0;
        bool attendanceEntered = false;

        int mainChoice = 0;
        bool running = true;

        while (running == true) {
            cout << "\n========== School Management System ==========\n";
            cout << "1. Student Management\n";
            cout << "2. Grade Management\n";
            cout << "3. Attendance Management\n";
            cout << "4. Exit\n";
            cout << "Choose an option: ";
            cin >> mainChoice;
            system("clear");

            switch (mainChoice) {
                case 1: {
                    int studentChoice = 0;
                    bool studentMenuRunning = true;

                    while (studentMenuRunning == true) {
                        cout << "\n========== Student Management ==========\n";
                        cout << "1. Enter student information\n";
                        cout << "2. Display student information\n";
                        cout << "3. Determine student status\n";
                        cout << "4. Return to the main menu\n";
                        cout << "Choose an option: ";
                        cin >> studentChoice;
                        system("clear");

                        switch (studentChoice) {
                            case 1:
                                cout << "Enter student name: ";
                                cin >> studentName;
                                cout << "Enter student age: ";
                                cin >> studentAge;
                                cout << "Enter student grade/class: ";
                                cin >> studentClass;
                                cout<<"Enter number phone : "; cin>>phone;
                                studentDataEntered = true;
                                cout << "Student information saved.\n";
                                break;
                                

                            case 2:
                                if (studentDataEntered == true) {
                                    cout << "\nStudent Information:\n";
                                    cout << "Name: " << studentName << "\n";
                                    cout << "Age: " << studentAge << "\n";
                                    cout << "Grade/Class: " << studentClass << "\n";
                                } else {
                                    cout << "Student information has not been entered yet.\n";
                                }
                                break;

                            case 3: {
                                double studentGrade;
                                cout << "Enter the student's score: ";
                                cin >> studentGrade;
                                if (studentGrade >= 50) {
                                    cout << "Student status: Passed\n";
                                } else {
                                    cout << "Student status: Failed\n";
                                }
                                break;
                            }

                            case 4:
                                studentMenuRunning = false;
                                break;

                            default:
                                cout << "Invalid option. Please try again.\n";
                        }
                    }
                    break;
                }

                case 2: {
                    int gradesChoice = 0;
                    bool gradesMenuRunning = true;

                    while (gradesMenuRunning == true) {
                        cout << "\n========== Grade Management ==========\n";
                        cout << "1. Enter student grades\n";
                        cout << "2. Display grades\n";
                        cout << "3. Calculate average grade\n";
                        cout << "4. Display highest grade\n";
                        cout << "5. Display lowest grade\n";
                        cout << "6. Return to the main menu\n";
                        cout << "Choose an option: ";
                        cin >> gradesChoice;
                        system("clear");

                        switch (gradesChoice) {
                            case 1:
                                cout << "Enter the number of students (1 to " << MAX_STUDENTS << "): ";
                                cin >> numberOfGrades;
                                while (numberOfGrades < 1 || numberOfGrades > MAX_STUDENTS) {
                                    cout << "Invalid number. Enter a number from 1 to " << MAX_STUDENTS << ": ";
                                    cin >> numberOfGrades;
                                }

                                for (int i = 0; i < numberOfGrades; i++) {
                                    cout << "Enter the grade for student " << i + 1 << ": ";
                                    cin >> grades[i];
                                }
                                gradesEntered = true;
                                cout << "Grades saved.\n";
                                break;

                            case 2:
                                if (gradesEntered == true) {
                                    cout << "Student grades: ";
                                    for (int i = 0; i < numberOfGrades; i++) {
                                        cout << grades[i] << " ";
                                    }
                                    cout << "\n";
                                } else {
                                    cout << "Grades have not been entered yet.\n";
                                }
                                break;

                            case 3:
                                if (gradesEntered == true) {
                                    double totalGrades = 0;
                                    for (int i = 0; i < numberOfGrades; i++) {
                                        totalGrades = totalGrades + grades[i];
                                    }
                                    cout << "Average grade: " << totalGrades / numberOfGrades << "\n";
                                } else {
                                    cout << "Enter the grades first.\n";
                                }
                                break;

                            case 4:
                                if (gradesEntered == true) {
                                    double highestGrade = grades[0];
                                    for (int i = 1; i < numberOfGrades; i++) {
                                        if (grades[i] > highestGrade) {
                                            highestGrade = grades[i];
                                        }
                                    }
                                    cout << "Highest grade: " << highestGrade << "\n";
                                } else 
                                    cout << "Enter the grades first.\n";
                                
                                break;

                            case 5:
                                if (gradesEntered == true) {
                                    double lowestGrade = grades[0];
                                    for (int i = 1; i < numberOfGrades; i++) {
                                        if (grades[i] < lowestGrade) {
                                            lowestGrade = grades[i];
                                        }
                                    }
                                    cout << "Lowest grade: " << lowestGrade << "\n";
                                } else {
                                    cout << "Enter the grades first.\n";
                                }
                                break;

                            case 6:
                                gradesMenuRunning = false;
                                break;

                            default:
                                cout << "Invalid option. Please try again.\n";
                        }
                    }
                    break;
                }

                case 3: {
                    int attendanceChoice = 0;
                    bool attendanceMenuRunning = true;

                    while (attendanceMenuRunning == true) {
                        cout << "\n========== Attendance Management ==========\n";
                        cout << "1. Enter the number present and absent\n";
                        cout << "2. Display the number present\n";
                        cout << "3. Display the number absent\n";
                        cout << "4. Calculate attendance percentage\n";
                        cout << "5. Return to the main menu\n";
                        cout << "Choose an option: ";
                        cin >> attendanceChoice;
                        system("clear");

                        switch (attendanceChoice) {
                            case 1:
                                cout << "Number present: ";
                                cin >> presentCount;
                                cout << "Number absent: ";
                                cin >> absentCount;
                                while (presentCount < 0 || absentCount < 0) {
                                    cout << "Negative numbers are not allowed.\n";
                                    cout << "Number present: ";
                                    cin >> presentCount;
                                    cout << "Number absent: ";
                                    cin >> absentCount;
                                }
                                attendanceEntered = true;
                                cout << "Attendance data saved.\n";
                                break;

                            case 2:
                                if (attendanceEntered == true) {
                                    cout << "Number present: " << presentCount << "\n";
                                } else {
                                    cout << "Enter attendance data first.\n";
                                }
                                break;

                            case 3:
                                if (attendanceEntered == true) {
                                    cout << "Number absent: " << absentCount << "\n";
                                } else {
                                    cout << "Enter attendance data first.\n";
                                }
                                break;

                            case 4:
                                if (attendanceEntered == true) {
                                    int totalStudents = presentCount + absentCount;
                                    cout << "Total students: " << totalStudents << "\n";
                                    if (totalStudents > 0) {
                                        double attendancePercentage = (presentCount * 100.0) / totalStudents;
                                        cout << "Attendance percentage: " << attendancePercentage << "%\n";
                                    } else {
                                        cout << "Cannot calculate the percentage because the total number of students is zero.\n";
                                    }
                                } else {
                                    cout << "Enter attendance data first.\n";
                                }
                                break;

                            case 5:
                                attendanceMenuRunning = false;
                                break;

                            default:
                                cout << "Invalid option. Please try again.\n";
                        }
                    }
                    break;
                }

                case 4:
                    cout << "Thank you for using the School Management System.\n";
                    cout << "Have a nice day.\n";
                    running = false;
                    break;

                default:
                    cout << "Invalid option. Please try again.\n";
            }
        }
    } else {
        cout << "All three attempts have been used. The system is now closed.\n";
    }

    return 0;}