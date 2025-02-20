#include <iostream>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

void Push(queue<int>& Queue, int n) {
    Queue.push(n);
}

void Size(queue<int>& Queue) {
    cout << Queue.size() << "\n";
}

void Pop(queue<int>& Queue) {
    if (Queue.empty())
        cout << "-1\n";
    else {
        cout << Queue.front() << "\n";
        Queue.pop();
    }
}

void Empty(queue<int>& Queue) {
    cout << (Queue.empty() ? "1\n" : "0\n");
}

void Front(queue<int>& Queue) {
    if (Queue.empty())
        cout << "-1\n";
    else
        cout << Queue.front() << "\n";
}

void Back(queue<int>& Queue) {
    if (Queue.empty())
        cout << "-1\n";
    else
        cout << Queue.back() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();  // 입력 버퍼 개행 제거

    queue<int> QueueTest;

    for (int i = 0; i < n; i++) {
        string strCommand;
        getline(cin, strCommand);  // 한 줄 입력 받기

        istringstream ss(strCommand);
        string operation;
        int value = 0;

        ss >> operation;  // 연산자 읽기

        if (operation == "push") {
            ss >> value;
            Push(QueueTest, value);
        }
        else if (operation == "pop") {
            Pop(QueueTest);
        }
        else if (operation == "size") {
            Size(QueueTest);
        }
        else if (operation == "empty") {
            Empty(QueueTest);
        }
        else if (operation == "front") {
            Front(QueueTest);
        }
        else if (operation == "back") {
            Back(QueueTest);
        }
    }

    return 0;
}