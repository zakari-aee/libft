# Linked List: The Complete Guide (From Zero to LeetCode)

> Goal: understand linked lists from the **memory level**, then be able to solve **any LeetCode linked list problem** using a small set of patterns.
>
> - Part 1-4: low-level understanding in **C** (memory, pointers, malloc, free)
> - Part 5-9: LeetCode patterns and full solutions in **JavaScript**
> - Part 10: practice roadmap and cheat sheet

---

## Table of Contents

1. [Memory basics: what is really happening](#1-memory-basics-what-is-really-happening)
2. [Array vs Linked List](#2-array-vs-linked-list)
3. [Anatomy of a node](#3-anatomy-of-a-node)
4. [Full singly linked list in C](#4-full-singly-linked-list-in-c)
5. [Variants: doubly, circular, sentinel](#5-variants-doubly-circular-sentinel)
6. [Complexity table](#6-complexity-table)
7. [LeetCode setup (JavaScript)](#7-leetcode-setup-javascript)
8. [The 8 core patterns](#8-the-8-core-patterns)
9. [Solved LeetCode problems (full code)](#9-solved-leetcode-problems-full-code)
10. [Cheat sheet, common bugs, roadmap](#10-cheat-sheet-common-bugs-roadmap)

---

## 1. Memory basics: what is really happening

### 1.1 Memory is a giant row of numbered boxes

Your RAM is a huge list of bytes. Each byte has an **address** (a number).

```
Address:   0x1000  0x1001  0x1002  0x1003  0x1004  0x1005 ...
Content:   [ 42 ]  [ 00 ]  [ 00 ]  [ 00 ]  [ 07 ]  [ 00 ] ...
```

An `int` usually takes **4 bytes**. A pointer on a 64-bit machine takes **8 bytes**.

### 1.2 A pointer is just a variable that stores an address

```c
int x = 42;        // x lives somewhere, e.g. at address 0x1000
int *p = &x;       // p stores 0x1000
printf("%d", *p);  // *p = "go to the address stored in p" -> 42
```

```
 x                p
+------+        +--------+
|  42  | <------| 0x1000 |
+------+        +--------+
@0x1000          @0x2000
```

- `&x` = "address of x"
- `*p` = "the value at the address p holds" (dereference)
- `NULL` = "points to nothing" (address 0). Dereferencing NULL crashes (segfault).

### 1.3 Stack vs Heap

| | Stack | Heap |
|---|---|---|
| Used for | local variables, function calls | memory you ask for manually |
| Lifetime | automatic, dies when function returns | lives until **you** `free()` it |
| Size | small | large |
| How | `int x;` | `malloc(...)` / `free(...)` |

Linked list nodes live on the **heap**, because they must survive after the function that created them returns.

### 1.4 malloc and free

```c
int *p = malloc(sizeof(int));  // ask the OS for 4 bytes on the heap
*p = 10;
free(p);                       // give it back
p = NULL;                      // good habit: avoid dangling pointer
```

Rules:
- Every `malloc` needs exactly one `free`. If you forget: **memory leak**.
- Never use memory after `free`: **use-after-free** bug.
- Never `free` twice: **double free** bug.
- Always check `malloc` result: it returns `NULL` if it fails.

---

## 2. Array vs Linked List

### Array = one continuous block

```
index:     0      1      2      3
address: 0x100  0x104  0x108  0x10C
        [ 10 ] [ 20 ] [ 30 ] [ 40 ]
```

- Access `arr[i]` is instant: `address = start + i * size` -> **O(1)**
- Insert in the middle: shift everything -> **O(n)**
- Size is fixed (or you need to reallocate and copy)

### Linked list = scattered nodes connected by pointers

```
head
 |
 v
[10 | *]--->[20 | *]--->[30 | *]--->[40 | NULL]
 @0x500      @0x120      @0x9A0      @0x340
```

Nodes can be **anywhere** in memory. Each node stores the address of the next one.

- Access the i-th element: you must walk from head -> **O(n)**
- Insert/delete after a known node: just change pointers -> **O(1)**
- Grows and shrinks freely, one node at a time

**Key idea: the list is only the chain of pointers. If you lose the head, you lose the whole list.**

---

## 3. Anatomy of a node

A node holds **data** and a **pointer to the next node**.

```c
typedef struct s_node
{
    int             data;
    struct s_node   *next;
} t_node;
```

Memory picture of one node (64-bit):

```
+-----------+-----------+
| data (4B) | next (8B) |     (+ 4 bytes padding, total 16 bytes)
+-----------+-----------+
```

Creating one:

```c
t_node *node_new(int data)
{
    t_node *n = malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->data = data;   // same as (*n).data = data
    n->next = NULL;
    return (n);
}
```

`->` means "go through the pointer, then take the field".

### Build a list by hand (3 nodes)

```c
t_node *a = node_new(10);
t_node *b = node_new(20);
t_node *c = node_new(30);
a->next = b;
b->next = c;
t_node *head = a;
```

```
head ---> a[10|*]---> b[20|*]---> c[30|NULL]
```

### Traverse

```c
t_node *cur = head;
while (cur != NULL)
{
    printf("%d -> ", cur->data);
    cur = cur->next;      // move forward
}
printf("NULL\n");
```

This `while (cur)` loop is the skeleton of 80% of linked list code.

---

## 4. Full singly linked list in C

Copy this into `list.c` and run: `cc -Wall -Wextra -Werror list.c && ./a.out`

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int             data;
    struct s_node   *next;
} t_node;

/* ---------- create ---------- */
t_node *node_new(int data)
{
    t_node *n = malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->data = data;
    n->next = NULL;
    return (n);
}

/* ---------- print ---------- */
void print_list(t_node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* ---------- length ---------- */
int list_len(t_node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return (len);
}

/* ---------- push front: O(1) ---------- */
/* We pass t_node **head (pointer to the head pointer)
   because the head itself changes. */
int push_front(t_node **head, int data)
{
    t_node *n = node_new(data);
    if (!n)
        return (-1);
    n->next = *head;   // new node points to old head
    *head = n;         // head now points to new node
    return (0);
}
```

```
Before:  head ---> [20|*]---> [30|NULL]
Step 1:  n[10|*] ---> [20|*]---> [30|NULL]      (n->next = *head)
Step 2:  head ---> n[10|*]---> [20|*]---> ...   (*head = n)
```

```c
/* ---------- push back: O(n) ---------- */
int push_back(t_node **head, int data)
{
    t_node *n = node_new(data);
    if (!n)
        return (-1);
    if (*head == NULL)       // empty list: new node becomes head
    {
        *head = n;
        return (0);
    }
    t_node *cur = *head;
    while (cur->next)        // stop at LAST node (not NULL)
        cur = cur->next;
    cur->next = n;
    return (0);
}

/* ---------- insert at index: O(n) ---------- */
int insert_at(t_node **head, int idx, int data)
{
    if (idx < 0)
        return (-1);
    if (idx == 0)
        return (push_front(head, data));
    t_node *cur = *head;
    for (int i = 0; i < idx - 1 && cur; i++)   // go to node BEFORE idx
        cur = cur->next;
    if (!cur)
        return (-1);                            // idx too large
    t_node *n = node_new(data);
    if (!n)
        return (-1);
    n->next = cur->next;    // 1) new node takes the rest of the list
    cur->next = n;          // 2) previous node points to new node
    return (0);
}
```

**ORDER MATTERS when inserting.** If you do `cur->next = n` first, you lose the rest of the list.

```
Insert X after A:
A ---> B ---> C

1) X->next = A->next      A ---> B ---> C
                          X ---> B
2) A->next = X            A ---> X ---> B ---> C
```

```c
/* ---------- delete first node with value: O(n) ---------- */
/* Pointer-to-pointer trick: no special case for head. */
int delete_value(t_node **head, int value)
{
    t_node **pp = head;
    while (*pp)
    {
        if ((*pp)->data == value)
        {
            t_node *tmp = *pp;
            *pp = tmp->next;     // skip over the node
            free(tmp);
            return (0);
        }
        pp = &(*pp)->next;       // move to the "next" field of current node
    }
    return (-1);
}

/* ---------- find: O(n) ---------- */
t_node *find(t_node *head, int value)
{
    while (head)
    {
        if (head->data == value)
            return (head);
        head = head->next;
    }
    return (NULL);
}

/* ---------- reverse: O(n) time, O(1) space ---------- */
void reverse(t_node **head)
{
    t_node *prev = NULL;
    t_node *cur = *head;
    t_node *next;
    while (cur)
    {
        next = cur->next;   // 1) save the next node
        cur->next = prev;   // 2) flip the arrow
        prev = cur;         // 3) move prev forward
        cur = next;         // 4) move cur forward
    }
    *head = prev;           // prev is the new head
}

/* ---------- free the whole list ---------- */
void free_list(t_node **head)
{
    t_node *tmp;
    while (*head)
    {
        tmp = (*head)->next;   // save next BEFORE freeing
        free(*head);
        *head = tmp;
    }
}

int main(void)
{
    t_node *head = NULL;

    push_back(&head, 20);
    push_back(&head, 30);
    push_front(&head, 10);
    insert_at(&head, 2, 25);
    print_list(head);          // 10 -> 20 -> 25 -> 30 -> NULL

    delete_value(&head, 20);
    print_list(head);          // 10 -> 25 -> 30 -> NULL

    reverse(&head);
    print_list(head);          // 30 -> 25 -> 10 -> NULL

    printf("len = %d\n", list_len(head));
    free_list(&head);
    return (0);
}
```

### Why `t_node **head`?

C passes arguments **by value** (a copy). If you pass `t_node *head`, the function changes only its own copy. To change the real head variable, pass **its address**: `t_node **`.

```
main:   head  (stores address of first node)
          ^
          |  &head
push_front(t_node **head, ...)   --> can modify main's head
```

Reverse trace (step by step):

```
Start:  prev=NULL  cur=1->2->3->NULL

Iter 1: next=2   1->NULL      prev=1  cur=2
Iter 2: next=3   2->1->NULL   prev=2  cur=3
Iter 3: next=NULL 3->2->1->NULL prev=3 cur=NULL
End:    head = prev = 3->2->1->NULL
```

---

## 5. Variants: doubly, circular, sentinel

### 5.1 Doubly linked list

Each node has `prev` and `next`.

```c
typedef struct s_dnode
{
    int             data;
    struct s_dnode  *prev;
    struct s_dnode  *next;
} t_dnode;
```

```
NULL <--[10]<-->[20]<-->[30]--> NULL
```

Pros: walk both directions; delete a node in O(1) if you have the node pointer.
Cons: more memory, more pointers to keep correct.

Delete node `n` from a doubly list:

```c
if (n->prev) n->prev->next = n->next;
if (n->next) n->next->prev = n->prev;
free(n);
```

Insert `n` after `a`:

```c
n->prev = a;
n->next = a->next;
if (a->next) a->next->prev = n;
a->next = n;
```

### 5.2 Circular linked list

Last node points back to head instead of NULL.

```
 +---------------------------+
 v                           |
[10]--->[20]--->[30]---------+
```

Loop condition changes: stop when `cur->next == head`, not when NULL.

### 5.3 Sentinel (dummy) node, the most useful trick for LeetCode

Add a fake node before the real head so that **inserting/deleting the head is no longer a special case**.

```
dummy ---> [1] ---> [2] ---> [3]
  ^
  prev starts here
```

You'll return `dummy.next` at the end. You'll use this in about 50% of problems.

---

## 6. Complexity table

| Operation | Array | Singly LL | Doubly LL |
|---|---|---|---|
| Access by index | O(1) | O(n) | O(n) |
| Search by value | O(n) | O(n) | O(n) |
| Insert at head | O(n) | **O(1)** | **O(1)** |
| Insert at tail | O(1) amortized | O(n) (O(1) with tail pointer) | O(1) with tail pointer |
| Insert after known node | O(n) | **O(1)** | **O(1)** |
| Delete head | O(n) | **O(1)** | **O(1)** |
| Delete a known node | O(n) | O(n) (need prev) | **O(1)** |
| Extra memory per element | 0 | 1 pointer | 2 pointers |

---

## 7. LeetCode setup (JavaScript)

LeetCode gives you this class (already defined, don't rewrite it in the submission):

```js
class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}
```

Helpers for testing locally (not part of submission):

```js
function fromArray(arr) {
    const dummy = new ListNode();
    let tail = dummy;
    for (const v of arr) {
        tail.next = new ListNode(v);
        tail = tail.next;
    }
    return dummy.next;
}

function toArray(head) {
    const out = [];
    while (head) {
        out.push(head.val);
        head = head.next;
    }
    return out;
}

// console.log(toArray(reverseList(fromArray([1,2,3,4,5]))));  // [5,4,3,2,1]
```

Notes:
- `head` can be `null` (empty list). **Always handle it first.**
- In LeetCode the list is given as `head`, a pointer to the first node. There is no "size" given.
- `node.next = null` marks the end.

### The 5 questions to ask for every problem

1. Can the list be empty or have 1 node? (edge cases)
2. Will the **head** change? -> use a **dummy node**.
3. Do I need the **previous** node? -> keep a `prev` pointer.
4. Do I need the **middle / k-th from end / cycle**? -> **fast & slow pointers**.
5. Can I do it in O(1) extra space? (interviewers love that) -> pointer manipulation instead of array/map.

**Always draw the list on paper and trace the pointers.** 90% of bugs are lost references.

---

## 8. The 8 core patterns

### Pattern 1: Traversal

```js
let cur = head;
while (cur) {
    // use cur.val
    cur = cur.next;
}
```

Use `while (cur.next)` when you need to stop at the **last** node.

### Pattern 2: Dummy node

```js
const dummy = new ListNode(0, head);
let prev = dummy;
// ... modify using prev.next ...
return dummy.next;
```

Use when the head may be removed, replaced, or when building a new list.

### Pattern 3: Build a new list (tail pointer)

```js
const dummy = new ListNode();
let tail = dummy;
// for each new value:
tail.next = new ListNode(val);
tail = tail.next;
return dummy.next;
```

### Pattern 4: Reverse (prev / cur / next)

```js
let prev = null, cur = head;
while (cur) {
    const next = cur.next;  // save
    cur.next = prev;        // flip
    prev = cur;             // advance prev
    cur = next;             // advance cur
}
return prev;
```

Memorize this. It's the base of many hard problems.

### Pattern 5: Fast & slow pointers (Floyd)

```js
let slow = head, fast = head;
while (fast && fast.next) {
    slow = slow.next;         // 1 step
    fast = fast.next.next;    // 2 steps
}
// slow is at the middle (second middle if even length)
```

Uses:
- middle of list
- detect cycle (they meet inside the cycle)
- find cycle start
- k-th from end (fast starts k steps ahead, both move 1 step)

### Pattern 6: Two lists, two pointers (merge)

Compare heads, attach the smaller, advance. Used in merge sorted lists, merge sort, merge k lists, add two numbers.

### Pattern 7: Hash map / set

When O(n) extra space is fine: detect cycle with a Set of visited nodes, copy list with random pointer using Map(old -> new), LRU cache with Map + doubly list.

### Pattern 8: Recursion

A list is "one node + a smaller list". Recursive thinking: trust the recursive call on `head.next`, then fix the current node.

```js
function reverseList(head) {
    if (!head || !head.next) return head;     // base case
    const newHead = reverseList(head.next);   // reverse the rest
    head.next.next = head;                    // flip the link
    head.next = null;
    return newHead;
}
```

Costs O(n) stack space. Fine for interviews, but iterative is safer for very long lists.

### Quick pattern chooser

| If the problem says... | Use |
|---|---|
| "remove / delete nodes", head may change | dummy node |
| "reverse", "palindrome", "reorder" | reverse pattern |
| "middle", "cycle", "nth from end" | fast & slow |
| "merge", "add numbers", "sorted" | two pointers + tail |
| "copy", "random pointer", "LRU", "duplicates" | hash map |
| "partition", "odd even", "split" | two dummy lists |
| "k groups", "between left and right" | reverse a sublist with dummy |

---

## 9. Solved LeetCode problems (full code)

Each solution has: idea, code, complexity. Numbers are LeetCode problem IDs.

---

### 206. Reverse Linked List (Easy)

Idea: flip every arrow with `prev / cur / next`.

```js
var reverseList = function (head) {
    let prev = null, cur = head;
    while (cur) {
        const next = cur.next;
        cur.next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
};
```

Time O(n), Space O(1). (Recursive version is in Pattern 8.)

---

### 21. Merge Two Sorted Lists (Easy)

Idea: dummy + tail, always attach the smaller head.

```js
var mergeTwoLists = function (l1, l2) {
    const dummy = new ListNode();
    let tail = dummy;
    while (l1 && l2) {
        if (l1.val <= l2.val) {
            tail.next = l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }
    tail.next = l1 || l2;   // attach the leftover (already sorted)
    return dummy.next;
};
```

Time O(n+m), Space O(1) (we reuse nodes).

---

### 876. Middle of the Linked List (Easy)

Idea: fast moves 2, slow moves 1. When fast ends, slow is at the middle. For even length, returns the **second** middle (as the problem asks).

```js
var middleNode = function (head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
};
```

---

### 141. Linked List Cycle (Easy)

Idea: if there is a cycle, fast eventually catches slow (like two runners on a circular track).

```js
var hasCycle = function (head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) return true;
    }
    return false;
};
```

Time O(n), Space O(1). (Set version: O(n) space.)

---

### 142. Linked List Cycle II: find where the cycle starts (Medium)

Idea (Floyd): after slow and fast meet, put one pointer back at `head`. Move both **one step at a time**: they meet exactly at the cycle start.

Why: let `a` = distance head -> cycle start, `b` = distance cycle start -> meeting point, `c` = cycle length. Fast travelled twice as much as slow, which gives `a = (k*c) - b` for some integer k, so walking `a` more steps from the meeting point lands on the cycle start.

```js
var detectCycle = function (head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            let p = head;
            while (p !== slow) {
                p = p.next;
                slow = slow.next;
            }
            return p;
        }
    }
    return null;
};
```

---

### 19. Remove Nth Node From End of List (Medium)

Idea: dummy + two pointers with a gap of `n` nodes. When the front pointer reaches the end, the back pointer is right before the node to delete.

```js
var removeNthFromEnd = function (head, n) {
    const dummy = new ListNode(0, head);
    let fast = dummy, slow = dummy;
    for (let i = 0; i < n + 1; i++) fast = fast.next;  // gap of n+1
    while (fast) {
        fast = fast.next;
        slow = slow.next;
    }
    slow.next = slow.next.next;   // delete
    return dummy.next;
};
```

The dummy handles the case where the head itself is removed. One pass, O(1) space.

---

### 83. Remove Duplicates from Sorted List (Easy)

```js
var deleteDuplicates = function (head) {
    let cur = head;
    while (cur && cur.next) {
        if (cur.val === cur.next.val) cur.next = cur.next.next;
        else cur = cur.next;
    }
    return head;
};
```

---

### 82. Remove Duplicates from Sorted List II (Medium)

Remove **all** nodes that have duplicates (keep only distinct values). Head can be removed -> dummy.

```js
var deleteDuplicates = function (head) {
    const dummy = new ListNode(0, head);
    let prev = dummy, cur = head;
    while (cur) {
        if (cur.next && cur.val === cur.next.val) {
            const v = cur.val;
            while (cur && cur.val === v) cur = cur.next;  // skip all copies
            prev.next = cur;
        } else {
            prev = cur;
            cur = cur.next;
        }
    }
    return dummy.next;
};
```

---

### 203. Remove Linked List Elements (Easy)

```js
var removeElements = function (head, val) {
    const dummy = new ListNode(0, head);
    let cur = dummy;
    while (cur.next) {
        if (cur.next.val === val) cur.next = cur.next.next;
        else cur = cur.next;
    }
    return dummy.next;
};
```

Note: only advance `cur` when you did NOT delete (the new `cur.next` may also match).

---

### 237. Delete Node in a Linked List (Medium)

You are given only the node to delete (not the head, and it's never the tail). Trick: copy the next node into this one, then skip the next.

```js
var deleteNode = function (node) {
    node.val = node.next.val;
    node.next = node.next.next;
};
```

---

### 234. Palindrome Linked List (Easy)

Idea (O(1) space): find the middle, reverse the second half, compare both halves.

```js
var isPalindrome = function (head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    // reverse from slow
    let prev = null, cur = slow;
    while (cur) {
        const next = cur.next;
        cur.next = prev;
        prev = cur;
        cur = next;
    }
    // compare
    let left = head, right = prev;
    while (right) {
        if (left.val !== right.val) return false;
        left = left.next;
        right = right.next;
    }
    return true;
};
```

(This modifies the list. If you must restore it, reverse the second half again.)

---

### 160. Intersection of Two Linked Lists (Easy)

Idea: two pointers. When one reaches the end, it jumps to the **other** list's head. Both travel `lenA + lenB` steps, so they meet at the intersection (or both become `null`).

```js
var getIntersectionNode = function (headA, headB) {
    let a = headA, b = headB;
    while (a !== b) {
        a = a ? a.next : headB;
        b = b ? b.next : headA;
    }
    return a;
};
```

Compare **nodes** (`===`), not values.

---

### 2. Add Two Numbers (Medium)

Digits are stored in reverse order, so we add from the head, like on paper, with a carry.

```js
var addTwoNumbers = function (l1, l2) {
    const dummy = new ListNode();
    let tail = dummy, carry = 0;
    while (l1 || l2 || carry) {
        const sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
        carry = Math.floor(sum / 10);
        tail.next = new ListNode(sum % 10);
        tail = tail.next;
        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }
    return dummy.next;
};
```

Don't forget the final carry (`999 + 1`). Related: **445. Add Two Numbers II** (digits not reversed -> use two stacks or reverse first).

---

### 92. Reverse Linked List II (Medium)

Reverse only the nodes from position `left` to `right` (1-indexed).

Idea: walk `prev` to the node before `left`. Then repeatedly take the node after `cur` and insert it right after `prev` (head insertion).

```js
var reverseBetween = function (head, left, right) {
    const dummy = new ListNode(0, head);
    let prev = dummy;
    for (let i = 1; i < left; i++) prev = prev.next;

    const cur = prev.next;               // stays pointing to the original left node
    for (let i = 0; i < right - left; i++) {
        const nxt = cur.next;
        cur.next = nxt.next;             // cut nxt out
        nxt.next = prev.next;            // put nxt at the front of the segment
        prev.next = nxt;
    }
    return dummy.next;
};
```

Trace for `1->2->3->4->5`, left=2, right=4:

```
start:      1 -> [2] -> 3 -> 4 -> 5          prev=1, cur=2
move 3:     1 -> 3 -> 2 -> 4 -> 5
move 4:     1 -> 4 -> 3 -> 2 -> 5
```

---

### 24. Swap Nodes in Pairs (Medium)

```js
var swapPairs = function (head) {
    const dummy = new ListNode(0, head);
    let prev = dummy;
    while (prev.next && prev.next.next) {
        const a = prev.next;
        const b = a.next;
        a.next = b.next;   // a skips b
        b.next = a;        // b points to a
        prev.next = b;     // prev points to b
        prev = a;          // a is now the end of the swapped pair
    }
    return dummy.next;
};
```

```
prev -> a -> b -> c      becomes      prev -> b -> a -> c
```

---

### 25. Reverse Nodes in k-Group (Hard)

Idea: for each group of k nodes: check that k nodes exist, reverse them, reconnect with the previous group and the next group.

```js
var reverseKGroup = function (head, k) {
    const dummy = new ListNode(0, head);
    let groupPrev = dummy;

    while (true) {
        // find the k-th node of this group
        let kth = groupPrev;
        for (let i = 0; i < k && kth; i++) kth = kth.next;
        if (!kth) break;                       // fewer than k nodes left

        const groupNext = kth.next;
        // reverse the group; first node will point to groupNext
        let prev = groupNext, cur = groupPrev.next;
        while (cur !== groupNext) {
            const nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        const oldFirst = groupPrev.next;       // now the last of the group
        groupPrev.next = kth;                  // kth is the new first
        groupPrev = oldFirst;
    }
    return dummy.next;
};
```

Time O(n), Space O(1).

---

### 143. Reorder List (Medium)

`L0 -> L1 -> ... -> Ln` becomes `L0 -> Ln -> L1 -> Ln-1 -> ...`

Idea (3 steps you must know): **find middle, reverse second half, merge alternately.**

```js
var reorderList = function (head) {
    if (!head || !head.next) return;

    // 1) find middle (end of first half)
    let slow = head, fast = head;
    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // 2) reverse second half
    let prev = null, cur = slow.next;
    slow.next = null;                  // cut the list in two
    while (cur) {
        const nxt = cur.next;
        cur.next = prev;
        prev = cur;
        cur = nxt;
    }

    // 3) merge alternately
    let a = head, b = prev;
    while (b) {
        const aNext = a.next, bNext = b.next;
        a.next = b;
        b.next = aNext;
        a = aNext;
        b = bNext;
    }
};
```

---

### 148. Sort List (Medium)

Merge sort is the best for linked lists: O(n log n) time. Split at the middle, sort each half, merge.

```js
var sortList = function (head) {
    if (!head || !head.next) return head;

    // split
    let slow = head, fast = head.next;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    const mid = slow.next;
    slow.next = null;

    return merge(sortList(head), sortList(mid));
};

function merge(a, b) {
    const dummy = new ListNode();
    let tail = dummy;
    while (a && b) {
        if (a.val <= b.val) { tail.next = a; a = a.next; }
        else                { tail.next = b; b = b.next; }
        tail = tail.next;
    }
    tail.next = a || b;
    return dummy.next;
}
```

Note `fast = head.next` so that for 2 nodes `slow` ends on the first node and the split is never empty (avoids infinite recursion).

---

### 138. Copy List with Random Pointer (Medium)

Each node has `next` and `random`. Make a **deep copy**.

Idea (hash map): map each original node to its clone, then wire `next` and `random` using the map.

```js
var copyRandomList = function (head) {
    if (!head) return null;
    const map = new Map();

    // pass 1: create clones
    for (let cur = head; cur; cur = cur.next) {
        map.set(cur, new Node(cur.val));
    }
    // pass 2: connect pointers
    for (let cur = head; cur; cur = cur.next) {
        map.get(cur).next = cur.next ? map.get(cur.next) : null;
        map.get(cur).random = cur.random ? map.get(cur.random) : null;
    }
    return map.get(head);
};
```

O(n) space. **O(1) space version**: interleave clones (`A -> A' -> B -> B'`), set `A'.random = A.random.next`, then split the lists apart.

---

### 23. Merge k Sorted Lists (Hard)

Idea: divide and conquer, merge lists in pairs (like merge sort). Reuses `merge` from problem 148.

```js
var mergeKLists = function (lists) {
    if (lists.length === 0) return null;
    while (lists.length > 1) {
        const merged = [];
        for (let i = 0; i < lists.length; i += 2) {
            const a = lists[i];
            const b = i + 1 < lists.length ? lists[i + 1] : null;
            merged.push(merge(a, b));
        }
        lists = merged;
    }
    return lists[0];
};
```

Time O(N log k), where N = total nodes. (Alternative: a min-heap of k heads, same complexity.)

---

### 61. Rotate List (Medium)

Idea: measure length, make the list circular, break it at the right place.

```js
var rotateRight = function (head, k) {
    if (!head || !head.next || k === 0) return head;

    let len = 1, tail = head;
    while (tail.next) { tail = tail.next; len++; }

    k %= len;
    if (k === 0) return head;

    tail.next = head;                       // make circular
    let newTail = head;
    for (let i = 0; i < len - k - 1; i++) newTail = newTail.next;
    const newHead = newTail.next;
    newTail.next = null;                    // break the circle
    return newHead;
};
```

---

### 86. Partition List (Medium)

Nodes `< x` first, then `>= x`, keeping original relative order. Use **two dummy lists** and join.

```js
var partition = function (head, x) {
    const smallDummy = new ListNode(), bigDummy = new ListNode();
    let small = smallDummy, big = bigDummy;
    for (let cur = head; cur; cur = cur.next) {
        if (cur.val < x) { small.next = cur; small = small.next; }
        else             { big.next = cur;   big = big.next; }
    }
    big.next = null;                 // IMPORTANT: avoid creating a cycle
    small.next = bigDummy.next;
    return smallDummy.next;
};
```

---

### 328. Odd Even Linked List (Medium)

Group odd-indexed nodes first, then even-indexed nodes, in place.

```js
var oddEvenList = function (head) {
    if (!head || !head.next) return head;
    let odd = head, even = head.next;
    const evenHead = even;
    while (even && even.next) {
        odd.next = even.next;
        odd = odd.next;
        even.next = odd.next;
        even = even.next;
    }
    odd.next = evenHead;
    return head;
};
```

---

### 146. LRU Cache (Medium, very common in interviews)

Need `get` and `put` in O(1). Combine:
- **Hash map**: key -> node (O(1) lookup)
- **Doubly linked list**: order of usage (most recent near head, least recent near tail). Doubly, because removing a node in O(1) needs its `prev`.

Dummy `head` and `tail` sentinels remove all edge cases.

```js
class DNode {
    constructor(key = 0, val = 0) {
        this.key = key;
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    constructor(capacity) {
        this.cap = capacity;
        this.map = new Map();
        this.head = new DNode();   // sentinel: most recent side
        this.tail = new DNode();   // sentinel: least recent side
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    _remove(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    _addFront(node) {
        node.next = this.head.next;
        node.prev = this.head;
        this.head.next.prev = node;
        this.head.next = node;
    }

    get(key) {
        if (!this.map.has(key)) return -1;
        const node = this.map.get(key);
        this._remove(node);
        this._addFront(node);       // now most recently used
        return node.val;
    }

    put(key, value) {
        if (this.map.has(key)) {
            const node = this.map.get(key);
            node.val = value;
            this._remove(node);
            this._addFront(node);
            return;
        }
        if (this.map.size === this.cap) {
            const lru = this.tail.prev;   // least recently used
            this._remove(lru);
            this.map.delete(lru.key);
        }
        const node = new DNode(key, value);
        this.map.set(key, node);
        this._addFront(node);
    }
}
```

That's why `DNode` stores the `key`: when evicting a node, we must delete it from the map.

---

### 707. Design Linked List (Medium)

Implement `get`, `addAtHead`, `addAtTail`, `addAtIndex`, `deleteAtIndex`. This is the C code from Part 4, in JS, with a dummy head and a size counter.

```js
class MyLinkedList {
    constructor() {
        this.dummy = new ListNode(0);
        this.size = 0;
    }

    get(index) {
        if (index < 0 || index >= this.size) return -1;
        let cur = this.dummy.next;
        for (let i = 0; i < index; i++) cur = cur.next;
        return cur.val;
    }

    addAtHead(val) { this.addAtIndex(0, val); }
    addAtTail(val) { this.addAtIndex(this.size, val); }

    addAtIndex(index, val) {
        if (index < 0 || index > this.size) return;
        let prev = this.dummy;
        for (let i = 0; i < index; i++) prev = prev.next;
        prev.next = new ListNode(val, prev.next);
        this.size++;
    }

    deleteAtIndex(index) {
        if (index < 0 || index >= this.size) return;
        let prev = this.dummy;
        for (let i = 0; i < index; i++) prev = prev.next;
        prev.next = prev.next.next;
        this.size--;
    }
}
```

---

## 10. Cheat sheet, common bugs, roadmap

### 10.1 Code snippets to memorize

```js
// reverse
let prev = null, cur = head;
while (cur) { const n = cur.next; cur.next = prev; prev = cur; cur = n; }
return prev;

// middle
let slow = head, fast = head;
while (fast && fast.next) { slow = slow.next; fast = fast.next.next; }

// cycle
if (slow === fast) ...

// dummy
const dummy = new ListNode(0, head); ... return dummy.next;

// merge
tail.next = a || b;

// k-th from end: fast goes k ahead, then both move
```

### 10.2 Common bugs (and fixes)

| Bug | Cause | Fix |
|---|---|---|
| `Cannot read properties of null (reading 'next')` | accessed `.next` on null | check `cur && cur.next` before accessing |
| Infinite loop / "Time limit exceeded" | created a cycle (forgot `node.next = null`) | cut the tail after splitting/rearranging |
| Lost half of the list | overwrote `next` before saving it | `const next = cur.next` first |
| Wrong answer when head is removed | no dummy node | use dummy |
| Off by one on "n-th from end" | gap of `n` instead of `n+1` with dummy | draw it with a 1-2 node list |
| Modified input unexpectedly | e.g. reversed half in palindrome | restore it if required |
| Compared values instead of nodes | `a.val === b.val` instead of `a === b` | intersection/cycle problems compare nodes |

In C also watch for: memory leak (no `free`), use-after-free, double free, not checking `malloc`, forgetting `**` when the head can change.

### 10.3 Interview checklist

1. Clarify: sorted? duplicates? can it have a cycle? in-place allowed? singly or doubly?
2. Say the brute force first (array / hash set), then improve to O(1) space.
3. Draw 3-5 nodes. Test: empty list, 1 node, 2 nodes, even length, odd length.
4. Name your pointers clearly: `prev`, `cur`, `next`, `slow`, `fast`, `tail`, `dummy`.
5. Before every `x.next = ...` ask: "did I save what x.next pointed to?"
6. State complexity at the end: time and space.

### 10.4 Practice roadmap (solve in this order)

**Level 1: basics (traversal, dummy, reverse)**
- 206 Reverse Linked List
- 21 Merge Two Sorted Lists
- 83 Remove Duplicates from Sorted List
- 203 Remove Linked List Elements
- 237 Delete Node in a Linked List
- 707 Design Linked List

**Level 2: fast & slow pointers**
- 876 Middle of the Linked List
- 141 Linked List Cycle
- 142 Linked List Cycle II
- 19 Remove Nth Node From End of List
- 160 Intersection of Two Linked Lists
- 234 Palindrome Linked List
- 2095 Delete the Middle Node of a Linked List

**Level 3: reversal and rewiring**
- 92 Reverse Linked List II
- 24 Swap Nodes in Pairs
- 328 Odd Even Linked List
- 86 Partition List
- 82 Remove Duplicates from Sorted List II
- 61 Rotate List
- 2 Add Two Numbers
- 445 Add Two Numbers II
- 725 Split Linked List in Parts

**Level 4: combine patterns**
- 143 Reorder List (middle + reverse + merge)
- 148 Sort List (middle + split + merge)
- 147 Insertion Sort List
- 138 Copy List with Random Pointer
- 430 Flatten a Multilevel Doubly Linked List

**Level 5: hard / design**
- 25 Reverse Nodes in k-Group
- 23 Merge k Sorted Lists
- 146 LRU Cache
- 460 LFU Cache

### 10.5 Final mental model

```
Linked list problem
   |
   +-- head might change?          -> dummy node
   +-- need middle / cycle / kth?  -> slow & fast
   +-- need to change direction?   -> prev / cur / next
   +-- combine two lists?          -> tail pointer + compare
   +-- need O(1) lookup?           -> hash map (+ doubly list)
   +-- stuck?                      -> draw it, trace 3 steps, find the lost pointer
```

Master these patterns plus the 4 base operations (traverse, insert, delete, reverse), and you can solve almost any linked list problem you will meet.

Good luck, Zakaria!