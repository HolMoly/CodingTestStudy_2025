def solution(myString, pat):
    converted = myString.replace("A", "X").replace("B", "A").replace("X", "B")
    
    return 1 if pat in converted else 0