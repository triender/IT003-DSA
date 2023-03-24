#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Point
{
    long x, y;
};

void nhapDiem(Point &X)
{
    scanf("%ld%ld", &X.x, &X.y);
}

void xuatDiem(const Point X)
{
    printf("%ld %ld\n", X.x, X.y);
}

void nhapMang(vector<Point> &arr, long &n)
{
    scanf("%ld", &n);
    arr.resize(n);
    for (long i = 0; i < n; i++)
        nhapDiem(arr[i]);
}

void xuatMang(vector<Point> &arr, long &n)
{
    for (long i = 0; i < n; i++)
    {
        xuatDiem(arr[i]);
    }
}

bool compareXY(const Point A, const Point B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y > B.y;
}

int main()
{
    vector<Point> arr;
    long n;
    nhapMang(arr, n);
    sort(arr.begin(), arr.end(), compareXY);
    xuatMang(arr, n);
    return 0;
}
