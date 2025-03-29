def solution(arr):
    answer = [num for a in arr for num in [a] * a]
    return answer