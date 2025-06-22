#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

    // ����� �ӵ��� ���̱� ���� ���̶� ��
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // �� �ݺ� Ƚ��
    cin >> t;

    while (t--) {
        string p, arr;
        int n;
        deque<int> x;
        int reversed = 0;
        bool isError = false;

        cin >> p;  //�Լ�RD
        cin >> n;  // �迭 ũ��

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            x.push_back(num);
        }

        for (int i = 0; i < p.size(); i++) {

            // R�̸�
            if (p[i] == 'R') {
                reversed = 1 - reversed;  //�ݴ�
            }

            // D�� �� 
            else if (p[i] == 'D') {

                // ��������� error
                if (x.empty()) {
                    isError = true;
                    break;
                }

                if (reversed) x.pop_back(); // �������̸� �ڿ��� �����ְ�
                else x.pop_front();  // �������̸� �տ��� ��
            }
        }

        // ��� ���
        if (isError) {
            cout << "error\n";
        }

        else {
            cout << "[";

            // ������ ���
            if (reversed) {
                for (int i = x.size() - 1; i >= 0; i--) {
                    cout << x[i];
                    if (i != 0) cout << ",";
                }
            }

            // ������ ���
            else {
                for (int i = 0; i < x.size(); i++) {
                    cout << x[i];
                    if (i != x.size() - 1) cout << ", ";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}

// �̷� ���� �� �� ��µǴµ� Ʋ�ȴٱ淡 chat���� ����ôµ� 
// �Է� ������ [1, 2, 3, 4]�� ���ڿ� �������� �޾ƾ� �ȴ뼭 �ٽ�..
// �� �κ��� ������ ���� �޾ҽ���.
=======================================================


#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    
    // ����� �ӵ��� ���̱� ���� ���̶� ��
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // �� �ݺ� Ƚ��
    cin >> t;

    while (t--) {
        string p, arr;
        int n;
        deque<int> x;
        int reversed = 0;
        bool isError = false;

        cin >> p;  //�Լ�RD
        cin >> n;  // �迭 ũ��

        cin >> arr;  // ���ڿ��� �Է¹޾Ƽ�

        // �迭 �Ľ�
        string num = "";
        for (char c : arr) {              // == for (int i = 0; i < arr.size(); i++)  { char c = arr[i]...
            if (isdigit(c)) num += c; //���ڸ� �̾�ٿ��� num�� ���� ('12'���� ��� 1, 2 ���ΰ� �ƴ϶� �ѹ��� �Է¹�������) 

            else if (!num.empty()) {
                x.push_back(stoi(num));  //num�� ������ȯ�ؼ� Ǫ��
                num = ""; // �ʱ�ȭ
            }
        }

        for (int i = 0; i < p.size(); i++) {
            
            // R�̸�
            if (p[i] == 'R') {
                reversed = 1 - reversed;  //�ݴ�
            }

            // D�� �� 
            else if (p[i] == 'D') {
                
                // ��������� error
                if (x.empty()) {
                    isError = true;
                    break;
                }

                if (reversed) x.pop_back(); // �������̸� �ڿ��� �����ְ�
                else x.pop_front();  // �������̸� �տ��� ��
            }
        }

        // ��� ���
        if (isError) {
            cout << "error\n";
        }

        else {
            cout << "[";

            // ������ ���
            if (reversed) {
                for (int i = x.size() - 1; i >= 0; i--) {
                    cout << x[i];
                    if (i != 0) cout << ",";
                }
            }

            // ������ ���
            else {
                for (int i = 0; i < x.size(); i++) {
                    cout << x[i];
                    if (i != x.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
