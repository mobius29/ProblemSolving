#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

typedef struct {
  int country;
  int student_id;
  int grade;
} Student;

int N;
vector<Student> students;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    Student student;
    cin >> student.country >> student.student_id >> student.grade;
    students.push_back(student);
  }

  sort(students.begin(), students.end(),
       [](Student a, Student b) { return a.grade > b.grade; });

  vector<Student> answer(students.begin(), students.begin() + 2);
  for (int i = 2; i < N; ++i) {
    int country = students[i].country;
    if (country != students[0].country || country != students[1].country) {
      answer.push_back(students[i]);
      break;
    }
  }

  for (auto [country, student_id, grade] : answer) {
    cout << country << ends << student_id << endl;
  }

  return 0;
}
