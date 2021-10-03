class StackWithArray {
    private var stackArray: IntArray = IntArray(100)
    private var top = -1

    fun push(data: Int) : Boolean {
        if(sizeOfStack() < 100) {
        	stackArray[++top] = data
            return true
        } else {
            print("stack is overflow")
          	return false  
        }
   	}

    fun pop() : Int {
        if(top == -1) {
            print("Stack is underflow")
            return -1
        }
        return stackArray[top--]
    }

    fun peek() : Int {
        if(top == -1) {
            print("Stack is underflow")
            return -1
        }
        return stackArray[top]
    }

    fun isEmpty() : Boolean {
        return (top == -1)
    }
    
    fun sizeOfStack() : Int {
        return top
    }
    
    fun display() {
        for(ele in 0..top) {
            print(stackArray[ele])
            print(" ")
        }
    }

}

fun main(arg: Array<String>) {

    val stack = StackWithArray()
    stack.push(1)
    println(stack.isEmpty())
    stack.pop()
    println(stack.isEmpty())
    stack.push(1)
    stack.push(2)
    println(stack.peek())
    stack.display()
}
