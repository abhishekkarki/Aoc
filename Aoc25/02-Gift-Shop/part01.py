def parse(s:str):
    l = s.split(',')
    d = [tuple(x.split('-')) for x in l]
    return d


with open('input.txt') as f:
    raw = f.read().strip()
    
    
data = parse(raw)
ans = 0
for rng in data:
    low = int(rng[0])
    hi = int(rng[1])
    for id in range(low, hi + 1):
        s_id = str(id)
        digits = len(s_id)
        if digits % 2 == 0 and s_id[:digits//2] == s_id[digits//2:] :
            # print(s_id)
            ans += id
        else :
            pass

print(ans)