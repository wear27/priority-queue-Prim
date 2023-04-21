#include"PriorityQueue.h"
#include<iostream>

using namespace std;

PriorityQueue::PriorityQueue(){}

PriorityQueue::~PriorityQueue()
{
    clear();
}

void PriorityQueue::push(int value, int priority) {
    queue.push_back(make_pair(value, priority));
    int pos = queue.size() - 1;
    shift_up(pos);
}

void PriorityQueue::pop() {
    if (queue.empty()) {
        return;
    }
    swap(queue[0], queue[queue.size() - 1]);
    queue.pop_back();
    shift_down(0);
}

int PriorityQueue::top() {
    return queue[0].first;
}

void PriorityQueue::clear() {
    queue.clear();
}

void PriorityQueue::printAsArray()
{
    if (queue.empty()) {
        return;
    }
    for (int i = 0; i < queue.size(); i++)
        cout << queue[i].first << endl;
}

void PriorityQueue::printAsTree() {
    for (int i = 0; i < queue.size(); i++) {
        cout << queue[i].second << endl;
        if (2 * i + 1 < queue.size())
            cout << queue[2 * i + 1].second << endl;
        if (2 * i + 2 < queue.size())
            cout << queue[2 * i + 2].second << endl;;
        cout << endl;
    }
}

void PriorityQueue::shift_up(int pos) {
    int child = pos;
    int parent = (child - 1) / 2;
    while (child != 0 && queue[parent].second > queue[child].second) {
        swap(queue[parent], queue[child]);
        child = parent;
        parent = (parent - 1) / 2;
    }
}

void PriorityQueue::shift_down(int pos)
{
    while (true) {
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;

        if (left >= queue.size()) {
            break;
        }

        int next_pos = pos;
        if (queue[next_pos].second < queue[left].second) {
            next_pos = left;
        }
        if (right < queue.size() && queue[next_pos].second < queue[right].second) {
            next_pos = right;
        }

        if (next_pos == pos) {
            break;
        }

        swap(queue[pos], queue[next_pos]);
        pos = next_pos;
    }
}
