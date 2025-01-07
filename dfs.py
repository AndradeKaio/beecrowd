lgraph = [
    [1, 2],
    [2],
    [1],
]

mgraph = [
    [0, 0, 1],
    [0, 0, 1],
    [1, 1, 0],
]

mgraph = [
    [0, 1, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0, 0],
    [0, 0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0, 1],
    [1, 0, 0, 0, 1, 0],
]

def print_matrix(mgraph):
    for i in range(len(mgraph)):
        a = ""
        for j in range(len(mgraph)):
            a += " " + mgraph[i][j]
        print(a)

def square_list(lgraph):
    i = 0
    lgraph = [[1, 2, 3], [0, 2, 3], [0, 1, 3], [0, 1, 2]]
    lgraph2 = [[] for _ in range(len(lgraph))]
    # E = 12
    # V = 4
    for v in range(len(lgraph)):
        ws = []
        for u in lgraph[v]:
            if u not in lgraph2[v] and v != u:
                lgraph2[v].append(u)
            for w in lgraph[u]:
                i+=1
                if w != v:
                    if w not in lgraph2[v]:
                        lgraph2[v].append(w)
    print(i)
    print(lgraph2)

def square_matrix(mgraph):
    print(mgraph)
    mgraph2 = [[0 for i in range(len(mgraph))] for _ in range(len(mgraph))]
    for v in range(len(mgraph)):
        ws = []
        for u in range(len(mgraph)):
            if mgraph[v][u] == 1:
                mgraph2[v][u] = 1
                ws.append(u)
        for w in ws:
            for adj in range(len(mgraph)):
                if mgraph[w][adj] == 1 and v != adj:
                    mgraph2[v][adj] = 1
    print(mgraph2)

def transpose(mgraph):
    print(mgraph)
    for v in range(len(mgraph)):
        for u in range(len(mgraph[v])):
            if u >= v:
                if mgraph[v][u] == 1:
                    if mgraph[u][v] == 1:
                        continue
                    mgraph[v][u] = 0
                    mgraph[u][v] = 1
    print(mgraph)


def transpose_list(lgraph):
    print(lgraph)
    lgraph2 = [[] for i in range(len(lgraph))]
    for v in range(len(lgraph)):
        for u in lgraph[v]:
            lgraph2[u].append(v)
    print(lgraph2)


graph = [
    [2, 4],
    [4, 5],
    [2, 5, 6],
    [],
    [],
    [],
    [5],
    [2, 3],
    [6],
    [],
    [],
]
color = {}


def dfs(graph, s):
    for i in range(len(graph)):
        if i not in color:
            dfs_visit(graph, i)

def dfs_visit(graph, v):
    print("visiting ", v + 1)
    color[v] = 1
    for u in graph[v]:
        if u - 1 not in color:
            dfs_visit(graph, u - 1)
    color[v] = 2

def dfs_iter(graph):
    visited = {}
    for i in range(len(graph)):
        if i not in visited:
            stack = [i]
            while stack:
                v = stack.pop()
                visited[v] = True
                print("visiting ", v + 1)
                for u in graph[v]:
                    if u - 1 not in visited:
                        stack.append(u - 1)

if __name__ == "__main__":
    #dfs(graph, 0)
    #print()
    #dfs_iter(graph)
    # transpose(mgraph)
    # transpose_list(lgraph)
    square_list(mgraph)

