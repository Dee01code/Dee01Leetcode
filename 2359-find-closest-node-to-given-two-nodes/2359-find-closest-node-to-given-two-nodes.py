class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        
        n = len(edges)

        def bfs(u):
            d = {u: 0}
            i = 0
            visited = [False] * n
            while u != -1:
                visited[u] = True
                d[u] = i
                i += 1
                if not visited[edges[u]]:
                    u = edges[u]
                else:
                    break
            return d

        d1, d2 = bfs(node1), bfs(node2)
        res = [float("inf"), None]
        for v in d1:
            if v in d2:
                dis = max(d1[v], d2[v])
                if dis < res[0] or (dis == res[0] and v < res[1]):
                    res = [dis, v]
        return res[1] if res[1] is not None else -1


# s = Solution()
# print(s.closestMeetingNode([4, 4, 4, 5, 1, 2, 2], 1, 1))