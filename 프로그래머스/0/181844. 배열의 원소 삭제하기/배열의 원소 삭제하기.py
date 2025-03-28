def solution(arr, delete_list):
    answer = [list for list in arr if list not in delete_list]
    return answer