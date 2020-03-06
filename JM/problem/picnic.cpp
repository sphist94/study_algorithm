// NOTE: Book(Algorithmic Problem Solving Strategies 1, 6.3)
// NOTE: https://algospot.com/judge/problem/read/PICNIC
// NOTE: Solver: Han(sphist94@gmail.com)
// NOTE: * Algorithm(Brute Force)
// NOTE: 1. pick up a student from student array, and then another student who is one of his friends
// NOTE: 2. recursive all pair cases of the students, and remove the two student from array
// NOTE: 3. and then recursive 1

#include <iostream>
#include <vector>

int C;
int n, m;
std::vector<std::vector<int>> friendship;

void readInput() {
    std::cin >> n >> m;
    friendship.resize(n);
    for (int i = 0; i < n; ++i) {
        friendship[i].resize(0);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
}

int getFirstNotMatedStudent(std::vector<bool> student) {
    for (int i = 0; i < student.size(); ++i) {
        if (!student[i]) {
            return i;
        }
    }
    return -1;
}

int mateStudents(std::vector<bool> student) {
    // NOTE: 1. pick up a student from student array, and then another student who is one of his friends
    int a = getFirstNotMatedStudent(student);
    if (a == -1) {
        return 1;
    }
    if (friendship[a].size() == 0) {
        return 0;
    }

    int ret = 0;
    // NOTE: 2. recursive all pair cases of the students, and remove the two student from array
    student[a] = true;
    for (int b : friendship[a]) {
        if (!student[b]) {
            student[b] = true;
            // NOTE: 3. and then recursive 1
            ret += mateStudents(student);
            student[b] = false;
        }
    }
    return ret;
}

int main() {
    std::cin >> C;
    std::vector<int> ans;
    while (C--) {
        readInput();
        std::vector<bool> student(n, false);
        ans.push_back(mateStudents(student));
    }

    for (int _ans : ans) {
        std::cout << _ans << std::endl;
    }
    return 0;
}