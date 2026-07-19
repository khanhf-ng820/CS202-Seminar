# CS202 Strategy Design Pattern — Presentation Defense & Q&A Guide

> **Document Purpose**: This document compiles potential questions that peer reviewers, students, and professors may ask during or after the CS202 Strategy Design Pattern seminar presentation. Each question is paired with a thorough, highly technical answer backed by C++ code examples, software architecture principles, and GoF design pattern theory.

---

## Table of Contents
1. [Category 1: Architectural & Design Fundamentals](#category-1-architectural--design-fundamentals)
2. [Category 2: Pattern Comparisons (Strategy vs. State, Template Method, Command, Decorator, Facade)](#category-2-pattern-comparisons)
3. [Category 3: C++ Implementation & Technical Deep Dive](#category-3-c-implementation--technical-deep-dive)
4. [Category 4: Real-World Applications & Testing Strategies](#category-4-real-world-applications--testing-strategies)
5. [Category 5: Reviewer & Professor Challenge Questions](#category-5-reviewer--professor-challenge-questions)

---

## Category 1: Architectural & Design Fundamentals

### Q1: What is the primary problem that the Strategy pattern solves, and how does it improve overall software design?
**Recommended Answer**:
The Strategy pattern solves the problem of hardcoded, monolithic algorithmic logic controlled by conditional statements (`if-else` or `switch`). 

In a naive navigation application without Strategy, calculating routes requires a single class (`Navigator`) to contain all routing calculations for driving, walking, public transit, and bicycling.

By introducing the **Strategy pattern**, we encapsulate each routing algorithm inside its own class implementing a common interface (`RouteStrategy`). This improves software design by:
- **Enforcing Open/Closed Principle (OCP)**: New algorithms can be added simply by creating a new `RouteStrategy` subclass without editing existing code.
- **Enforcing Single Responsibility Principle (SRP)**: The `Navigator` context handles navigation session state, while individual strategy classes handle the complex mathematical mechanics of routing.
- **Enabling Runtime Flexibility**: Clients can dynamically switch routing strategies on-the-fly (`navigator.setStrategy(&walking)`).

---

### Q2: How does the principle "Favor Composition over Inheritance" manifest in the Strategy pattern?
**Recommended Answer**:
Instead of creating a complex class hierarchy where `DrivingNavigator`, `WalkingNavigator`, and `TransitNavigator` inherit from a base `Navigator` class:
- **Inheritance Approach (Rigid)**: A `DrivingNavigator` object is permanently locked to driving logic at instantiation. Changing to walking mid-session requires destroying the object and creating a new `WalkingNavigator`.
- **Composition Approach (Strategy - Flexible)**: A single `Navigator` (Context) object **has a** `RouteStrategy` reference. The behavior is delegated to the strategy object, allowing the algorithm to be swapped at runtime via `setStrategy()`.

---

### Q3: Does using the Strategy pattern lead to an explosion of classes? When is it an anti-pattern?
**Recommended Answer**:
- **Class Count Overhead**: Yes, creating a separate class for every variation of an algorithm increases the number of files in a codebase.
- **When Strategy becomes an Anti-Pattern / Over-engineering**: If an algorithm has only one static implementation, or if variations are trivial 1-line parameters (e.g. changing a speed multiplier `x1.5`), creating Strategy interfaces and multiple classes introduces unnecessary indirection and complexity. Strategy should be used when algorithms have distinct structural mechanics or variable dependencies.

---

## Category 2: Pattern Comparisons

### Q4: What is the exact difference between the Strategy pattern and the State pattern?
**Recommended Answer**:
Structure-wise, Strategy and State are virtually identical (both use composition and delegate work to an interface). However, their **intents and state transitions** differ fundamentally:

| Feature | Strategy Pattern | State Pattern |
| :--- | :--- | :--- |
| **Primary Intent** | Provide interchangeable algorithms to achieve a goal. | Represent internal state transitions of an object. |
| **Awareness of Siblings** | Concrete strategies are completely independent and unaware of other strategies. | Concrete states often know about sibling states and trigger transitions to next states. |
| **Client Control** | The **Client** usually selects and passes the strategy to the Context. | State transitions happen **automatically inside the Context or State classes** as state changes. |

---

### Q5: How does Strategy differ from the Template Method pattern?
**Recommended Answer**:
- **Strategy (Composition / Delegation)**: Defines a whole algorithm behind an interface. The Context delegates work to a Strategy object at runtime. Works at the **object level**.
- **Template Method (Inheritance / Subclassing)**: Defines the skeleton of an algorithm in a base class method (`templateMethod()`), deferring specific steps to subclasses via primitive virtual methods. Works at the **class level** at compile-time.

---

### Q6: How does Strategy differ from Command and Decorator?
**Recommended Answer**:
- **Strategy vs. Command**: Strategy encapsulates *how* to do a task (algorithm choices). Command encapsulates *an action request* (along with parameters and receiver) into an object so it can be queued, logged, or undone.
- **Strategy vs. Decorator**: Strategy changes the *guts* of an object (swapping its internal algorithm). Decorator changes the *skin* of an object (wrapping it to add extra responsibilities dynamically without altering its interface).

---

## Category 3: C++ Implementation & Technical Deep Dive

### Q7: Why is a virtual destructor (`virtual ~RouteStrategy() = default;`) required in the Strategy interface header?
**Recommended Answer**:
In C++, when deleting an object of a derived class (`DrivingStrategy`) through a pointer to its base class interface (`RouteStrategy*`), if the base class destructor is not declared `virtual`, the behavior is **undefined**. Specifically:
- The derived class destructor will not execute, causing memory leaks or unreleased resources (e.g. closed file handles, sockets, or dynamically allocated memory inside `DrivingStrategy`).
- Marking `virtual ~RouteStrategy() = default;` ensures proper polymorphic cleanup.

---

### Q8: In your C++ implementation, why did you pass strategy pointers (`const RouteStrategy*`) into the Context instead of passing by value (`RouteStrategy strategy`)?

```cpp
class Navigator {
private:
    const RouteStrategy* strategy;
public:
    void setStrategy(const RouteStrategy* newStrategy) { strategy = newStrategy; }
};
```

**Recommended Answer**:
1. **Preventing Object Slicing**: In C++, passing a derived class (`DrivingStrategy`) by value into a parameter expecting a base class (`RouteStrategy`) causes **object slicing**. The derived members and vtable entry are stripped away, breaking virtual dispatch.
2. **Polymorphic Execution**: Pointers (`RouteStrategy*`) or references (`RouteStrategy&`) preserve the virtual method table (vtable), enabling dynamic runtime dispatch to `DrivingStrategy::buildRoute()`.
3. **Smart Pointer Alternative (`std::unique_ptr`)**: In modern C++, if the Context owns the strategy lifecycle, `std::unique_ptr<RouteStrategy>` can be used for automatic memory management. In our stack-allocated demo, passing raw pointers or references guarantees zero heap allocation overhead.

---

### Q9: Does the virtual function call in the Strategy pattern cause significant performance overhead?
**Recommended Answer**:
Virtual function calls in C++ incur a tiny overhead due to **vtable pointer dereferencing** and the prevention of compiler method inlining. 

However:
- For high-level operations like route planning, database queries, or payment processing, the nanosecond vtable lookup cost is completely negligible compared to the execution time of the algorithm itself.
- For hyper-performance low-level loops (e.g., executing a calculation 10 billion times per second inside a GPU shader), **Static Polymorphism** via C++ Templates (CRTP - Curiously Recurring Template Pattern) or `std::variant` can be used instead of virtual functions.

---

## Category 4: Real-World Applications & Testing Strategies

### Q10: How is the Strategy pattern applied in modern Web Development frameworks?
**Recommended Answer**:
- **Passport.js Authentication (Node.js)**: Developers configure authentication strategies like `passport.use(new LocalStrategy(...))` or `passport.use(new GoogleStrategy(...))`. The authentication middleware context calls `authenticate()` without caring whether it's checking password hashes or OAuth tokens.
- **Payment Processing**: E-commerce platforms define a `PaymentStrategy` interface with implementations `CreditCardPayment`, `PayPalPayment`, and `CryptoPayment`.

---

### Q11: How does Strategy facilitate Automated Testing and Mocking?
**Recommended Answer**:
In unit testing, the Strategy pattern allows testing the Context (`Navigator`) in total isolation:
- A `MockRouteStrategy` can be injected into `Navigator` during unit tests.
- The mock strategy logs when `buildRoute()` is called and verifies origin/destination strings without executing actual route calculations or fetching real-world traffic data APIs.

---

## Category 5: Reviewer & Professor Challenge Questions

### Q12: (Professor Challenge) "If the client must know about all concrete strategies to pick one, doesn't that couple the client to concrete classes anyway?"
**Recommended Answer**:
"That is a great observation, Professor. While the client creates the concrete strategy instance, this coupling is **localized entirely to initialization time**. 

Once the strategy is injected into the Context (`Navigator`), the entire execution pipeline and subsequent application layers depend strictly on the abstract `RouteStrategy` interface. Furthermore, strategy selection can be decoupled even further by combining Strategy with a **Factory Pattern** or Dependency Injection container, allowing clients to pass a string configuration (e.g., `StrategyFactory::create("driving")`) without directly referencing concrete strategy classes."

---

### Q13: (Reviewer Challenge) "What happens if a client forgets to set a strategy before calling `buildRoute()`?"
**Recommended Answer**:
"In our C++ implementation, we guard against `nullptr` with an explicit check:

```cpp
void buildRoute(const std::string& origin, const std::string& destination) const {
    if (strategy) {
        strategy->buildRoute(origin, destination);
    } else {
        std::cout << " -> Error: No routing strategy set!\n";
    }
}
```

Alternatively, we can use the **Null Object Pattern** by providing a `DefaultRouteStrategy` or `NullRouteStrategy` as a fallback, ensuring `strategy` is never null and eliminating defensive `if (strategy)` checks."

---

### Q14: Summary Checklist for Presentation Q&A Defense

| Question Topic | Key Defense Keyword / Concept |
| :--- | :--- |
| **Why Strategy?** | Open/Closed Principle (OCP), Single Responsibility (SRP), eliminating `if-else`/`switch` blocks. |
| **Strategy vs. State** | Strategy = *Independent algorithms chosen by client*; State = *Automatic state transitions*. |
| **Strategy vs. Template Method** | Strategy = *Composition at runtime*; Template Method = *Inheritance at compile time*. |
| **C++ Memory & Virtuals** | Pass by pointer/reference to avoid *object slicing*; use `virtual` destructor for safe cleanup. |
| **Client Coupling** | Combine Strategy with *Factory Pattern* or DI to decouple client from concrete classes. |
| **Null Safety** | Defensive checks or *Null Object Pattern* fallback. |
