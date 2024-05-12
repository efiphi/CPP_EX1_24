# Graph and Algorithms Project


## Prerequisites

    - C++ Compiler (GCC or Clang recommended)
    - CMake
    - Doctest for unit testing

# Overview

 This project implements a graph representation through an adjacency matrix and includes algorithms that operate on these graphs. It is designed to handle both directed and undirected, as well as weighted and unweighted graphs.
 
## Documentation
### Files and Classes

    - Graph.hpp / Graph.cpp: Manage the representation of graphs via an adjacency matrix. Methods include loading graphs and displaying their structure.

    - Algorithms.hpp / Algorithms.cpp: Contain the Algorithms class that implements various graph-related algorithms, such as cycle detection and checking graph bipartiteness.

    - Makefile: Provides rules for compiling the project and associated utilities. It includes targets for building the project, cleaning up binaries, running tests, and more.

    - Test.cpp: Includes unit tests for verifying the functionality of the graph algorithms implemented in the Algorithms class. It uses the doctest framework for test cases.

    - TestCounter.cpp: Typically used for additional test implementations or for counting specific algorithm operations, although specifics would depend on your project's requirements.

### Methods in Graph

    - loadGraph(const std::vector<std::vector<int>>& matrix): Initializes the graph with a given adjacency matrix.
    - printGraph(): Displays the graph in a human-readable format.

### Methods in Algorithms

    - isConnected(const Graph &g): Checks if the graph is connected.
    - *std::vector<int> shortestPath(const ariel::Graph& g, size_t start, size_t end)**: Computes the shortest path from start to end vertex.
    - std::vector<int> isContainsCycle(const ariel::Graph& g): Determines if the graph contains any cycles.
    - std::vector<std::set<int>> isBipartite(const Graph&): Determines if the graph is bipartite and returns the dividing sets of vertices.
    - void negativeCycle(const ariel::Graph& g): Checks for the presence of any negative weight cycles in the graph.

# Usage
## Commands

    - make: Compiles the entire project and generates executable files.
    - make clean: Removes all compiled objects and executable files to clean the project directory.
    - make run: Executes the main program to demonstrate graph functionalities.
    - make test: Runs all unit tests to ensure algorithm correctness and stability.
This setup ensures that all components are functioning correctly and efficiently, adhering to modern C++ standards and practices.



# מטלה 1 - גרפים (Classes and Namespaces)

המטרה שלכם במטלה הזאת היא ליצור מחלקה שמייצגת גרף ולממש אלגוריתמים על הגרפים (זה הזמן להזכר בקורס אלגוריתמים 1).

במטלה הזאת הייצוג של הגרף שלכם יתבצע בעזרת מטריצת שכנויות - https://he.wikipedia.org/wiki/%D7%9E%D7%98%D7%A8%D7%99%D7%A6%D7%AA_%D7%A9%D7%9B%D7%A0%D7%95%D7%AA.

הגרף יכול להיות גרף מכוון ולא מכוון וגם גרף ממושקל. מטריצת השכנויות חייבת להיות מטריצה ריבועית.

עליכם לכתוב את הקבצים הבאים:

```
Graph.cpp
Algorithms.cpp
```

הקובץ `Graph.cpp` מכיל מחלקה המייצגת גרף.
המחלקה מכילה את הפעולות `loadGraph` המקבלת מטריצת שכנויות וטוענת אותה לתוך הגרף ו-`printGraph` שמדפיסה את הייצוג של הגרף (הפורמט לבחירתכם, ראו דוגמה ב-`Demo.cpp`).

הקובץ `Algorithms.cpp` מכיל מימושים לאלגוריתמים על גרפים. ביניהם:

- `isConnected(g)` - האלגוריתם מקבל גרף ומחזיר 1 אם הגרף קשיר (אחרת מחזיר 0).
- `shortestPath(g,start,end)` - האלגוריתם מקבל גרף, קודקוד התחלה וקודקוד סיום ומחזיר את המסלול הקל ביותר (במקרה שהגרף לא ממושקל - הקצר ביותר) בין שני הקודקודים. במידה ואין מסלול כזה, האלגוריתם יחזיר -1.
- `isContainsCycle(g)` - האלגוריתם מקבל גרף ומדפיס מעגל כלשהו. אם לא קיים מעגל בגרף, האלגוריתם יחזיר 0.
- `isBipartite(g)` - האלגוריתם מקבל גרף ומחזיר את החלוקה של הגרף לגרף דו-צדדי. אם אי אפשר לחלק את הגרף, האלגוריתם יחזיר 0.
- `negativeCycle(g)` - האלגוריתם מקבל גרף ומוצא מעגל שלילי (כלומר מעגל שסכום המשקלים של הצלעות שלילי). אם לא קיים מעגל כזה, האלגוריתם ידפיס שלא קיים מעגל שלילי.

הקובץ `Demo.cpp` מכיל דוגמאות של קלטים ופלטים.
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. כמו כן, בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש). אי עמידה בהנחיות תגרור הפחתה בציון. בהצלחה!
  
