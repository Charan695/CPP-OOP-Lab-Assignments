#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    vector<Student> students = {
        {"Aarav", 82}, {"Meera", 95}, {"Kabir", 68},
        {"Sara", 91}, {"Ishaan", 76}
    };

    // sort students by marks in descending order.
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) { return a.marks > b.marks; });

    cout << "===== Sorted Student Marks =====\n";
    for (const auto& student : students)
        cout << student.name << ": " << student.marks << '\n';

    // find_if finds the first record meeting the condition.
    auto topper = find_if(students.begin(), students.end(),
                          [](const Student& s) { return s.marks >= 90; });
    if (topper != students.end())
        cout << "\nFirst student scoring at least 90: " << topper->name << '\n';

    // map stores keys in sorted order.
    map<string, int> marksByName;
    for (const auto& student : students)
        marksByName[student.name] = student.marks;

    cout << "\n--- map: name to marks ---\n";
    for (const auto& entry : marksByName)
        cout << entry.first << ": " << entry.second << '\n';

    // unordered_map stores grade frequencies; iteration order is unspecified.
    unordered_map<string, int> gradeCounts;
    for (const auto& student : students) {
        string grade = student.marks >= 90 ? "A" :
                       student.marks >= 75 ? "B" : "C";
        ++gradeCounts[grade];
    }

    cout << "\n--- unordered_map: grade counts ---\n";
    for (const auto& entry : gradeCounts)
        cout << entry.first << ": " << entry.second << '\n';

    // transform creates a second collection with two bonus marks added.
    vector<int> marks, bonusMarks(students.size());
    for (const auto& student : students) marks.push_back(student.marks);
    transform(marks.begin(), marks.end(), bonusMarks.begin(),
              [](int mark) { return mark + 2; });

    cout << "\n--- transform: marks after adding 2 ---\n";
    for (int mark : bonusMarks) cout << mark << ' ';
    cout << '\n';
    return 0;
}
