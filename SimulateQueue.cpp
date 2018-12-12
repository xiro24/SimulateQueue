#include <iostream>
#include <stack>
#include <vector>
#include <string>

/*have stacks as a queue for sorting both alphabets and numbers*/
/*kina like tower of hanoi*/
/*queue is FIFO
stack is LIFO*/

void Separate(std::vector<char> &values);
void PopQueue(std::vector<int> &numbers, std::vector<char> &alpha); 
	
int main() {
	/*to contain values*/
	std::vector<char> values;
	
	char input;
	std::cout << "enter Stacks here // enter 'e' to finish" << std::endl;
	std::cin >> input;
	while (input != 'e') {
		values.push_back(input);
		std::cin >> input;
	}
	Separate(values);
	return 0;
}

void Separate(std::vector<char> &values) {
	std::vector<int> numbers;
	std::vector<char> alpha;
	int i;
	for (i =0 ; i < values.size() ; i++) {
		if (std::isdigit(values[i])) {
			int g = values[i] - '0';
			numbers.push_back(g);
		} else {
			alpha.push_back(values[i]);	
		}
	}
	std::cout << "numbers" << std::endl;
	for (i =0; i < numbers.size() ; i++) {
		std::cout << numbers[i] << std::endl; 
	}
	std::cout << "alpha" << std::endl;
	for (i =0; i < alpha.size() ; i++) {
		std::cout << alpha[i] << std::endl;
	}
	PopQueue(numbers,alpha);
}

void PopQueue(std::vector<int> &numbers, std::vector<char> &alpha) {
	/*to simulate queue -- you could make this into a template function*/
	std::stack<int> stack1;
	std::stack<int> stack2;
	int i;
	for (i=0; i < numbers.size() ; i++) {
		stack1.push(numbers[i]);
	}
	while (!stack1.empty()) {
		int s = stack1.top();
		stack2.push(s);	
		stack1.pop();
	}
	stack2.pop(); /*pops first in first out*/
	std::cout << "stack2 -- queue" << std::endl;
	while (!stack2.empty()) {
		std::cout << stack2.top();
		stack2.pop();
	}
	/*pops the stack while printing*/
}

