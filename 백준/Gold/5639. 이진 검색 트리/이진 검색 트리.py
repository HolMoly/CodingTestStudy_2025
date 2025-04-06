""" 
input
    // 트리의 전위 순회 결과
    // 노드
        // 키 값 = 10**6 이하의 정수
        // 수 = 10,000개 이하
        // 노드의 키 값은 중복되지 않음
    // 노드는 한 줄에 하나씩 주어짐

output
    // 전위 순회 결과를 통한 이진 검색 트리의 후위 순회 결과
    // 후위 순회 결과는 한 줄에 하나씩 출력

process
    // 전위 순회 결과 -> 배열 전환환
    // 재귀를 통한 노드 객체 및 트리 구성
    // 구성한 트리 후위 순회
"""

import sys
sys.setrecursionlimit(10**6)  # 백준 입출력 관련 recursion 제한 해제
#sys.stdin = open('input.txt', 'r')

preorder = list(map(int, sys.stdin.read().split()))

""""
키 값 = 10**6 이하의 정수 + 수 = 10,000개 이하
해당 조건에 의한 것인지 백준에서 시간 초과 판정

규칙 및 해결 알고리즘 발견
전체 트리의 루트 노드의 값인 최초의 값을 기준으로 해당 숫자보다 높아지는 시점 = 우측 서브트리
배열의 인덱스를 이동하며, 좌 우측을 나누는 함수 구현 필요
또한, 해당 함수를 재귀적으로 사용하면 이진 트리 및 각 노드를 구성 가능

class Node: # 이진 트리에서 사용될 노드
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def assign(node, value): # 재귀적으로 노드에 값을 할당
    if value < node.value:
        if node.left is None:
            node.left = Node(value)
        else:
            assign(node.left, value)
    else:
        if node.right is None:
            node.right = Node(value)
        else:
            assign(node.right, value)

root = Node(preorder[0]) # 전위 순회이기에 첫번째 값 = 루트 노드
for value in preorder[1:]:
    assign(root, value) # 반복문마다 root에서 시작하기에 비효율적

def postorder(node): # 후위 순회
    if node is None:
        return
    postorder(node.left)
    postorder(node.right)
    print(node.value)

postorder(root)
"""

def assign_postorder(start, end):
    if start >= end: # 종료조건 = 배열 순회 완료 시, 종료
        return
    
    root = preorder[start] # 전위 순회이기에 첫번째 값을 루트 노드에 할당
    # 반복문에 포함하여, 자식 노드에서 재귀적으로 사용할 때마다 값 갱신

    division_index = start + 1 # 좌 우 서브트리 구분을 위한 인덱스

    while division_index < end and preorder[division_index] < root: 
        # 1. 구분점 인덱스가 마지막까지만 이동
        # 2. 루트 노드보다 큰 값이 나오기 전까지 이동
        division_index += 1

    # postorder 함수와 같이, 좌측부터 우측, 루트 순회하도록 구성
    assign_postorder(start + 1, division_index)  # 좌측 서브 트리 범위
    assign_postorder(division_index, end)  # 우측 서브 트리 범위
    print(root)  # 좌 우측 서브 트리 순회가 완료된 후, 루트 노드 출력

assign_postorder(0, len(preorder))