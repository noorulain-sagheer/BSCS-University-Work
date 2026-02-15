import math
b=2
def minimax(curDepth, nodeIndex, maxTurn, scores, targetDepth):
 
    if curDepth == targetDepth:
        return scores[nodeIndex]
    
    if maxTurn: 
        return max(
            minimax(curDepth + 1, nodeIndex * b, False, scores, targetDepth),
            minimax(curDepth + 1, nodeIndex * b + 1, False, scores, targetDepth)
            
           
        )
    else: 
        return min(
            minimax(curDepth + 1, nodeIndex * b, True, scores, targetDepth),
            minimax(curDepth + 1, nodeIndex * b + 1, True, scores, targetDepth)
            
           
        )

scores = [3, 5, 2,9]

treeDepth = int(math.log(len(scores), b))

print("The optimal value is:", end=" ")
print(minimax(0, 0, True, scores, treeDepth))  

