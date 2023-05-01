using System;
using System.Collections.Generic;

namespace Data_Structures__C_Sharp_
{
    public class RoundedStack<T>
    {
        public RoundedStack(int capacity)
        {
            if (capacity <= 0)
                throw new ArgumentOutOfRangeException("Capacity must exceed 0.");

            this.capacity = capacity;
            this.size = 0;
        }

        public int Count { get => size; }

        // Pushes a new object to the top of the stack.
        // If the capacity is exceeded, the bottom of the stack is dropped.
        public void Push(T value)
        {
            stack.Push(value);
            ++size;

            if (size > capacity)
            {
                // TODO O(n) can be improved upon using a doubly linked list but we'd
                // have to implement this from scracth too as it's not part of .NET
                var arr = stack.ToArray();
                stack.Clear();
                for(int i = arr.Length - 2; i>=0; --i)
                    stack.Push(arr[i]);
                --size;
            }
        }

        // Removes and returns the object at the top of the stack.
        // Throws InvalidOperationException if stack is empty.
        public T Pop()
        {
            --size;
            return stack.Pop();
        }

        public void Clear()
        {
            stack.Clear();
            size = 0;
        }

        public T[] ToArray()
        {
            return stack.ToArray();
        }

        private Stack<T> stack = new Stack<T>();
        private int size = 0;
        private int capacity = 0;
    }
}
