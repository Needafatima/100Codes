                """Pascal's triangle"""

def generate(self, numRows: int) -> List[List[int]]:
        pascal = [[1]]
        prev = [1]
        for i in range(2,numRows+1):
            res = []
            for j in range(i):
                if j==0:
                    res.append(prev[0])
                elif j==i-1:
                    res.append(prev[-1])
                else:
                    res.append(prev[j-1]+prev[j])
            prev = []
            prev = res.copy()
            pascal.append(res)
        return pascal

if __name__ == '__main__':
    p = generate(5)
    print(p)