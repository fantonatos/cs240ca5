# CA5
Team Name: Let's Go Mets
Members: Fotis Antonatos, Liam Lyu, Travis Hoa
[See the Piazza post for project design](https://piazza.com/class/kkwzvpyvhe5349?cid=640).

## A. Making and Breaking Friendships `20 points`
 - [X] `10 pts` Add users, make friendships, break friendships, and show friendships
 - [X] `10 pts` Friendships of a user should be stored with his instance
## B. Adding and Moving Songs `35 points`
 - [X] `5 pts` Add songs to system library and show them
 - [ ] `5 pts` Add songs from system library to primary user library (via recommend), show the primary user's library
 - [ ] `5 pts` Show main system library after some songs have been moved to primary user's library
 - [ ] `5 pts` Remove song from primary user's library, show that they go back to system, with count of 0
 - [ ] `15 pts` Song containers should be indexed by a BST (BinarySearchTree) to look up faster than O(N)
## C. Tracking Listens `30 points`
 - [X] `5 pts` Show that you can build a network of friends, set EFN to 2
 - [X] `5 pts` Have users within the network listen to songs, causing the counts on the heap to go up (and show the songs w/ their plays)
 - [X] `5 pts` When users outside the network (EFN) listen to the song, the count should not go up
 - [X] `15 pts` Implement a BFS (BreadthFirstSearch)
## D. Making Recommendations `35 points`
 - [X] `5 pts` Build up a heap using add song and listen, show the heap (displaying the songs and counts)
 - [ ] `10 pts` Get recommendations for many songs at a time. Show that they come off the top of the heap and are added to user library
 - [ ] `5 pts` Listen to a song after is has been moved within the heap to show that the BST can still find it and increase listen count
 - [ ] `15 pts` Show that code for this functionality is implemented in a heap. Show the spot in the code where heap updates the BST index.