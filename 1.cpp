#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

// Distance squared between two points
int dis(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// ---------------- JARVIS MARCH ----------------
bool ccw(point a, point b, point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) > 0;
}

vector<point> jarvis(vector<point> &points) {
    int n = points.size();
    if (n < 3) return {};

    vector<point> hull;
    int leftmost = 0;

    for (int i = 1; i < n; ++i) {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    int p = leftmost;
    do {
        hull.push_back(points[p]);
        int q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (ccw(points[p], points[i], points[q]))
                q = i;
        }
        p = q;
    } while (p != leftmost);

    return hull;
}

point base; 

bool compare(point p1, point p2) {
    int o = orientation(base, p1, p2);
    if (o == 0)
        return dis(base, p1) < dis(base, p2);
    return (o == 2);
}

vector<point> graham(vector<point> &points) {
    int n = points.size();
    if (n < 3) return {};

    
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < points[minIdx].y) ||
            (points[i].y == points[minIdx].y && points[i].x < points[minIdx].x))
            minIdx = i;
    }

    swap(points[0], points[minIdx]);
    base = points[0];

    
    sort(points.begin() + 1, points.end(), compare);


    vector<point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    
    for (int i = 3; i < n; i++) {
        while (hull.size() >= 2 &&
               orientation(hull[hull.size()-2], hull[hull.size()-1], points[i]) != 2)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    vector<point> points = {
        {0, 0}, {0, 4}, {-4, 0}, {5, 0}, {0, -6}, {1, 0}
    };


    // vector<point> convex_hull = jarvis(points);
    vector<point> convex_hull = graham(points);

    cout << "Convex Hull by graham:\n";
    for (auto p : convex_hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}
