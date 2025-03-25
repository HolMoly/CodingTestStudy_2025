def solution(hp):
    monsterHp = hp
    general = 5
    soldier = 3
    worker = 1
    
    general_ants = monsterHp // general
    monsterHp %= general

    soldier_ants = monsterHp // soldier
    monsterHp %= soldier
    
    worker_ants = monsterHp
    
    answer = general_ants + soldier_ants + worker_ants
    return answer