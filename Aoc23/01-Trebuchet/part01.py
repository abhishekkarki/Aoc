result = 0
with open("input.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        print(line)
        
        # getting the leftmost digit from the line
        for ch in line:
            if ch.isdigit():
                left = ch
                break
            else:
                left = 0
        
        for ch in reversed(line):
            if ch.isdigit():
                right = ch
                break
            else:
                right = 0
        
        digit = int(left + right)
        result = result + digit
        
print("this is the result", result)