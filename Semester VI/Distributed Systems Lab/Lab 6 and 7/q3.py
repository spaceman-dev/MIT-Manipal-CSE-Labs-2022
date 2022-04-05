import sys
noOfNodes = int(sys.argv[1])
initiatorNode = int(sys.argv[2])

def bully_algorithm():
    print('Node: ' + str(initiatorNode) +' notices the coordinator: ' + str(noOfNodes)+' has failed')
    biggerNodes = []
    for i in range(initiatorNode+1, noOfNodes):
        print('sent ELECTION message to: ' + str(i))
        biggerNodes.append(i)
    for i in biggerNodes:
        print(str(i)+' sent OK message to ' + str(initiatorNode))
        if len(biggerNodes) != 1:
            i = biggerNodes[0]
    for j in range(i+1, noOfNodes):
        print(str(i)+' sent ELECTION message to '+str(j))
    for k in range(i+1, noOfNodes):
        print(str(k)+' sent OK message to '+str(i))
    biggerNodes.remove(i)
    newCoordinatorNode = biggerNodes[0]
    for i in range(0, newCoordinatorNode):
        print(str(newCoordinatorNode)+' sends COORDINATOR message to '+str(i))

if __name__ == '__main__':
    bully_algorithm()