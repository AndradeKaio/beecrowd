# -*- coding: utf-8 -*-
from collections import defaultdict

counter = 0
name_map = {}
parents = defaultdict(list)

def dfs(graph, start) -> set:
    q = [start]
    visited = {}
    parents = set([start])
    while q:
        t = q.pop()
        visited[t] = True
        for u in graph[t]:
            if u not in visited:
                visited[u] = True
                q.append(u)
                parents.add(u)
    return parents

def get_index(name: str) -> int:
    global counter
    if name in name_map:
        return name_map[name]
    else:
        name_map[name] = counter
        counter += 1
        return counter - 1

N, C, T = map(int, input().split())

lgraph = [[] for _ in range(N)]

for _ in range(C):
    f, m, c = input().split(" ")

    #insert into the graph
    child_index = get_index(c)
    father_index = get_index(f)
    mother_index = get_index(m)

    lgraph[child_index].append(father_index)
    lgraph[child_index].append(mother_index)

for _ in range(T):
    #print test result
    A, B = input().split()
    parents_a = dfs(lgraph, get_index(A))
    parents_b = dfs(lgraph, get_index(B))
    result = parents_a & parents_b
    print("verdadeiro" if result else "falso")

