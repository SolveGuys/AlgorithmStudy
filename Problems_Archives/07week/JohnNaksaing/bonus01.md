
# 보너스 문제01 : 인피니티 워

## [상황]

취준생 T는 계속되는 낙방에 지쳐 결국 세상 전부를 증오하게 되어 우주를 멸망시키고자 인피니티 스톤을 모았다.  
T는 스톤을 끼우고 손가락을 튕겨 작동시킬 수 있는 건틀릿을 만들고, 그걸 사용하였을 때 살아남는 사람을 구하고자 한다.

## [문제]

1. 스톤과 건틀렛의 자료구조를 설계하시오.  
2. 스톤을 끼우고 작동시킬 때 살아남는 사람을 구하시오.

  

## [규칙]

1.
인피니티 스톤은 bool을 반환하는 콜러블이며, 주어지는 input의 type은 알 수 없다.  
스톤을 끼울 건틀릿은 모든 스톤을 담을 수 있는 하나의 컨테이너로 이루어져야 한다.  
모든 스톤이 같은 자료형을 가지는 보장은 없다.  

2.
사람들은 ```std::vector<int>```로 주어지며, 각 요소인 정수 값은 해당 사람을 의미한다.  
스톤의 조건에 "모두" 해당하는 사람은 죽는다.

  

## [입력 예시]

예

사람 : 
```{2, 1, 2, 3, 4, 8, 4, 2, 6, 8, 1, 7, 8}```

스톤 : 
```
1. 이 사람을 구성하는 숫자에는 직선이 있다(참고할 것 : 3, 6, 8, 9, 0).
2. 이 사람은 주어진 자료구조의 마지막이 아니다.
3. 주어진 자료구조의 앞에서 이 사람과 같은 숫자의 사람이 있었다.
```
(스톤의 입력은 채점 과정에서 주어지지 않는다고 가정하고, 문제의 예시 상황에 따라 알맞게 설계하여 건틀릿에 끼우시면 됩니다.)

예상 결과 : 
``` {2, 1, -, 3, 4, 8, -, -, 6, 8, -, 7, 8} ```  
(```-``` 표시는 이해를 돕기 위한 것으로, 출력하지 않아도 정답으로 인정된다고 하겠습니다.)