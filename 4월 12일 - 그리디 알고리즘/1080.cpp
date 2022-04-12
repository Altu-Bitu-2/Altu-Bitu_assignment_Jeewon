#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) {	//i부터 i+2까지 (행)
        for (int j = col; j < col + 3; j++) {	//j부터 j+2까지 (렬)
            if (matrix_a[i][j] == '1') {	//a의 원소가 1일 때 
                matrix_a[i][j] = '0';	//0으로 뒤집음 
            }
            else {	//a의 원소가 0일 때 
                matrix_a[i][j] = '1';	//1로 뒤집음 
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {	//행렬 a와 b의 row크기 
        for (int j = 0; j < m; j++) {	//행렬 a와 b의 column크기
            if (matrix_a[i][j] != matrix_b[i][j]) {	//a와 b의 다른 부분 발견하면 
                return false;	//false, 두 행렬이 같지 않음 
            }
        }
    }
    return true;	//두 행렬이 같음  
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m;	//행렬의 크기 

    //입력
    cin >> n >> m;	//n: row, m: column 입력받음 
    vector<string> matrix_a(n);	//행렬 A 
    vector<string> matrix_b(n);	//행렬 B 
    for (int i = 0; i < n; i++) {
        cin >> matrix_a[i];	//행렬 A 입력 받음 
    }

    for (int i = 0; i < n; i++) {
        cin >> matrix_b[i];	//행렬 B 입력 받음 
    }

    //연산
    int ans = 0;	//필요한 연산의 횟수의 최솟값을 저장하는 변수 
    for (int i = 0; i <= n - 3; i++) {	//부분행렬의 크기가 3*3, 따라서 row 
        for (int j = 0; j <= m - 3; j++) {	//3*3 부분행렬의 column 
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a);	//행렬 A의 (i,j)에서 3*3크기의 부분 행렬에 있는 모든 원소 뒤집음 
                ans++;	//뒤집었기 때문에 ans에 1씩 더함 
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) {	//만약 행렬 A와 행렬 B가 같지 않다면 
        ans = -1;	//-1을 출력함 
    }
    cout << ans;	//정답 출력 
    return 0;	//종료 
}
