import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val)

"""
from collections import Counter

def least_testcases():
    n,k = map(int,input().split())
    counts = Counter(map(int,input().split()))
    lengths = list(counts.keys())
    lengths.sort()
    restrictions = list(map(int,input().split()))
    restrictions = [restrictions[i-1] for i in lengths]
    
    #set up list that can be used to point to length that still has space
    first_size = [None for i in range(restrictions[0] + 1)]
    curr = restrictions[-1]
    first_size[curr] = len(restrictions)-1
    for i in range(len(restrictions)-2,-1,-1):
        new = restrictions[i]
        if new != curr:
            for j in range(curr+1, new+1):
                first_size[j] = i
            curr = new
    testcases = []
    added = 0
    current = len(lengths) -1 
    while added < n:
        current = len(lengths) -1 
        testcase = []
        while current > -1:
            curr_len = lengths[current]
            max_curr = restrictions[current]-len(testcase)
            if counts[curr_len] == 0:
                pass
            elif counts[curr_len] > max_curr:
                testcase += [curr_len]*max_curr
                added += max_curr
                counts[curr_len] -= max_curr
            else:
                testcase += [curr_len]*counts[curr_len]
                added += counts[curr_len]
                counts[curr_len] = 0
            if restrictions[0] == len(testcase):
                break
            elif current == 0:
                break
            elif restrictions[current-1] == len(testcase):
                current = first_size[len(testcase) + 1]
            else:
                current -= 1
        testcases.append(testcase)
    """
"""
    output = str(len(testcases)) + '\n'
    for testcase in testcases:
        string_case = list(map(str,testcase))
        output += str(len(testcase)) + " " + " ".join(string_case) + '\n'
    return output
    """
"""
    print(str(len(testcases)) + '\n')
    for testcase in testcases:
        string_case = list(map(str,testcase))
        print(str(len(testcase)) + " " + " ".join(string_case) + '\n')
"""

class linkedlist:
    def __init__(self,length):
        self.length = length
        self.prev = None
        self.next = None
        self.head = None
        self.tail = None
    
def least_testcases():
    n,k = map(int,input().split())
    counts = Counter(map(int,input().split()))
    lengths = list(counts.keys())
    lengths.sort()
    restrictions = [0] + list(map(int,input().split()))
    
    for i in range(len(lengths)):
        lengths[i] = linkedlist(lengths[i])
    lengths[0].tail = True
    lengths[-1].head = True
    if len(lengths) > 1:
        lengths[0].next = lengths[1]
        lengths[-1].prev = lengths[-2]
    for i in range(1,len(lengths)-1):
        lengths[i].prev = lengths[i-1]
        lengths[i].next = lengths[i+1]

    restrictions2 = [restrictions[node.length] for node in lengths]
    #set up list that can be used to point to length that still has space
    first_size = [None for i in range(restrictions2[0] + 1)]
    curr = restrictions2[-1]
    first_size[curr] = len(restrictions2)-1
    for i in range(len(restrictions2)-2,-1,-1):
        new = restrictions2[i]
        if new != curr:
            for j in range(curr+1, new+1):
                first_size[j] = i
            curr = new
            
    testcases = []
    added = 0
    head = lengths[-1]
    tail = lengths[0]
    while added < n:
        curr_node = head
        testcase = []
        while True:
            curr_len = curr_node.length
            max_curr = restrictions[curr_len]-len(testcase)
            if counts[curr_len] > max_curr:
                testcase += [curr_len]*max_curr
                added += max_curr
                counts[curr_len] -= max_curr
            else:
                testcase += [curr_len]*counts[curr_len]
                added += counts[curr_len]
                counts[curr_len] = 0
                if curr_node.head == True:
                    if curr_node.tail == True:
                        pass
                    else:
                        curr_node.prev.head = True
                        head = curr_node.prev
                elif curr_node.tail == True:
                    if curr_node.head == True:
                        pass
                    else:
                        curr_node.next.tail == True
                        tail = curr_node.next
                else:
                    curr_node.next.prev = curr_node.prev
            if restrictions[1] == len(testcase):
                break
            elif curr_node.tail == True:
                break
            elif restrictions[curr_node.prev.length] == len(testcase):
                curr_node = lengths[first_size[len(testcase) + 1]]
            else:
                curr_node = curr_node.prev
            
        
        testcases.append(testcase)
    print(str(len(testcases)) + '\n')
    for testcase in testcases:
        string_case = list(map(str,testcase))
        print(str(len(testcase)) + " " + " ".join(string_case) + '\n')
    
"""
    output = str(len(testcases)) + '\n'
    for testcase in testcases:
        string_case = list(map(str,testcase))
        output += str(len(testcase)) + " " + " ".join(string_case) + '\n'
    return output

print(least_testcases())
"""
least_testcases()
