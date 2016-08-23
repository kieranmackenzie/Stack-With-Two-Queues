/*
 *  Created on: May 22, 2016
 *      Author: Kieran Mackenzie
 *      Implementation of a stack with two queues
 */

#include <iostream>
#include <time.h> // this is so we can analyze the running time
#include <queue>
using namespace std;

class theStack {

	public:
		void push(int x); //we will push integer values into our stack
		int pop(); // We will return what we popped to ensure it is working like a stack
		void printQ(); // This was added so I could debug easier
		theStack() // Constructor
		{}

	private:
		queue<int> firstQ; //Our two queues
		queue<int> secondQ;

};



int main(){
	theStack stack; //Our object called stack
    int option, popped; //user option, and value we popped being initialized

	while(true)
	{
     cout << "What do you want to do?" << endl;
     cout << "1 to push(x), 2 to pop(), and 3 to print out the queue and end program" << endl;
     cin >> option; //accepting the user input
     switch(option){

     case 1:
    	 int value; //initializing the value to catch the user input
    	 cout << "What value do you want to push?" << endl;
    	 cin >> value; //accepting user input
    	 stack.push(value); // pushing that value onto the stack
    	 break;
    case 2:
    	 popped = stack.pop(); // getting the value that was popped
    	 cout << "The value popped was: " << popped << endl;
    	 cout << endl;
    	 break;
    case 3:
    	 stack.printQ();
    	 cout << "\nReminder, this shows the queue, not the stack we are implementing with the two queues" << endl;
    	 cout << "Program Ending..." << endl;
    	 return 0;
    default:
    	 cout << "You entered an invalid number" << endl;
     }
	}
	return 0;
}


int theStack::pop(){
	clock_t tStart = clock();
	int temp,popped,check;
	check = firstQ.size();
	if(check >= 1) //making sure the queue isnt empty
	{
		while(firstQ.size() > 1)
		{
		temp = firstQ.front(); // holding the value of the first in the queue
		firstQ.pop(); // getting rid of it
	    secondQ.push(temp); //Piping that value into the secondQ
		}

	popped = firstQ.front(); //saving the final value left in the firstQ
	firstQ.pop(); // getting rid of it

		while(!secondQ.empty())
		{
		int temp = secondQ.front(); // rea-dding the values back into the firstQ
		secondQ.pop();
		firstQ.push(temp);
		}

	}
	else
	{
		cout << "Empty queue, nothing to pop!" << endl;
		return 0;
	}

    printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return popped;

}

void theStack::push(int value)
{
  clock_t tStart = clock();

  firstQ.push(value); // Simply adding the value into the first Q

  printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}

void theStack::printQ(){
	//This function destroys our firstQ in order to print out the queue
	//But its OK because the user is aware it will end the program
	int i;
	if(firstQ.size() != 0)
	{
		while(!firstQ.empty()) //While it isnt empty
		{
			i = firstQ.front(); // Print the element at the front
			cout << i << " ";
			firstQ.pop(); // Get rid of that element, then move to the next
		}
	}
	else
	{
	cout <<"Empty queue, nothing to print!" << endl;
	}
}

