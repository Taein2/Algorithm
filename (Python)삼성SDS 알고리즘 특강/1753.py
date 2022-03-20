import sys
import heapq
def dijkstra(start, answer, queue, graph):
    answer[start] = 0
    heapq.heappush(queue, [0, start])
    while queue:
        current_weight, node = heapq.heappop(queue)
        if answer[node] < current_weight:
            continue
        for next_node, weight in graph[node]:
            next_w = weight + current_weight
            if next_w < answer[next_node]:
                answer[next_node] = next_w
                heapq.heappush(queue, [next_w, next_node])
def solution():
    v, e = map(int, input().split())
    k = int(input())
    INF = float('inf')
    graph = [[] for _ in range(v + 1)]
    answer = [INF] * (v + 1)
    queue = []
    for i in range(e):
        u, v, w = map(int,input().split())
        graph[u].append([v,w])
    dijkstra(k, answer, queue, graph)
    for i in answer[1:]:
        print(i if i != INF else "INF")
solution()