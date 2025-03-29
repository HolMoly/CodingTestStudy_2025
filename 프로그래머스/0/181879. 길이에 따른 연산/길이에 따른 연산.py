def solution(num_list):
    if len(num_list) >= 11:
        answer = sum(num_list)
    else:
        answer = 1
        for num in num_list:
            answer *= num
    return answer