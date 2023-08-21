#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 1;
    int end = distance;
    int mid;
    int cnt, prev;
    
    sort(rocks.begin(), rocks.end()); // 정렬
    
    while(start <= end){ 
        mid = (start+end)/2;
        cnt = 0;
        prev = 0;
        
        for (int i = 0; i < rocks.size(); ++i){ // 출발지점부터 돌간 사이 간격 확인
            if(mid > rocks[i] - prev)
                ++cnt;
            else
                prev = rocks[i];
        }
        
        if(mid > distance - prev) // 추가로 마지막 돌과 도착지점 비교
            ++cnt;
        
        if(cnt > n) // 돌을 더 많이 제거했다면
            end = mid-1;
        else{ // 돌을 같거나 덜 제거했다면
            start = mid+1;
            answer = mid;
        }
    }
    
    return answer;
}