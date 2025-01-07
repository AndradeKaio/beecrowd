from typing import List



def dfs2(lgraph, start):
    visited = [False] * len(lgraph)
    return dfs2_visit(lgraph, visited, start)

def dfs2_visit(lgraph, visited, v):
    visited[v] = True
    for u in lgraph[v]:
        if not visited[u]:
            dfs2_visit(lgraph, visited, u)
    return visited
def dfs(lgraph, start) -> List:
    visited = [False] * len(lgraph)
    stack = [start]
    while stack:
        u = stack.pop()
        visited[u] = True
        for adj in lgraph[u]:
            if not visited[adj]:
                stack.append(adj)
    return visited

def main():
    n, m = map(int, input().split())
    while n and m:
        lgraph = [[] for _ in range(n + 1)]
        # read graph
        while m > 0:
            v, u, p = map(int, input().split())
            lgraph[v].append(u)
            if p == 2:
                lgraph[u].append(v)
            m -= 1
        # check connectivity
        flag = False
        for u in range(1, len(lgraph)):
            # visited = dfs(lgraph, u)
            visited = dfs2(lgraph, u)
            for i in range(1, len(lgraph)):
                if visited[i] is False:
                    flag = True
                    break
            if flag == True:
                break

        print(0 if flag else 1)

        n, m = map(int, input().split())


if __name__ == "__main__":
    main()
