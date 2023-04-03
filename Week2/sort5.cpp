#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*constexpr là một từ khoá trong ngôn ngữ lập trình C++,
được sử dụng để chỉ ra rằng giá trị của biểu thức có thể được tính toán
tại thời điểm biên dịch và sẽ không thay đổi trong quá trình chạy.

Theo định nghĩa trên, khi ta khai báo một biến hay một hàm là constexpr,
chương trình sẽ đảm bảo rằng giá trị của nó sẽ được tính toán tại thời điểm biên dịch
và có thể được sử dụng như một giá trị hằng trong suốt quá trình chạy.

Điều này giúp tăng hiệu suất của chương trình,
vì khi giá trị của biểu thức được tính toán tại thời điểm biên dịch,
chương trình không cần phải tính toán nó lại tại thời điểm chạy,
giảm thiểu thời gian chạy và tăng tốc độ của chương trình.*/
// Đọc không hiểu thì dùng mảng hằng hoặc mảng bình thường cũng được
constexpr int kNumDigits = 10;
constexpr int kDigitsToRemove[] = {1, 2, 4, 5, 7, 8};

// chỉ cần bó 1 hoặc 2 số sẽ ra tối ưu bài toán
int removeDigits(int digitCount[], int sum, int &numberOfDigits)
{
    // Remove 1 digit.
    for (int digit : kDigitsToRemove)
    {
        // (sum - digit) % 3 == 0
        if (digit % 3 == sum % 3 && digitCount[digit] > 0)
        {
            digitCount[digit]--;
            numberOfDigits--;
            return 1;
        }
    }

    // Remove 2 digits.
    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
        {
            int digitSum = kDigitsToRemove[i] + kDigitsToRemove[j];
            // (digitSum - sum) % 3 == 0
            if (digitSum % 3 == sum % 3 && digitCount[kDigitsToRemove[i]] > 0 &&
                // chỗ này phụ thuộc vào i và j có trùng không, nếu có thì trả về 1 và j > 1 đảm bảo
                // có dủ số chữ số để bỏ
                // còn i khác j và j có thì bỏ như bình thường
                digitCount[kDigitsToRemove[j]] > (i == j))
            {
                digitCount[kDigitsToRemove[i]]--;
                digitCount[kDigitsToRemove[j]]--;
                numberOfDigits -= 2;
                return 1;
            }
        }
    }

    return -1;
}

int main()
{
    string number;
    cin >> number;
    int numberOfDigits = number.length();
    int digitCount[kNumDigits] = {0};
    int sum = 0;

    for (char c : number)
    {
        digitCount[c - '0']++;
        sum += c - '0';
    }

    int result = (sum % 3 == 0) ? 1 : removeDigits(digitCount, sum, numberOfDigits);

    if (result == -1 || numberOfDigits == 0)
    {
        for (int i = 0; i < number.length(); i++)
            cout << 0;
        cout << endl;
    }
    else
    {
        for (int digit = kNumDigits - 1; digit >= 0; digit--)
            for (int i = 0; i < digitCount[digit]; i++)
                cout << digit;
        cout << endl;
    }
    system("pause");
    return 0;
}
