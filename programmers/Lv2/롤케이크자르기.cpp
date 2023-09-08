#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0, cake;
    unordered_map <int,int> base, cmp;// base: ���߸� ��¥ ����ũ, cmp: �߶������� ����
    for(auto c : topping) base[c]++;
    cake = base.size();// ����ũ�� �ö� ������ �� ����
    for(auto c : topping)
    {// �� ���ξ� �߶��ش�.
        cmp[c]++; base[c]--;
        if (base[c] == 0 ) cake--;// �ش� ������ ������ �������� ���ڸ� ����ũ ���μ�--
        if (cake == cmp.size()) answer++;// ���ڸ� ����ũ ���μ� == �ڸ� ����ũ ���μ� �̸�
    }
    return answer;
}