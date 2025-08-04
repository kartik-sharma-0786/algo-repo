// // #include <iostream>
// // #include <vector>
// // #include <set>
// // #include <algorithm>
// // #include <cmath>
// // #include <limits>
// // #include <cfloat>

// // using namespace std;

// // struct Point {
// //     double x, y;
// //     Point(double x, double y) : x(x), y(y) {}
// //     bool operator<(const Point& other) const {
// //         if (x != other.x) {
// //             return x < other.x;
// //         }
// //         return y < other.y;
// //     }
// // };

// // double brute_force(const vector<Point>& points) {
// //     double min_sq = DBL_MAX;
// //     int n = points.size();
// //     for (int i = 0; i < n; i++) {
// //         for (int j = i + 1; j < n; j++) {
// //             double dx = points[i].x - points[j].x;
// //             double dy = points[i].y - points[j].y;
// //             double d_sq = dx * dx + dy * dy;
// //             if (d_sq < min_sq) {
// //                 min_sq = d_sq;
// //             }
// //         }
// //     }
// //     return min_sq;
// // }

// // double closest_pair_helper(vector<Point> Px, vector<Point> Py) {
// //     int n = Px.size();
// //     if (n <= 3) {
// //         return brute_force(Px);
// //     }

// //     int mid = n / 2;
// //     vector<Point> Qx(Px.begin(), Px.begin() + mid);
// //     vector<Point> Rx(Px.begin() + mid, Px.end());

// //     set<Point> set_Qx(Qx.begin(), Qx.end());
// //     vector<Point> Qy;
// //     vector<Point> Ry;
// //     for (Point p : Py) {
// //         if (set_Qx.find(p) != set_Qx.end()) {
// //             Qy.push_back(p);
// //         }
// //         else {
// //             Ry.push_back(p);
// //         }
// //     }

// //     double d_left_sq = closest_pair_helper(Qx, Qy);
// //     double d_right_sq = closest_pair_helper(Rx, Ry);
// //     double d_sq = min(d_left_sq, d_right_sq);

// //     double mid_x = Rx[0].x;
// //     vector<Point> strip;
// //     for (Point p : Py) {
// //         double dx = p.x - mid_x;
// //         if (dx * dx < d_sq) {
// //             strip.push_back(p);
// //         }
// //     }

// //     double min_strip_sq = d_sq;
// //     for (int i = 0; i < strip.size(); i++) {
// //         for (int j = i + 1; j < strip.size() && j <= i + 7; j++) {
// //             double dx = strip[i].x - strip[j].x;
// //             double dy = strip[i].y - strip[j].y;
// //             double dist_sq = dx * dx + dy * dy;
// //             if (dist_sq < min_strip_sq) {
// //                 min_strip_sq = dist_sq;
// //             }
// //         }
// //     }

// //     return min_strip_sq;
// // }

// // double closest_pair(vector<Point> points) {
// //     if (points.size() < 2) {
// //         return 0.0;
// //     }
// //     vector<Point> Px = points;
// //     vector<Point> Py = points;
// //     sort(Px.begin(), Px.end(), [](const Point& a, const Point& b) {
// //         return a.x < b.x;
// //         });
// //     sort(Py.begin(), Py.end(), [](const Point& a, const Point& b) {
// //         return a.y < b.y;
// //         });
// //     double d_sq = closest_pair_helper(Px, Py);
// //     return d_sq;
// // }

// // int main() {
// //     vector<Point> points = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
// //     double min_dist = closest_pair(points);
// //     cout << "Closest pair distance: " << min_dist <<closest_pair(points)<< endl;

// //     vector<Point> points2 = { {0,0}, {1,1} };
// //     min_dist = closest_pair(points2);
// //     cout << "Test 2: " << min_dist << " (expected: " << sqrt(2) << ")" <<closest_pair(points)<< endl;

// //     vector<Point> points3 = { {0,0}, {1,0}, {2,0} };
// //     min_dist = closest_pair(points3);
// //     cout << "Test 3: " << min_dist << " (expected: " << 1.0 << ")" <<closest_pair(points)<< endl;

// //     vector<Point> points4 = { {0,0}, {0,0} };
// //     min_dist = closest_pair(points4);
// //     cout << "Test 4: " << min_dist << " (expected: " << 0.0 << ")" <<closest_pair(points)<< endl;

// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// using namespace std;

// bool isConnectedToAll(const vector<vector<int>>& adj, const vector<int>& clique, int node) {
//     for (int u : clique) {
//         if (find(adj[node].begin(), adj[node].end(), u) == adj[node].end())
//             return false;
//     }
//     return true;
// }

// void dfs(const vector<vector<int>>& adj, vector<int>& clique, int start, int& count, int n) {
//     for (int next = start + 1; next < n; ++next) {
//         if (isConnectedToAll(adj, clique, next)) {
//             clique.push_back(next);
//             if (clique.size() >= 2)
//                 count++;#include <iostream>
// #include <vector>
// #include <algorithm>
//             dfs(adj, clique, next, count, n);
//             clique.pop_back();
//         }
//     }
// }

// int countCliquesDFS(const vector<vector<int>>& adj) {
//     int n = adj.size(), count = 0;
//     for (int i = 0; i < n; ++i) {
//         vector<int> clique = {i};
//         dfs(adj, clique, i, count, n);
//     }
//     return count;
// }

// int main() {
//     // Example graph as adjacency list
//     vector<vector<int>> adj = { 
//         { 2, 3,4}, // 1
//         {1, 3}, // 2
//         {1, 2, 4},//3
//         {1,3,5,6},  // 4
//         {4,6,7,8},
//         {4,5,7,8},
//         {5,8,9},
//         {5,6,7,9},
//         {7}

//     };

//     cout << "Number of cliques (DFS): " << countCliquesDFS(adj) << "\n";
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void rangeSearch(Node* node, int low, int high, vector<int>& result) {
        if (!node) return;

        // Traverse left subtree if needed
        if (node->key > low)
            rangeSearch(node->left, low, high, result);

        // Add current node if in range
        if (node->key >= low && node->key <= high)
            result.push_back(node->key);

        // Traverse right subtree if needed
        if (node->key < high)
            rangeSearch(node->right, low, high, result);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    vector<int> rangeQuery(int low, int high) {
        vector<int> result;
        rangeSearch(root, low, high, result);
        return result;
    }
};

int main() {
    AVLTree tree;
    vector<int> keys = {3, 10, 19, 23, 30, 57, 52, 62, 70, 80};

    for (int key : keys) {
        tree.insert(key);
    }

    vector<int> inRange = tree.rangeQuery(18, 77);

    cout << "Nodes in range [18,77]: ";
    for (int val : inRange) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}