// 📝 Problem Statement: Detect Intersecting Segments

// You are given N line segments on a 2D plane.
// Each segment is defined by the coordinates of its two endpoints.

// Your task is to determine whether any two of these segments intersect at a point other than just sharing an endpoint.
// If there exists at least one pair of segments that intersect (cross or touch), print "YES".
// Otherwise, print "NO".

#include <bits/stdc++.h>
using namespace std;

/* ---------- Geometry Structures ---------- */

struct Point {
    double x, y;
};

struct Segment {
    Point p, q; // endpoints
    int id;
    
    // y-coordinate of segment at given sweep line x
    double yAt(double x) const {
        if (fabs(p.x - q.x) < 1e-9) return p.y; // vertical segment
        return p.y + (q.y - p.y) * ( (x - p.x) / (q.x - p.x) );
    }
};

struct Event {
    double x;
    int segId;
    bool isLeft; // true if left endpoint
    double y;
};

static double sweepX; // current sweep line position
static vector<Segment> segs;

/* ---------- Orientation / Intersection ---------- */

int orientation(const Point &a, const Point &b, const Point &c) {
    double val = (b.y - a.y) * (c.x - b.x) -
                 (b.x - a.x) * (c.y - b.y);
    if (fabs(val) < 1e-9) return 0;       // collinear
    return (val > 0) ? 1 : 2;             // 1:clockwise, 2:counterclockwise
}

bool onSegment(const Point &a, const Point &b, const Point &c) {
    return min(a.x, c.x) <= b.x + 1e-9 && b.x <= max(a.x, c.x) + 1e-9 &&
           min(a.y, c.y) <= b.y + 1e-9 && b.y <= max(a.y, c.y) + 1e-9;
}

bool intersects(const Segment &s1, const Segment &s2) {
    const Point &p1 = s1.p;
    const Point &q1 = s1.q;
    const Point &p2 = s2.p;
    const Point &q2 = s2.q;

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true; // proper intersection

    // Special Cases for collinear overlaps / touching
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

/* ---------- Active Set Comparator ---------- */
struct ActiveCmp {
    bool operator()(int a, int b) const {
        if (a == b) return false;
        double ya = segs[a].yAt(sweepX);
        double yb = segs[b].yAt(sweepX);
        if (fabs(ya - yb) > 1e-9) return ya < yb;
        return a < b;
    }
};

/* ---------- Main Sweep Line Function ---------- */
bool hasIntersection(vector<Segment> &segments) {
    segs = segments;

    // Prepare events
    vector<Event> events;
    for (auto &s : segs) {
        Segment seg = s;
        // Make sure left endpoint has smaller x
        if (seg.q.x < seg.p.x || (fabs(seg.q.x - seg.p.x) < 1e-9 && seg.q.y < seg.p.y))
            swap(seg.p, seg.q);
        s = seg;

        events.push_back({seg.p.x, seg.id, true, seg.p.y});
        events.push_back({seg.q.x, seg.id, false, seg.q.y});
    }

    // Sort events by x, then left before right
    sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
        if (fabs(a.x - b.x) > 1e-9) return a.x < b.x;
        return a.isLeft > b.isLeft; // left endpoints first
    });

    set<int, ActiveCmp> active;

    for (auto &e : events) {
        sweepX = e.x;

        if (e.isLeft) {
            auto it = active.insert(e.segId).first;
            auto prevIt = (it == active.begin()) ? active.end() : prev(it);
            auto nextIt = next(it);

            if (prevIt != active.end() && intersects(segs[*prevIt], segs[*it]))
                return true;
            if (nextIt != active.end() && intersects(segs[*nextIt], segs[*it]))
                return true;

        } else {
            auto it = active.find(e.segId);
            if (it != active.end()) {
                auto prevIt = (it == active.begin()) ? active.end() : prev(it);
                auto nextIt = next(it);
                if (prevIt != active.end() && nextIt != active.end() &&
                    intersects(segs[*prevIt], segs[*nextIt]))
                    return true;
                active.erase(it);
            }
        }
    }
    return false;
}

/* ---------- Main ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments[i] = {{x1, y1}, {x2, y2}, i};
    }

    cout << (hasIntersection(segments) ? "YES\n" : "NO\n");
    return 0;
}
