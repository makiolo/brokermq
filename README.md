# Idea ECS SharedMemory Microservices

- 1 EntityManager-DLL. Use for create entities and assign components. Factory of components.
- 1 EventManager-DLL. Let comunicate systems between them.
- Service-DLL - publishing interface. Use cffi to generate a service dll with interface in C. Let mixing languages C++, Python, Rust ...
- Component-DLL - publishing structure. Use proto + cffi and generate a dll for each group of structures.
