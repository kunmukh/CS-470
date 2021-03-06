//File: buffer.h                                                              
//Buffer header file that contains function definition   
//-----------------------------------------------------------------             
// Class: CS 470                     Instructor: Dr. Deborah Hwang              
// Assignment:    Thread Synchronization Project 
// Date assigned:  1/24/2018                  
// Programmer:    Kunal Mukherjee    Date completed: 2/7/2018 

typedef int buffer_item;
#define BUFFER_SIZE 5

#include <iostream>

buffer_item buffer [BUFFER_SIZE];

int insert_item(buffer_item item);
int remove_item(buffer_item* item);
using namespace std;

//insert item into buffer
//return 0 if succesful, otherwise
//return -1 indicating an error condition
int insert_item(buffer_item item){

	//empty space
	int empty = 0;

	//trying to find the first empty spot
	while ((buffer[empty] != -1) && (empty < BUFFER_SIZE)){
		empty++;
	}

	//if empty spot  cannot be found -1 is returned
	if (empty == BUFFER_SIZE)
		return -1;
	else{
		buffer[empty] = item;
		return 0;
	}

}

//remove an object from buffer
//place it in item
//return 0 if succesful, otherwise
//return -1 indicating an error condition
int remove_item(buffer_item *item){
	//empty space
	int empty = 0;

	while ((buffer[empty] == -1) && (empty < BUFFER_SIZE)){
		empty++;
	}

	if (empty == BUFFER_SIZE)
		return -1;
	else{
	  
	  *item = buffer[empty];
	  buffer[empty] = -1;
	  return 0;
	}

}

//print out the buffer
void printBuffer(void){
  cout << "[ " ;
  for (int i = 0; i < BUFFER_SIZE; i++){
    cout << buffer[i] << " ";
  }
  cout << " ]" << endl;
}
