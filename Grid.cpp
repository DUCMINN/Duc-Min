#include "Grid.h"
#include <iostream>
#include <vector>

void updateGrid(piece grid[10][10]) {
    // Kiểm tra và làm trống các viên đá matched
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            grid[i][j].match = 0; // Đặt trạng thái match ban đầu là 0
        }
    }

    // Kiểm tra các nhóm viên đá match theo chiều ngang và dọc
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            // Kiểm tra theo chiều ngang
            if (j <= 6 && grid[i][j].kind == grid[i][j + 1].kind && grid[i][j].kind == grid[i][j + 2].kind) {
                grid[i][j].match = 1;
                grid[i][j + 1].match = 1;
                grid[i][j + 2].match = 1;
            }
            // Kiểm tra theo chiều dọc
            if (i <= 6 && grid[i][j].kind == grid[i + 1][j].kind && grid[i][j].kind == grid[i + 2][j].kind) {
                grid[i][j].match = 1;
                grid[i + 1][j].match = 1;
                grid[i + 2][j].match = 1;
            }
        }
    }

    // Làm trống các ô có viên đá đã matched
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (grid[i][j].match == 1) {
                grid[i][j].kind = -1; // Đặt lại viên đá đã matched thành -1 (trống)
            }
        }
    }

    // Thực hiện "rơi" các viên đá xuống dưới (lấp đầy các ô trống)
    for (int j = 1; j <= 8; j++) {
        std::vector<int> fall;
        for (int i = 1; i <= 8; i++) {
            if (grid[i][j].kind != -1) {
                fall.push_back(grid[i][j].kind);  // Thêm các viên đá còn lại vào vector
            }
        }

        // Đặt các viên đá rơi xuống dưới
        for (int i = 8; i >= 1; i--) {
            if (!fall.empty()) {
                grid[i][j].kind = fall.back(); // Đặt viên đá từ dưới lên
                fall.pop_back();
            } else {
                grid[i][j].kind = -1; // Nếu không còn viên đá nào, đặt ô trống
            }
        }
    }

    // Thêm các viên đá mới từ trên xuống
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (grid[i][j].kind == -1) {
                grid[i][j].kind = rand() % 7; // Tạo viên đá mới (loại ngẫu nhiên từ 0 đến 6)
            }
        }
    }
}
