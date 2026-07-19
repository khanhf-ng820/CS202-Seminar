# Presentation: Strategy Design Pattern

## Slide 1 — Title
- **Strategy Design Pattern**
- CS202 — Object-Oriented Programming
- CS202 Seminar Group

## Slide 2 — The Problem: Route Planning
- Building a GPS Navigation App (Google Maps)
- Multiple transport modes: Driving, Walking, Public Transit, Bicycling
- Each transport mode has unique algorithms, constraints, and data feeds
- **Question**: How can we design a flexible routing system without messy `if-else` blocks?

## Slide 3 — Naive Solution
- Single monolithic `Navigator` class
- Uses `enum TransportMode` and a huge `switch`/`if-else` block inside `buildRoute()`
- Show snippet of naive `main.cpp`
- **Pain Point**: Modifying or adding one algorithm requires modifying and recompiling the entire `Navigator`

## Slide 4 — Problems with the Naive Approach
- **Violates Open/Closed Principle (OCP)**: Adding `BICYCLING` breaks existing code
- **Violates Single Responsibility Principle (SRP)**: `Navigator` manages UI *and* all routing algorithms
- **High Maintenance**: Hard to test individual algorithms in isolation
- **Rigid**: Cannot swap or configure algorithm objects dynamically at runtime

## Slide 5 — Strategy Pattern — Introduction
- **Intent**: Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
- A **behavioral** design pattern (GoF)
- Encapsulates *what changes* (the algorithm) behind a common interface

## Slide 6 — General Class Diagram
- `Client` → `Context` o--> `Strategy` (Interface) <|.. `ConcreteStrategyA`, `ConcreteStrategyB`, `ConcreteStrategyC`
- `Context` delegates algorithm execution to `Strategy`

## Slide 7 — Navigation App Class Diagram
- `Client` → `Navigator` o--> `RouteStrategy` (Interface) <|.. `DrivingStrategy`, `WalkingStrategy`, `PublicTransitStrategy`, `BicyclingStrategy`
- `setStrategy(RouteStrategy*)` allows dynamic runtime strategy swapping

## Slide 8 — C++ Implementation: Strategy Interface & Concrete Classes
- `RouteStrategy.h` abstract base class with pure virtual `buildRoute()`
- `DrivingStrategy.h`, `WalkingStrategy.h`, `BicyclingStrategy.h` implementation headers
- Code walkthrough of clean polymorphism

## Slide 9 — C++ Implementation: Context & Clean Client Code
- `Navigator` context class holding `const RouteStrategy* strategy`
- Client code: 3 lines to switch strategy dynamically at runtime
- Zero `if-else` statements in client or context

## Slide 10 — Pros & Cons

| Pros | Cons |
| :--- | :--- |
| Open/Closed Principle (OCP) compliant | Increases number of classes/objects |
| Single Responsibility Principle (SRP) | Clients must be aware of strategy differences |
| Runtime algorithm switching | Overhead for simple/rarely-changing logic |
| Isolated unit testing | |

## Slide 11 — Other Applications
- **Web**: Authentication strategies (Passport.js), Payment Gateways (PayPal, Stripe)
- **Mobile**: Layout managers (RecyclerView), Image caching policies
- **Gaming**: NPC AI behavior trees (Patrol, Attack, Flee)
- **Databases**: Adaptive sorting algorithms (Introsort, Quicksort)

## Slide 12 — Interactive Kahoot Quiz (7 Questions)
- 2x2 rectangular grid layout
- Green highlighted correct answers for immediate feedback

## Slide 13 — Conclusion & Q&A
- Key takeaway: *Encapsulated algorithms make systems open for extension, closed for modification.*
- Questions & Discussion
