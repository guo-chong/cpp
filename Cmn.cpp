/*
 * 从长度为n字符串中随机挑选出m个字符，有多少种方法。
 * 用递归实现Anm，用set以及muitiSet去除重复。
 * author：guochong
 *
 * */
#include <iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
vector<string> addOne(vector<string> l,vector<string> r,int m){
    if(l[0].size()==m)return l;
    else {
        vector<string>vecTempL,vecTempR;
        for (int i = 0; i < l.size(); ++i) {
            for (int j = 0; j < r[i].size(); ++j) {
                char tempC=r[i][j];
                string tempLi=l[i];
                string tempRi=r[i];
                tempLi.push_back(tempC);
                tempRi.erase(j,1);
                vecTempL.push_back(tempLi);
                vecTempR.push_back(tempRi);
            }
        }
        return addOne(vecTempL,vecTempR,m);
    }
}
int main() {
    vector<string> answer=addOne({""},{"abcdefg"},3);
    set<multiset<char>> ansSet;
    for (int i = 0; i < answer.size(); ++i) {
        multiset<char>temp;
        for (int j = 0; j < answer[i].size(); ++j) {
            temp.insert(answer[i][j]);
        }
        ansSet.insert(temp);
    }
    int a=ansSet.size();
    return 0;
}