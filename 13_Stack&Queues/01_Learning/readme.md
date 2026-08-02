# 🧠 Array vs Linked List Memory Management

## 📦 Array

✅ **One single memory block is allocated.**

```cpp
st = new int[n];
```

### Pop Operation
- Only moves `top`.
- Element is **logically removed**, but the memory is still part of the array.

### Memory Release

```cpp
delete[] st;
```

The **entire array** is released at once.

### 🏢 Real-Life Analogy

Think of an **apartment building**.

- One building contains many rooms.
- If one room becomes empty, you **don't demolish that room**.
- The **entire building** is demolished only once.


---

## 🔗 Linked List

✅ **Each node is allocated separately.**

```cpp
new Node(x);
```

### Pop Operation
- Move `top` to the next node.
- Delete the old node.

```cpp
delete temp;
```

### Memory Release

Only the removed node's memory is released.

### 🏠 Real-Life Analogy

Think of **individual houses**.

- Every house is built separately.
- If one house is no longer needed, you can **demolish only that house**.
- The remaining houses are unaffected.


---

## 🔥 Memory Trick

| Array | Linked List |
|-------|-------------|
| One big memory block | Many small memory blocks |
| `delete[]` once | `delete` each removed node |
| Pop only moves `top` | Pop moves `top` **and** deletes the old node |

> **Remember:**  
> **Array = One Big Block → `delete[]` once**  
> **Linked List = Many Small Blocks → `delete` each node**