# Our first Git & C++ team project

**Take-home assignment · 13 students**

We are building one calculator together. Each student adds one small method, opens a Pull Request (PR), and reviews a classmate's work.

Only three project files matter:

- `Calculator.h` — a small class with private numbers and public methods.
- `main.cpp` — creates an object and displays results. The HTML is already provided.
- `README.md` — everything you need for the assignment.

Use your usual C++ IDE to run `main.cpp`. Enter two small numbers, such as `12 3`. You see results in the console, and the program saves **calculator.html** in its working folder. Open that file in a browser.

The page displays results calculated by C++. To change the numbers, run the program again and refresh the page. It is a results page, so you do not type numbers into the browser. No HTML, JavaScript, web server, or extra tools are part of the exercise.

## 1. The little bit of OOP we need

- **Class:** `Calculator` describes a calculator.
- **Object:** `Calculator calculator(first, second);` creates one.
- **Constructor:** receives the two numbers when the object is created.
- **Private data:** `a` and `b` are used inside the class.
- **Public methods:** `calculator.add()` asks the object to do something.

Your new method goes inside the class, under `public:`. It can use `a` and `b` directly. No inheritance, pointers, or advanced C++ is needed.

For example, the existing `add()` method returns `a + b`. The existing line `addRow(page, "Addition", calculator.add());` displays that result. Follow that same pattern for your task. Leave the provided display helper and HTML alone.

## 2. Your task

One-input methods use A and ignore B. Use small numbers; numeric overflow is outside this beginner exercise.

| Student | Add this public method | What it returns | Test with A=12, B=3 | Student to review |
| --- | --- | --- | --- | --- |
| 01 | `double square()` | A × A | 144 | 02 |
| 02 | `double cube()` | A × A × A | 1728 | 01 |
| 03 | `double absolute()` | Positive magnitude of A; use if/else | 12; also try A=-12 → 12 | 04 |
| 04 | `double negate()` | A with its sign reversed | -12; also try A=-12 → 12 | 03 |
| 05 | `double minimum()` | The smaller of A and B; use if/else | 3 | 06 |
| 06 | `double maximum()` | The larger of A and B; use if/else | 12 | 05 |
| 07 | `double average()` | (A + B) / 2 | 7.5 | 08 |
| 08 | `double percentage()` | B percent of A: A × B / 100 | 0.36 | 07 |
| 09 | `double doubleA()` | A × 2 | 24 | 10 |
| 10 | `double halfA()` | A / 2 | 6; also try A=5 → 2.5 | 09 |
| 11 | `double increment()` | A + 1, without changing stored A | 13 | 12 |
| 12 | `double decrement()` | A - 1, without changing stored A | 11 | 13 |
| 13 | `double sumOfSquares()` | A × A + B × B | 153 | 11 |

Every student makes just **two changes**:

1. Add your method in `Calculator.h`.
2. Add one matching `addRow(...)` line in `main.cpp`, using your method and a readable label. For example, Student 01's line calls `calculator.square()` and labels it `Square`.

Where to put them:

- Students **01/02** replace their `PAIR_A` comment with their method, and `ROW_A` with their display line.
- Students **03/04** do the same at `PAIR_B` and `ROW_B`.
- Students **05/06** do the same at `PAIR_C` and `ROW_C`.
- Students **07–13** add methods above `OTHER_METHODS` and rows above `OTHER_ROWS`, keeping those comments.

Work from your own starting branch. Keep all existing methods and rows. Do not edit another student's method.

**Check your work:** run with `12 3`, then `0 0`, then `-4 2`. Work out your expected answer before checking the result. Minimum/Maximum students also test equal numbers, such as `3 3`. Check that Addition still works and your new row appears in the browser after a refresh. Division by zero should show a message.

## 3. Git steps — everyone does these

The instructor gives you the repository URL. Everyone uses the same repository. Replace `REPOSITORY_URL` and `student01` below with your actual URL and your student number. If the cloned folder has another name, use that name in `cd`.

```sh
git clone REPOSITORY_URL
cd Calculator
git switch main
git pull origin main
git switch -c student01
```

