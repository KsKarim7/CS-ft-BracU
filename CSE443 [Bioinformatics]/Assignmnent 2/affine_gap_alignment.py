def load_blosum62():
    blosum62_str = """
       A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V
    A  4 -1 -2 -2  0 -1 -1  0 -2 -1 -1 -1 -1 -2 -1  1  0 -3 -2  0
    R -1  5  0 -2 -3  1  0 -2  0 -3 -2  2 -1 -3 -2 -1 -1 -3 -2 -3
    N -2  0  6  1 -3  0  0  0  1 -3 -3  0 -2 -3 -2  1  0 -4 -2 -3
    D -2 -2  1  6 -3  0  2 -1 -1 -3 -4 -1 -3 -3 -1  0 -1 -4 -3 -3
    C  0 -3 -3 -3  9 -3 -4 -3 -3 -1 -1 -3 -1 -2 -3 -1 -1 -2 -2 -1
    Q -1  1  0  0 -3  5  2 -2  0 -3 -2  1  0 -3 -1  0 -1 -2 -1 -2
    E -1  0  0  2 -4  2  5 -2  0 -3 -3  1 -2 -3 -1  0 -1 -3 -2 -2
    G  0 -2  0 -1 -3 -2 -2  6 -2 -4 -4 -2 -3 -3 -2  0 -2 -2 -3 -3
    H -2  0  1 -1 -3  0  0 -2  8 -3 -3 -1 -2 -1 -2 -1 -2 -2  2 -3
    I -1 -3 -3 -3 -1 -3 -3 -4 -3  4  2 -3  1  0 -3 -2 -1 -3 -1  3
    L -1 -2 -3 -4 -1 -2 -3 -4 -3  2  4 -2  2  0 -3 -2 -1 -2 -1  1
    K -1  2  0 -1 -3  1  1 -2 -1 -3 -2  5 -1 -3 -1  0 -1 -3 -2 -2
    M -1 -1 -2 -3 -1  0 -2 -3 -2  1  2 -1  5  0 -2 -1 -1 -1 -1  1
    F -2 -3 -3 -3 -2 -3 -3 -3 -1  0  0 -3  0  6 -4 -2 -2  1  3 -1
    P -1 -2 -2 -1 -3 -1 -1 -2 -2 -3 -3 -1 -2 -4  7 -1 -1 -4 -3 -2
    S  1 -1  1  0 -1  0  0  0 -1 -2 -2  0 -1 -2 -1  4  1 -3 -2 -2
    T  0 -1  0 -1 -1 -1 -1 -2 -2 -1 -1 -1 -1 -2 -1  1  5 -2 -2  0
    W -3 -3 -4 -4 -2 -2 -3 -2 -2 -3 -2 -3 -1  1 -4 -3 -2 11  2 -3
    Y -2 -2 -2 -3 -2 -1 -2 -3  2 -1 -1 -2 -1  3 -3 -2 -2  2  7 -1
    V  0 -3 -3 -3 -1 -2 -2 -3 -3  3  1 -2  1 -1 -2 -2  0 -3 -1  4
    """
    lines = [line.split() for line in blosum62_str.strip().split("\n")]
    aas = lines[0]
    blosum62 = {}
    for i in range(1, len(lines)):
        for j in range(1, len(lines[i])):
            blosum62[(lines[i][0], aas[j-1])] = int(lines[i][j])
    return blosum62

BLOSUM62 = load_blosum62()
sigma = 11  
epsilon = 1  


def affine_gap_alignment(v, w):
    n, m = len(v), len(w)
    NEG_INF = -10**9

 
    M = [[NEG_INF] * (m+1) for _ in range(n+1)]  
    X = [[NEG_INF] * (m+1) for _ in range(n+1)]  
    Y = [[NEG_INF] * (m+1) for _ in range(n+1)]  

    
    back_M = [[None]*(m+1) for _ in range(n+1)]
    back_X = [[None]*(m+1) for _ in range(n+1)]
    back_Y = [[None]*(m+1) for _ in range(n+1)]


    M[0][0] = 0
    for i in range(1, n+1):
        X[i][0] = -sigma - (i-1)*epsilon
    for j in range(1, m+1):
        Y[0][j] = -sigma - (j-1)*epsilon

   
    for i in range(1, n+1):
        for j in range(1, m+1):
           
            s = BLOSUM62[(v[i-1], w[j-1])]
            best = max(M[i-1][j-1], X[i-1][j-1], Y[i-1][j-1])
            M[i][j] = best + s
            if best == M[i-1][j-1]:
                back_M[i][j] = ("M", i-1, j-1)
            elif best == X[i-1][j-1]:
                back_M[i][j] = ("X", i-1, j-1)
            else:
                back_M[i][j] = ("Y", i-1, j-1)

           
            cand1 = M[i-1][j] - sigma
            cand2 = X[i-1][j] - epsilon
            if cand1 >= cand2:
                X[i][j] = cand1
                back_X[i][j] = ("M", i-1, j)
            else:
                X[i][j] = cand2
                back_X[i][j] = ("X", i-1, j)

            
            cand1 = M[i][j-1] - sigma
            cand2 = Y[i][j-1] - epsilon
            if cand1 >= cand2:
                Y[i][j] = cand1
                back_Y[i][j] = ("M", i, j-1)
            else:
                Y[i][j] = cand2
                back_Y[i][j] = ("Y", i, j-1)

   
    final_score = max(M[n][m], X[n][m], Y[n][m])
    if final_score == M[n][m]:
        state, i, j = "M", n, m
    elif final_score == X[n][m]:
        state, i, j = "X", n, m
    else:
        state, i, j = "Y", n, m

    
    aln_v, aln_w = [], []
    while i > 0 or j > 0:
        if state == "M":
            prev, pi, pj = back_M[i][j]
            aln_v.append(v[i-1])
            aln_w.append(w[j-1])
        elif state == "X":
            prev, pi, pj = back_X[i][j]
            aln_v.append(v[i-1])
            aln_w.append("-")
        else:  # Y
            prev, pi, pj = back_Y[i][j]
            aln_v.append("-")
            aln_w.append(w[j-1])
        state, i, j = prev, pi, pj

    return final_score, "".join(reversed(aln_v)), "".join(reversed(aln_w))


if __name__ == "__main__":
    v = input().strip()
    w = input().strip()
    score, aln_v, aln_w = affine_gap_alignment(v, w)
    print(score)
    print(aln_v)
    print(aln_w)
