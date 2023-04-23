import math


def closest_pair(x, y):
    n = len(x)
    if n <= 3:
        return brute_force(x, y)
    mid = n // 2
    xl = x[:mid]
    yl = y[:mid]
    xr = x[mid:]
    yr = y[mid:]
    d_l = closest_pair(xl, yl)
    d_r = closest_pair(xr, yr)
    d = min(d_l, d_r)
    strip = []
    for i in range(n):
        if abs(x[mid] - x[i]) < d:
            strip.append((x[i], y[i]))
    return min(d, strip_closest(strip, d))


def brute_force(x, y):
    n = len(x)
    xy = []
    min_dist = float("inf")
    for i in range(n - 1):
        for j in range(i + 1, n):
            dist = math.sqrt((x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2)
            if dist < min_dist:
                xy = [x[i], y[i], x[j], y[j]]
                min_dist = dist
    print(xy)
    print(min_dist)
    return min_dist


def strip_closest(strip, d):
    min_dist = d
    xy = []
    for i in range(len(strip) - 1):
        for j in range(i + 1, len(strip)):
            if abs(strip[j][1] - strip[i][1]) < min_dist:
                dist = math.sqrt((strip[j][0] - strip[i][0]) ** 2 + (strip[j][1] - strip[i][1]) ** 2)
                if dist < min_dist:
                    xy = [strip[j][0], strip[j][1], strip[i][0], strip[i][1]]
                    min_dist = dist
    print(xy)
    print(min_dist)
    return min_dist


x = [10, 5, 20, 6, 9, 15, 8, 20, 17, 16, 7, 10, 1, 8, 30, 22]
y = [15, 15, 3, 1, 7, 9, 15, 14, 13, 11, 12, 10, 19, 8, 9, 4]
points = list(zip(x, y))
points.sort()
x = [p[0] for p in points]
y = [p[1] for p in points]
print(closest_pair(x, y))


# (10, 10, 15, 16, 17, 20, 20, 22, 30)
# (15, 10, 9, 11, 13, 3, 14, 4, 9)