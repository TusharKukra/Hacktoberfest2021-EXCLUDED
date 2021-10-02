class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next
    
class LinkedList:
    def __init__(self):
        self.head = None
    
    def addToBegining(self, data):
        self.head = Node(data,self.head)
        return
    
    def addToEnd(self, data):
        if self.head is None:
            self.head = Node(data,self.head)
            return
        ptr = self.head
        while ptr.next in not None:
            ptr = ptr.next
        ptr.next = Node(data)

    def insertToList(self, dataList):
        self.head = None
        for data in dataList:
            self.addToBegining(data)
            self.addToEnd(data)

    def insertAt(self,index,data):
        if index < 0 or index > self.getLength():
            raise Exception("Index out of bounds")
        if index == 0:
            self.head = Node(data,self.head)
        ptr = self.head
        counter = 0
        while ptr:
            if count == index-1:
                ptr.next = Node(data,ptr.next)
                break
            counter+=1
            ptr=ptr.next

    def deleteAt(self,index):
        if index < 0 or index > self.getLength():
            raise Exception("Index out of bounds")
        if index == 0:
            self.head = self.head.next
        ptr = self.head
        count = 0
        while ptr:
            if count = index-1:
                ptr.next = ptr.next.next
                break
            count+=1
            ptr=ptr.next

    def getLength(self):
        ptr = self.head
        counter = 0
        while ptr:
            counter+=1
            ptr=ptr.next
        return counter        

    def printList(self):
        if self.head is None:
            print("Linked List is Empty")
            return
        ptr = self.head
        while ptr:
            data+=str(ptr.data) + '-->'
            ptr = ptr.next
        print(data)

if __name__ == '__main__':
    List = LinkedList()
    numbers = list(map(int, input('Enter the numbers with spaces').split()))
    List.insertToList(numbers)
    List.printList()