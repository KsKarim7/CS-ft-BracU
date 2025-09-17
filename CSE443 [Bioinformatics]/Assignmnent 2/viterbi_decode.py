def parse_input_from_file(filename):
    with open(filename, "r") as f:
        lines = [line.strip() for line in f if line.strip()]

    seq = lines[0]  

    
    sigma_index = lines.index("--------")
    sigma = lines[sigma_index + 1].split()

    
    states_index = lines.index("--------", sigma_index + 1)
    states = lines[states_index + 1].split()

    
    trans_index = lines.index("--------", states_index + 1)
    trans_lines = lines[trans_index + 1: trans_index + 1 + len(states) + 1]
    trans_header = trans_lines[0].split()
    transition = {}
    for line in trans_lines[1:]:
        parts = line.split()
        row_state = parts[0]
        transition[row_state] = {s: float(val) for s, val in zip(trans_header, parts[1:])}

    
    emis_index = lines.index("--------", trans_index + 1)
    emis_lines = lines[emis_index + 1: emis_index + 1 + len(states) + 1]
    emis_header = emis_lines[0].split()
    emission = {}
    for line in emis_lines[1:]:
        parts = line.split()
        row_state = parts[0]
        emission[row_state] = {sym: float(val) for sym, val in zip(emis_header, parts[1:])}

    return seq, sigma, states, transition, emission


def viterbi(seq, states, transition, emission):
    n = len(seq)
    m = len(states)
    V = [[0.0] * n for _ in range(m)]  
    back = [[0] * n for _ in range(m)]  

    
    for i, s in enumerate(states):
        V[i][0] = emission[s][seq[0]]

    for t in range(1, n):
        for j, s in enumerate(states):
            max_prob, argmax = max(
                (V[i][t - 1] * transition[states[i]][s] * emission[s][seq[t]], i)
                for i in range(m)
            )
            V[j][t] = max_prob
            back[j][t] = argmax

    last_state = max(range(m), key=lambda i: V[i][n - 1])
    path = [last_state]
    for t in range(n - 1, 0, -1):
        last_state = back[last_state][t]
        path.append(last_state)
    path.reverse()
    return "".join(states[i] for i in path)


if __name__ == "__main__":
    seq, sigma, states, transition, emission = parse_input_from_file("input.txt")
    path = viterbi(seq, states, transition, emission)
    print(path)
