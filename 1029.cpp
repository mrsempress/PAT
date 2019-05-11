//内存超限
//题目的long int因为内存限制原因，并不会为最终答案，只是干扰数据，
//题目很恶心啊，给出的数据居然是已经排好序的
//Given two increasing sequences of integers, you are asked to find their median.
//啊 疯了
#include <iostream>
using namespace std;
int k[200005];
int main(){
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] < temp) {//小的第k[i]个
            count++;
            if (count == midpos) cout << k[i];
            i++;
        }
        count++;
        if (count == midpos) cout << temp;
    }
    while (i <= n) {
        count++;
        if (count == midpos) cout << k[i];
        i++;
    }
    return 0;
}