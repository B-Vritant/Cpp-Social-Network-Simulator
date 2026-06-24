# C++ Social Network Simulator

**A command-line social network backend simulator built in C++ using AVL Trees, Graphs, and BFS.**

This project demonstrates key data structure and algorithm concepts through a simplified social media system.

## Features

- User Management (`ADD_USER`)
- Friendship System (`ADD_FRIEND`, `LIST_FRIENDS`)
- Smart Friend Suggestions (`SUGGEST_FRIENDS`)
- Degrees of Separation (`DEGREES_OF_SEPARATION`)
- Post Management (`ADD_POST`, `OUTPUT_POSTS`)

## Data Structures & Algorithms Used

- **AVL Trees** – For maintaining sorted friends and timestamped posts
- **Graph** – Adjacency list using `unordered_map`
- **BFS** – For finding shortest path (degrees of separation)
- **Mutual Friends Algorithm** – For recommendations

## Tech Stack
- C++17
- STL Containers

## Compilation & Execution

bash
g++ -std=c++17 main.cpp -o simulator
./simulator

## Example Usage

```bash
ADD_USER alice
ADD_USER bob
ADD_FRIEND alice bob
SUGGEST_FRIENDS alice 5
DEGREES_OF_SEPARATION alice bob
ADD_POST alice Hello world!
OUTPUT_POSTS alice 5
EXIT
```

## Data Structures & Algorithms Used

- **AVL Trees** – Self-balancing Binary Search Trees for efficient friend lists and timestamp-ordered posts.
- **Graph Representation** – `unordered_map<string, AVLtree>` for storing user connections.
- **Breadth-First Search (BFS)** – Used to calculate degrees of separation between users.
- **Mutual Friends Algorithm** – Used for generating friend recommendations.

## Tech Stack

- **C++17**
- **Standard Template Library (STL)**
- **Custom AVL Tree Implementation**

---

## Compilation & Execution

```bash
g++ -std=c++17 main.cpp -o simulator
./simulator
```

## Learning Outcomes

- Deep understanding of AVL Tree operations (rotations, balancing, insertion)
- Graph modeling and traversal algorithms
- Command-line interface design and input parsing in C++
- Memory management with custom data structures

## Author

**B Vritant**

Made with ❤️ for learning Data Structures & Algorithms.

## Roadmap

- Persistent storage using files
- Better input validation and error messages
- Modular code structure
- Unit tests
