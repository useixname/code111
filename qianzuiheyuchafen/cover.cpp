#include <iostream>
#include <vector>
#include <cmath>

// 判断一个点是否在网格范围内
bool isWithinGrid(int x, int y, int n)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

// 计算被探测的点数量
int countCoveredPoints(int n, const std::vector<std::tuple<int, int, int>> &detectors)
{
    // 创建一个 n x n 的网格并初始化为未探测状态
    std::vector<std::vector<bool>> grid(n + 1, std::vector<bool>(n + 1, false));

    // 对每个探测器进行处理
    for (const auto &detector : detectors)
    {
        int x = std::get<0>(detector);
        int y = std::get<1>(detector);
        int r = std::get<2>(detector);

        // 遍历探测器半径范围内的所有点
        for (int dx = -r; dx <= r; ++dx)
        {
            for (int dy = -r; dy <= r; ++dy)
            {
                int nx = x + dx;
                int ny = y + dy;

                // 检查这个点是否在探测器的范围内并且在网格范围内
                if (isWithinGrid(nx, ny, n) && (dx * dx + dy * dy <= r * r))
                {
                    grid[nx][ny] = true; // 标记为已探测
                }
            }
        }
    }

    // 统计被探测的点数量
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (grid[i][j])
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n, m, r;
    std::cin >> n >> m >> r;
    std::vector<std::tuple<int, int, int>> detectors(m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        detectors[i] = std::make_tuple(x, y, r);
    }

    int result = countCoveredPoints(n, detectors);
    std::cout << result << std::endl;

    return 0;
}
