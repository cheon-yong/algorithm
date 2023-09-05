#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0; i < skill_trees.size(); i++)
    {
        string skillTree = skill_trees[i];
        int skillIndex = 0;
        bool possible = true;
        for (int j = 0; j < skillTree.size(); j++)
        {
            auto pos = skill.find(skillTree[j]);
            if (pos == string::npos)
                continue;
            
            else
            {
                if (skillIndex != pos)
                {
                    possible = false;
                    break;
                }
                else
                {
                    skillIndex++;
                }
            }
        }
        
        if (possible)
            answer++;
    }
    
    return answer;
}