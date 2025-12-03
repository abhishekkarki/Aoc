def parse(s:str):
    l = s.split(',')
    d = [tuple(x.split('-')) for x in l]
    return d


with open('input.txt') as f:
    raw = f.read().strip()
    
    
def invalid_id(id:int):
    s_id = str(id)
    digits = len(s_id)
    for window in range(1, digits):
        unique_chunks = set()
        if digits % window == 0:
            n_groups = digits // window
            for i in range(n_groups):
                chunk = s_id[i * window : (i+1) * window]
                unique_chunks.add(chunk)
            if len(unique_chunks) == 1: 
                return True
    return False


data = parse(raw)
ans = 0

for rng in data:
    low = int(rng[0])
    hi = int(rng[1])
    for id in range(low, hi + 1):
        if invalid_id(id) :
            ans += id
        else :
            pass

print(ans)