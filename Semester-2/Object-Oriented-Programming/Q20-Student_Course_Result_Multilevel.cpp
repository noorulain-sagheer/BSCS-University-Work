#include<iostream>
using namespace std;
class Record
{
protected:
    int rollNo;
    string course1Name;
    string course2Name;
public:
    Record(int r, string c1, string c2)
    {
        rollNo = r;
        course1Name = c1;
        course2Name = c2;
    }
    int getRollNo()
    {
        return rollNo;
    }

    string getCourse1Name()
    {
        return course1Name;
    }

    string getCourse2Name()
    {
        return course2Name;
    }
};
class CourseRecord : public Record
{
protected:
    int marksCourse1;
    int marksCourse2;
public:
    CourseRecord(int r, string c1, string c2, int m1, int m2) : Record(r, c1, c2)
    {
        marksCourse1 = m1;
        marksCourse2 = m2;
    }
    int getMarksCourse1()
    {
        return marksCourse1;
    }
    int getMarksCourse2()
    {
        return marksCourse2;
    }
};
class CourseResult : public CourseRecord
{
private:
    int totalMarks;
public:
    CourseResult(int r, string c1, string c2, int m1, int m2) : CourseRecord(r, c1, c2, m1, m2)
    {
        totalMarks = marksObtained();
    }
    int marksObtained()
    {
        return marksCourse1 + marksCourse2;
    }
    void display()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Course 1: " << course1Name << endl;
        cout << "Course 2: " << course2Name << endl;
        cout << "Marks in " << course1Name << ": " << marksCourse1 << endl;
        cout << "Marks in " << course2Name << ": " << marksCourse2 << endl;
        cout << "Total Marks: " << marksObtained() << endl;
    }
};
int main()
{
    CourseResult student(101, "OOP", "DSA", 85, 90);
    student.display();

    return 0;
}
