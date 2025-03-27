def solution(array, height):
    array.sort()
    
    left, right = 0, len(array) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if array[mid] > height:
            right = mid - 1
        else:
            left = mid + 1
    
    return len(array) - left