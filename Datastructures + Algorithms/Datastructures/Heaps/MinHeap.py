class MinHeap:
  def __init__(self, heap = [None]):
    self.heap = heap
    self.count = len(heap)- 1 

  def parent_idx(self, idx):
    return idx // 2  

  def left_child_idx(self, idx):
    return idx * 2

  def right_child_idx(self, idx):
    return idx * 2 + 1

  def child_present(self, idx):
    return self.left_child_idx(idx) <= self.count

  def get_smaller_child_idx(self, idx):
    if self.left_child_idx(idx) == self.count:
      return self.left_child_idx(idx)
    else:
      left_child = self.heap[self.left_child_idx(idx)]
      right_child = self.heap[self.right_child_idx(idx)]
      if left_child < right_child:
        return self.left_child_idx(idx)
      else:
        return self.right_child_idx(idx)

  def add(self, element):
    self.heap.append(element)
    self.count += 1
    self.heapify_up()

  def get_min(self):
    if self.count == 0:
      return None
    else: 
      min = self.heap[1]
      self.heap[1] = self.heap[-1]
      self.heap.pop()
      self.count -= 1
      self.heapify_down()
      return min

  def heapify_up(self):
    idx = self.count
    while self.parent_idx(idx) > 0:
      if self.heap[self.parent_idx(idx)] > self.heap[idx]:
        parent = self.heap[self.parent_idx(idx)]
        self.heap[self.parent_idx(idx)] = self.heap[idx]
        self.heap[idx] = parent
        idx = self.parent_idx(idx)
      else:
        break 

  def heapify_down(self):
    idx = 1
    while self.child_present(idx):
      smaller_child_idx = self.get_smaller_child_idx(idx)
      if self.heap[idx] > self.heap[smaller_child_idx]:
        child = self.heap[smaller_child_idx]
        self.heap[smaller_child_idx] = self.heap[idx]
        self.heap[idx] = child 
        idx = smaller_child_idx
      else:
        break
