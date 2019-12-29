////서울에서 경산까지_프로그래머스
////서울에서 경산까지 여행을 하면서 모금 활동을 하려 합니다. 여행은 서울에서 출발해 다른 도시를 정해진 순서대로 딱 한 번 방문한 후 경산으로 도착할 예정입니다. 도시를 이동할 때에는 도보 혹은 자전거를 이용합니다. 이때 도보 이동에 걸리는 시간, 도보 이동 시 얻을 모금액, 자전거 이동에 걸리는 시간, 자전거 이동 시 얻을 모금액이 정해져 있습니다. K시간 이내로 여행할 때 모을 수 있는 최대 모금액을 알아보려 합니다.
//예를 들어 여행 루트가 다음과 같고 K = 1,650 일 때
//
//1, 2번 구간은 도보로, 3번 구간은 자전거로 이동해 모금액을 660으로 하는 것이 가장 좋은 방법입니다. 이때, 1,600시간이 소요됩니다.
//solution 함수의 매개변수로 각 도시를 이동할 때 이동 수단별로 걸리는 시간과 모금액을 담은 2차원 배열 travel과 제한시간 K가 주어집니다. 제한시간 안에 서울에서 경산까지 여행을 하며 모을 수 있는 최대 모금액을 return 하도록 solution 함수를 작성하세요.
//제한사항
//travel 배열의 각 행은 순서대로 [도보 이동에 걸리는 시간, 도보 이동 시 얻을 모금액, 자전거 이동에 걸리는 시간, 자전거 이동 시 얻을 모금액]입니다.
//travel 배열 행의 개수는 3 이상 100 이하인 정수입니다.
//travel 배열에서 시간을 나타내는 숫자(각 행의 첫 번째, 세 번째 숫자)는 10,000 이하의 자연수, 모금액을 나타내는 숫자(각 행의 두 번째, 네 번째 숫자)는 1,000,000 이하의 자연수입니다.
//K는 0보다 크고 100,000보다 작거나 같은 자연수입니다.

//  20191229_DP_Seoul2Gyeonsan.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/29/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int K, vector<vector<int>> travel) {
    int answer=0;
//    int a=0;
//    int b=0;
 
    int money[101][100001];
    
    money[0][travel[0][0]] = travel[0][1];
    money[0][travel[0][2]] = travel[0][3];
    
    for(int i=1; i<travel.size(); i++){
        for(int j=0; j<=K; j++){
            
            if(money[i-1][j]==0){
                continue;
            }
            if(j+travel[i][0] <= K){
                money[i][j+travel[i][0]] = max(money[i][j+travel[i][0]], money[i-1][j]+travel[i][1]);
                //a = a<money[i][j+travel[i][0]]?money[i][j+travel[i][0]]:a;
            }
            if(j+travel[i][2] <= K){
                money[i][j+travel[i][2]] = max(money[i][j+travel[i][2]], money[i-1][j]+travel[i][3]);
               // b= b<money[i][j+travel[i][2]]?money[i][j+travel[i][2]]:b;
            }
        }
    }
    //answer = max(a, b);
//    for(auto&x : money[travel.size()-1]){
//        answer = max(answer,x);
//    }
    for(int i=0; i<=K; i++)
        answer = max(answer, money[travel.size()-1][i]);
    return answer;
}
