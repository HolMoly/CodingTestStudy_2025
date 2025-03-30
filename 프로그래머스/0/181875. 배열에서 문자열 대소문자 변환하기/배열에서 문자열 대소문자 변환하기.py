def solution(strArr):
    answer = [s.lower() if i % 2 == 0 else s.upper() for i, s in enumerate(strArr)]
    return answer