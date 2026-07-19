# Presentation: Facade Design Pattern

## Slide 1 — Title
- **Facade Design Pattern**
- CS202 — Object-Oriented Programming
- Your Name / Group Name

## Slide 2 — The Problem
- You want to watch a movie on your home theater
- Multiple components: amplifier, DVD player, projector, screen, lights
- Each has its own setup steps, and the order matters
- **Question**: How can we simplify this for the user?

## Slide 3 — Naive Solution
- Client code directly interacts with every subsystem
- Show a snippet of the naive `main.cpp`
- The client must remember a 10-step sequence
- Every "watch movie" operation repeats the same code

## Slide 4 — Problems with the Naive Approach
- Tight coupling: client knows every class
- Code duplication: same sequence everywhere
- Maintenance nightmare: adding a subwoofer breaks everything
- Violates Single Responsibility Principle

## Slide 5 — Facade Pattern — Introduction
- **Intent**: Provide a unified interface to a set of interfaces in a subsystem
- A **structural** design pattern (GoF)
- Does not hide the subsystem — provides a simpler view

## Slide 6 — General Class Diagram (Mermaid)
```
Client → Facade → SubsystemA, SubsystemB, SubsystemC
```
- Client only sees the Facade
- Facade delegates to subsystems

## Slide 7 — Home Theater Class Diagram (Mermaid)
```
Client → HomeTheaterFacade → Amplifier, DvdPlayer, Projector, Screen, TheaterLights
```
- `watchMovie()` encapsulates the full sequence
- `endMovie()` encapsulates the teardown

## Slide 8 — Implementation Walkthrough
- `HomeTheaterFacade` class
  - Receives subsystem references via constructor
  - `watchMovie()` — all 10 steps in one method
  - `endMovie()` — cleanup in one method
- Client code: 3 lines instead of 10

## Slide 9 — Live Demo (if applicable)
- Run `facade/theater_facade`
- Show the output
- Compare to the naive version output — same results, less code

## Slide 10 — Pros & Cons

| Pros | Cons |
|------|------|
| Loose coupling | Can become a god object |
| Reduced duplication | Extra layer of indirection |
| Clean client code | May hide fine-grained control |
| Easy maintenance | |

## Slide 11 — Other Applications
- **Web**: API Gateway in microservices
- **Mobile**: Camera / GPS hardware abstraction
- **Gaming**: Unity/Unreal engine APIs
- **Databases**: JDBC, Hibernate ORM

## Slide 12 — Quiz (Interactive)
1. Structural, creational, or behavioral? → **Structural**
2. Primary purpose? → **Simplify a complex subsystem**
3. Can clients still access subsystems directly? → **Yes**
4. Main risk? → **Becoming a god object**

## Slide 13 — Conclusion & Q&A
- Facade simplifies complex systems without hiding them
- Key takeaway: *Keep your clients simple; hide complexity behind a clean interface*
- Questions?