Now make your two changes and test them. Then:

```sh
git status
git diff
git add Calculator.h main.cpp
git commit -m "Add my calculator method"
git push -u origin student01
```

On GitHub, click **Compare & pull request**. Choose **main** as the base. Write your method name and two test results in the description. Ask your assigned reviewer to review. The instructor coordinates the merge order below; do not merge early.

## 4. Review a classmate on GitHub

Review the student listed in the last column of your task table. Students 01–10 review in pairs. Students 11–13 use a review circle: **11 reviews 12, 12 reviews 13, and 13 reviews 11**. Everyone writes one PR and receives one review.

Open the assigned PR on GitHub, read the code and test results, and submit a review. Use PR comments to ask questions and reply to feedback; you do not need to work at the same time.

- Does it run and show the correct answer?
- Is the method name easy to understand?
- Does it handle zero and negative inputs for this task?
- Are the old methods and rows still there?

A useful comment: “Please try A=-4. Absolute should return 4.”

A useful reply: “Fixed the negative case and tested -4 and 0.”

If a fix is needed, the author edits their own branch, tests, commits, and pushes again. The same PR updates. The reviewer checks again and approves. If everything is correct, approve and say which inputs you checked; do not invent a problem. Each author replies to acknowledge the review.

## 5. A conflict is part of the activity

Two people may edit the same place. Git asks us to decide how both changes fit together.

Before your PR is merged, update your branch from main when the instructor asks:

```sh
git switch student02
git fetch origin
git merge origin/main
```

If Git reports a conflict, open the named file. Between `<<<<<<<`, `=======`, and `>>>>>>>` you will see the two versions. **Keep both students' methods and both display rows**, then remove the marker lines. Check that no method or row is duplicated.

```sh
git add Calculator.h main.cpp
git commit -m "Keep both calculator features"
# Run again and check both features.
git push
```

If Git merged automatically, skip the extra commit. Your assigned reviewer checks the combined result. Merge the PR on GitHub only when the instructor confirms your turn. Do not use force push.

## 6. Merge coordination

The instructor provides repository access and publishes the starter on `main`. Everyone must create their own branch from that starter before the first PR merges. Use your usual C++ IDE; compiler downloads and setup are not part of this assignment.

The instructor coordinates merges through GitHub comments. Students can implement, test, and review at home independently. Wait for your merge turn so everyone keeps the shared features.

**Three planned conflicts:** students in each listed pair replace the same starting comment with different valid code.

| Merge first | Then update this branch | Preserve and verify |
| --- | --- | --- |
| 01 | 02 | Square=144 and Cube=1728 for A=12 |
| 03 | 04 | Absolute=12 and Negate=-12 for A=12 |
| 05 | 06 | Minimum=3 and Maximum=12 for A=12, B=3 |

Students 02/04/06 wait until the corresponding first PR has merged before merging main into their branches. Resolve conflicts using section 5, keeping both methods and both rows. Ask for help through PR comments if needed, and explain to your reviewer what you preserved.

Merge order: **01 → 03 → 05 → 02 → 04 → 06 → 07 → 08 → 09 → 10 → 11 → 12 → 13**. These are student IDs, not GitHub PR numbers. Before each merge, the author updates from current main, keeps all methods and rows, tests, pushes, and gets reviewer approval. Other shared edits may conflict too; use the same steps. If Git combines changes automatically, check the result anyway.

## 7. What to submit

Each student submits:

- A link to their PR, with the method name and expected/actual results for `12 3`, `0 0`, and `-4 2`.
- A screenshot of the generated browser page showing their feature.
- A review on their assigned classmate's PR and replies to feedback on their own PR.
- A short PR comment explaining any conflict they resolved. If there was no conflict, say that the update merged automatically and confirm the existing features still work.

After all approved PRs are merged, pull the final project:

```sh
git switch main
git pull origin main
```

Run it again and refresh `calculator.html`. Check that your feature and the four original operations still work and no conflict markers remain. If all 13 tasks merged, the page has **17 operation rows**. Do not commit the generated HTML; C++ recreates it from the shared code.
