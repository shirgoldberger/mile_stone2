# mile_stone2
# 
Openning connection with clients using socket and solving their problems using algorithms. 

 [Link to our project's repository](https://github.com/Eliadsellem/mile_stone2.git)

## General Description

This program has differents implements for openning a server to income client. 
The server receive a generic problem from the client, solve it and return the solution back to the client.
Solving the problem is doing by using a OOP Searcher class that implements an individual algorithm such as: 
 - Best First Search
 - Breadth First Search
 - Depth First Search
 - A* (A Star)
 
After testing all the algorithms we discover that the Best First Search won all the others. 
As a result in our main function we are running a parallel server that use the Best First Search algorithm to solve the given problems.
The problems given from the client for now are graphs thet represented as matrix but can easily be transfer to any other representation 
by implement new Searchable class and relevents Searcher class 

## Collaborators

This program was developed by [Eliadsellem](https://github.com/Eliadsellem) and [shirgoldberger](https://github.com/shirgoldberger), CS students from Bar-Ilan university, Israel.


## Features
-The program is openning a server that can accept multi clients in parallel. 
we have to posibilites of choosing a port, or by using a defualt port 5600,
or by using a given port as an input to the running program.
we are running the server with the open function that recieve this port and a ClientHandler object as parameters.

-ClientHandler is a class that is responsible to all the recive problem's and return solution's protocols.
The client handler using composite design pattern and containing a CacheManager and Solver objects.

-CacheManager is an object that is responsible to save solution's data in any way he likes.
-FileCacheManager implement CacheManager by saving the solution's date in a unique files.
the name are decided by a hash function to the problem.
 
 -Searcher is responsible to the algorithm.
 The searcher have search method that recieve a Searchable object as a parameter, solve and returning the
 path from the initilal state to the goal state.
 

## Setup and execute

You can choose Port as desired, but you should keep LocalHost IP if you're running both the program and the client on the same PC.

1. Complie the program code:

    ```bash
    g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
    ```

2. Run a.out with an input port you want the server will be listening on.
    ```bash
   ./a.out port
    ```
3. The program will wait for client's connections recieved and return back data.

## Comments

1. Please find the file: "mile_ston.pdf" in the repository and you can find statistic about all the fourth algorithms
that been run on 10 diffrents matrix in diffrents size between 10-50.

2. Please find the file: "matrix.txt" as an example of a problem matrix.
- need to have "\n" after each sentence.
- 3 lines before the end should include the initial state.
- 2 lines before the end should include the goal state.
- The last sentence should be "end\n".

