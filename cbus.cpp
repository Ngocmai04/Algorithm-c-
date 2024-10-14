#include <bits/stdc++.h>
using namespace std;

const int N = 50; // Số lượng đỉnh tối đa
const int oo = 1e9; // Giá trị vô cùng lớn
int n, K, cmin = oo; // n: số lượng khách, K: dung lượng tối đa, cmin: chi phí tối thiểu
int C[2*N + 1][2*N + 1], x[2*N + 1], xOpt[2*N + 1]; // Ma trận chi phí, mảng giải pháp hiện tại và tối ưu
int fCur = 0, load = 0, fOpt = oo; // fCur: chi phí hiện tại, load: tải trọng hiện tại, fOpt: chi phí tối ưu
bool visited[2*N + 1]; // Mảng để đánh dấu các đỉnh đã thăm

// Kiểm tra ứng viên v cho vị trí thứ k
bool check(int v, int k) {
	if (visited[v]) return false; // Nếu đã thăm ứng viên v, trả về false

	// Nếu v là khách, cần phải đón họ trước
	if (v > n) {
		if (!visited[v - n]) return false; // Nếu chưa đón khách, không hợp lệ
	} else {
		// Nếu đã đầy khách thì không thể thêm khách mới
		if (load == K) return false;
	}

	return true; // Ứng viên hợp lệ
}

// Cập nhật giải pháp tối ưu nếu giải pháp hiện tại tốt hơn
void updateSol() {
	if (fCur + C[x[2*n]][0] < fOpt) { // Kiểm tra xem chi phí hiện tại + chi phí về có nhỏ hơn chi phí tối ưu không
		fOpt = fCur + C[x[2*n]][0]; // Cập nhật chi phí tối ưu
		for (int i = 0; i <= 2*n; i++)
			xOpt[i] = x[i]; // Sao chép giải pháp hiện tại vào giải pháp tối ưu
	}
}

// Hàm quay lui để tìm kiếm giải pháp
int TRY(int k) {
	for (int v = 1; v <= 2*n; v++) { // Duyệt tất cả ứng viên
		if (check(v, k)) { // Kiểm tra tính hợp lệ của ứng viên
			x[k] = v; // Gán ứng viên vào vị trí k
			visited[v] = true; // Đánh dấu ứng viên là đã thăm
			fCur += C[x[k-1]][v]; // Cập nhật chi phí hiện tại
			load += (v > n ? -1 : 1); // Cập nhật tải trọng

			if (k == 2*n) 
				updateSol(); // Nếu đã chọn đủ số khách, cập nhật giải pháp
			else {
				// Nếu chi phí hiện tại có khả năng nhỏ hơn chi phí tối ưu, tiếp tục đệ quy
				if (fCur + (2*n + 1 - k) * cmin < fOpt)
					TRY(k + 1);
			}
			
			// Quay lui
			visited[v] = false; // Đánh dấu ứng viên lại là chưa thăm
			fCur -= C[x[k-1]][v]; // Khôi phục lại chi phí hiện tại
			load -= (v > n ? -1 : 1); // Khôi phục lại tải trọng
		}
	}
}

// Hàm nhập dữ liệu
void input() {
	cin >> n >> K; // Nhập số lượng khách và dung lượng
	for (int i = 0; i <= 2*n; i++)
		for (int j = 0; j <= 2*n; j++) {
			cin >> C[i][j]; // Nhập giá trị chi phí cho ma trận
			if (i != j) cmin = min(cmin, C[i][j]); // Cập nhật chi phí tối thiểu
		}
}

int main() {
	// freopen("data.inp", "r", stdin); // Mở tệp nhập (nếu cần)
	input(); 
	x[0] = 0; visited[0] = true; // Bắt đầu từ đỉnh xuất phát
	TRY(1); 
	cout << fOpt << endl; // In ra chi phí tối ưu
	return 0;
}
