class Solution(object):
    def transpose(self, matrix):
        transposed_matrix = list(map(list, zip(*matrix)))
        return transposed_matrix
        
        