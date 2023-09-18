#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> combination[11];
int maxMenu[11] = {0,};

void dfs(string order, string partial, int index) {
    if(index >= order.length()) 
        return;

    dfs(order, partial, index+1);

    partial += order[index];
    combination[partial.length()][partial]++;

    if (combination[partial.length()][partial] > maxMenu[partial.length()]) {
        maxMenu[partial.length()] = combination[partial.length()][partial];
    }

    dfs(order, partial, index+1);
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // �� �ֹ����� dfs�� �ѹ��� �����鼭 ���հ� Ƚ���� ã�Ƴ���.
    for(string order : orders) {
        sort(order.begin(), order.end());
        //���ĵ� �ֹ��� ù��° �޴��� init�Ѵ�.
        
        dfs(order, "", 0);
    }

    for (int num : course) {
        for(auto comb : combination[num]) {
            if (maxMenu[num] >= 2 && comb.second == maxMenu[num]) {
                answer.push_back(comb.first);
            }   
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}