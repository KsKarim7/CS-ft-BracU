import numpy as np
import sys

def read_data(file_name):
    with open(file_name, 'r') as file:
        k, t = (int(element) for element in (file.readline().strip()).split())
        motifs = [motif.strip() for motif in file]
    return k, t, motifs

def rand_motif_search(dna, k, t):
    last_ind = len(dna[0]) - k + 1
    idxs = [np.random.randint(0, last_ind) for _ in range(t)]
    best_motifs = [s[start:(start + k)] for s, start in zip(dna, idxs)]

    while True:
        profile = create_profile(best_motifs)
        motifs = create_motifs(profile, dna)
        if score(motifs) < score(best_motifs):
            best_motifs = motifs
        else:
            return best_motifs

def create_profile(motifs):
    profile = dict()
    motif_len = len(motifs[0])
    profile['A'] = [1 for _ in range(motif_len)]
    profile['C'] = [1 for _ in range(motif_len)]
    profile['G'] = [1 for _ in range(motif_len)]
    profile['T'] = [1 for _ in range(motif_len)]

    for motif in motifs:
        for j in range(motif_len):
            profile[motif[j]][j] += 1

    return profile

def create_motifs(profile, dna):
    return [get_best_match(profile, s) for s in dna]

def get_best_match(profile, string):
    motif_len = len(profile['A'])
    scores = calc_prob_for_all(profile, string)
    start = scores.index(max(scores))
    return string[start:start + motif_len]

def calc_prob_for_all(profile, string):
    return [calc_prob(profile, string, pos) for pos in range(len(string) - len(profile['A']) + 1)]

def calc_prob(profile, string, pos):
    result = 1
    for i in range(len(profile['A'])):
        result *= profile[string[pos + i]][i]
    return result

def score(motifs):
    consensus = get_consensus(motifs)
    return sum(hamming_dist(consensus, motif) for motif in motifs)

def get_consensus(motifs):
    length = len(motifs[0])
    profile = {'A': [0] * length, 'C': [0] * length, 'G': [0] * length, 'T': [0] * length}

    for motif in motifs:
        for j in range(length):
            profile[motif[j]][j] += 1

    consensus = []
    for j in range(length):
        max_elem = max(profile['A'][j], profile['C'][j], profile['G'][j], profile['T'][j])
        for nuc in 'ACGT':
            if profile[nuc][j] == max_elem:
                consensus.append(nuc)
                break

    return ''.join(consensus)

def hamming_dist(str_one, str_two):
    if len(str_one) != len(str_two):
        raise ValueError("Strings must be the same length.")
    return sum(c1 != c2 for c1, c2 in zip(str_one, str_two))

def read_input():
    lines = sys.stdin.read().strip().split('\n')
    k, t = map(int, lines[0].split())
    dna = lines[1:]
    return k, t, dna


if __name__ == "__main__":
    ITER_NUM = 1000
    k, t, strings = read_input()

    best_motifs = rand_motif_search(strings, k, t)

    for _ in range(ITER_NUM - 1):
        motifs = rand_motif_search(strings, k, t)
        if score(motifs) < score(best_motifs):
            best_motifs = motifs

    for motif in best_motifs:
        print(motif)
