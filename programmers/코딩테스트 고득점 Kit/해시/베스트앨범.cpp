#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

static bool comp(pair<string, vector<pair<int, int>>>& a, pair<string, vector<pair<int, int>>>& b){
    auto av = a.second;
    int asum = 0;
    for (int i = 0; i < av.size(); i++)
    {
        asum += av[i].second;
    }
    
    auto bv = b.second;
    int bsum = 0;
    for (int i = 0; i < bv.size(); i++)
    {
        bsum += bv[i].second;
    }
    
	return asum > bsum;
}

static bool comp2(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

// 합계로 장르 정렬
// 재생순으로 곡 정렬
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> playlist;
    
    int len = genres.size();
    for (int i = 0; i < len; i++)
    {
        playlist[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    vector<pair<string, vector<pair<int, int>>>> v(playlist.begin(), playlist.end());
    
    sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < v.size(); i++)
    {
        auto temp = v[i].second;
        sort(temp.begin(), temp.end(), comp2);
        int limit2 = min(2, (int)temp.size());
        
        for (int j = 0; j < limit2; j++)
        {
            answer.push_back(temp[j].first);
        }
    }
    
    return answer;
}