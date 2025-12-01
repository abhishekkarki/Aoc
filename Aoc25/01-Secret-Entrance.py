

def count_zero_crossings(data):
  
  point = 50
  zeros = 0
  
  for row in data:
    go_right = 1 if row[0] == "R" else -1
    amount = int(row[1:])
    
    # get each full cycle of 100
    zeros += amount // 100
    
    # remainder is next value pointing
    remainder = amount % 100
    
    if remainder > 0:
      new_point = point + go_right * remainder
      
      # check if we crossed zero
      if (go_right > 0 and new_point >= 100) or (go_right < 0 and new_point < 1 and point > 0):
        zeros += 1
      
      point = (new_point + 100) % 100
      
  return zeros
 

with open("input.txt", "r", encoding="utf-8") as f:
    data = [line.strip() for line in f]

print(count_zero_crossings(data))
