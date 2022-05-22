# 백준 3190 뱀
 
## 시뮬레이션

## 알고리즘
움직인다음 방향전환을 해야되는 부분에서 입력을 받으면서 바꿔나갈지, 먼저 입력을 받고 조건에 만족하면 바꿔줄지 생각을 해봐야 되는 문제인 것 같다.
앞부분이 생성되면서 뒷부분이 사라지는 경우는 덱큐로 풀어야하지만 덱큐에 넣고 매번 체크하는 과정에서 애를 먹어서 구현으로 풀었다.
텍스트케이스를 통과한후 덱큐로 푸는 방법과 이런경우에 모듈러연산을 깔끔히 하는 방법을 알고 싶어서 개발자분이 보내주신 코드를 가져왔다. 
  

## 코드
[코드 보러가기](https://github.com/ktjs7252/Baekjoon_code/blob/main/3190-2.c%2B%2B)


## 느낀 점
다른 텍스트케이스에서 틀렸지만 갈때마다 사과가 있거나 전체 모서리에 사과가 있을 경우 마지막에 몸에 닿아서 끝나야되는데 범위를 벗어나서 틀린다고 생각했다.
이 부분을 해결하려면 다른 부분을 바꿔야된다고 생각해서 오래 시간이 걸렸지만 간단하게 -1로 초기화 하면 된다는 것을 알았다.
백준 텍스트케이스는 이 부분을 추가해주지 않아서 데이터가 추가 요청을 했다.
