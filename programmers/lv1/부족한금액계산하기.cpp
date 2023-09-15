using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long num = 0;
    for (int i = 1; i <= count; i++)
    {
        num += i * price;
    }
    
    if (num < money)
        return 0;
    
    answer = num - money;
    return answer;
}