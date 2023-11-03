# Quaternary Search Tree (QST)

## Introduction

A Quaternary Search Tree (QST) is a data structure with nodes having up to four children. The goal of this project is to design a template-based Quaternary Search Tree, which allows for the insertion and deletion of elements according to specific rules. The key of an element determines which child it is sent to for insertion. The rules are as follows:

- Elements in the range [0, k/2) are recursively sent to the leftmost child for insertion.
- Elements in the range [k/2, k) are recursively sent to the second child for insertion.
- Elements in the range [k, 2k) are recursively sent to the third child for insertion.
- Elements greater than or equal to 2k are recursively sent to the rightmost child for insertion.

## Implementation

### Template-Based Class

We have created a template-based class that provides the following functionalities:

1. *Constructor*: Accepts an array of objects to initialize the QST.
2. *Preorder and Postorder Printing*: The class allows you to print the elements in the tree in both preorder and postorder traversals.
3. *Insertion Function*: You can insert additional elements into the QST. The insertion process follows the rules mentioned above.
4. *Deletion Function*: You can delete an element with a specific key.
5. *Menu-Based System*: The program is controlled by a menu-based system, allowing the user to choose the desired operation.

### Exception Handling and Assertion

We utilize exception handling to ensure that user options do not create undefined situations. We have defined custom exceptions to handle specific error scenarios. We also use assertions to ensure the validity of user inputs and the integrity of the data structure.

## 

## Usage

Here's how you can use the QST implementation:

1. Initialize the QST with an array of objects.
2. Use the menu-based system to perform operations such as insertion, deletion, and printing.
3. Observe the behavior of the QST as it organizes and manages the data according to the specified rules.

## Getting Started

You can start using this project by cloning this repository.
This file contains a make file which can be used to compile.

## Creator
OwnerShip and copyrights:
Mo Rashid 
MT23047
## Resources 
Geeks for Geeks 
OpenAI 

# command to run make file 
make -f makefile_name 
./main
./non_premptive
