import re
import time
import random
from collections import deque

# ==========================================================
# NORMALIZE INPUT
# ==========================================================
def normalize_equation(eq):
    return eq.upper().replace(" ", "")

# ==========================================================
# VALIDATE & PARSE
# ==========================================================
def validate_and_parse(eq):
    if not eq:
        return False, "Empty input", None
    if re.search(r"[0-9]", eq):
        return False, "Digits not allowed", None
    if re.search(r"[^A-Z+=-]", eq):
        return False, "Invalid characters", None
    if eq.count("=") != 1:
        return False, "Exactly one '=' required", None

    left, right = eq.split("=")

    if "+" in left:
        w1, w2 = left.split("+")
    elif "-" in left:
        w1, w2 = left.split("-")
    else:
        return False, "Only + or - supported", None

    letters = set(w1 + w2 + right)
    if len(letters) > 10:
        return False, "Too many letters (>10)", None

    return True, "OK", (w1, w2, right)

# ==========================================================
# DOMAIN INITIALIZATION
# ==========================================================
def preprocess_domains(words, result):
    letters = set("".join(words) + result)
    domains = {l: set(range(10)) for l in letters}

    for w in words + [result]:
        domains[w[0]].discard(0)

    return domains

# ==========================================================
# AC-3 CONSTRAINT PROPAGATION
# ==========================================================
def ac3(domains):
    queue = deque([(x, y) for x in domains for y in domains if x != y])

    while queue:
        xi, xj = queue.popleft()
        if revise(domains, xi, xj):
            if not domains[xi]:
                return False
            for xk in domains:
                if xk != xi and xk != xj:
                    queue.append((xk, xi))
    return True

def revise(domains, xi, xj):
    revised = False
    for x in set(domains[xi]):
        if x in domains[xj] and len(domains[xj]) == 1:
            domains[xi].remove(x)
            revised = True
    return revised

# ==========================================================
# CONSISTENCY CHECK
# ==========================================================
def is_consistent(assign, w1, w2, res):
    max_len = max(len(w1), len(w2), len(res))
    carry = 0

    for i in range(1, max_len + 1):
        a = assign.get(w1[-i]) if i <= len(w1) else None
        b = assign.get(w2[-i]) if i <= len(w2) else None
        c = assign.get(res[-i]) if i <= len(res) else None

        if a is not None and b is not None:
            s = a + b + carry
            if c is not None and c != s % 10:
                return False
            carry = s // 10
        else:
            break

    return True

# ==========================================================
# MRV + LCV
# ==========================================================
def select_mrv(domains, assign):
    return min(
        (v for v in domains if v not in assign),
        key=lambda x: len(domains[x])
    )

def order_lcv(var, domains, assign):
    impact = []
    for val in domains[var]:
        count = sum(val in domains[v] for v in domains if v not in assign)
        impact.append((count, val))
    return [v for _, v in sorted(impact)]

# ==========================================================
# BACKTRACKING SEARCH
# ==========================================================
def backtrack(assign, domains, w1, w2, res):
    if len(assign) == len(domains):
        return assign

    var = select_mrv(domains, assign)

    for val in order_lcv(var, domains, assign):
        if val in assign.values():
            continue

        assign[var] = val
        if is_consistent(assign, w1, w2, res):
            result = backtrack(assign, domains, w1, w2, res)
            if result:
                return result
        del assign[var]

    return None

# ==========================================================
# MIN-CONFLICTS WITH RANDOM RESTARTS
# ==========================================================
def min_conflicts_restart(words, result, restarts=20, steps=3000):
    letters = list(set("".join(words) + result))

    for _ in range(restarts):
        assign = {l: random.randint(0, 9) for l in letters}

        for _ in range(steps):
            if is_consistent(assign, words[0], words[1], result):
                return assign

            var = random.choice(letters)
            best_val = None
            min_conf = float("inf")

            for v in range(10):
                assign[var] = v
                conflicts = 0
                if not is_consistent(assign, words[0], words[1], result):
                    conflicts += 1
                if conflicts < min_conf:
                    min_conf = conflicts
                    best_val = v

            assign[var] = best_val

    return None

# ==========================================================
# SOLVER PIPELINE (HYBRID)
# ==========================================================
def solve(eq):
    eq = normalize_equation(eq)
    valid, msg, data = validate_and_parse(eq)
    if not valid:
        return False, msg, 0.0

    w1, w2, res = data
    domains = preprocess_domains([w1, w2], res)

    start = time.time()

    ac3(domains)
    solution = backtrack({}, domains, w1, w2, res)

    if not solution:
        solution = min_conflicts_restart([w1, w2], res)

    duration = time.time() - start

    if solution:
        return True, solution, duration
    return False, "No solution", duration

# ==========================================================
# MAIN LOOP
# ==========================================================
if __name__ == "__main__":
    print("\n=== CipherForge Hybrid AI Solver ===\n")
    while True:
        eq = input("Enter cryptarithm: ")
        success, result, t = solve(eq)

        print("\n----------------------------")
        if success:
            print("Solution Found:")
            for k in sorted(result):
                print(f"{k} = {result[k]}")
        else:
            print("Error:", result)
        print(f"Time Taken: {t:.4f} sec")
        print("----------------------------")

        while True:
            choice = input("Again? (yes/no): ").strip().lower()
            if choice == "yes":
                break
            elif choice == "no":
                print("\nThank you for using CipherForge. Goodbye!")
                exit()
            else:
                print("Please enter only 'yes' or 'no'.")
