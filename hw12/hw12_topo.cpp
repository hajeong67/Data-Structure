위상정렬(G) :
    결과 = []  // 정렬된 노드를 저장할 리스트
    진입차수 = {}  // 각 노드의 진입 차수를 저장할 딕셔너리

  // 각 노드의 진입 차수 계산
    for each 노드 in G :
        진입차수[노드] = 0
    for each 노드 in G :
    for each 인접한_노드 in 노드의_인접_노드 :
         진입차수[인접한_노드] += 1

  // 진입 차수가 0인 노드를 큐에 추가
   큐 = []
    for each 노드 in G :
           if 진입차수[노드] == 0 :
               큐.append(노드)

   // 큐가 빌 때까지 반복
   while 큐 :
           현재_노드 = 큐.pop(0)
           결과.append(현재_노드)

  // 현재 노드와 연결된 모든 노드에 대해 진입 차수 감소
  for each 인접한_노드 in 현재_노드의_인접_노드 :
           진입차수[인접한_노드] -= 1

  // 진입 차수가 0이 된 노드를 큐에 추가
  if 진입차수[인접한_노드] == 0 :
       큐.append(인접한_노드)

   // 결과 반환
   return 결과