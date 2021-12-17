#pragma once
template <class T>
class Stack 
{
private:
		class Node
		{
		public:
			T value;
			Node* prev;
			Node(const T element) :value(element), prev(0) {}
		};
		Node* current;
		size_t size_stack;
	public:
		// Consrtructor 
		Stack() :current(0), size_stack(0) {}

		// Desrtructor 
		~Stack()
		{
			while (current)
				pop();
		}

		// Add element to stack
		void push(const T element)
		{
			Node* temp = current;
			current = new Node(element);
			current->prev = temp;
			size_stack++;
		}

		// Remove top element from stack
		void pop()
		{
			if (size_stack) {
				Node* temp = current->prev;
				delete current;
				current = temp;
				size_stack--;
			}
			else {
				throw std::out_of_range("stack is empty");
			}
		}

		// Get the element on the top of the stack
		T top()
		{
			if (empty())
			{
				throw std::out_of_range("Empty");
			}
			else return current->value;
		}

		// Check stack's empty
		bool empty()
		{
			return !size_stack;
		}

		// Get the size of stack
		size_t size()
		{
			return size_stack;
		}
		
};
