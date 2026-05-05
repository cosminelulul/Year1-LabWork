# Year 1 Lab Work — Programming & Programming Languages
### Faculty of Applied Sciences, Politehnica University of Bucharest

This repository is a full record of my first-year C/C++ lab assignments across two semesters. It charts a deliberate path: from writing my first loops and functions in C, through understanding memory at a low level, all the way to designing multi-class C++ systems with inheritance, operator overloading, and polymorphism. Each folder represents a week or lab session; the progression in complexity is intentional and reflects what I actually learned, in order.

---

## Semester I — Foundations of Programming in C/C++

The first semester used a mix of C and C++ to build a solid grounding in how programs actually work. The emphasis was on procedural thinking: breaking problems into functions, understanding how data is stored and moved in memory, and getting comfortable with the compiler before introducing any abstraction.

### What I learned

**Types, expressions, and control flow** (Labs 2–4)
Wrote programs involving integer/float arithmetic, type casting, and conditional logic using both `if/else` and the ternary operator. Learned how integer division differs from floating-point division and when explicit casting is needed. Exercises included comparing fractions, checking parity, and evaluating compound boolean conditions.

**Arrays, vectors, and strings** (Labs 4–6)
Worked with fixed-size arrays and character arrays (`char[]`), implementing operations like finding duplicates, reversing strings, case conversion, and string comparison without the standard library. Learned that a "string" in C is just a null-terminated array of characters — and why that matters.

**Matrices** (Labs 5–7)
Implemented 2D array operations: traversal, transpose, searching for min/max values, and working with integer matrices. Learned to reason about row-major layout and nested loop complexity.

**Functions and references** (Labs 7–8)
Moved from monolithic `main()` to properly decomposed programs. Practiced pass-by-value vs. pass-by-reference (`&`), wrote recursive functions (factorial, GCD), and learned when returning a value vs. modifying via reference is the right choice. Also implemented basic sorting and concatenation of dynamically allocated vectors.

**Pointers and dynamic memory allocation** (Labs 8–9)
Learned to allocate memory on the heap using `malloc` / `free` and `new` / `delete`. Understood pointer arithmetic, the difference between stack and heap lifetime, and why forgetting to `free` causes memory leaks. Built vectors whose size is determined at runtime — the step from `int arr[10]` to `int *arr = (int*)malloc(n * sizeof(int))` turned out to be one of the most important shifts in the whole year.

**Structs and enums** (Labs 10–11)
Grouped related data into `struct` types — fractions (`Fractie`), vehicles (`Vehicul`), students. Used `enum` to represent a fixed set of values (e.g. land / water / air / space vehicles) in a type-safe way. Implemented functions that operated on structs by reference, including arithmetic on fractions (addition, subtraction, multiplication, division with simplification via GCD) and dynamic arrays of structs.

**Bit fields** (Lab 11)
Used bit-field members inside a struct (`unsigned int putere:8`) to pack data into fewer bytes than a normal `int` would use. A small detail, but it demonstrated that C gives you control at the bit level if you need it.

**Transition to classes** (Lab 12)
Took an existing struct (`Persoane`) and rewrote it as a proper class, adding `private` visibility, a constructor, and member functions for reading/displaying data. This was the conceptual bridge into Semester II.

### Semester I Project — Basic Calculator
A standalone calculator supporting both integer and floating-point operands, written in C++. Reinforced function decomposition and input validation in a self-contained program.

---

## Semester II — Object-Oriented Programming in C++

The second semester was entirely C++ and entirely OOP. Each weekly assignment built on the last, introducing one or two new concepts at a time on the same running example (a `Masina`/car class that grew from a simple struct into a fully-featured class with operator overloading, file I/O, and inheritance).

### What I learned

