import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        x_coords = []
        y_coords = []
        for i in range(4):
            x,y = map(int,input().split())
            x_coords.append([x,i])
            y_coords.append([y,i])
            
        x_coords.sort()
        y_coords.sort()

        zero_square = x_coords[3][0]-x_coords[0][0] + x_coords[2][0]-x_coords[1][0] + \
                   y_coords[3][0]-y_coords[0][0] + y_coords[2][0]-y_coords[1][0]

        pos_square_len = max(x_coords[2][0]-x_coords[1][0],y_coords[2][0]-y_coords[1][0])
        if x_coords[3][0]-x_coords[0][0] >= pos_square_len and \
           y_coords[3][0]-y_coords[0][0] >= pos_square_len:
            mn_idx = 4
            mx_idx = -1
            unique_vals = set()
            for i in range(4):
                unique_vals.add(x_coords[i][0])
                if len(unique_vals) > 2 or (i == 2 and x_coords[1][0] != x_coords[2][0]):
                    break
                
                for j in range(4):
                    if y_coords[j][1] == i:
                        y_coord = y_coords[j][0]
                for j in range(4):
                    if y_coords[j][0] == y_coord:
                        mn_idx = min(mn_idx,j)
                        mx_idx = max(mx_idx,j)
                        
            if mn_idx <= 1 and mx_idx >= 2:
                print(zero_square - 2*(x_coords[2][0]-x_coords[1][0] + y_coords[2][0]-y_coords[1][0]))
            else:
                print(zero_square)
        else:
            print(zero_square)
            
prog()
