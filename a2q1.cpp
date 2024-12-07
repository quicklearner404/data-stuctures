//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstdlib> 
//#include <ctime>   
//
//using namespace std;
//
//void josephus(int n, int k) {
//    queue<int> q;
//
//    // Fill the queue with people numbered from 1 to n
//    for (int i = 1; i <= n; ++i) {
//        q.push(i);
//    }
//
//    // Output the initial state
//    cout << "Initial people: ";
//    for (int i = 1; i <= n; ++i) {
//        cout << i << " ";
//    }
//    cout << "\n";
//
//    // Set random seed based on current time
//    srand(static_cast<unsigned int>(time(0)));
//
//    // Generate a random starting position between 1 and n
//    int start = rand() % n + 1; // Random number from 1 to n
//    cout << "Random starting position: " << start << endl;
//
//    // Move to the starting position
//    for (int i = 0; i < start - 1; ++i) {
//        int front = q.front();
//        q.pop();
//        q.push(front);  // Move to the back until we reach the starting position
//    }
//
//    // While more than one person is in the queue
//    while (q.size() > 1) {
//        // Move the first (k-1) people to the back of the queue (clockwise counting)
//        int rotations = (k - 1) % q.size();
//        for (int i = 0; i < rotations; ++i) {
//            // Move the person at the front of the queue to the back
//            int front = q.front();
//            q.pop();
//            q.push(front);  // This is clockwise movement
//        }
//
//        // Eliminate the k-th person 
//        int eliminated = q.front();
//        q.pop();
//        cout << "Eliminated: Person " << eliminated << "\n";
//
//        // Output the remaining people
//        cout << "Remaining: ";
//        queue<int> tempQueue = q; // Use a temporary queue to print remaining people
//        while (!tempQueue.empty()) {
//            cout << tempQueue.front() << " ";
//            tempQueue.pop();
//        }
//        cout << "\n";
//    }
//
//    // Last remaining 
//    int lastRemaining = q.front();
//    cout << "Last Remaining Person: " << lastRemaining << "\n";
//}
//
//int main() {
//    int n, k;
//    cout << "Enter the number of people (n): ";
//    cin >> n;
//    cout << "Enter the step count (k): ";
//    cin >> k;
//
//    josephus(n, k);
//
//    return 0;
//}
//
