# Final Project (CA5) for CS 240: Data Structures and Algorithms
Binghamton University

Team Name: Let's Go Mets

Collaborators: Fotis Antonatos, Travis Hoa, and Liam Lyu

## Project Info
This program simulates an [`Extended Friendship Network` (EFN)](friendships.hpp) containing users who listen to music. Using various data structures, a user can query the network and see what songs are popular among his friends and the friends of his friends. There is no limit to the network size. A user can accept song recommendations from `N` radius around him.
## Specifications
See [CHECKLIST.md](CHECKLIST.md)
## Data Structures
A requirement of this project is for all data to be accessible within O(log(n)) time complexity. For that reason, we chose these data structures:
 - [Binary Search Tree](bstree.hpp): Stores [`Users`](user.hpp) and the global [`Song`](song.hpp) library.
    - Allows searching for data in log(n) time.
    - Linked Nodes Implementation
 - [Max Heap](maxheap.hpp): Contains songs organized by their playcount
    - Allows retrieval of most popular song in constant time.
    - Array Implementation
 - [Unweighted, Undirected Graph](friendships.hpp): Represents the `Extended Friendship Network`
 ## Algorithms
 Necessary for the proper implementation of the above data structures:
 - Breadth First Search: Implemented in [`FindUserRadius()`](friendships.hpp)
    - `FindUserRadius()` returns the distance of a provided `User` from the source `User`. i.e. The number of friends between them.
    - Supports the counting of a Song's plays for users within the EFN Radius.
    - Uses a FIFO Queue