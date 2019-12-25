////정수 삼각형_프로그래머스
//위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.
//삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.
//제한사항
//삼각형의 높이는 1 이상 500 이하입니다.
//삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
//  20191225_DP_IntegerTriangle.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/25/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i=1; i<triangle.size(); i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                triangle[i][j]+=triangle[i-1][j];
            }else if(i==j){
                triangle[i][j]+=triangle[i-1][j-1];
            }else{
                triangle[i][j]+=max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }
    
    sort(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    answer = triangle[triangle.size()-1].back();
   
    return answer;
}

void assertions(vector<vector<int>> triangle, int answer){
    long long t = solution(triangle);
    if(t==answer)
        cout <<"Correct!"<<endl;
    else
        cout <<"Wrong!"<<endl;
}

int main(){
    assertions({{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}}, 30);
    return 0;;
}
