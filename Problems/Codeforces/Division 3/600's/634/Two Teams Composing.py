"""t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    students = list(map(int,input().split()))
    skills = {}
    for student in students:
        skills[student] = skills.get(student,0) + 1
    max_num = 0
    for skill_lvl in skills:
        if skills[skill_lvl] > max_num:
            max_num = skills[skill_lvl]
    if max_num <= len(skills) - 1:
        print(max_num)
    elif max_num == len(skills):
        print(max_num - 1)
    else:
        print(len(skills))"""
"""With counter"""
def yo():
    from collections import Counter
    t = int(input().strip())
    for i in range(t):
        n = int(input().strip())
        students = list(map(int,input().split()))
        skills = Counter(students)
        max_num = skills.most_common(1)[0][1]
        if max_num <= len(skills) - 1:
            print(max_num)
        elif max_num == len(skills):
            print(max_num - 1)
        else:
            print(len(skills))
yo()
