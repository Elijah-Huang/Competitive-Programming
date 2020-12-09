'''
ID: elijahj1
TASK: game1
LANG: PYTHON3
'''
# Code has a guaranteed strategy for player1/2 to win and some optimization
# to maximize the score of the winner, but it uses a averaged long run step
# by step heuristic, whereas DP can give a by definition via induction maximum
'''
def prog():
    with open('game1.in') as fin:
        n = int(fin.readline().strip())
        board = list(map(int,fin.read().split()))
    L = 0
    R = n-1
    player1 = 0 
    player2 = 0
    switch = False
    if n % 2 == 1:
        switch = True
        if board[0] > board[-1]:
            player2 += board[0]
            L += 1
        else:
            player2 += board[-1]
            R -= 1
    even = [0]
    odd = [0]
    for i in range(0,R+1,2):
        even.append(even[-1] + board[i])
    for i in range(1,R+1,2):
        odd.append(odd[-1] + board[i])
    for i in range(R+1-L):
        if i % 2 == 0:
            odd_sum = odd[(R+1)//2] - odd[L//2]
            even_sum = even[(R+2)//2] - even[(L+1)//2]
            if odd_sum > even_sum:
                if R % 2 == 1:
                    player1 += board[R]
                    R -= 1
                else:
                    player1 += board[L]
                    L += 1
            elif odd_sum < even_sum:
                if R % 2 == 0:
                    player1 += board[R]
                    R -= 1
                else:
                    player1 += board[L]
                    L += 1
            else:
                if board[R] > board[L]:
                    player1 += board[R]
                    R -= 1
                else:
                    player1 += board[L]
                    L += 1
        else:
            if board[R] > board[L]:
                player2 += board[R]
                R -= 1
            else:
                player2 += board[L]
                L += 1
    if switch:
        output = str(player2) + ' ' + str(player1)
    else:
        output = str(player1) + ' ' + str(player2)
    print(output)
    with open('game1.out','w') as fout:
        fout.write(output + '\n')
prog()   
'''
# recursion has exponential blowup due to recalculations
'''
def best(board):
    if len(board) == 1:
        return board[0]
    else:
        total = sum(board)
        return max(board[0] + total - best(board[1:]), \
                   board[-1] + total - best(board[:-1]))
'''
def prog():
    with open('game1.in') as fin:
        n = int(fin.readline().strip())
        board = list(map(int,fin.read().split()))
    bests = [[] for i in range(n+1)]
    psum = [0]
    for num in board:
        psum.append(psum[-1] + num)
    bests[1] = board.copy()
    for size in range(2,n+1):
        for start in range(0,n-size+1):
            total1 = psum[start+size-1] - psum[start]
            total2 = psum[start+size] - psum[start+1]
            bests[size].append(max(board[start+size-1] + total1 - bests[size-1][start],\
                                   board[start] + total2 - bests[size-1][start+1]))
    output = str(bests[-1][0]) + ' ' + str(psum[-1] - psum[0] - bests[-1][0]) + '\n'
    with open('game1.out','w') as fout:
        fout.write(output)
prog()
