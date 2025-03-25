def solution(box, n):
    
    length = box[0] // n
    width = box[1] // n
    height = box[2] // n
    
    answer = length * width * height
    return answer