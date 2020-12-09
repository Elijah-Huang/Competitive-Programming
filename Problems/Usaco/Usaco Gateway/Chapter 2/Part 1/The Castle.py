"""
ID: elijahj1
TASK: castle
LANG: PYTHON3
"""
from collections import deque

def binary(value):
    new_val = bin(value)[2:]
    new_val = "0"*(4- len(new_val)) + new_val
    return new_val

class Room:
    def __init__(self,value):
        self.room = None
        self.neighbors = []
        self.walls = binary(value)
    
def floodfill(vertex,rooms,current_rooms):
    stack = deque([vertex])
    while stack:
        had_neighbors = False
        current_vertex = stack[-1]
        for neighbor in current_vertex.neighbors:
            if neighbor.room == None:
                neighbor.room = current_rooms
                rooms[current_rooms] += 1
                stack.append(neighbor)
                had_neighbors = True
                break
        if not had_neighbors:
            stack.pop()
        
def set_doors(castle):
    for row in range(n):
        for column in range(m):
            castle[row][column] = Room(castle[row][column])
    for row in range(n):
        for column in range(m-1):
            if castle[row][column].walls[1] == "0":
                castle[row][column].neighbors.append(castle[row][column+1])
                castle[row][column+1].neighbors.append(castle[row][column])
    for row in range(n-1):
        for column in range(m):
            if castle[row][column].walls[0] == "0":
                castle[row+1][column].neighbors.append(castle[row][column])
                castle[row][column].neighbors.append(castle[row+1][column])

def find_rooms(castle,rooms):
    current_rooms = 0
    for row in range(n):
        for column in range(m):
            if castle[row][column].room == None:
                rooms.append(1)
                current_rooms += 1
                castle[row][column].room = current_rooms
                floodfill(castle[row][column],rooms,current_rooms)
    return current_rooms

def generate_largest(castle,rooms):
    max_size = 0
    max_size_location = None
    for column in range(m):
        for row in range((n-1),-1,-1):
            if row != 0:
                if castle[row][column].walls[2] != "0":
                    if castle[row][column].room != castle[row-1][column].room:
                        current_size = rooms[castle[row][column].room] + rooms[castle[row-1][column].room]
                        if current_size > max_size:
                            max_size = current_size
                            max_size_location = str(row+1) + ' ' + str(column+1) +' N'
            if column != m-1:            
                if castle[row][column].walls[1] != "0":
                    if castle[row][column].room != castle[row][column+1].room:
                        current_size = rooms[castle[row][column].room] + rooms[castle[row][column+1].room]
                        if current_size > max_size:
                            max_size = current_size
                            max_size_location = str(row+1) + ' ' + str(column+1) +' E'
    return str(max_size) + '\n' + max_size_location + '\n'
                
with open("castle.in") as fin:
    m,n = list(map(int,fin.readline().split()))
    castle = [list(map(int,line.split())) for line in fin.readlines()]
set_doors(castle)
rooms = [0]
total_rooms = find_rooms(castle,rooms)
largest_size = max(rooms)
merged_room = generate_largest(castle, rooms)
output = str(total_rooms) + '\n' + str(largest_size) + '\n' + merged_room
with open("castle.out",'w') as fout:
    fout.write(output)






        
    

