#include <iostream>
#include <vector>
#include <cmath>

// �ж�һ�����Ƿ�������Χ��
bool isWithinGrid(int x, int y, int n)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

// ���㱻̽��ĵ�����
int countCoveredPoints(int n, const std::vector<std::tuple<int, int, int>> &detectors)
{
    // ����һ�� n x n �����񲢳�ʼ��Ϊδ̽��״̬
    std::vector<std::vector<bool>> grid(n + 1, std::vector<bool>(n + 1, false));

    // ��ÿ��̽�������д���
    for (const auto &detector : detectors)
    {
        int x = std::get<0>(detector);
        int y = std::get<1>(detector);
        int r = std::get<2>(detector);

        // ����̽�����뾶��Χ�ڵ����е�
        for (int dx = -r; dx <= r; ++dx)
        {
            for (int dy = -r; dy <= r; ++dy)
            {
                int nx = x + dx;
                int ny = y + dy;

                // ���������Ƿ���̽�����ķ�Χ�ڲ���������Χ��
                if (isWithinGrid(nx, ny, n) && (dx * dx + dy * dy <= r * r))
                {
                    grid[nx][ny] = true; // ���Ϊ��̽��
                }
            }
        }
    }

    // ͳ�Ʊ�̽��ĵ�����
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
