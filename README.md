# Programming Checkpoint 2: Wildfire

## Programming Outcomes:
Develop a C++ class that uses recursion to simulate a wildfire

## Project Overview:
In this programming checkpoint, you will be required to create a class which
will simulate a wildfire. The class can read a description of a map of cells
where each cell can be either a Tree (**T**), Fire (**F**), or Water (**W**).
Starting a fire in a **T** cell would turn it to an **F** as well as spread the
fire to the adjacent (top, down, right, and left) **T** cells. The fire would
stop spreading in a given direction when it encounters a **W** cell.

## Project Requirements:
You are provided with a test suite in folder [test/](test/).
Your implementation must pass all tests provided in this test suite:
1. The test suites are:
    1. [test-1-wildfire](test/test-1-wildfire.cpp)
    1. [test-2-wildfire](test/test-2-wildfire.cpp)
    1. [test-3-wildfire](test/test-3-wildfire.cpp)

    The wildfire test suite is broken into three sets for grading purposes.

1. Running all of these tests must be possible by running `make` or '
   `make test-all`.
1. Your project will lose points if memory leaks exist.
1. Your project should use recursion.

## Input format
The ``Wildfire`` class takes a string that contains a description of the map of
cells as the input. The first two lines of the string contain the number of
rows and columns of the map. Each following line represents a row of cells.
Each cell contains either a tree (**T**), water (**W**) or a fire(**F**). You
can assume that the input string is always properly formatted.

Example map:
```
5
4
W W W W
W T T W
W T T W
W W W W
W T T W
```

As a string:
```
string map = "5\n4\nW W W W\nW T T W\nW T T W\nW W W W\nW T T W\n"
```

## UML of the classes
![UML of Wildfire class](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuKhEIImkLWZFp4b9oonALQZcqatEI2nIqD9Io4qiuDBDp2jHg81GbLpQS6KQnIKfLbR59KMPUUaWXMcPEQcQoF90JXqA3soX6vW7DbD70MocffL2MNvc2fTsPbvQlWQGXsGmLosNGsfU2j2L0000)

Text version for accessibility (- means private, + means public):
```
class Wildfire {
-char ** map
-int x
-int y
+Wildfire (std::string mapfile)
+Wildfire ()
+~Wildfire ()
+startFire (int x, int y): void
+info(): std::string
}
```

- employ a dynamic 2d array of char values that holds 'W', 'T', 'F' to
  represent water, tree and fire respectively
- The default constructor will create a 5x5 map with all trees.
- The parameterized constructor will take a string to create the map.
- The ``startFire`` method will set a fire at the specified position and spread
  it out to neighboring positions recursively. It should return if the position
  is out of range, or is not a tree. This method are designed to be recursive
  so it spread out by calling itself on neighboring positions.
- The ``info`` method should provide a map as string to show the result after
  the spread of fire. You can display the result like this example of a 3x4 all
  fire map: ``"F F F F \nF F F F \nF F F F "`` **You may notice the space after
  the last F. It is on purpose to allow an easier loop to generate the text.**
  The use of string steam is strongly recommended.

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you
   "accepted" the assignment.
    1. After pushing, with `git push origin main`, visit the web URL of your
       repository to verify that your code is there. If you don't see the code
       there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your
   score for your submission.
    1. The auto-grading build should begin automatically when you push your
       code to GitHub.
    2. If your program will not compile, you will not get credit

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects
  received after that time will get a grade of zero.
- Please review the academic honesty policy.
    - Note that viewing another student's solution, whether in whole or in part,
      is considered academic dishonesty.
    - Also note that submitting code obtained through the Internet or other
      sources, whether in whole or in part, is considered academic dishonesty.
    - All programs submitted will be reviewed for evidence of academic
      dishonesty, and all violations will be handled accordingly.

## Grade break-down
- 50 pts - Auto-grading

## Checking Auto-grading Results:

After you push your code, GitHub will automatically run tests on your
submission. To view the results:

1. On your GitHub repository page, click the :arrow_forward: **Actions** tab at
   the top
2. Click on the most recent workflow run (it will show your commit message)
3. Wait until the run finishes (showing either ✅ or ❌)
4. Scroll down to "Autograding summary" section to see the summary
5. It will display:
   - **Points:** Your score (e.g., 10/10)
   - ✅ All tests passed! or ❌ Some tests failed
6. If tests failed, click the "Autograding" button above to see detailed logs:
   - Expand the **education/autograding@v1** step to see which tests failed
   - Look for :x: marks to identify specific failures
