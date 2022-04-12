#include <iostream>
#include <vector>

using namespace std;

//�κ� ��� ���� ������ �Լ�
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) {	//i���� i+2���� (��)
        for (int j = col; j < col + 3; j++) {	//j���� j+2���� (��)
            if (matrix_a[i][j] == '1') {	//a�� ���Ұ� 1�� �� 
                matrix_a[i][j] = '0';	//0���� ������ 
            }
            else {	//a�� ���Ұ� 0�� �� 
                matrix_a[i][j] = '1';	//1�� ������ 
            }
        }
    }
}

//���������� A == B���� Ȯ���ϴ� �Լ�
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {	//��� a�� b�� rowũ�� 
        for (int j = 0; j < m; j++) {	//��� a�� b�� columnũ��
            if (matrix_a[i][j] != matrix_b[i][j]) {	//a�� b�� �ٸ� �κ� �߰��ϸ� 
                return false;	//false, �� ����� ���� ���� 
            }
        }
    }
    return true;	//�� ����� ����  
}

/**
 * [���]
 *
 * (0, 0) �ε������� �κ������ ���� �� �ִ� ������ �ε������� �˻��ϸ� �׸����ϰ� Ǫ�� ����
 * A, B ����� ���� �ε��� ���� ���� �ٸ��ٸ� A ��Ŀ��� ���� �ε����� '����'�ϴ� 3x3 ũ�⸸ŭ�� �κ� ��� ���� ������
 * �˻簡 ��� ���� ��, A�� B�� ���� �ٸ��ٸ� �ٲ� �� ���� �����
 * !����! �Է��� ������� �־����Ƿ� string���� ����
 */

int main() {
    int n, m;	//����� ũ�� 

    //�Է�
    cin >> n >> m;	//n: row, m: column �Է¹��� 
    vector<string> matrix_a(n);	//��� A 
    vector<string> matrix_b(n);	//��� B 
    for (int i = 0; i < n; i++) {
        cin >> matrix_a[i];	//��� A �Է� ���� 
    }

    for (int i = 0; i < n; i++) {
        cin >> matrix_b[i];	//��� B �Է� ���� 
    }

    //����
    int ans = 0;	//�ʿ��� ������ Ƚ���� �ּڰ��� �����ϴ� ���� 
    for (int i = 0; i <= n - 3; i++) {	//�κ������ ũ�Ⱑ 3*3, ���� row 
        for (int j = 0; j <= m - 3; j++) {	//3*3 �κ������ column 
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)���Ұ� ���� �ٸ��ٸ�
                reverseMtx(i, j, matrix_a);	//��� A�� (i,j)���� 3*3ũ���� �κ� ��Ŀ� �ִ� ��� ���� ������ 
                ans++;	//�������� ������ ans�� 1�� ���� 
            }
        }
    }

    //���
    if (!isPossible(n, m, matrix_a, matrix_b)) {	//���� ��� A�� ��� B�� ���� �ʴٸ� 
        ans = -1;	//-1�� ����� 
    }
    cout << ans;	//���� ��� 
    return 0;	//���� 
}
