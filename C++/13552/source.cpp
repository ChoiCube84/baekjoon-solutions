#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

template <typename T>
class Point3D {
    private:
        T x;
        T y;
        int z;
    public:
        Point3D(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}; 
        friend T distanceSquared(const Point3D& A, const Point3D& B) {
            T dx = A.x - B.x;
            T dy = A.y - B.y;
            T dz = A.z - B.z;
            
            return dx * dx + dy * dy + dz * dz;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<Point3D<ull>> points;
    for (int i=0; i<N; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        
        points.push_back({x, y, z});
    }
    
    int M;
    cin >> M;
    
    for (int i=0; i<M; i++) {
        ll x, y, z, r, result = 0;
        cin >> x >> y >> z >> r;
        
        for (auto& point : points) {
            if (distanceSquared(point, {x, y, z}) <= r * r) {
                result++;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
