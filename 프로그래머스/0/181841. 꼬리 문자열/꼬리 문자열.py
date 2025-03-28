def solution(str_list, ex):
    answer = "".join([s for s in str_list if ex not in s])
    return answer