**Encapsulation and class design** (Săpt 1–2)
Converted struct-based code into proper classes with `private` attributes and `public` member functions. Wrote constructors (default and parameterised), destructors, and getter/setter methods. Understood *why* encapsulation exists — it protects invariants (e.g., a fraction's denominator can never be zero) and separates interface from implementation.

**The Rule of 3 — Copy constructor, destructor, assignment operator** (Săpt 2–3)
When a class owns a raw pointer (like `char *marca`), the compiler-generated copy constructor and assignment operator do a *shallow copy* — both objects end up pointing to the same memory, and freeing one corrupts the other. Learned to write a deep-copying copy constructor and a safe `operator=`, and a destructor that frees the pointer. This is the Rule of 3, and it explained a whole class of bugs that had been baffling me.

**Operator overloading** (Săpt 3–4)
Overloaded `==`, `!=`, `<`, `>`, `<=`, `>=` as `friend` functions, and `=` as a member function. Also overloaded `<<` and `>>` so objects could be used directly with `cout`/`cin`. Writing `operator<<` for a class makes debugging dramatically easier. Learned the difference between member and friend overloads, and when each is appropriate.

**Static members** (Săpt 4)
Added a `static int nr_obiecte` counter to the `Masina` class, incremented in every constructor and decremented in the destructor. Learned that `static` members belong to the *class*, not to any individual object — one variable shared across all instances.

**`std::string` and file I/O** (Săpt 5)
Switched from raw `char*` to `std::string` for the `Persoana` class. Parsed CNP numbers (Romanian personal identification codes) using string indexing to extract birth date, gender, and validity. Used `fstream` (both `ifstream` and `ofstream`) to read objects from a file and write them back — real persistence, not just printing to the terminal.

**Composition and aggregation** (Săpt 6)
Modelled an `Imobil` (building) that *contains* an `Adresa` (address) object. Learned the distinction between composition (the inner object is owned and destroyed with the outer) and aggregation (the inner object has independent lifetime). Managing constructors that initialise member objects via initialiser lists came out of this.

**Custom string class — `MyString`** (Săpt 7, Bonus)
Implemented a string class from scratch: internal `char*` buffer, copy constructor, assignment operator, destructor (Rule of 3 again), and overloaded `+`, `+=`, `[]`, `==`, `!=`, and relational operators for alphabetical ordering. Building something you already take for granted (`std::string`) from first principles is one of the most effective ways to understand C++ memory management.

**Inheritance and the Rule of 5** (Săpt 8)
Introduced a `Produs` base class and derived `Aliment` (food product) and `Aliment_Ambalat` (packaged food) from it. Practiced calling base class constructors from derived constructors using the member initialiser list. With inheritance and dynamic memory in play, the copy constructor and assignment operator of the derived class need to explicitly handle the base class's resources — the Rule of 3 became the Rule of 5 (adding move constructor and move assignment).

**Polymorphism and virtual functions** (Săpt 11–12)
Declared `virtual` methods in a `Produs` base class and overrode them in `produs_software`, `modul_hardware`, and `Piesa` subclasses. Used a base-class pointer to a derived object and confirmed that the right `afis()` / `getPret()` implementation was called at runtime (dynamic dispatch). Also worked with pure virtual functions (`= 0`) to define abstract interfaces that subclasses *must* implement.

**The Standard Template Library** (Săpt 12)
Used `std::vector` to replace manually managed dynamic arrays — no more `new[]`, pointer arithmetic, or manual resizing. Learned how `vector` manages its own memory and why it should almost always be preferred over raw arrays when the size is not fixed at compile time.

### Semester II Project — Music Library
A multi-file C++ project modelling a music catalogue with four classes: `Persoana` (base), `Artist` (inherits `Persoana`), `Album`, and `Track`. `Artist` holds a `std::vector<Album>` and each `Album` holds a `std::vector<Track>`. The project pulled together everything from the semester: inheritance, composition, `std::vector`, file separation into `.h`/`.cpp` pairs, and virtual display methods.

---

## Concepts at a Glance

| Concept | Where it appears |
|---|---|
| Pointers & dynamic memory (`malloc`, `new`) | Sem 1 Labs 8–11, Sem 2 Săpt 1–4 |
| Structs and enums | Sem 1 Labs 10–12 |
| Classes, encapsulation | Sem 2 Săpt 1+ |
| Rule of 3/5 (copy ctor, dtor, `operator=`) | Sem 2 Săpt 2–8 |
| Operator overloading | Sem 2 Săpt 3–4, 7 |
| Static class members | Sem 2 Săpt 4 |
| `std::string` & file I/O | Sem 2 Săpt 5 |
| Composition & aggregation | Sem 2 Săpt 6 |
| Inheritance | Sem 2 Săpt 8, 11–12 |
| Polymorphism & virtual functions | Sem 2 Săpt 11–12 |
| Abstract classes | Sem 2 Săpt 12 |
| `std::vector` (STL) | Sem 2 Săpt 12, Proiect |

---

## Notes

All code was written as coursework at the [Faculty of Applied Sciences, Politehnica University of Bucharest](http://fsa.pub.ro/), and subsequently cleaned up and commented for clarity. File names follow the original lab numbering; Romanian variable and function names reflect the course materials.
